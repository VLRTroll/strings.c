#include <stdlib.h>
#include <string.h>
#include "strings.h"

int strfind(const char *str, const char *substr) {
  const char *pch = strstr(str, substr);
  return pch ? (int)(pch - str) : -1;
}

int *strrfind(const char *str, const char *substr) {
  int *pos = (int *)malloc((strcnt(str, substr) + 1) * sizeof(*pos));
  int i = 0;

  for (const char *pch = strstr(str, substr); pch; pch = strstr(pch + 1, substr))
    pos[i++] = (int)(pch - str);

  pos[i] = -1;
  return pos;
}

int strcnt(const char *str, const char *substr) {
  int c = 0;

  for (const char *pch = strstr(str, substr); pch; c++)
    pch = strstr(pch + 1, substr);

  return c;
}

char *strtrim(char *str, const char c) {
  while (*str++ == ' ');          /* trim left */
  char *estr = str + strlen(str); /* end of string */
  while (*--estr == ' ');         /* trim left */
  *++estr = '\0';                 /* set end of string */

  char *trimmed_string = (char *)malloc(sizeof(*trimmed_string) * (estr - str));
  strcpy(trimmed_string, --str);  /* copy trimmed string */

  *estr = ' ';                    /* reset end of string */
  return trimmed_string;
}

char *strstok(char *str, const char *delim) {
  static char *laststr, *pch;
  static int lendel;

  if (str) {                /* Is a new string? */
    laststr = str;          /* Store it for the next call */
  } else {
    if (!pch) return NULL;  /* If it's the string end */
    laststr = pch + lendel; /* Set the pointer for the start of the next string */
  }

  pch = strstr(laststr, delim); /* Search the next delimiter occourency */
  lendel = strlen(delim);       /* Store the length of the delimiter */
  if (pch) *pch = '\0';         /* Set the end of the string */

  return laststr; /* Return the begginig of the next string */
}