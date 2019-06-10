#include "stdafx.h"
#include "Solder.h"
#include "GameManager.h"

Solder::Solder(solderType type,std::string id, int HP_max, float position_x, float position_y, int damage, int damage_distance, int move_distance)
	: Unit(id, 0, HP_max, position_x, position_y, move_distance)
	, type(type)
	, damage(damage)
	, damage_distance(damage_distance)
{
	int spriteWidth = GameManager::instance().getGameConfigue()->sprite_width();
	int spriteHeight = GameManager::instance().getGameConfigue()->sprite_height();
	float unitScale = GameManager::instance().getGameConfigue()->unit_scale();
	if (type == WARRIOR) {
		myImage.loadFromFile("../QtGuiApplication/asset/warrior.png");
		mySprite.setTexture(myImage);
		
		mySprite.setTextureRect(sf::IntRect(0, spriteHeight*2, spriteWidth, spriteHeight));
		mySprite.scale(unitScale, unitScale);
		mySprite.setPosition(getPosition().first, getPosition().second);

	}else if (type == ARCHER) {
		myImage.loadFromFile("../QtGuiApplication/asset/archer.png");
		mySprite.setTexture(myImage);
		mySprite.setTextureRect(sf::IntRect(0, spriteHeight*2, spriteWidth, spriteHeight));
		mySprite.scale(unitScale, unitScale);
		mySprite.setPosition(getPosition().first, getPosition().second);

	}
}


Solder::~Solder()
{
}

void Solder::attack(std::unique_ptr<Unit> unit_target)
{

}

int Solder::getDamage()
{
	return damage;
}

int Solder::getDamageDistance()
{
	return damage_distance;
}

solderType Solder::getType()
{
	return type;
}

sf::Sprite Solder::getMySprite()
{
	return mySprite;
}

