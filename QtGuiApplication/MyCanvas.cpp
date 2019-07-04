#include "mycanvas.h"
#include <string>
#include <memory>
#include "../MyLibrary/myLog.h"
#include "../MyLibrary/GameManager.h"
#include "../MyLibrary/MoveCommand.h"
#include "../MyLibrary/AttackCommand.h"
#include "QtGuiBattlefield.h"
#include <QMessageBox>


MyCanvas::MyCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size,int bossID,int numberWarrior,int numberArcher) : QSFMLCanvas(Parent, Position, Size),thisRound(bossID,numberWarrior,numberArcher)
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
	((QtGuiBattlefield *)parentWidget())->updateGameRound(std::to_string(thisRound.getTurn()));

	//every time redraw mycanvas
	//show map
	MapLayer layer(map, 0);
	RenderWindow::draw(layer);

	updateSprites();

	QMessageBox msgBox;
	
	switch (thisRound.fsm.state())
	{
	//before start let player modify army's position
	case INIT:
		dragAndput();
		break;
	case END:
		RenderWindow::close();
		break;
	case START:
		thisRound.fsm.execute(GameRound::Triggers::winOrLoss);
		doCommand();
		break;
	case WIN:
		thisRound.fsm.execute(GameRound::Triggers::gameEnd);
		msgBox.setText("Victory!!!!^^");
		msgBox.exec();
		break;
	case LOSS:
		thisRound.fsm.execute(GameRound::Triggers::gameEnd);
		msgBox.setText("Defeat");
		msgBox.exec();
		break;
	case DRAW:
		thisRound.fsm.execute(GameRound::Triggers::gameEnd);
		msgBox.setText("Draw");
		msgBox.exec();
		break;
	}
	
	myClock.restart();
}

//bool MyCanvas::isSomeoneSelected()
//{
//	for (std::shared_ptr<Unit> solder : thisRound.getArmy()) {
//		if (solder->fsm.state() == Unit::States::Selected) return true;
//	}
//	return false;
//}

std::shared_ptr<Unit> MyCanvas::getSelected()
{
	for (std::shared_ptr<Unit> solder : thisRound.getArmy()) {
		if (solder->fsm.state() != Unit::States::Unselected) return solder;
	}
	return NULL;
}


GameRound & MyCanvas::getGameRound()
{
	// TODO: insert return statement here
	return thisRound;
}


bool MyCanvas::checkCollision(sf::Vector2f newPosition) {
	for (std::shared_ptr<Unit> solder : thisRound.getArmy()) {
		if (solder->fsm.state() == Unit::States::Selected) continue;
		else {
			if (solder->getMySprite().getGlobalBounds().contains(newPosition)) {
				return true;
			}
		}
	}
	return false;
}

void MyCanvas::dragAndput()
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
						solder->fsm.execute(Unit::Triggers::Select);
					}
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
		{
			for (std::shared_ptr<Unit> solder : thisRound.getArmy())
			{
				if (solder->fsm.state() == Unit::States::Selected) {
					float positonx = sf::Vector2f(sf::Mouse::getPosition(*this)).x - (spriteWidth / 2 * unitScale);
					float positony = sf::Vector2f(sf::Mouse::getPosition(*this)).y - (spriteHeight / 2 * unitScale);
					//move solder's position except he has no collision with any other units
					if (!checkCollision(sf::Vector2f(sf::Mouse::getPosition(*this)))) {
						solder->moveTo(std::pair<float, float>(positonx, positony));
					}
					solder->fsm.reset();
				}
			}
			break;
		}
		}

	}
	
}

void MyCanvas::doCommand()
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
					switch (solder->fsm.state()) {
					case Unit::States::Unselected:
						if (solder->getMySprite().getGlobalBounds().contains(mousePotitionf)) {
							solder->fsm.execute(Unit::Triggers::Select);
						}
						break;
					case Unit::States::Selected:
						solder->fsm.reset();
						break;
					case Unit::States::Moving:
						//move solder if it is in its move range
						if (distanceSprite.getGlobalBounds().contains(mousePotitionf)) {
							float positonx = sf::Vector2f(sf::Mouse::getPosition(*this)).x - (spriteWidth / 2 * unitScale);
							float positony = sf::Vector2f(sf::Mouse::getPosition(*this)).y - (spriteHeight / 2 * unitScale);
							std::shared_ptr<Command> moveCommande = std::make_shared<MoveCommand>(solder, std::pair<float, float>(positonx, positony));
							moveCommande->execute();
							thisRound.addCommand2Army(moveCommande);
							thisRound.addTurn();
						}
						else {
							solder->fsm.reset();
						}
						break;
					case Unit::States::Attacking:
						for (auto boss : thisRound.getBosss()) {
							//check if boss is in the solder's attack range and player choose to attack this boss
							if (distanceSprite.getGlobalBounds().intersects(boss->getMySprite().getGlobalBounds()) && boss->getMySprite().getGlobalBounds().contains(mousePotitionf)) {
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
									bossCommand = std::make_shared<MoveCommand>(boss, std::pair<float, float>(bossPositionx - bossMoveDistance, bossPositiony));
									//bossCommand = std::make_shared<MoveCommand>(boss, std::pair<float, float>(bossPositionx - defaultScale*3, bossPositiony));

								}
								bossCommand->execute();
								thisRound.addCommand2Boss(bossCommand);
								thisRound.addTurn();
							}
							else {
								solder->fsm.reset();
							}
							break;
						}


					}
				}
			}
		}
	}
}

void MyCanvas::updateSprites()
{
	for (auto solder : thisRound.getArmy())
	{
		//show army sprites
		if(solder->getHP() > 0) RenderWindow::draw(solder->getMySprite());
		if (solder->fsm.state() != Unit::States::Unselected) {
			((QtGuiBattlefield *)parentWidget())->updateUnitID(solder->getID());
			((QtGuiBattlefield *)parentWidget())->updateUnitHP(std::to_string(solder->getHP()) + "/" + std::to_string(solder->getHPmax()));
			((QtGuiBattlefield *)parentWidget())->updateUnitMoveDistance(std::to_string(solder->getMoveDistance()));
			((QtGuiBattlefield *)parentWidget())->updateUnitAttribute("Damage: " + std::to_string(solder->getDamage()));
		}
		//show selected unit move/attack range
		if (solder->fsm.state() == Unit::States::Moving) {
			sf::FloatRect unit = solder->getMySprite().getGlobalBounds();
			float d = solder->getMoveDistance();
			distanceSprite.setTexture(moveTexture);
			distanceSprite.setTextureRect(sf::IntRect(0, 0, int(2 * d + unit.width), int(2 * d + unit.height)));
			distanceSprite.setPosition(unit.left - d, unit.top - d);
			RenderWindow::draw(distanceSprite);
		}
		else if (solder->fsm.state() == Unit::States::Attacking) {
			sf::FloatRect unit = solder->getMySprite().getGlobalBounds();
			float d = solder->getDamageDistance();
			distanceSprite.setTexture(attackTexture);
			distanceSprite.setTextureRect(sf::IntRect(0, 0, int(2 * d + unit.width), int(2 * d + unit.height)));
			distanceSprite.setPosition(unit.left - d, unit.top - d);
			RenderWindow::draw(distanceSprite);
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
}