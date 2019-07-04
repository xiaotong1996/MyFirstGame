#pragma once
#include <pugixml.hpp>
/*GameConfigue used to analyse xml file for confuguation.
* Make it easier to change game settings.
*/
class GameConfigue
{
public:
	GameConfigue();
	~GameConfigue();

	static const int population_limit_boss1();
	static const int default_scale();
	static const int sprite_width();
	static const int sprite_height();
	static const float unit_scale();
	static const float boss_scale();

	static const std::string boss1_id();
	static const float boss1_position_x();
	static const float boss1_position_y();
	static const int boss1_HP_max();
	static const int boss1_damage();
	static const int boss1_damage_distance();
	static const int boss1_heal_dose();
	static const int boss1_move_distance();
	
	static const std::string warrior_id();
	static const float warrior_position_x();
	static const float warrior_postition_y();
	static const int warrior_HP_max();
	static const int warrior_damage();
	static const int warrior_damage_distance();
	static const int warrior_move_distance();

	static const std::string archer_id();
	static const float archer_postition_x();
	static const float archer_postition_y();
	static const int archer_HP_max();
	static const int archer_damage();
	static const int archer_damage_distance();
	static const int archer_move_distance();

private:
	//static pugi::xml_document doc;
};

