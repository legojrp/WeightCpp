//A weight processor for randomness and chances... MIT License
#include <cstdlib>
#include <ctime>
#include <iostream>
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
	void randWeight(int min, int max);
	bool lastProcessRead();
private:
float weight;
bool lastProcess;
};
float Weights::readWeight(){
  //reads weight attribute in object
  return this->weight;
}
void Weights::resetWeight(float weight){
  //sets the weight
  if (weight <= 1 && weight >= 0){
  	this->weight = weight;
  }
  else {
    this->weight = 0;
    std::cerr << weight << " is too far above or below weight range of 0 to 1." << std::endl;  
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
    std::cerr << "An error occurred in the parameters" << std::endl;
    min = 0;
    max = 100;
  }
  //random number in min , and max
  std::srand(time(NULL));
  max = max + 1;
  int diff = 0-min + max;
  return std::rand() % diff + min;
}
void Weights::randWeight(int min, int max){
  //random number to weigh
  min *= 1000;
  max *= 1000;
  if (min >= 1000 || max <= 0 || max < min){
  	std::cerr << "An error occur in the parameters." << std::endl;
    min = 0;
    max = 1000;
  }
  
  this->weight = Weights::rand(min, max) / 1000;
}
bool Weights::lastProcessRead(){
  return this->lastProcess;
}
