#include<iostream>
#include<fstream>

using namespace std;

int main(){

  ifstream in_stream;
  in_stream.open("count_itself.cpp");
  if (in_stream.fail()){
    cout << "In stream fail." << endl;
  }

  int count = 0;
  char character;

  in_stream.get(character);

  while(!in_stream.eof()){
    ++count;
    in_stream.get(character);
  }

  cout << "The number of characters in this program's source file is " << count << endl;

  /*Add 25 char for test..*/

  return 0;

}
