#pragma once

#include <QMainWindow>
#include "ui_QtGuiBattlefield.h"

class QtGuiBattlefield : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiBattlefield(QWidget *parent = Q_NULLPTR);
	~QtGuiBattlefield();

private:
	Ui::QtGuiBattlefield ui;
};
