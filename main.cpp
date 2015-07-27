#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	MainWindow window;
	window.show();
	return app.exec();
	// main code you will see in mainwindow.cpp
}
