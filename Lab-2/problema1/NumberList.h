class NumberList {
  // public-protected-private
  // private-nu poate fi apelat/accesat decat din interiorul clasei
  // protected - nu poate fi apelat / accesat din exterior, dar poate fi apelat
  // dintr-o clasa derivata public - poate fi apelat/accesat de oriunde
  int numbers[11];
  int count;

 public:
  void Init();
  bool Add(int x);

  void Sort();
  void Print();
};