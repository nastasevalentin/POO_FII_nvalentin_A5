class Number

{
  // add data members
 public:
  char* val;
  int current_base;

 public:
  Number(const char* value, int base);  // where base is between 2 and 16

  //~Number();

  // add operators and copy/move constructor
  int operator+(const Number& i);
  int operator-(const Number& i);
  int operator>(const Number& i);
  int operator>=(const Number& i);
  int operator<(const Number& i);
  int operator<=(const Number& i);
  int operator==(const Number& i);

  void SwitchBase(int newBase);

  void Print();

  int GetDigitsCount();  // returns the number of digits for the current number

  int GetBase();  // returns the current base
};