#ifndef BESTSCORE
#define BESTSCORE
#include <fstream>
using std::ifstream;
using std::ofstream;
class BestScore{
public:
	BestScore();
	~BestScore();
	void saveIfBest(const int &score); // Сохранить в файл, если лучший
	int getBestScore(); // Прочитать лучший счёт из файла
	bool isBest(const int &score); // Лучший ли счёт score?
private:
	static int _best_score;
};

#endif // BESTSCORE

