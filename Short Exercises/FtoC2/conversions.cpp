#include<iostream>
#include<iomanip>
#include"conversions.h"

using namespace std;

void print_table(int lowest, int highest, int interval){

     int Fahrenheit = 0;

     cout << setiosflags(ios::left);

     cout << endl << setw(15) << "Fahrenheit" << setw(15) << "Celcius" << setw(15) << "Kelvin" << endl;

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


    }}
