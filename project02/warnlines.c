#include <stdio.h>

void aux_line(int length) {
  int i = 1;
  printf("\n");
  while (i <= length + 8) {
    if (i <= 88) {
      printf("%c", ' ');
    } else {
      printf("%c", '^');
    }
    i++;
  }
}

int main(void) {
  char ch = 0;
  int count = 0;
  int size = 0;
  int line = 0;
  char temp[1200];

  while (!feof(stdin)) {
    int i = 1;
    scanf("%c", &ch);
    count++;
    if (ch == '\t') {
      size += 8 - (size % 8);
    } else {
      size++;
    }
    temp[count] = ch;

    if (ch == '\n' && count > 1) {
      line++;
      count--;
      size--;
      if (size > 80) {
        printf("%c", '*');
      } else {
        printf("%c", ' ');
      }

      printf("% 5d", line);
      printf("%c%c", ':', ' ');
      while (i <= count) {
        printf("%c", temp[i]);
        i++;
      }
      if (size > 80) {
        aux_line(size);
      }
      count = 0;
      size = 0;
      printf("\n");
    }
  }

  return 0;
}
