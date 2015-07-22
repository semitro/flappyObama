#ifndef BESTSCORE
#define BESTSCORE
#include <fstream>
using std::ifstream;
using std::ofstream;
class BestScore{
public:
	BestScore();
	~BestScore();
	void saveIfBest(const int &score);
	int getBestScore();
	bool isBest(const int &score);
private:
	static int _best_score;
	int crypto(int); //Шифровщик
	int uncrypto(int); // Дешифровщик
};

#endif // BESTSCORE

