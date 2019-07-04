#include "mycanvas.h"
#include <string>
#include <memory>
#include "../MyLibrary/myLog.h"
#include "../MyLibrary/GameManager.h"
#include "../MyLibrary/MoveCommand.h"
#include "../MyLibrary/AttackCommand.h"
#include "QtGuiBattlefield.h"
#include <QMessageBox>


MyCanvas::MyCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size) : QSFMLCanvas(Parent, Position, Size), is_move(false), is_attack(false), turn(0), thisRound(bossID,numberWarrior,numberArcher)
{
	spriteWidth = GameConfigue::sprite_width();
	spriteHeight = GameConfigue::sprite_height();
	unitScale = GameConfigue::unit_scale();
	defaultScale = GameConfigue::default_scale();
}

void MyCanvas::OnInit()
{
	clear();
	// Load the image
	//tmx::Map map;
	map.load("asset/map.tmx");
	MapLayer layer(map, 0);
	RenderWindow::draw(layer);

	//set Texture used for diaplay diatance range
	moveTexture.loadFromFile("../QtGuiApplication/asset/movePosition.png");
	attackTexture.loadFromFile("../QtGuiApplication/asset/attackPosition.png");

	
	for (auto solder : thisRound.getArmy())
	{
		RenderWindow::draw(solder->getMySprite());
	}

	for (auto boss : thisRound.getBosss())
	{
		RenderWindow::draw(boss->getMySprite());
	}
	myClock.restart();
}


void MyCanvas::OnUpdate()
{

	//update turn time in UI
	((QtGuiBattlefield *)parentWidget())->updateGameRound(std::to_string(turn));

	//every time redraw mycanvas
	//show map
	MapLayer layer(map, 0);
	RenderWindow::draw(layer);

	for (auto solder : thisRound.getArmy())
	{
		//show selected unit move/attack range
		if (solder->isSelected()) {
			if (is_move) {
				sf::FloatRect unit = solder->getMySprite().getGlobalBounds();
				float d = solder->getMoveDistance();
				distanceSprite.setTexture(moveTexture);
				distanceSprite.setTextureRect(sf::IntRect(0, 0, int(2 * d + unit.width), int(2 * d + unit.height)));
				distanceSprite.setPosition(unit.left - d, unit.top - d);
				RenderWindow::draw(distanceSprite);
			} else if (is_attack) {
				sf::FloatRect unit = solder->getMySprite().getGlobalBounds();
				float d = solder->getDamageDistance();
				distanceSprite.setTexture(attackTexture);
				distanceSprite.setTextureRect(sf::IntRect(0, 0, int(2 * d + unit.width), int(2 * d + unit.height)));
				distanceSprite.setPosition(unit.left - d, unit.top - d);
				RenderWindow::draw(distanceSprite);
			}
		}
		//show army sprites
		if (solder->getHP() > 0) {
			((QtGuiBattlefield *)parentWidget())->updateUnitID(solder->getID());
			((QtGuiBattlefield *)parentWidget())->updateUnitHP(std::to_string(solder->getHP()) + "/" + std::to_string(solder->getHPmax()));
			((QtGuiBattlefield *)parentWidget())->updateUnitMoveDistance(std::to_string(solder->getMoveDistance()));
			((QtGuiBattlefield *)parentWidget())->updateUnitAttribute("Damage: " + std::to_string(solder->getDamage()));
			RenderWindow::draw(solder->getMySprite());
		}
		
		
	}
	//show boss sprites
	for (auto boss : thisRound.getBosss())
	{
		if (boss->getHP() > 0) {
			RenderWindow::draw(boss->getMySprite());
			((QtGuiBattlefield *)parentWidget())->updateBossID(boss->getID());
			((QtGuiBattlefield *)parentWidget())->updateBossHP(std::to_string(boss->getHP()) + "/" + std::to_string(boss->getHPmax()));
			((QtGuiBattlefield *)parentWidget())->updateBossMoveDistance(std::to_string(boss->getMoveDistance()));
			((QtGuiBattlefield *)parentWidget())->updateBossAttribute("Damage: " + std::to_string(boss->getDamage()) + " Heal: " + std::to_string(boss->getHeal()));
		}
	}
	
	//if game end close this renderwindow
	/*if (GameManager::instance().getGamer()->getCurrentRound().isEnd())
	{
		RenderWindow::close();
	}
*/
	
	//check if player pushes start button
	//if game hasn't started
	if (!thisRound.isStart())
	{
		sf::Event event;
		//these two mouse events allow player change his army's position
		while (pollEvent(event)) {
			switch (event.type) {
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					sf::Vector2i mousePotitionpix = sf::Mouse::getPosition(*this);
					sf::Vector2f mousePotitionf = sf::Vector2f(mousePotitionpix);
					for (std::shared_ptr<Unit> solder : thisRound.getArmy())
					{
						if (solder->getMySprite().getGlobalBounds().contains(mousePotitionf)) {
							solder->setSelected();
							((QtGuiBattlefield *)parentWidget())->updateUnitID(solder->getID());
							((QtGuiBattlefield *)parentWidget())->updateUnitHP(std::to_string(solder->getHP()) + "/" + std::to_string(solder->getHPmax()));
							((QtGuiBattlefield *)parentWidget())->updateUnitMoveDistance(std::to_string(solder->getMoveDistance()));
							((QtGuiBattlefield *)parentWidget())->updateUnitAttribute("Damage: " + std::to_string(solder->getDamage()));
						}
					}
				}
				break;
			case sf::Event::MouseButtonReleased:
			{
				for (std::shared_ptr<Unit> solder : thisRound.getArmy())
				{
					if (solder->isSelected()) {
						float positonx = sf::Vector2f(sf::Mouse::getPosition(*this)).x-(spriteWidth/2*unitScale);
						float positony = sf::Vector2f(sf::Mouse::getPosition(*this)).y-(spriteHeight/2*unitScale);
						//move solder's position except he has no collision with any other units
						if (!checkCollision(sf::Vector2f(sf::Mouse::getPosition(*this)))) {
							solder->moveTo(std::pair<float, float>(positonx, positony));
						}
						solder->setUnSelected();
					}
				}
				break;
			}
			}
		}

	}
	else {
		
		sf::Event event;
		//these two mouse events allow player change his army's position
		while (pollEvent(event)) {
			switch (event.type) {
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					sf::Vector2i mousePotitionpix = sf::Mouse::getPosition(*this);
					sf::Vector2f mousePotitionf = sf::Vector2f(mousePotitionpix);
					for (std::shared_ptr<Unit> solder : thisRound.getArmy())
					{
						if (solder->isSelected()&& solder->getHP() > 0){
							if (is_move) {
								//move solder if it is in its move range
								if (distanceSprite.getGlobalBounds().contains(mousePotitionf)) {
									float positonx = sf::Vector2f(sf::Mouse::getPosition(*this)).x - (spriteWidth / 2 * unitScale);
									float positony = sf::Vector2f(sf::Mouse::getPosition(*this)).y - (spriteHeight / 2 * unitScale);
									std::shared_ptr<Command> moveCommande = std::make_shared<MoveCommand>(solder, std::pair<float, float>(positonx, positony));
									moveCommande->execute();
									//GameManager::instance().getGamer()->getCurrentRound().addCommand2Army(moveCommande);
									thisRound.addTurn();
								}
							}
							else if (is_attack) {
								for (auto boss : thisRound.getBosss()) {
									//check if boss is in the solder's attack range and player choose to attack this boss
									if (distanceSprite.getGlobalBounds().intersects(boss->getMySprite().getGlobalBounds())&& boss->getMySprite().getGlobalBounds().contains(mousePotitionf)) {
										std::shared_ptr<Command> attackCommand = std::make_shared<AttackCommand>(solder, boss);
										attackCommand->execute();
										thisRound.addCommand2Army(attackCommand);
										//boss AI command
										std::shared_ptr<Command> bossCommand;
										if (boss->getMySprite().getGlobalBounds().intersects(solder->getMySprite().getGlobalBounds())) {
											bossCommand = std::make_shared<AttackCommand>(boss, solder);
										}
										else {
											float bossPositionx = boss->getPosition().first;
											float bossPositiony = boss->getPosition().second;
											int bossMoveDistance = boss->getMoveDistance();
											bossCommand = std::make_shared<MoveCommand>(boss, std::pair<float, float>(bossPositionx- bossMoveDistance, bossPositiony));
											//bossCommand = std::make_shared<MoveCommand>(boss, std::pair<float, float>(bossPositionx - defaultScale*3, bossPositiony));

										}
										bossCommand->execute();
										thisRound.addCommand2Boss(bossCommand);
											
										
										thisRound.addTurn();
									}
								}
								
							}
						}

						if (solder->getMySprite().getGlobalBounds().contains(mousePotitionf)&& solder->getHP() > 0) {
							if (solder->isSelected())
							{
								solder->setUnSelected();
							}
							else {
								solder->setSelected();
							}
							((QtGuiBattlefield *)parentWidget())->updateUnitID(solder->getID());
							((QtGuiBattlefield *)parentWidget())->updateUnitHP(std::to_string(solder->getHP()) + "/" + std::to_string(solder->getHPmax()));
							((QtGuiBattlefield *)parentWidget())->updateUnitMoveDistance(std::to_string(solder->getMoveDistance()));
							((QtGuiBattlefield *)parentWidget())->updateUnitAttribute("Damage: " + std::to_string(solder->getDamage()));
							
						}
						else {
							solder->setUnSelected();
						}

					}

				}
				break;
			}
		}
	}
	
	//check this round win or loss
	QMessageBox msgBox;

	RoundState state = thisRound.winOrLoss();
	switch (state) {
	case RoundState::WIN: {
		msgBox.setText("Victory!!!!^^");
		msgBox.exec();
		thisRound.gameEnd();
		break;
	}
	case RoundState::LOSS: {
		msgBox.setText("Defeat");
		msgBox.exec();
		thisRound.gameEnd();
		break;
	}
	case RoundState::DRAW: {
		msgBox.setText("Draw");
		msgBox.exec();
		thisRound.gameEnd();
		break;
	}
	}

	myClock.restart();
}

bool MyCanvas::isSomeoneSelected()
{
	for (std::shared_ptr<Unit> solder : thisRound.getArmy()) {
		if (solder->isSelected()) return true;
	}
	return false;
}


void MyCanvas::setIsMove(bool i)
{
	is_move = i;
}

void MyCanvas::setIsAttack(bool i)
{
	is_attack = i;
}

void MyCanvas::setBossID(int id)
{
	bossID = id;
}

void MyCanvas::setNumberWarrior(int n)
{
	numberWarrior = n;
}

void MyCanvas::setNumberArcher(int n)
{
	numberArcher = n;
}


bool MyCanvas::checkCollision(sf::Vector2f newPosition) {
	for (std::shared_ptr<Unit> solder : thisRound.getArmy()) {
		if (solder->isSelected()) continue;
		else {
			if (solder->getMySprite().getGlobalBounds().contains(newPosition)) {
				return true;
			}
		}
	}
	return false;
}
