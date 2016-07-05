#include<iostream>
#include<fstream>

using namespace std;


int main(){

  ifstream in_stream;
  
  
    cout.setf(ios::left);
    cout.width(15);
    cout << "Character" << "Count" << endl;

  for (int small = 97; small <= 122; small++){
    int count = 0;

    in_stream.open("occur.cpp");
      if (in_stream.fail()){
        cout << "In stream fail.";
      }
    char character;
    in_stream.get(character);

    while (!in_stream.eof()){
      if (character==small)
	++count;
      
      in_stream.get(character);
    }

    cout.width(15);
    cout << static_cast<char>(small) << count << endl;
    in_stream.close();
  }

  

  return 0;
}

// BbbBBbbbBenji
