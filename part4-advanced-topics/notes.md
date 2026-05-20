# Part 4: Jumps, signals, time, macros and variadic functions

## Exercise progress

- [ ] Goto
- [ ] Signals
- [ ] Current time
- [ ] Days of a week
- [ ] Date difference
- [ ] Macro definitions
- [ ] Quicksort #2
- [ ] String concatenation
- [ ] Multi-insert into a list
- [ ] Custom fprintf

## Summary

1. **`goto`**

   `goto` jumps to a label inside the same function.

   Useful pattern:

   ```c
   i = 0;
   row_loop:
   if (i >= rows) goto end;

   /* work here */

   i++;
   goto row_loop;

   end:
   ```

   - Labels end with `:`
   - `goto label;` jumps to that label
   - Keep the structure simple
   - It can be useful for breaking out of nested logic or cleanup

2. **Signals**

   Signals allow the program to react to events such as `Ctrl+C`.

   Basic structure:

   ```c
   #include <signal.h>

   void handler(int sig) {
       /* react to signal */
   }

   int main(void) {
       signal(SIGINT, handler);
   }
   ```

   - Handler must return `void`
   - Handler takes one `int`
   - Keep the handler simple
   - Use global variables carefully if needed

3. **Current Time**

   Use `<time.h>`.

   ```c
   time_t now;
   struct tm *t;

   now = time(NULL);
   t = localtime(&now);
   ```

   Remember:

   ```c
   year  = t->tm_year + 1900;
   month = t->tm_mon + 1;
   day   = t->tm_mday;
   ```

   Important fields:

   ```c
   tm_year   /* years since 1900 */
   tm_mon    /* 0-11 */
   tm_mday   /* day of month */
   tm_wday   /* 0 = Sunday */
   ```

4. **Days of a Week**

   Use `tm_wday` or an array of weekday names.

   ```c
   const char *days[] = {
       "Sunday", "Monday", "Tuesday", "Wednesday",
       "Thursday", "Friday", "Saturday"
   };
   ```

   Then:

   ```c
   printf("%s\n", days[t->tm_wday]);
   ```

   - Sunday is index `0`
   - Saturday is index `6`

5. **Date Difference**

   Convert dates into `time_t`, then subtract.

   ```c
   struct tm a = {0};
   struct tm b = {0};

   a.tm_year = year1 - 1900;
   a.tm_mon = month1 - 1;
   a.tm_mday = day1;

   b.tm_year = year2 - 1900;
   b.tm_mon = month2 - 1;
   b.tm_mday = day2;

   seconds = difftime(mktime(&b), mktime(&a));
   days = seconds / (60 * 60 * 24);
   ```

   - Initialize `struct tm` with `{0}`
   - Adjust year and month
   - Use `mktime`
   - Use `difftime`

6. **Macros**

   Macros are handled before compilation.

   ```c
   #define PI 3.141592653589793
   #define MAX2(a, b) ((a) > (b) ? (a) : (b))
   #define MIN2(a, b) ((a) < (b) ? (a) : (b))
   ```

   For three or four values:

   ```c
   #define MAX3(a, b, c) MAX2(MAX2((a), (b)), (c))
   #define MAX4(a, b, c, d) MAX2(MAX2((a), (b)), MAX2((c), (d)))
   ```

   - Always use parentheses
   - Use `#ifdef` for optional debug output
   - Use `#ifndef` for default values

   Example:

   ```c
   #ifndef TYYPPI
   #define TYYPPI unsigned char
   #endif
   ```

   If `TYYPPI` is not given during compilation, it uses `unsigned char`.

7. **Quicksort #2**

   Generic quicksort uses `void *`, element size, and a comparison function.

   Function idea:

   ```c
   void jarjesta(void *base, size_t n, size_t size,
                 int (*cmp)(const void *, const void *));
   ```

   Access element `i`:

   ```c
   char *arr = base;
   void *elem = arr + i * size;
   ```

   Swap generic values:

   ```c
   void swap(void *a, void *b, size_t size) {
       char *tmp = malloc(size);

       memcpy(tmp, a, size);
       memcpy(a, b, size);
       memcpy(b, tmp, size);

       free(tmp);
   }
   ```

   - Cast `void *` to `char *` before pointer arithmetic
   - Use `memcpy`
   - Use the comparison function
   - Recursively sort left and right parts

8. **String Concatenation**

   Main steps:
   1. Count total length
   2. Allocate memory
   3. Copy all characters
   4. Add `'\0'`

   Example idea:

   ```c
   char *result = malloc(total + 1);
   ```

   Then copy characters manually or with string functions, depending on task rules.
   - Include space for `'\0'`
   - Check `malloc`
   - Return the new string
   - Caller must `free` it

9. **Multi-insert into a List**

   A generic linked-list node often stores `void *data`.

   ```c
   typedef struct Solmu {
       void *data;
       struct Solmu *seur;
   } Solmu;
   ```

   Creating a node:

   ```c
   Solmu *s = malloc(sizeof(Solmu));
   s->data = malloc(data_size);
   memcpy(s->data, data, data_size);
   s->seur = next;
   ```

   - Allocate node
   - Allocate memory for data
   - Copy data with `memcpy`
   - Link nodes in the correct order
   - Free already-created nodes if allocation fails

   Most important linking idea:

   ```c
   new_node->seur = current->seur;
   current->seur = new_node;
   ```

   Also remember: function declarations in `.h` and definitions in `.c` must match exactly.

10. **Custom `fprintf`**

    The task was to implement a simplified output function:

    ```c
    size_t tulosta(FILE *td, const char *mj, ...);
    ```

    Supported formats:

    ```c
    %d   int
    %s   string
    %c   character
    %%   percent sign
    ```

    Use variadic arguments:

    ```c
    #include <stdarg.h>

    va_list args;
    va_start(args, mj);

    /* use va_arg */

    va_end(args);
    ```

    Scan the format string character by character:

    ```c
    while (*mj != '\0') {
        if (*mj == '%') {
            mj++;

            if (*mj == 'd') {
                int x = va_arg(args, int);
            } else if (*mj == 's') {
                char *s = va_arg(args, char *);
            } else if (*mj == 'c') {
                int c = va_arg(args, int);
            } else if (*mj == '%') {
                fputc('%', td);
            }
        } else {
            fputc(*mj, td);
        }

        mj++;
    }
    ```

    - Use only `fputc` for output
    - Count every printed character
    - Convert integers manually
    - Handle negative numbers
    - Remember `char` arguments are read as `int` from `va_arg`

## Common mistakes

-
