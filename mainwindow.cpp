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
	//main code
	static Music background; // Первым делом музыка :)
	background.openFromFile("Sounds/back.ogg");
	background.setVolume(32);
	background.setLoop(true);
	background.play();
	std::srand(std::time(NULL));
	Map map;
	Menu menu;
	std::list<Food*> balalaikes;
	std::list<Food*>::iterator it_balala;
	sf::RenderWindow w(VideoMode(64*16,64*9),"FlappyObama, v 2.0",Style::Close);
	w.setPosition(sf::Vector2i(128,0));
	w.setFramerateLimit(65);
	Image img;
	img.loadFromFile("Images/icon.png");
	w.setIcon(64,64,img.getPixelsPtr());
	Obama obama(w);
	Event event;
	Clock clock;
	Clock nextFoodSpawnTimer;
	nextFoodSpawnTimer.restart();
	Time currentTime;
	float complexityTime = rand()%2+5; // Сложность будет постепенно увеличиваться
									  // Сделаем так, что она обратно пропорционально сией переменной
////////////////////////////////////////////////////////////////////////////////////
	//main loop
	while(w.isOpen()){
		if(complexityTime>0.005)
			complexityTime -= 0.001;
		currentTime = clock.getElapsedTime();
		clock.restart();
		static int nextFoodSpawnTime = 3+rand()%2;
///////////////////////////////////////////////////////////////////////////////////
		if(int(nextFoodSpawnTimer.getElapsedTime().asSeconds()) == nextFoodSpawnTime){
			if(balalaikes.size() < 4+obama.getScore()/10){
				if(rand()%6 == 0)		// Спауним 'еду'
					balalaikes.push_back(new Food(Food::Gambyrger));
				if(rand()%7 == 0)
					balalaikes.push_back(new Food(Food::Dollar));
				if(rand()%18 == 0)
					balalaikes.push_back(new Food(Food::Kli4ko));
				if(rand()%36 == 0)
					balalaikes.push_back(new Food(Food::Pechka));
				if(rand()%(40-obama.getScore()/50) == 0) // Путин бывает редко
					balalaikes.push_back(new Food(Food::Putin));
				if(rand()%2048 == 0)
					balalaikes.push_back(new Food(Food::Rammstein));
				if(rand()%4096 == 0)
					balalaikes.push_back(new Food(Food::Nirvana));

				balalaikes.push_back(new Food(Food::FoodType(rand()%3)));
			}
			nextFoodSpawnTime = rand()%5+complexityTime; // Время вылета следующего объекта
			nextFoodSpawnTimer.restart();
		}
////////////////////////////////////////////////////////////////////////////////////
		while(w.pollEvent(event))
		{
			if(event.type == Event::Closed ||
			  (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape)))
				w.close();
			if(event.type == Event::MouseButtonPressed)
				if(Mouse::isButtonPressed(Mouse::Left))
					obama.jump();
			if(event.type == Event::KeyPressed)
				if(Keyboard::isKeyPressed(Keyboard::Space))
					obama.jump();
		}
////////////////////////////////////////////////////////////////////////////////////

		obama.Update(currentTime);
		map.update(currentTime,obama.alive());
		map.render(w);
////////////////////////////////////////////////////////////////////////////////////
		// Проверка столкновения с едой
		for(it_balala=balalaikes.begin();it_balala!=balalaikes.end();it_balala++){
			obama.checkIntersect(*(*it_balala),background); // Проверяем столкновение Обамы с едой
			(*it_balala)->update(currentTime);// Рисуем и апдейтим балалайки и не только
			(*it_balala)->draw(w);
		}
////////////////////////////////////////////////////////////////////////////////////
		// Уничтожение вылетевших балалаек и не только лишь балалаек
		for(it_balala=balalaikes.begin();it_balala!=balalaikes.end(); )
		{
			Food *tempFood = *it_balala;
			if(tempFood->getSprite().getPosition().x < -128){ // Если еда вылетела
				if(tempFood->getType() != Food::Gambyrger // За уворот от бонусов баллы
						&& tempFood->getType() != Food::Dollar // Не прибавляются
						&& tempFood->getType() != Food::Kli4ko
						&& obama.alive())
					obama.addScore();
				if(tempFood->getType() == Food::Putin)
					obama.addScore(14); // 1 + 14 = Пятнадцать за Путина
				it_balala = balalaikes.erase(it_balala);
				delete tempFood;
			}
			else
				it_balala++;
		}
////////////////////////////////////////////////////////////////////////////////////
		obama.checkIntersect(map); // Не врезался ли Обама в землю?
		if(!obama.alive()){ // Если обама погиб
			menu.update(obama);
			static RectangleShape lens(Vector2f(w.getSize().x,w.getSize().y));
			lens.setFillColor(Color(2,4,8,128));
			lens.setPosition(0,0);
			w.draw(lens);
			menu.render(w);
		}
////////////////////////////////////////////////////////////////////////////////////
		obama.render(w);
		obama.renderScore(w);
		w.display();
		w.clear();
	}
}
