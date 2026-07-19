## 1. `strtol()`

### Prototype

```c
long strtol(const char *nptr, char **endptr, int base);
```

### Parameters

- `nptr` – string to convert.
- `endptr` – points to the first character after the converted number (`NULL` if not needed).
- `base` – number base (`2`–`36`, or `0` for automatic detection).

### Examples

```c
strtol("123", NULL, 10);   // 123
strtol("FF", NULL, 16);    // 255
strtol("1010", NULL, 2);   // 10
strtol("0xFF", NULL, 0);   // 255 (auto)
```

**Notes**

- C has **no default arguments**; all three parameters are required.
- `base = 0` means automatically detect the base.

# 2. `unsigned char`

- `unsigned char` is an **integer type**.
- Range: **0–255**.
- Commonly used as an array index.

```c
balance[(unsigned char)c]++;
```

**Why cast?**

Avoid negative array indices when `char` is signed.

```c
char c = '\xFF';

balance[c];                  // may be balance[-1]
balance[(unsigned char)c];   // balance[255]
```

# 3. Unsigned Integer Overflow

Unsigned integers wrap around modulo (2^N).

Example (`unsigned char`):

```
255 + 1 → 0
255 + 2 → 1
-1 → 255
-5 → 251
```

Detect overflow:

```c
if (next < current)
```

because wrapping makes the value smaller.

# 4. `abs()` vs `fabs()`

| Function | Type | Header |
| --- | --- | --- |
| `abs()` | `int` | `<stdlib.h>` |
| `labs()` | `long` | `<stdlib.h>` |
| `llabs()` | `long long` | `<stdlib.h>` |
| `fabs()` | `double` | `<math.h>` |

```c
abs(-5);      // 5
fabs(-3.14);  // 3.14
```

Use:

- `abs()` → integers.
- `fabs()` → floating-point numbers.

# 5. `strncpy()`

### Prototype

```c
char *strncpy(char *dest, const char *src, size_t n);
```

### Meaning of `n`

Maximum number of characters to copy.

### Behavior

If `src` is shorter than `n`:

```
Copies string and pads with '\0'.
```

If `src` is at least `n` characters long:

```
Copies exactly n characters.
No '\0' is appended.
```

### Safe Usage

```c
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

# 6. Counting Occurrences (Nested Loops)

### Initialize

```c
int count[n] = {0};
```

### Count Frequencies

```c
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        if (numbers[i] == numbers[j]) {
            count[i]++;
        }
    }
}
```

Example:

```
numbers = {2, 5, 2, 2, 5}
count   = {3, 2, 3, 3, 2}
```

### Count Each Value Only Once

```c
for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++)
        if (numbers[i] == numbers[j])
            break;

    if (j == i) {
        /* Count/process numbers[i] */
    }
}
```

**Notes**

- `count[]` should be initialized to `0`.
- The basic version counts duplicate values repeatedly.
- The improved version processes each distinct value only once.
- Time complexity: **O(n²)**.
