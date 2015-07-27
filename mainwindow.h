#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "obama.h"
#include "map.h"
#include "food.h"
#include <list>
#include "menu.h"
#include "bestscore.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_StartGameButton_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
