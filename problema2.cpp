#include <stdio.h>

#include <cstring>
#include <iostream>
using namespace std;
char sir[1001], n[100][100];
int nr;
int main() {
  // cin.get(sir, 1001);
  scanf("%[^\n]", &sir);
  char *p;
  p = strtok(sir, " ");
  while (p) {
    strcpy(n[++nr], p);
    p = strtok(NULL, " ");
  }

  for (int i = 1; i < nr; i++) {
    for (int j = i + 1; j <= nr; j++) {
      if (strlen(n[i]) > strlen(n[j])) swap(n[i], n[j]);
    }
  }
  for (int i = 1; i < nr; i++) {
    for (int j = i + 1; j <= nr; j++) {
      if (strlen(n[i]) == strlen(n[j])) {
        for (int k = 0; k < strlen(n[i]); k++) {
          if (n[i][k] < n[j][k]) {
            swap(n[i], n[j]);
            break;

          } else

              if (n[i][k] > n[j][k])
            break;
        }
      }
    }
  }

  for (int i = nr; i >= 1; i--) {
    printf("%s", n[i]);
    printf("\n");
  }

  return 0;
}