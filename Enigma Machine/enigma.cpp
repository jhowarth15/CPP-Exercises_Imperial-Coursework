#include <iostream>
#include <cstring>
#include "enigma.h"
#include "errors.h"
#include <fstream>

using namespace std;

//PLUGBOARD//////////////////////////////////
Plugboard::Plugboard(const char* file)
{

  ifstream in_stream;
  in_stream.open(file);

  //Check that it opened file correctly.
  if (in_stream.fail())
    {
      throwEnigmaError(ERROR_OPENING_CONFIGURATION_FILE, file);
    }

  char ch;
  int charCount = 0;   //use this count to avoid error checking EOF flag later.
    in_stream.get(ch);
    while (!in_stream.eof())
      {	  
	charCount++;
	in_stream.get(ch);
      }

    in_stream.close();
    in_stream.open(file);

    //Check that the individual characters are 0-9 or space.
    in_stream.get(ch);
    int c=1;
    while (!in_stream.eof() && c<charCount) //Less than charCount to exclude EOF flag.
      {
	if (ch!=' ' && (ch<ASCII_ZERO || ch>ASCII_NINE))
	  {
	    throwEnigmaError(NON_NUMERIC_CHARACTER, ch, file);	
	  }
	c++;
	in_stream.get(ch);
      }
    in_stream.close();
  
    in_stream.open(file); //Close and re-open file to start fresh look through file.

  //Get and check the integer numbers in file.
  int number;
  this->count = 0;
  in_stream >> number;
  if (number>25)
    {
      throwEnigmaError(INVALID_INDEX, number, file);
    }
  while (!in_stream.eof())
    {
      configuration[this->count] = number;
      
      this->count++;
      in_stream >> number;
      if (number>25)
	{
	  throwEnigmaError(INVALID_INDEX, number, file);
	}
    }

  //Check even number of parameters.
  if (count%2!=0)
      {
	throwEnigmaError(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS,file);
      }
  //Check no repeated parameters.
  for (int check=0; check<count; check++)
      {
	for (int x=1; x<count-check; x++)
	  {
	    if (configuration[check]==configuration[check+x])
	      {
		throwEnigmaError(IMPOSSIBLE_PLUGBOARD_CONFIGURATION, configuration[check], file);
	      }
	  } 
      }

    in_stream.close();

};

void Plugboard::display()
{
  int x = 0;
  while (x<this->count)
    {
      cout << configuration[x] << endl;
      x++;
    }
};

void Plugboard::charSwitch(int& number)
{
  int original = number;

  for (int x=0; x<this->count; x++)
    {
      if (this->configuration[x]==original)
	{
	  if (x%2==0)
	    {
	      number = configuration[x+1];
	    }
	  else
	    {
	      number = configuration[x-1];
	    }
	}
    }


 };

//REFLECTOR/////////////////////////////////
Reflector::Reflector(const char* file)
{
  
  ifstream in_stream;
  in_stream.open(file);

  if (in_stream.fail())
    {
      throwEnigmaError(ERROR_OPENING_CONFIGURATION_FILE, file);
    }

  char ch;
  int charCount = 0; 
    in_stream.get(ch);
    while (!in_stream.eof())
      {	  
	charCount++;
	in_stream.get(ch);
      }

    in_stream.close();
    in_stream.open(file);

    in_stream.get(ch);
    int c=1;
    while (!in_stream.eof() && c<charCount)
      {
	if (ch!=' ' && (ch<ASCII_ZERO || ch>ASCII_NINE))
	  {
	    throwEnigmaError(NON_NUMERIC_CHARACTER, ch, file);	
	  }
	c++;
	in_stream.get(ch);
      }
    in_stream.close();
  
  in_stream.open(file);

  int number;
  this->count = 0;
  in_stream >> number;
  if (number>25)
    {
      throwEnigmaError(INVALID_INDEX, number, file);
    }
  while (!in_stream.eof())
    {
      configuration[this->count] = number;
      
      this->count++;
      in_stream >> number;
      if (number>25)
	{
	  throwEnigmaError(INVALID_INDEX, number, file);
	}
    }

  if (count%2!=0)
      {
	throwEnigmaError(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS,file, 1);
      }

  if (count<26)
      {
	throwEnigmaError(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS,file, 2);
      }
  if (count>26)
      {
	throwEnigmaError(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS,file, 3);
      }      

  for (int check=0; check<count; check++)
      {
	for (int x=1; x<count-check; x++)
	  {
	    if (configuration[check]==configuration[check+x])
	      {
		throwEnigmaError(INVALID_REFLECTOR_MAPPING, configuration[check], file);
	      }
	  } 
      }

    in_stream.close();
};

void Reflector::display()
{
  int x = 0;
  while (x<this->count)
    {
      cout << configuration[x] << endl;
      x++;
    }
};

void Reflector::charSwitch(int& number)
{
  int original = number;

  for (int x=0; x<this->count; x++)
    {
      if (this->configuration[x]==original)
	{
	  if (x%2==0)
	    {
	      number = configuration[x+1];
	    }
	  else
	    {
	      number = configuration[x-1];
	    }
	}
    }
 };

//ROTOR///////////////////////////////
Rotor::Rotor(const char* file)
{

  ifstream in_stream;
  in_stream.open(file);

  if (in_stream.fail())
    {
      throwEnigmaError(ERROR_OPENING_CONFIGURATION_FILE, file);
    }

  char ch;
  int charCount = 0; 
    in_stream.get(ch);
    while (!in_stream.eof())
      {	  
	charCount++;
	in_stream.get(ch);
      }

  in_stream.close();

  in_stream.open(file);

  in_stream.get(ch);
  int c=1;
  while (!in_stream.eof() && c<charCount) 
      {
	if (ch!=' ' && (ch<ASCII_ZERO || ch>ASCII_NINE))
	  {
	    throwEnigmaError(NON_NUMERIC_CHARACTER, ch, file);	
	  }
	c++;
	in_stream.get(ch);
      }
  in_stream.close();
  
  in_stream.open(file);

  int number;
  this->count = 0;
  in_stream >> number;
  if (number>25)
    {
      throwEnigmaError(INVALID_INDEX, number, file);
    }
  while (!in_stream.eof())
    {
      configuration[this->count] = number;
      this->count++;
      in_stream >> number;
      if (number>25)
	{
	  throwEnigmaError(INVALID_INDEX, number, file);
	}
    }

  if (count<26)
    throwEnigmaError(INVALID_ROTOR_MAPPING,file);

  for (int check=0; check<26; check++)
      {
	for (int x=1; x<26-check; x++)
	  {
	    if (configuration[check]==configuration[check+x])
	      {
		throwEnigmaError(INVALID_ROTOR_MAPPING, configuration[check], file);
	      }
	  } 
      }

  //CREATE NOTCH POSITION ARRAY
  int noNotchPositions = count - 26;
  for (int x=0; x<noNotchPositions; x++)
	{
	  notchPosition[x] = configuration[count-1-x];
	}

  this->rotateCount = WHEELMARK_NO;

    in_stream.close();
};

void Rotor::display()
{
  int x = 0;
  while (x<this->count)
    {
      cout << configuration[x] << ",";
      x++;
    }
  cout << endl;
};

void Rotor::rightToLeft(int& number)
{
  number = configuration[number];
};

void Rotor::leftToRight(int& number)
{
  int original = number;

  for (int x=0; x<this->count - 1; x++)
    {
      if (this->configuration[x]==original)
	{
	  number = x;
	  return;
	}
    }
};

void Rotor::rotate()
{
  int relativeMapping[MAX];
  
  for (int x=0; x<count; x++)
    {
      relativeMapping[x] = configuration[x] - x;
    }

  //CREATE NEW CONFIGURATION AFTER ROTATION OF RELATIVE MAPPINGS
  for (int x=0; x<CHAR_NO; x++)
    {
      configuration[x] = x + relativeMapping[x+1];

    }
  configuration[CHAR_NO] = CHAR_NO + relativeMapping[0]; //Circular

  //CONVERT ANY NEGATIVES
  for (int x=0; x<count; x++)
    {
      configuration[x] = (configuration[x] + 26)%26;
    }

rotateCount++;

};


//ROTOR_SETUP/////////////////////////////////
Rotor_Setup::Rotor_Setup(const char* file)
{
  
  ifstream in_stream;
  in_stream.open(file);

  if (in_stream.fail())
    {
      throwEnigmaError(ERROR_OPENING_CONFIGURATION_FILE, file);
    }

  char ch;
  int charCount = 0;  
    in_stream.get(ch);
    while (!in_stream.eof())
      {	  
	charCount++;
	in_stream.get(ch);
      }

  in_stream.close();

  in_stream.open(file);

  in_stream.get(ch);
  int c=1;
  while (!in_stream.eof() && c<charCount)
      {
	if (ch!=' ' && (ch<ASCII_ZERO || ch>ASCII_NINE))
	  {
	    throwEnigmaError(NON_NUMERIC_CHARACTER, ch, file);	
	  }
	c++;
	in_stream.get(ch);
      }
  in_stream.close();
  
  in_stream.open(file);

  int number;
  this->count = 0;
  in_stream >> number;
  if (number>25)
    {
      throwEnigmaError(INVALID_INDEX, number, file);
    }
  while (!in_stream.eof())
    {
      configuration[this->count] = number;
      this->count++;
      in_stream >> number;
      if (number>25)
	throwEnigmaError(INVALID_INDEX, number, file);
    }
    in_stream.close();

};

void Rotor_Setup::display()
{
  int x = 0;
  while (x<this->count)
    {
      cout << configuration[x] << endl;
      x++;
    }
};
