/* error codes  */
#define INSUFFICIENT_NUMBER_OF_PARAMETERS		1
#define INVALID_INPUT_CHARACTER				2
#define INVALID_INDEX					3
#define NON_NUMERIC_CHARACTER				4
#define IMPOSSIBLE_PLUGBOARD_CONFIGURATION		5
#define INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS	6
#define INVALID_ROTOR_MAPPING				7
#define NO_ROTOR_STARTING_POSITION			8
#define INVALID_REFLECTOR_MAPPING			9
#define INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS	10
#define ERROR_OPENING_CONFIGURATION_FILE		11

#define NO_ERROR					0

//Regular structure for throwEnigmaError function below to use.
struct EnigmaError {
  int code;
  char text[MAX];
};

//Functions to throw exceptions.
void throwEnigmaError (int code);
void throwEnigmaError (int code, const char* file);
void throwEnigmaError (int code, char **argv, int argc);
void throwEnigmaError (int code, char inputChar);
void throwEnigmaError (int code, char inputChar, const char* file);
void throwEnigmaError (int code, int inputNum, const char* file);
void throwEnigmaError (int code, const char* file, int variant);
