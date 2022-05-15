#include <string.h>

#include <iostream>
using namespace std;

template <class T, class K>
class Map {
  struct elemente {
    T key;
    K value;
    int index;
  };
  elemente* a = new elemente[5];
  int nr = 0;

 public:
  K& operator[](int key1) {
    int i;
    for (i = 0; i < nr; i++) {
      if (key1 == a[i].key) return a[i].value;
    }

    a[nr].key = key1;
    a[nr].index = nr;

    nr++;

    return a[nr - 1].value;
  }

  void Set(T cheie, K valoare) {
    int ok = 0;
    for (int i = 0; i < nr; i++) {
      if (a[i].key == cheie) {
        ok = 1;
        a[i].value = valoare;
        break;
      }
    }
    if (ok == 0) {
      a[nr].key = cheie;
      a[nr].value = valoare;
      a[nr].index = nr;
      nr++;
    }
  }
  bool Get(const T& key, K& value) {
    for (int i = 0; i < nr; i++) {
      if (a[i].key == key) value = a[i].value;
      return true;
    }
    return false;
  }

  int Count() { return nr; }

  void Clear() {
    nr = 0;
    delete[] a;
  }

  bool Delete(const T& key) {
    for (int i = 0; i < nr; i++) {
      if (a[i].key == key) {
        for (int j = i + 1; j < nr; j++) {
          a[j].index--;
          a[j - 1] = a[j];
        }
        nr--;
        return true;
      }
    }
    return false;
  }
  bool Includes(const Map<T, K>& newmap) {
    int ok = 0, i, j;
    for (j = 0; j < newmap.nr; j++) {
      T keys = newmap.a[j].key;
      ok = 0;
      for (i = 0; i < nr; i++) {
        if (a[i].key == keys) ok = 1;
      }
      if (ok == 0) return false;
    }
    return true;
  }
  elemente* begin() { return &a[0]; }
  elemente* end() { return &a[nr]; }
};

int main()

{
  Map<int, const char*> m;

  m[10] = "C++";
  m[20] = "test";
  m[30] = "Poo";
  cout << "Set:"
       << "\n";
  m.Set(40, "FII");
  for (auto [key, value, index] : m) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }
  cout << "Delete:"
       << "\n";
  m.Delete(30);
  for (auto [key, value, index] : m) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }
  cout << "Get:"
       << "\n";
  const char* ok;
  m.Get(10, ok);
  cout << ok << "\n";
  cout << "Clear:"
       << "\n";
  m.Clear();
  for (auto [key, value, index] : m) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }

  return 0;
}