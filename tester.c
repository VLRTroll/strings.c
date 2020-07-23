#include <stdio.h>
#include "strings.h"

int main() {
  char string[] = "      I am who I am    ";
  
  int index = strfind(string, "who");

  printf("Index of 'who': %d\n", index);
  // Index of 'who': 11
  

  int count = strcnt(string, "am");

  printf("Qntd. of 'am's: %d\n", count);
  // Qntd. of 'am's: 2


  int *indexes = strrfind(string, "am");

  printf("Indexes of 'am': [");
  for (int i = 0; indexes[i] != -1; i++)
    printf("%d, ", indexes[i]);
  printf("\b\b]\n");
  // Indexes of 'am': [8, 17]


  char *trimmed_string = strtrim(string, ' ');

  printf("Trimmed string: '%s'\n", trimmed_string);
  // Trimmed string: 'I am who I am'

  char *slice = strslc(string, index, 3);
  printf("Sliced string (%d,14): '%s'\n", index, slice);
  // Sliced string (11,14): 'who'

  slice = strslc(trimmed_string, 9, 10);
  printf("Sliced string (9,13): '%s'\n", slice);
  // Sliced string (9,13): 'who'

  char *next = strstok(trimmed_string, "am");

  printf("Parts: [");
  while (next) {
    printf("'%s', ", strtrim(next, ' '));
    next = strstok(NULL, "am");
  }
  printf("\b\b]\n");
  // Parts: ['I', 'who I', '']

  return 0;
}