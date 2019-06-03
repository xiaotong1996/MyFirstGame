#include "QtGuiArmyConfig.h"
#include "QtGuiBattlefield.h"
QtGuiArmyConfig::QtGuiArmyConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QtGuiArmyConfig::~QtGuiArmyConfig()
{
}

void QtGuiArmyConfig::BtnOK_Click()
{
	QtGuiBattlefield* gui_field = new QtGuiBattlefield(this);
	gui_field->show();
	this->hide();
}

void QtGuiArmyConfig::BtnB_Click() {
	this->parentWidget()->show();
	delete this;
}
