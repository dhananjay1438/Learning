#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_something(int count, const char *format, ...) {
  va_list args;
  va_start(args, format);
  for (int i = 0; i < count; i++) {
    printf("%s ", va_arg(args, char *));
  }
  va_end(args);
}

int main(void) {

  int a = 10;

  print_something(4, "%s", "hklasdf", "klasdfjsad", "lkadsfsa",
                  "lkasjfsad"); // Anyway to do it without passing number of
                                // arguments as a argument?
  return 0;
}
