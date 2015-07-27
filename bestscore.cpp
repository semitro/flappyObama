#include <bestscore.h>
int BestScore::_best_score; // Переменная статическая
BestScore::BestScore(){
	ifstream fin;
	fin.open("txt/.score.bst");
	fin >> _best_score;
	fin.close();
}
BestScore::~BestScore(){

}
int BestScore::getBestScore(){
	return _best_score;
}
bool BestScore::isBest(const int &score){
	return (score > _best_score);
}
void BestScore::saveIfBest(const int &score){
	if(isBest(score)){
		_best_score = score;
		ofstream fout;
		fout.open("txt/.score.bst");
		fout << _best_score;
	}
}
