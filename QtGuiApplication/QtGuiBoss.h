#pragma once

#include <QMainWindow>
#include "ui_QtGuiBoss.h"

class QtGuiBoss : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiBoss(QWidget *parent = Q_NULLPTR);
	~QtGuiBoss();

private:
	Ui::QtGuiBoss ui;

private slots:
	void BtnB_Click();
	void Btn1_Click();

};
