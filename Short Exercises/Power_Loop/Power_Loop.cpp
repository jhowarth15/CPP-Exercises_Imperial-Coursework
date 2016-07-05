#include <iostream>

using namespace std;

int main(){

  int count, power, number, answer;

  answer = 1;

  cout << "Enter number:";
  cin >> number;

  cout << endl << "Enter power:";
  cin >> power;
cd..

  for(count=0; count<power; ++count){
    answer = answer * number;
  }

  cout << endl << "Answer: " << answer << endl;

return 0;
}
