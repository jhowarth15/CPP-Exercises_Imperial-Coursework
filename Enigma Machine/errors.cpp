#include <iostream>
#include "enigma.h"
#include "errors.h"
#include <fstream>
#include <cstring>

using namespace std;

void throwEnigmaError (int code, char **argv, int argc)
{ 
  EnigmaError err;
  err.code = code;

  if (code == INSUFFICIENT_NUMBER_OF_PARAMETERS)
    {
      strcpy(err.text,"correct usage: enigma plugboard-file reflector-file (<rotor-file>* rotor-positions)?. your usage:");
      for (int x=0; x<argc; x++)
	{
	  strcat(err.text, argv[x]);
	  strcat(err.text, " ");
	}
    }

  throw err;
}

void throwEnigmaError (int code, const char* file)
{ 
  EnigmaError err;
  err.code = code;

  if (code == ERROR_OPENING_CONFIGURATION_FILE)
    {
      strcpy(err.text,"Error opening: ");
      strcat(err.text, file);
    }

  if (code == INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS)
    {
      strcpy(err.text,"Incorrect number of parameters in plugboard file ");
      strcat(err.text, file);
    }

  if (code == INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS)
    {
      strcpy(err.text,"Insufficient number of mappings in reflector file:");
      strcat(err.text, file);
    }

  if (code == INVALID_ROTOR_MAPPING)
    {
      strcpy(err.text,"Not all inputs mapped in rotor file: ");
      strcat(err.text, file);
    }

  if (code == NO_ROTOR_STARTING_POSITION)
    {
      strcpy(err.text,"Not enough starting positions for rotors in: ");
      strcat(err.text, file);
    }

  throw err;
}


void throwEnigmaError (int code, char inputChar)
{ 
  EnigmaError err;
  err.code = code;

  if (code == INVALID_INPUT_CHARACTER) 
    {
      cerr << inputChar;
      strcpy(err.text," is not a valid input character (input characters must be upper case letters A-Z)!");
    }

  throw err;
}

void throwEnigmaError (int code, char inputChar, const char* file)
{ 
  EnigmaError err;
  err.code = code;

  if (code==NON_NUMERIC_CHARACTER)
    {
      cerr << inputChar;
      strcpy(err.text," is a non-numeric character in file ");
      strcat(err.text,file);

    }

  if (code==INVALID_INDEX)
    {
      int number;
      number = inputChar;
      cerr << number;
      strcpy(err.text," is an invalid input number in file: ");
      strcat(err.text,file);

    }

  if (code==IMPOSSIBLE_PLUGBOARD_CONFIGURATION)
    {
      int number;
      number = inputChar;
      cerr << number;
      strcpy(err.text," occurs more than once in file: ");
      strcat(err.text,file);
    }

  throw err;
}

void throwEnigmaError (int code, int inputNum, const char* file)
{ 
  EnigmaError err;
  err.code = code;

  if (code==INVALID_INDEX)
    {
      cerr << inputNum;
      strcpy(err.text," is an invalid input number in file: ");
      strcat(err.text,file);

    }

  if (code==IMPOSSIBLE_PLUGBOARD_CONFIGURATION)
    {
      cerr << inputNum;
      strcpy(err.text," occurs more than once in file: ");
      strcat(err.text,file);
    }

  if (code==INVALID_REFLECTOR_MAPPING)
    {
      cerr << inputNum;
      strcpy(err.text," occurs more than once in file: ");
      strcat(err.text,file);
    }

  if (code==INVALID_ROTOR_MAPPING)
    {
      cerr << inputNum;
      strcpy(err.text," is mapped more than once as an ouput in: ");
      strcat(err.text,file);
    }

  throw err;
}

void throwEnigmaError (int code, const char* file, int variant)
{ 
  EnigmaError err;
  err.code = code;

  if (code == INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS && variant==1)
    {
      strcpy(err.text,"Incorrect (odd) number of mappings in reflector file ");
      strcat(err.text, file);
    }
  if (code == INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS && variant==2)
    {
      strcpy(err.text,"Insufficient number of mappings in reflector file: ");
      strcat(err.text, file);
    }
  if (code == INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS && variant==3)
    {
      strcpy(err.text,"Too many mappings in reflector file: ");
      strcat(err.text, file);
    }

  throw err;
}
