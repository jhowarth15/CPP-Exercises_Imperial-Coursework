#include<iostream>
#include<cstring>

using namespace std;

//prototypes
const int MAX = 100;
void no_reps(char sentence[], int position);
void shift_over(char statement[], int take_out);


int main()
{

  char statement[MAX];

  cout << "Enter your statement to remove reps: ";
  cin.getline(statement,MAX);

  int count = 0;
  while (statement[count] != '\0')
  {
    no_reps(statement, count);
    count++;
  }

  cout << endl << "Your new statement: " << statement << endl;

  return 0;
}


void no_reps(char sentence[], int position)
{
  char character = sentence[position];
  position++;
  while (sentence[position] != '\0')
    {
      if (sentence[position]==character)
	shift_over(sentence, position);
      else position++;
    }
}

void shift_over(char statement[], int take_out)
{
  while (take_out<MAX)
    {
      statement[take_out] = statement[take_out + 1];
      take_out++;
    }
} 
