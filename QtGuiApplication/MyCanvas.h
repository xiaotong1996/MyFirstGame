#ifndef MYCANVAS_H
#define MYCANVAS_H
#include "qsfmlcanvas.h"
#include <SFML/Graphics.hpp>
#include "SFMLOrthogonalLayer.h"
#include "../MyLibrary/Unit.h"
#include "../MyLibrary/Boss.h"

/*MyCanvas is the main class combining UI and logical part.
*/
class MyCanvas : public QSFMLCanvas
{
public:
	MyCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size);//creaeted in Qt parent widget
	void OnInit();//init canvas
	void OnUpdate();//update UI accronding to commands
	bool isSomeoneSelected();//check if there is a unit has been selected by player
	void setIsMove(bool i);//set is_move
	void setIsAttack(bool i);//set is_attack
private:
	
	bool checkCollision(sf::Vector2f newPosition);//check if there is collision between solders
	sf::Clock myClock;//used for refresh
	std::vector<std::shared_ptr<Unit>> army;//stock player's chosen army
	std::vector<std::shared_ptr<Boss>> bosss;//stock game setting bosses
	tmx::Map map;//game map
	sf::Texture moveTexture;//blue block used to show unit's move range
	sf::Texture attackTexture;//red block used to show unit's attack range
	sf::Sprite distanceSprite;//take the above two textures
	bool is_move;//ture if movebutton clicked
	bool is_attack;//ture if attackbutton clicked
};
#endif // MYCANVAS_H