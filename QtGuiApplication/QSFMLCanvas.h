#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H
#include <QWidget>
#include <SFML/Graphics.hpp>
#include <QTimer>
/*QSFMLCanvas used to combine SFMLWindow and QtWidget
*support to create a SFML window in Qt.
*/
class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
	//Q_OBJECT
public:
	explicit QSFMLCanvas(QWidget *parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);
	virtual void showEvent(QShowEvent*);
	virtual QPaintEngine* paintEngine() const;
	virtual void paintEvent(QPaintEvent*);
	virtual ~QSFMLCanvas();
	virtual void OnInit();
	virtual void OnUpdate();
private:
	QTimer myTimer;
	bool myInitialized;
};
#endif // QSMLCANVAS_H