# Part 2: Bits, pointers and structs

## Exercise progress

- [x] Two's complement
- [x] IEEE 754 floating point numbers
- [x] Reading bits
- [x] Reversing bits
- [x] UTF-8 encoding
- [x] Days of the month
- [x] Value swap
- [x] Array value transformation
- [x] Tetris
- [x] 3D points
- [x] Temperatures
- [x] Cards
- [x] Fractions
- [x] Dates
- [x] 3-way partitioning
- [x] Quicksort

## Key learning points

1. `*p` → dereference
   - Access the value stored at the address `p` points to
2. `&x` → address-of
   - Get the memory address of variable `x`
3. Array vs pointer
   - `int t[10];`
     - `t` is the address of the first element
     - size is fixed → cannot be reassigned (`t = ...` ❌)
   - `int *p = t;`
     - `p` is a pointer variable
     - can move: `p++`, `p = &x`
4. `typedef struct`

   ```c
   typedef struct {
       int day;
       int month;
       int year;
   } Date;
   ```

   - Defines a structure type
   - `typedef` allows using `Date` directly instead of `struct Date`

5. Accessing struct members
   - `d.day` → when `d` is a struct variable
   - `p->day` → when `p` is a pointer to struct
6. Parameter passing
   - `void f(int x)`
     - pass by value → changes do NOT affect original
   - `void f(int *x)`
     - pass address → can modify original using `x`
7. `enum`

   ```c
   enum { RED, GREEN, BLUE };
   ```

   - Defines named integer constants
   - Values start from 0 by default
   - Values can also be explicitly assigned

     ```c
     enum { RED = 1, GREEN = 5, BLUE = 10 };
     ```

8. Leap year rule

   ```c
   if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
   ```

   - Divisible by 4 → leap year
   - Except divisible by 100
   - Unless divisible by 400

9. Bit operations
   - `x & y` → AND
   - `x | y` → OR
   - `x ^ y` → XOR (bits are different)
   - `~x` → NOT (flip all bits)
   - `x << n` → shift left (multiply by 2ⁿ)
   - `x >> n` → shift right (divide by 2ⁿ)
10. Bit tricks
    - `x & 1` → check if odd (last bit)
    - `x >> 1` → divide by 2
    - `x << 1` → multiply by 2

## Key learning points 2

1. `CHAR_BIT` (`<limits.h>`)
   - Number of bits in a byte (usually 8)
   - Used with `sizeof` to get total bits
2. `sizeof`
   - Returns size in **bytes**, not bits
   - Convert to bits:

     ```c
     sizeof(type) * CHAR_BIT
     ```

3. Reading a bit

   ```c
   (x >> i) & 1
   ```

   - `x >> i`
     - shifts the binary representation of `x` right by `i` positions
     - the bit originally at position `i` moves to the least significant bit (LSB)
   - `& 1`
     - masks all bits except the LSB
     - result is either `0` or `1`

   👉 So this expression extracts the value of the **i-th bit of x**

   ⚠️ Important:
   - Use **unsigned types** (e.g. `unsigned int`)
     - signed right shift may perform **sign extension** (fill with 1s for negative numbers)
   - Bit positions are counted from right to left:
     - LSB = position 0
     - next = position 1, etc.

4. Printing bit representation

   ```c
   for (i = num_bits - 1; i >= 0; i--) {
       int bit = (ux >> i) & 1;
       printf("%d", bit);
   }
   ```

   - Loop runs from **most significant bit (MSB)** to **least significant bit (LSB)**
     - ensures output is in normal binary order (left → right)
   - `num_bits` is typically:

     ```c
     sizeof(type) * CHAR_BIT
     ```

   - `ux` should be an **unsigned version of x**
     - avoids incorrect results due to sign extension

   👉 Output example:

   ```
   00000000 00000000 00000000 00001010
   ```

   ⚠️ Common mistakes:
   - Using signed variable → wrong bits for negative numbers
   - Loop direction wrong → reversed output
   - Wrong `num_bits` → missing or extra bits

5. Reversing bits

   ```c
   #include <limits.h>

   int num_bits = sizeof(num) * CHAR_BIT;
   unsigned char reversed = 0;

   for (int i = 0; i < num_bits; i++) {
      unsigned char bit = (num >> i) & 1;
      reversed |= bit << (num_bits - 1 - i);
   }

   ```

   - Take bit from position `i` → place at reversed position
   - ⚠️ Use `|=` to accumulate

6. Converting `'0'` / `'1'` to integer

   ```c
   value += (binary_str[i] - '0');
   ```

   - `'0'` → 0, `'1'` → 1
   - ⚠️ Must subtract `'0'`

   ```c
   <!-- Convert a binary string to an integer -->
   char binary_str[] = "1011";
   int value = 0;

   for (int i = 0; binary_str[i] != '\0'; i++) {
      value *= 2;
      value += (binary_str[i] - '0');
   }
   ```

7. Casting

   ```c
   (int)x, (short)x, (signed char)x
   ```

   - Converts type, may truncate higher bits
   - ⚠️ Risk of overflow / data loss

8. `L` suffix

   ```c
   2015L
   ```

   - Marks constant as `long`

9. `extern`

   ```c
   extern const char *array[];
   ```

   - Declares variable defined in another file

10. `strcasecmp`
    - Compares strings ignoring case
    - Returns 0 if equal
11. `ldexp(value, exp)`
    - Computes:

      ```
      value × 2^exp
      ```

      - Useful for IEEE 754 reconstruction

12. Key bit concepts
    - Use unsigned for bit operations
    - Be careful with shifting signed values
    - Always track bit positions correctly
13. Difficult topic
    - 3-way partitioning
      - Split array into:

      ```
      - left: x < pivot1
      - middle: pivot1 ≤ x < pivot2
      - right: x ≥ pivot2
      ```

      - Common mistakes:
        - using index instead of value
        - wrong boundaries
        - incorrect swaps
