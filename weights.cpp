//A weight processor for randomness and chances... MIT License
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
int rand(int min, int max);
class Weights {
public:
	Weights(float weight = 0){
  		this->weight = weight;
	 }
	void resetWeight(float weight);
	bool weightTest();
	static int rand(int min, int max);
	float readWeight();
private:
float weight;
bool lastProcess;
};
float Weights::readWeight(){
  return this->weight;
}
void Weights::resetWeight(float weight){
  if (weight <= 1 && weight >= 0){
  this->weight = weight;
    }
  else {
    this->weight = 0;
  }
}
bool Weights::weightTest(){
  std::srand(time(NULL));
  weight = this->weight * 1000;
  int proposed = std::rand() % 999 + 1;
  if (weight >= proposed){
    this->lastProcess = true;
    return true;
  }
  else {
    this->lastProcess = false;
    return false;
  }

  
}
int Weights::rand(int min, int max){
  std::srand(time(NULL));
  max = max + 1;
  int diff = 0-min;
  int diff2 = max + diff;
  return std::rand() % diff2 + min;
}
