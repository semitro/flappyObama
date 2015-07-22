#include "mainwindow.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "obama.h"
#include "map.h"
#include "food.h"
#include <vector>
#include <qdebug.h>
#include <list>
#include "menu.h"
using std::vector;
using namespace sf;
int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	MainWindow window;
	window.show();
	return app.exec();
	// main code you will see in mainwindow.cpp
}
