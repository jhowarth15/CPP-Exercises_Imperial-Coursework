#include<iostream>
#include"IntegerArray.h"


using namespace std;


void input_array(int a[], int N)
{

  for (int n=0; n<N; n++)
    {
      cout << "Enter element " << n+1 << ": ";
      cin >> a[n];
      cout << endl;
    }
}

void display_array(int a[], int N)
{
  for (int n=0; n<N; n++)
    {
      cout << n+1 << ": " << a[n] << endl;
    }
}

void copy_array(int a1[], int a2[], int N)
{
  for (int n=0; n<N; n++)
    {
      a1[n]=a2[n];
    }
}

