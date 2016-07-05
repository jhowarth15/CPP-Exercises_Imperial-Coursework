#include<iostream>
#include<fstream>

using namespace std;

int number_count();
char print_current(int current);

int main(){

  int count = number_count();

  int char_num = count;

  for (; char_num>0; char_num--){
    cout << print_current(char_num); 
  }

  return 0;

}

int number_count(){

  ifstream in_stream;
  in_stream.open("backwards.cpp");
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

  in_stream.close();

  return count;

}

char print_current(int current){
    ifstream in_stream;
    in_stream.open("backwards.cpp");
    if (in_stream.fail()){
    cout << "In stream fail." << endl;
    }

    char character;
    for (int x=0; x<current; x++){
      in_stream.get(character);
    }  

    in_stream.close();

    return character;

}/*hbdjwqb*/
