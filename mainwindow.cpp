#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	BestScore BScore;
	ui->label_score->setText(ui->label_score->text() + QString().number(BScore.getBestScore()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_StartGameButton_clicked()
{

	close();
	Game game(GameMode(ui->comboBox_mode->currentIndex()),ui->checkBox_sound->isChecked());
	game.start();
	//main code

}
