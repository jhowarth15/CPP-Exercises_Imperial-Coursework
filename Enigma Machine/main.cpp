#include <iostream>
#include <cstring>
#include "enigma.h"
#include "errors.h"
#include <cstdlib>
#include <fstream>

using namespace std;

int EnigmaMachine (int argc, char **argv)
{

  //PARAMETER ERROR HANDLING
  if (argc < 3)
    {
      throwEnigmaError(INSUFFICIENT_NUMBER_OF_PARAMETERS, argv, argc);
    }

  //INITIALIZE PLUGBOARD, REFLECTOR, ROTOR ARRAY
  Plugboard plugboardA(argv[1]);

  //plugboardA.display();
  
  Reflector reflectorA(argv[2]);

  //reflectorA.display();

  int rotorCount = argc-4;

  Rotor* rotorArray[MAX];

  if (rotorCount>=1)
    {
      
      //ROTORS ARE CREATED RIGHT TO LEFT
      for (int x=0; x<rotorCount; x++)
	{
	  rotorArray[x] = new Rotor(argv[argc-2-x]);	  
	}
      
      Rotor_Setup rotorSetupA(argv[argc-1]);

      if (rotorSetupA.count<rotorCount)
	{
	  throwEnigmaError(NO_ROTOR_STARTING_POSITION, argv[argc-1]);
	}

      //ROTOR INITIAL ROTATION SETUP
      int rotorSettingNumber = rotorSetupA.count-1;
      for (int x = 0; x<rotorCount; x++)
	{
	  for (int z=0; z<rotorSetupA.configuration[rotorSettingNumber]; z++)
	    {
	      rotorArray[x]->rotate();
	    }
	  rotorSettingNumber--;
	}
    }

  //CREATE, READ IN AND SANITIZE THE INPUT MESSAGE
  char inputMessage[MAX], sortedInput[MAX];

  //cout << "Enter input message in capitals:" << endl;

  cin.getline(inputMessage,MAX);

  int x = 0, charCount = 0;
  while (inputMessage[x] != '\0')
  {
    if (inputMessage[x] != ' ')
      {
	sortedInput[charCount] = inputMessage[x];
	charCount++;
      }
    x++;
  }

  //CONVERT MESSAGE TO BE ENCRYPTED TO ZERO INDEX
  //cout << endl << "Your message to encrypt is: " << endl;

  int y=0, indexedInput[charCount];  //zero indexed
  while (y < charCount)
    {
      indexedInput[y] = sortedInput[y] - ASCII_A;
      if (indexedInput[y]<0 || indexedInput[y]>25)
	{
	  throwEnigmaError(INVALID_INPUT_CHARACTER, sortedInput[y]);
	  }
      //cout << indexedInput[y] << endl;
      y++;
    }

  //ENIGMA MACHINE WHOLE LOOP THROUGH INPUT LETTERS
  int totalLoop = 0;
  while (totalLoop<charCount)
    {
      if (rotorCount>=1)
	{
	  //ROTATE RIGHTMOST ROTOR
	  rotorArray[0]->rotate();

	  //cout << "rotor 1 array:";
	  //rotorArray[0]->display();
	  //cout << endl;


	  //CHECK ROTORS IF NOTCHES ALIGNED AND ROTATE IF SO
	  for (int currentRotor=0; currentRotor<rotorCount-1; currentRotor++)
	    {
	      for (int x=0; x<rotorArray[currentRotor]->count-26; x++)
		{
		  //cout << "rotor " << rotorArray[currentRotor+1] << ", rotate count: " << rotorArray[currentRotor+1]->rotateCount << endl; 

		  if (rotorArray[currentRotor]->rotateCount%26 == rotorArray[currentRotor]->notchPosition[x])
		    {
		      rotorArray[currentRotor+1]->rotate();	      
		      break;
		    }
		}
	    }	  
	}
      
      //SEND CHARACTER THROUGH PLUGBOARD
      plugboardA.charSwitch(indexedInput[totalLoop]);

      //ROTORS, RIGHT TO LEFT.
      if (rotorCount>=1)
	{	 
	  for (int x=0; x<rotorCount; x++)
	    {
	      rotorArray[x]->rightToLeft(indexedInput[totalLoop]);
	    }
	}
      
      //REFLECTOR
      reflectorA.charSwitch(indexedInput[totalLoop]);

      //ROTORS, LEFT TO RIGHT
      if (rotorCount>=1)
	{
	  for (int x=rotorCount-1; x>-1; x--)
	    {
	      rotorArray[x]->leftToRight(indexedInput[totalLoop]);
	    }
	}

      //BACK THROUGH PLUGBOARD
      plugboardA.charSwitch(indexedInput[totalLoop]);

      totalLoop++;
    }

  //CONVERT ENCRYPTED OUTPUT BACK TO CHARACTERS
  //DISPLAY ENCRYTED MESSAGE

  char encryptedOutput[charCount];
  //cout << "Your encryted output is:" << endl;
  for (int x=0; x<charCount; x++)
    {
      encryptedOutput[x] = indexedInput[x] + ASCII_A;
      cout << encryptedOutput[x];
    }

  /*for (int x=0; x<rotorCount; x++)
    {
      rotorArray[x]->display();
      cout << endl;
      }*/
  
  //rotorSetupA.display();
  //cout << endl;

  //CLEANUP NEW ROTORS
  for (int x=0; x<rotorCount; x++)
    {
      delete rotorArray[x];  
    }
  
  return 0;
}

//WRAP WHOLE ENIGMA MACHINE TO THROW EXCEPTIONS
int main(int argc, char **argv)
{
  try 
    {
    return EnigmaMachine(argc,argv);
    }  
  catch (EnigmaError e)
    {
      cerr << e.text;
      return e.code;
    }
}
