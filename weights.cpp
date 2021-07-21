//A weight processor for randomness and chances... MIT License
#include <cstdlib>
#include <ctime>
int rand(int min, int max); 
class Weights {
public:
	Weights(float weight = 0){
  		this->resetWeight(weight);
	 }
	int resetWeight(float weight);
	bool weightTest();
	static int rand(int min, int max);
	float readWeight();
	int randWeight(int min, int max);
	bool lastProcessRead();
private:
	float weight;
	bool lastProcess;
};
float Weights::readWeight(){
  //reads weight attribute in object
  return this->weight;
}
int Weights::resetWeight(float weight){
  //sets the weight
  if (weight <= 1 && weight >= 0){
  	this->weight = weight;
    return 1;
  }
  else {
    this->weight = 0;
  	return -1; 
  }
}
bool Weights::weightTest(){
  //true or false based on weight
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
  if (max < min){
  	return -1;
  }
  //random number in min , and max
  std::srand(time(NULL));
  max = max + 1;
  int diff = 0-min + max;
  return std::rand() % diff + min;
}
int Weights::randWeight(int min, int max){
  //random number to weigh
  min *= 1000;
  max *= 1000;
  int returnvalue;
  if (min >= 1000 || max <= 0 || max < min){
  	returnvalue = -1;
    min = 0;
    max = 1000;
  }
  this->weight = Weights::rand(min, max) / 1000;
  returnvalue = 1;
  return returnvalue;
  }
bool Weights::lastProcessRead(){
  return this->lastProcess;
}
