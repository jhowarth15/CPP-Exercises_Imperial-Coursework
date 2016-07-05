#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  double lowest, highest, interval;

  cout << "This program provides a table of Fahrenheit temperatures converted into both Celsius and Kelvin" << endl;
   cout << "Please enter the lowest temperature wanted in the table:\n";

   cin >> lowest;
   cout << lowest;

   cout << "\nPlease enter the highest temperature wanted in the table:\n";
   cin >> highest;
   cout << highest;

   cout << "\nPlease enter the temperature size interval:\n";
   cin >> interval;
   cout << interval;

  int Fahrenheit = 0;

  cout << setiosflags(ios::left);

  cout << endl << setw(15) <<  "Fahrenheit" << setw(15) << "Celcius" << setw(15) << "Kelvin" << endl;

  for (Fahrenheit = lowest; Fahrenheit <= highest; Fahrenheit = Fahrenheit + interval){
    double Celsius = ((static_cast<double>(Fahrenheit)-32)*5)/9;
    double Kelvin = Celsius+273.15;

    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout.width(15);
    cout << Fahrenheit;

    cout.width(15);
    cout << Celsius;

    cout.width(15);
    cout << Kelvin << endl;
  }

  return 0;
}
