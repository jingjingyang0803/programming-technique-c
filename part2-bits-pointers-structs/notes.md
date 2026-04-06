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

1. `p` → dereference
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
