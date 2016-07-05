#include<iostream>
#include"IntegerArray.h"

using namespace std;


int main()
{

  int input_values, input_values_b,array_size_a,array_size_b;

  cout << "Make array a size: ";
  cin >> array_size_a;

  int a[array_size_a];

  cout << "How many values do you want to put in a?" << endl;

  cin >> input_values;

  input_array(a, input_values);

  cout << "Make array b size: ";
  cin >> array_size_b;

  int b[array_size_b];

  cout << "How many values do you want to put in b?" << endl;

  cin >> input_values_b;
 
  input_array(b, input_values_b);

  cout << "Array a:" << endl;

  display_array(a, array_size_a);

  cout << "Array b:" << endl;

  display_array(b, array_size_b);

  int copy;

  cout << "Copy first how many n from b to a: ";

  cin >> copy;

  copy_array(a,b,copy);

  cout << "Array a:" << endl;

  display_array(a, array_size_a);

  cout << "Array b:" << endl;

  display_array(b, array_size_b);

  return 0;
}
