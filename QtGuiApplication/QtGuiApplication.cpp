#include "QtGuiApplication.h"
#include "QtGuiBoss.h"
#include <memory>
#include <qdebug.h>
#include "../MyLibrary/GameManager.h"

QtGuiApplication::QtGuiApplication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


void QtGuiApplication::BtnS_Click() {
	GameManager::instance().initGamer();
	GameManager::instance().initGameConfigue();
	QtGuiBoss* gui_boss = new QtGuiBoss(this);
	gui_boss->show();
	this->hide();
}