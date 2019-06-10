#include "stdafx.h"
#include "Boss.h"
#include "GameManager.h"
Boss::Boss(std::string id, int HP_max, float position_x, float position_y, int damage, int damage_distance, int heal_dose, int move_distance)
	: Unit(id,0,HP_max,position_x,position_y,move_distance)
	,damage(damage)
	,damage_distance(damage_distance)
	,heal_dose(heal_dose)
{
	int spriteWidth = GameManager::instance().getGameConfigue()->sprite_width();
	int spriteHeight = GameManager::instance().getGameConfigue()->sprite_height();
	float bossScale = GameManager::instance().getGameConfigue()->boss_scale();
	if (id == "boss1") {
		myImage.loadFromFile("../QtGuiApplication/asset/boss1.png");
	}
	mySprite.setTexture(myImage);
	mySprite.setTextureRect(sf::IntRect(0, spriteHeight, spriteWidth, spriteHeight));
	mySprite.scale(bossScale, bossScale);
	mySprite.setPosition(getPosition().first, getPosition().second);
}

Boss::~Boss()
{
}

int Boss::getDamage()
{
	return damage;
}

int Boss::getDamageDistance()
{
	return damage_distance;
}

solderType Boss::getType()
{
	return solderType();
}

const int Boss::getHeal()
{
	return heal_dose;
}

sf::Sprite Boss::getMySprite()
{
	return mySprite;
}
