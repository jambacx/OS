#include <stdio.h>
int main() {
  int p = 5, r = 4, i, j, k, total[4], y = 0, flag;
  int alloc[p][r] = {
      {0, 0, 1, 2}, {1, 0, 0, 0}, {1, 3, 5, 4}, {0, 6, 3, 2}, {0, 0, 1, 4}};

  int max[p][r] = {
      {0, 0, 1, 2}, {1, 7, 5, 0}, {2, 3, 5, 6}, {0, 6, 5, 2}, {0, 6, 5, 6}};

  int avail[r] = {1, 5, 2, 0};

  int f[p], ans[p], ind = 0;
  for (k = 0; k < p; k++) {
    f[k] = 0;
  }

  // Need matrix iig oloh
  int need[p][r];
  for (i = 0; i < p; i++) {
    for (j = 0; j < r; j++)
      need[i][j] = max[i][j] - alloc[i][j];
  }
  // Need matrix iig hewleh
  printf("\n");
  printf("Need Matrix : \n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < r; j++)
      printf("%d ", need[i][j]);
    printf("\n");
  }
  printf("\n");

  for (k = 0; k < p; k++) {
    for (i = 0; i < p; i++) {
      if (f[i] == 0) {
        int flag = 0;
        for (j = 0; j < r; j++) {
          if (need[i][j] > avail[j]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < r; y++)
            avail[y] += alloc[i][y];
          f[i] = 1;
        }
      }
    }
  }

  printf("Processuudiin ajlah daraalal\n");
  for (i = 0; i < p - 1; i++)
    printf(" P%d ->", ans[i]);
  printf(" P%d", ans[p - 1]);

  for (i = 0; i < p; i++) {
    if (flag == 0) {
      printf("\n Deadlock vvssen baina.");
      return 0;
    }
  }
  return 0;
}