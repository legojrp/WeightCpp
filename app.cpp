#include "weights.cpp"
#include <iostream>
int main(){
  std::cout << Weights::rand(56, 57)<< std::endl;
  Weights weight = Weights(0.876);
  weight.resetWeight(1);
  std::cout << weight.readWeight() << std::endl;
  weight.resetWeight(0.250);
  std::cout << weight.weightTest() << std::endl;
}
