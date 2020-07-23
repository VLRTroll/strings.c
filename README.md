# strings.c
A collection of string methods that complement the standart string.h library methods.

## Methods 🈸:
```c
/* Return the index of substring */
int strfind(const char *str, const char *substr);

/* Return the indexes of substring */
int *strrfind(const char *str, const char *substr);

/* Count how many times substring occur in string */
int strcnt(const char *str, const char *substr);

/* Remove a specific char from both sides of a string */
char *strtrim(char *str, const char c);

/* Return a string slice */
char *strslc(const char *str, int init, int len);

/* Split string into string tokens */
char *strstok(char *str, const char *delim);
```

## Usage 👩‍💻:
```c
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


char *next = strstok(trimmed_string, "am");

printf("Parts: [");
while (next) {
  printf("'%s', ", strtrim(next, ' '));
  next = strstok(NULL, "am");
}
printf("\b\b]\n");
// Parts: ['I', 'who I', '']
```

## Standart Methods 🔎
- [string.h Reference](http://cplusplus.com/reference/cstring/)

---

<p align="center">Made with ❤️ by <strong>VLRTroll :alien: </p>
