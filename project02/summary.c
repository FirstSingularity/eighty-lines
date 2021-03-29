#include <stdio.h>

int main(void) {
  int line = 1;
  int first = 0;
  int check = 0;
  char ch = 0;

  do {
    scanf("%c", &ch);
    if (check == 0) {
      check++;
      if (ch == '*') {
        if (first == 0) {
          printf("%d", line);
          first = 1;
        } else {
          printf(" %d", line);
        }
        line--;
      }
    }
    if (ch == '\n') {
      line++;
      check = 0;
    }
  } while (!feof(stdin));

  printf("%c", '\n');
  return 0;
}