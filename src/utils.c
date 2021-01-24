
#include <stdio.h>
#include <stdlib.h>

int int_to_char_array(int num, char *buf) {
  snprintf(buf, sizeof(buf), "%d", num);
  return(0);
}
