class Number

{
  // add data members
 public:
  char* val;
  int current_base;

 public:
  Number(const char* value, int base);

  Number(int num);
  Number(const char* value);
  Number(const Number& num);
  Number(const Number&& num);

  ~Number();

  Number& operator=(Number&& i);

  int operator[](int index);

  bool operator-=(Number i);
  bool operator>(Number i);
  bool operator>=(Number i);
  bool operator<(Number i);
  bool operator<=(Number i);
  bool operator==(Number i);

  // add operators and copy/move constructor
  friend Number operator+(const Number& i);
  friend Number operator-(const Number& i);

  Number& operator+=(const Number& i);

  void operator++(int i);
  void operator--(int i);
  void operator--();
  // bool operator=(int i);

  void SwitchBase(int newBase);

  void Print();

  int GetDigitsCount();  // returns the number of digits for the current number

  int GetBase();  // returns the current base
};