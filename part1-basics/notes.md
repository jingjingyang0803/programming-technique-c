# Part 1: Basics of C

## Exercises

- [x] Hello world!
- [x] Numbers
- [x] Multiplication table
- [x] ASCII
- [x] Command line parameters
- [x] Numbers #2
- [x] Roots
- [x] Lottery
- [x] Multiplication table #2
- [x] Statistics
- [x] Equation
- [x] Palindromes
- [x] Parameter table
- [x] Geometry
- [x] Transformation
- [x] Caesar cipher
- [x] Anagrams
- [x] Type limits
- [x] Unsigned
- [x] Floating point comparison

## Key learning points

### 1. Common header files

- `stdio.h`

  For input/output functions such as `printf` and `fprintf`.

- `stdlib.h`

  For utility functions such as `atoi` and `atof`.

- `string.h`

  For string handling functions such as `strlen` and `strncpy`.

- `limits.h`

  For constants such as `UCHAR_MAX`.

- `ctype.h`

  For character classification and conversion functions such as `tolower` and `toupper`.

- `math.h`

  For mathematical functions such as `sqrt` and `fabs`.

### 2. The `main` function

- `int main(void)`

  Used when the program does not need command-line arguments.

- `int main(int argc, char *argv[])`

  Used when the program needs command-line arguments.

#### `argc` and `argv`

- `argc` = argument count
- `argv` = argument vector (array of strings)
  - `argv[0]` is the program name
  - actual user arguments start from `argv[1]`
  - So in practice, user-provided arguments start from index `1`, not `0`.

### 3. Converting strings to numbers

- `atoi` converts a string to `int`
  - `int n = atoi(argv[1]);`
- `atof` converts a string to `double`
  - `double x = atof(argv[2]);`

`atoi` and `atof` are simple, but they do not report conversion errors clearly.

They return 0 on failure, which is ambiguous because "0" is also a valid input.

For more robust programs, `strtol` and `strtod` are often better choices.

### 4. Output with `printf`(important!)

- `%s` for strings
- `%d` for `int`
- `%c` for `char`
- `%f` for `double` (float is automatically promoted to double)
- `%lu` for `unsigned long`
- `%zu` for `size_t`
- `%Lf` for `long double`
- `%.4d` for printing an `int` with _at least_ 4 digits (pads with leading zeros if needed)
  - e.g. `printf("%.4d\n", 7);`
- `%.10f` for showing 10 digits after the decimal point
  - e.g. `printf("%.10f\n", x);`

#### Dynamic width `%*d` and precision `%.*f`

```c
printf("%*d\n", 5, n);    /* print n with width 5 */
printf("%.*f\n", 3, x);   /* print x with 3 digits after decimal */
```

#### Left alignment`%-*s`

```c
printf("%-*s|\n", 10, "cat"); /* print the string left-aligned in a field of width 10 */
```

### 5. Printing long strings across multiple lines

A long string literal can be split across lines by placing string literals next to each other:

```c
printf("Usage: %s win1 win2 win3 win4 win5 win6 win7 "
       "ticket1 ticket2 ticket3 ticket4 ticket5 ticket6 ticket7\n",
       argv[0]);
```

This is useful for keeping code readable.

### 6. Error output with `fprintf(stderr, ...)`

```c
fprintf(stderr, "Error: invalid input\n");
```

- `stderr` is the standard error stream.
- Error messages are usually printed to `stderr` instead of standard output.

### 7. Math functions

- `sqrt(x)` computes the square root
- `fabs(x)` computes the absolute value of a floating-point number

### 8. Character and string basics

#### String terminator

In C, strings end with the null character `'\0'`.

```c
for (i = 0; mj1[i] != '\0'; i++) /* loop continue until the end of the string */
```

#### Useful functions

- `strlen(s)` gives the length of a string
  - returns a value of type `size_t`
  - `size_t len = strlen(s);`
- `tolower(c)` converts a character to lowercase
- `toupper(c)` converts a character to uppercase

### 9. Safe copying with `strncpy`

```c
/* Copy the original parameter to transformed */
strncpy(transformed, argv[i], sizeof(transformed) - 1); /* sizeof(transformed) - 1 leaves space for the terminating '\0' */
transformed[sizeof(transformed) - 1] = '\0'; /* ensures the copied string is always null-terminated */
```

Note: `strncpy` does NOT guarantee null-termination if the source string is longer than the specified size, so manual `'\0'` termination is necessary.

### 10. Calculating number width

This is useful for formatted output.

- start with width = 1
- keep dividing by 10
- each division removes one digit
- count how many digits there are

```c
width = 1;
while (num >= 10) {
  num /= 10;
  width++;
}
```

### 11. Reversing a string

- `i` starts from the left
- `j` starts from the right
- swap characters until they meet in the middle

```c
/* A classic two-index technique */
size_t len = strlen(mj);

if (len > 0) {
	for (i = 0, j = len - 1; i < j; i++, j--) {
		temp = mj[i];
		mj[i] = mj[j];
		mj[j] = temp;
	}
}
```

### 12. Counting occurrences of characters using frequency table

```c
#include <limits.h>

int freq[UCHAR_MAX + 1] = {0};

for (i = 0; s[i] != '\0'; i++) {
	freq[(unsigned char)s[i]]++;/* Casting to `unsigned char` ensures the value is non-negative and can be safely used as an array index. */
}
```

### 13. Counting occurrences of numbers with nested loops

```c
for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
		if (numbers[i] == numbers[j]) {
			count[i]++;
		}
	}
}
```

### 14. `break` is very useful

When some condition is met, there is no need to continue the inner loop. Example:

```c
/* Check if the current character in mj matches the original alphabet */
if (mj[i] == orig[j]) {
  /* If it matches, replace it with the corresponding character in the
   * permuted alphabet */
  mj[i] = perm[j];
  /* Break the inner loop since we found a match and replaced the
   * character */
  break;
}
```

### 15. Boolean-style variables are very useful

In C90, `int` is commonly used as a boolean flag.

- checking whether something has appeared before
- preventing duplicate output
- tracking state in loops

### 16. `extern`

`extern` means the variable is defined somewhere else, but we want to use it here.

This is useful when working with multiple source files.

```c
extern const long double PII;
```

### 17. `unsigned`

This is important when working with:

- sizes
- counts
- bit operations
- values that should never be negative

**Be careful:** mixing signed and unsigned values can lead to unexpected result!

```c
int i = -1;
unsigned int j = 1;

if (i < j)  // surprising result!
```

### 18. `UCHAR_MAX`

`UCHAR_MAX` is the maximum value representable by `unsigned char` (typically 255).

It is often used when building frequency tables for characters to create an array large enough to store information for every possible `unsigned char` value.

```c
#include <limits.h>

int balance[UCHAR_MAX + 1];
```
