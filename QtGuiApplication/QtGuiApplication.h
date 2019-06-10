#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication.h"
/*QtGuiApplication Main Gui just owns a start button.
* Used as login window, can be expand for future.
*/
class QtGuiApplication : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplicationClass ui;

private slots:
	void BtnS_Click();
};
