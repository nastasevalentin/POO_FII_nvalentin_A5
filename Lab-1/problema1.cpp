#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
using namespace std;

int conversie(char s[200]) {
  int p = 10, x = 0;
  for (int i = 0; i < strlen(s); i++) {
    x = x * p + (s[i] - 48);
  }
  return x;
}

int main() {
  FILE* fp;

  char myString[200], backup[200];
  int sum = 0;
  if (fopen_s(&fp, "in.txt", "r") != 0) {
    // printf("eroare");
  } else {
    // printf("am deschis fisierul");
    while (fgets(myString, 200, fp)) {
      strcpy(backup, myString);
      myString[strlen(myString) - 1] = '\0';
      //  printf("am citit din fisier");
      sum = sum + conversie(myString);
    }
  }
  sum = sum - conversie(myString) + conversie(backup);
  cout << sum;
}