#include<iostream>


using namespace std;

int fibon(int number);


int main()
{

  cout << "Enter the fibonacci number that you want to know: ";

  int integer;

  cin >> integer;

  cout << endl << "Answer: " << fibon(integer) << endl;

  return 0;
}


int fibon(int number)
{
  if (number<=0)
    {
      cout << endl << "Number must be above 0" << endl;
      return 0;
    }

  else if (number==1 || number==2)
    return 1;

  else 
    return (fibon(number-1)+fibon(number-2));

}
