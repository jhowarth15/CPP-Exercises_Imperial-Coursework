const int ASCII_A = 65;
const int ASCII_Z = 90;
const int ASCII_ZERO = 48;
const int ASCII_NINE = 57;
const int MAX = 100;
const int CHAR_NO = 25;
const int WHEELMARK_NO = 26;

class Plugboard{
public:
  Plugboard(const char* file);
  int count; //Zero indexed count of number of integers in configuration file.
  int configuration[MAX]; //Array of integers representing the configuration file.
  void display(); //Displays the object on the console.
  void charSwitch(int& number); //Switches a char that goes through to appropriate mapping.

};

class Reflector{
public:
  Reflector(const char* file);
  int count;
  int configuration[MAX];
  void display();
  void charSwitch(int& number);

};

class Rotor{
public:
  Rotor(const char* file);
  int count;
  int configuration[MAX];
  void display();
  void rightToLeft(int& number); //Sends input characters through right to left.
  void leftToRight(int& number); //Sends characters through l to r.
  void rotate(); //Rotates rotor and increments rotateCount.
  int rotateCount;
  int notchPosition[MAX];

};

class Rotor_Setup{
public:
  Rotor_Setup(const char* file);
  int count;
  int configuration[MAX];
  void display();
};


