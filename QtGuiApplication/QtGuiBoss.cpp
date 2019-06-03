#include "QtGuiBoss.h"
#include "QtGuiArmyConfig.h"

QtGuiBoss::QtGuiBoss(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QtGuiBoss::~QtGuiBoss()
{
}

void QtGuiBoss::Btn1_Click()
{
	QtGuiArmyConfig* gui_army = new QtGuiArmyConfig(this);
	gui_army->show();
	this->hide();
}

void QtGuiBoss::BtnB_Click() {
	this->parentWidget()->show();
	delete this;
}
