#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

int compare(char a, char b);

bool test_alpha(char string_a[], char string_b []);

int main()
{

  cout << "This program tests whether your first word is alpabetically smaller than your second word." << endl;

  cout << "Enter first word: ";

  char first[MAX], second[MAX];

  cin >> first;

  cout << endl << "Enter second word: ";

  cin >> second;

  cout << endl << "Is the first word alphabetically smaller? ";

  if (test_alpha(first, second))
    cout << "True" << endl;
  else cout << "False" << endl;



  return 0;
}



bool test_alpha(char string_a[], char string_b [])
{

  int x = 0;

  int result = compare(string_a[x], string_b[x]);

  while (result>=2)
    {
      x++;
      result = compare(string_a[x], string_b[x]);
    }
  
  return result;

}


int compare(char a, char b)
{
  if (a < b)
      return 1;

  else if (a > b)
      return 0;

  else return 2;
}
