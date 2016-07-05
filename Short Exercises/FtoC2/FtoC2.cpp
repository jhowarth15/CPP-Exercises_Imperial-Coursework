#include <iostream>
#include <iomanip>
#include"conversions.h"

using namespace std;

void print_preliminary_message();
void input_table_specifications(int& lowest, int& highest, int& interval);
void print_message_echoing_input(int lowest, int highest, int interval);


/* START OF MAIN PROGRAM */

int main() {

  int lowest = 0, highest = 0, interval = 0;

/* print a message explaining what the program does: */

  print_preliminary_message();
  
/* prompt the user for table specifications in Fahrenheit: */

  input_table_specifications(lowest, highest, interval);
   
/* print appropriate message including an echo of the input: */

  print_message_echoing_input(lowest, highest, interval);

/* Print the table (including the column headings): */

  print_table(lowest, highest, interval);

  return 0;
}

/* END OF MAIN PROGRAM */

/*FUNCTIONS*/

void print_preliminary_message(){
    cout << "This program provides a table of Fahrenheit temperatures converted into both Celsius and Kelvin" << endl;
 }

void input_table_specifications(int& lowest, int& highest, int& interval){
    cout << "Please enter the lowest temperature wanted in the table:\n";

    cin >> lowest;

    cout << "\nPlease enter the highest temperature wanted in the table:\n";
    cin >> highest;

    cout << "\nPlease enter the temperature size interval:\n";
    cin >> interval;
  }
void print_message_echoing_input(int lowest, int highest, int interval){
    cout << "Lowest Temp: " << lowest << endl;
    cout << "Highest Temp: " << highest << endl;
    cout << "Interval: " << interval << endl;
  }


