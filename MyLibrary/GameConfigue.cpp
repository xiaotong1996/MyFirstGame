#include "stdafx.h"
#include "GameConfigue.h"



GameConfigue::GameConfigue()
{
	//doc.load_file("../MyLibrary/config/gamesetting.xml");
}


GameConfigue::~GameConfigue()
{
}

const int GameConfigue::population_limit_boss1()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("General").attribute("populationLimit1").as_int();
}

const int GameConfigue::default_scale()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("General").attribute("defaultScale").as_int();
}

const int GameConfigue::sprite_width()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("General").attribute("spriteWidth").as_int();
}

const int GameConfigue::sprite_height()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("General").attribute("spriteHeight").as_int();
}

const float GameConfigue::unit_scale()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("General").attribute("unitScale").as_float();
}

const float GameConfigue::boss_scale()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("General").attribute("bossScale").as_float();
}

const std::string GameConfigue::boss1_id()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("Id").as_string();
}

const float GameConfigue::boss1_position_x()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("PositionX").as_float();
}

const float GameConfigue::boss1_position_y()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("PositionY").as_float();
}

const int GameConfigue::boss1_HP_max()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("HPMax").as_int();
}

const int GameConfigue::boss1_damage()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("Damage").as_int();
}

const int GameConfigue::boss1_damage_distance()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("DamageDistance").as_int();
}

const int GameConfigue::boss1_heal_dose()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("HeadDose").as_int();
}

const int GameConfigue::boss1_move_distance()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Boss1").attribute("MoveDistance").as_int();
}

const std::string GameConfigue::warrior_id()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Warrior").attribute("Id").as_string();
}

const float GameConfigue::warrior_position_x()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Warrior").attribute("PositionX").as_float();
}

const float GameConfigue::warrior_postition_y()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Warrior").attribute("PositionY").as_float();
}

const int GameConfigue::warrior_HP_max()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Warrior").attribute("HPMax").as_int();
}

const int GameConfigue::warrior_damage()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Warrior").attribute("Damage").as_int();
}

const int GameConfigue::warrior_damage_distance()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Warrior").attribute("DamageDistance").as_int();
}

const int GameConfigue::warrior_move_distance()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Warrior").attribute("MoveDistance").as_int();
}

const std::string GameConfigue::archer_id()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Archer").attribute("Id").as_string();
}

const float GameConfigue::archer_postition_x()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Archer").attribute("PositionX").as_float();
}

const float GameConfigue::archer_postition_y()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Archer").attribute("PositionY").as_float();
}

const int GameConfigue::archer_HP_max()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Archer").attribute("HPMax").as_int();
}

const int GameConfigue::archer_damage()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Archer").attribute("Damage").as_int();
}

const int GameConfigue::archer_damage_distance()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Archer").attribute("DamageDistance").as_int();
}

const int GameConfigue::archer_move_distance()
{
	pugi::xml_document doc;
	doc.load_file("../MyLibrary/config/gamesetting.xml");
	return doc.child("Game").child("Archer").attribute("MoveDistance").as_int();
}
