#include <iostream>

using  namespace std;

int main() {

  char character, character2;
  int number;

  cout << "Please enter a letter.\n";
  cin  >> character;

  number = character;

  if (number >= 97 && number <= 122){
    number = number - 32;
    character2 = number;
    cout << "The upper case letter corresponding to " <<  character << " is:\n" << character2 << endl;
  }  

  else if (number >= 65  && number <= 90){
    number = number + 32;
    character2 = number;
    cout << "The lower case letter corresponding to " <<  character << " is:\n" << character2 << endl;
  }  

  else {
    cout << character << " is not a letter. Go away and come back when you are ready to cooperate." << endl;
  }

  return 0;
}
