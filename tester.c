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


  char *tokens = strstok(trimmed_string, "am");

  printf("Tokens: [");
  while (tokens) {
    printf("'%s', ", strtrim(tokens, ' '));
    tokens = strstok(NULL, "am");
  }
  printf("\b\b]\n");
  // Tokens: ['I', 'who I', '']

  return 0;
}