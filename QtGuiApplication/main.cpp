#include "QtGuiApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	a.setQuitOnLastWindowClosed(false);

	QtGuiApplication w;
	w.show();
	return a.exec();
}
