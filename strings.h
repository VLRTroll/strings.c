#ifndef STRINGS_H_
#define STRINGS_H_

/* Return the index of substring */
int strfind(const char *str, const char *substr);

/* Return the indexes of substring */
int *strrfind(const char *str, const char *substr);

/* Count how many times substring occur in string */
int strcnt(const char *str, const char *substr);

/* Remove a specific char from both sides of a string */
char *strtrim(char *str, const char c);

/* Split string into string tokens */
char *strstok(char *str, const char *delim);

/* Return a string slice */
char *strslc(const char *str, int init, int len);

#endif
