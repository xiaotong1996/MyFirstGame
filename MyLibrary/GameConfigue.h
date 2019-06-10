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

	const int population_limit_boss1();
	const int default_scale();
	const int sprite_width();
	const int sprite_height();
	const float unit_scale();
	const float boss_scale();

	const std::string boss1_id();
	const float boss1_position_x();
	const float boss1_position_y();
	const int boss1_HP_max();
	const int boss1_damage();
	const int boss1_damage_distance();
	const int boss1_heal_dose();
	const int boss1_move_distance();
	
	const std::string warrior_id();
	const float warrior_position_x();
	const float warrior_postition_y();
	const int warrior_HP_max();
	const int warrior_damage();
	const int warrior_damage_distance();
	const int warrior_move_distance();

	const std::string archer_id();
	const float archer_postition_x();
	const float archer_postition_y();
	const int archer_HP_max();
	const int archer_damage();
	const int archer_damage_distance();
	const int archer_move_distance();

private:
	pugi::xml_document doc;
};

