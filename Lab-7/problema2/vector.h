
template <typename T>
class Vector {
 public:
  int count;
  T* elements;
  int index;
  Vector();
  ~Vector();
  void push(T element);
  void pop(T element);
  void remove(T index);
  void insert(T index, T element);
  const T& get(int index);
  void set(int index, T element);
  int countV();
  void sort();
};