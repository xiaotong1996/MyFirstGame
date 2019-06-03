#include "QtGuiApplication.h"
#include "QtGuiBoss.h"
#include <memory>
#include <qdebug.h>
QtGuiApplication::QtGuiApplication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


void QtGuiApplication::BtnS_Click() {
	QtGuiBoss* gui_boss = new QtGuiBoss(this);
	gui_boss->show();
	this->hide();
}