# COMP.CS.120 Programming technique C

This repository contains my study notes, programming exercises, and exam preparation materials for the course COMP.CS.120 Programming technique C at Tampere University.

## Course topics

- Basic syntax and operations
- Memory addresses and pointers
- C string handling
- Dynamic memory handling
- Functions and parameter passing
- C standard library

## 📚 Course Structure

### Part 1: Basics of C

- Syntax, variables, control flow, functions

### Part 2: Bits, pointers and structs

- Memory, addresses, pointers
- Structs and low-level data

### Part 3: Dynamic memory and files

- malloc, free, void pointers
- File input/output

### Part 4: Advanced topics

- Macros
- Variadic functions
- Signals and time

## 📚 Main Study Materials

### Recommended by instructor

- The C Book – Banahan, Brady, and Doran
- The C Programming Language – Kernighan and Ritchie

### Online resources

- https://www.geeksforgeeks.org/c/c-programming-language/
- https://en.cppreference.com/w/c
- The C Library Reference Guide: http://www.fortran-2000.com/ArnaudRecipes/Cstd/

## 🎯 Goal

- Master C programming fundamentals
- Build strong understanding of pointers and memory

## 🛠 Strict C90 compilation

Use these flags to enforce ISO C90 and avoid compiler extensions:

```bash
gcc -std=c90 -pedantic-errors -Wall -Wextra -Werror
```

### What each flag does

- `-std=c90`: Compile using the ISO C90 standard.
- `-pedantic-errors`: Enforce strict compliance. Any non‑C90 feature becomes an error.
- `-Wall`: Enable common warnings.
- `-Wextra`: Enable additional warnings that `-Wall` does not include.
- `-Werror`: Treat all warnings as errors.

### Key C90 restrictions

#### 1) Declarations must come before statements (no mixing)

In C90, declarations must appear before any statements within the same block.

```c
/* OK (C90): declarations first, then statements */
int i;
puts("hi");
```

```c
/* ERROR (C90): statement before a declaration */
puts("hi");
int i;
```

```c
/* ERROR (C90): declaration after statements (mixed code + declarations) */
int i;
i = 5;
int j;
```

#### 2) No declarations inside `for`

```c
/* OK (C90) */
int i;
for (i = 0; i < n; i++) {
	/* ... */
}
```

```c
/* ERROR (C90): declarations in for-init are not allowed */
for (int i = 0; i < n; i++) {
	/* ... */
}
```

#### 3) No `//` comments

```c
/* OK (C90) */
/* This is fine in C90 */
```

```c
/* ERROR (C90): // comments are not allowed */
// This is not valid in C90
```

#### 5) No `bool` type (without `stdbool.h`)

C90 does not include `bool`.

```c
/* Workarounds (C90): use int (there is no built-in bool) */

/* Option A: plain int */
int flag = 1;            /* 0 = false, nonzero = true */

/* Option B: readability macros */
#define TRUE  1
#define FALSE 0
int flag2 = TRUE;
```

#### 6) Use function prototypes (avoid implicit declarations)

Declare functions before use to prevent implicit declarations and type mismatches.

```c
/* Example (C90): prototype before use */
int add(int a, int b);

int main(void) {
	return add(1, 2);
}

int add(int a, int b) {
	return a + b;
}
```
