#include<iostream>
#include<cmath>

using namespace std;

bool prime_test(int number);

bool result;

int main(){

  bool leave;

  do {

    cout << "Enter your number here: ";

    int entry;

    cin >> entry;

    prime_test(entry);

    cout << endl << "Is " << entry  << " prime? " << result << endl;

    cout << "enter 0 or 1 if you want to leave or stay respectively." << endl;

    cin >> leave;

  }

  while (leave);

  return 0;
}


bool prime_test(int number){

  result = 1;

  int divider = number-1;

  while (divider>1 && result==1){

    bool remainder = number%divider;

    if (remainder == 0){
      result = 0;
    }
    else 
      divider--;
  }

  return result;
}
