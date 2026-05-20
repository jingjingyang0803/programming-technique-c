# Part 3: Dynamic memory handling, void-pointers and files

## Exercise progress

- [ ] Fibonacci sequence
- [ ] String array
- [ ] Dynamically created objects
- [ ] Multiplication table #3
- [ ] Fibonacci sequence #2
- [ ] Multiplication table #4
- [ ] Double list
- [ ] String array #2
- [ ] Sorting
- [ ] Generic search
- [ ] Generic list
- [ ] 3-way partitioning #2
- [ ] Printing to a file
- [ ] Input numbers
- [ ] Currency exchange rates
- [ ] Tidy spaces
- [ ] Reading a line of input
- [ ] Tokenizing a string
- [ ] File-based array
- [ ] Municipality statistics

## Summary

1. **malloc/free、字符串数组、sprintf**
   - **A. malloc / free 基本用法**
     - 分配：`unsigned int *fibonacci = malloc(n * sizeof(unsigned int));`
     - 检查：`if (fibonacci == NULL) { /* handle error */ }`
     - 释放：`free(fibonacci);`
   - **B. 字符串数组（`char** kopiot`）：结构与释放顺序
     - `char **kopiot;` 表示 _array of `char_ ` pointers\*（指针数组）
     - 释放顺序：先释放每个字符串，再释放指针数组本身

     ```c
     free(kopiot[j]); /* Free previously allocated strings. */

     free(kopiot); /* Free the array of string pointers. */
     ```

   - **C. 二维表（`kt->kertotaulu`）+ 结构体：释放顺序**
     - 释放顺序：行 → 行指针数组 → 结构体

     ```c
     free(kt->kertotaulu[k]); /* Free previously allocated rows. */

     free(kt->kertotaulu); /* Free the array of row pointers. */
     free(kt);             /* Free the Kertotaulu structure. */
     ```

   - **D. `sizeof(...)` + malloc 结果检查**
     - 例：`sizeof(Rectangle)` / `cols * sizeof(uint)`

     ```c
     kt->kertotaulu[i] = malloc(cols * sizeof(uint));
     if (kt->kertotaulu[i] != NULL) {
     ```

   - **E. `strcpy` 的位置**
     - 只有在目标内存已分配（例如 `malloc(strlen(src) + 1)`）之后才能 `strcpy(dest, src)`
   - **F. `sprintf` vs `printf`**
     - `printf("%u", fib);`：输出到屏幕
     - `sprintf(buf, "%u", fib);`：把格式化结果写进字符串数组 `buf`

2. **Dynamic memory pattern**

   **Basic allocation**

   ```c
   int *arr;
   size_t n = 10;

   arr = malloc(n * sizeof(int));
   if (arr == NULL) {
       return 1;
   }
   ```

   使用完必须：

   ```c
   free(arr);
   ```

3. **For structs**

   ```c
   typedef struct {
       char *name;
       int age;
   } Person;
   ```

   创建对象：

   ```c
   Person *p = malloc(sizeof(Person));
   if (p == NULL) {
       return NULL;
   }
   ```

   如果 struct 里面还有动态成员：

   ```c
   p->name = malloc(strlen(name) + 1);
   if (p->name == NULL) {
       free(p);
       return NULL;
   }
   strcpy(p->name, name);
   ```

   释放时反过来：

   ```c
   free(p->name);
   free(p);
   ```

4. **String array**

   常见结构：

   ```c
   char **arr;
   ```

   表示“字符串数组”。

   创建：

   ```c
   arr = malloc(n * sizeof(char *));
   if (arr == NULL) {
       return NULL;
   }
   ```

   每个字符串单独申请：

   ```c
   arr[i] = malloc(strlen(src) + 1);
   if (arr[i] == NULL) {
       /* free previous strings */
   }
   strcpy(arr[i], src);
   ```

   释放：

   ```c
   for (i = 0; i < n; i++) {
       free(arr[i]);
   }
   free(arr);
   ```

   常见任务：

   ```c
   duplicate string array
   sort string array
   append strings
   read strings from file/input
   ```

5. **`void *` and generic arrays**

   `void *` 表示未知类型的数据。

   不能直接做：

   ```c
   arr[i]
   ```

   必须先转换成 `char *`，按字节移动：

   ```c
   char *bytes = arr;
   ```

   第 `i` 个元素地址：

   ```c
   bytes + i * sz
   ```

   复制一个元素：

   ```c
   memcpy(dest, src, sz);
   ```

   比较两个元素：

   ```c
   memcmp(a, b, sz);
   ```

6. **Generic search pattern**

   ```c
   size_t etsi(void *arr, size_t n,
               void *key, size_t m,
               size_t sz);
   ```

   核心结构：

   ```c
   size_t i, j;
   char *a = arr;
   char *k = key;

   for (i = 0; i + m <= n; i++) {
       int found = 1;

       for (j = 0; j < m; j++) {
           if (memcmp(a + (i + j) * sz,
                      k + j * sz,
                      sz) != 0) {
               found = 0;
               break;
           }
       }

       if (found) {
           return i;
       }
   }

   return n;
   ```

7. **Generic sorting**

   通常会给一个 comparator：

   ```c
   int cmp(const void *a, const void *b);
   ```

   通用数组排序时，需要临时空间：

   ```c
   void *tmp = malloc(sz);
   ```

   交换两个元素：

   ```c
   memcpy(tmp, a, sz);
   memcpy(a, b, sz);
   memcpy(b, tmp, sz);
   ```

   通用元素地址：

   ```c
   char *base = arr;

   void *x = base + i * sz;
   void *y = base + j * sz;
   ```

8. **3-way partitioning**

   三路划分常见于 quicksort。

   目标：

   ```
   < pivot | == pivot | > pivot
   ```

   常用变量：

   ```c
   size_t lt = 0;
   size_t i = 0;
   size_t gt = n;
   ```

   结构：

   ```c
   while (i < gt) {
       int c = cmp(base + i * sz, pivot);

       if (c < 0) {
           swap(base + lt * sz, base + i * sz, sz);
           lt++;
           i++;
       } else if (c > 0) {
           gt--;
           swap(base + i * sz, base + gt * sz, sz);
       } else {
           i++;
       }
   }
   ```

   注意：

   ```c
   gt--
   ```

   后不能马上 `i++`，因为换过来的元素还没检查。

9. **Linked list / double list**

   **Node structure**

   ```c
   typedef struct Solmu {
       void *data;
       struct Solmu *next;
       struct Solmu *prev;
   } Solmu;
   ```

   List structure:

   ```c
   typedef struct {
       Solmu *head;
       Solmu *tail;
       size_t dataKoko;
       size_t count;
   } Lista;
   ```

10. **Create node**

    ```c
    Solmu *s = malloc(sizeof(Solmu));
    if (s == NULL) {
        return NULL;
    }

    s->data = malloc(dataKoko);
    if (s->data == NULL) {
        free(s);
        return NULL;
    }

    memcpy(s->data, data, dataKoko);
    s->next = NULL;
    s->prev = NULL;
    ```

11. **Insert at end**

    ```c
    if (lista->tail == NULL) {
        lista->head = s;
        lista->tail = s;
    } else {
        s->prev = lista->tail;
        lista->tail->next = s;
        lista->tail = s;
    }

    lista->count++;
    ```

12. **Remove node**

    需要处理三种情况：

    ```c
    if (s->prev != NULL) {
        s->prev->next = s->next;
    } else {
        lista->head = s->next;
    }

    if (s->next != NULL) {
        s->next->prev = s->prev;
    } else {
        lista->tail = s->prev;
    }

    free(s->data);
    free(s);
    lista->count--;
    ```

13. **File basics**

    **Open file**

    ```c
    FILE *f = fopen("file.txt", "r");
    if (f == NULL) {
        return 1;
    }
    ```

    Close:

    ```c
    fclose(f);
    ```

    Modes:

    ```c
    "r"   read text
    "w"   write text
    "a"   append text
    "rb"  read binary
    "wb"  write binary
    "ab"  append binary
    ```

14. **Text file input/output**

    **Print to file**

    ```c
    fprintf(f, "%d %s\n", n, str);
    ```

    或者逐字符：

    ```c
    fputc(c, f);
    ```

    **Read numbers**

    ```c
    int x;

    while (fscanf(f, "%d", &x) == 1) {
        /* use x */
    }
    ```

    常见结构：

    ```c
    sum += x;
    count++;
    ```

    **Read doubles**

    ```c
    double x;

    while (fscanf(f, "%lf", &x) == 1) {
        /* use x */
    }
    ```

    注意：

    ```c
    scanf("%lf", &double_var);
    printf("%f", double_var);
    ```

15. **Binary file input/output**

    **Write array**

    ```c
    fwrite(arr, sizeof(int), n, f);
    ```

    **Read array**

    ```c
    fread(arr, sizeof(int), n, f);
    ```

    返回值是成功读/写的元素数量：

    ```c
    if (fread(arr, sizeof(int), n, f) != n) {
        /* error */
    }
    ```

16. **File-based array**

    重点是：

    ```c
    array data is stored in a binary file
    read/write elements by index
    ```

    常用函数：

    ```c
    fseek
    ftell
    fread
    fwrite
    ```

    移动到第 `i` 个元素：

    ```c
    fseek(f, i * elem_size, SEEK_SET);
    ```

    读一个元素：

    ```c
    fread(ptr, elem_size, 1, f);
    ```

    写一个元素：

    ```c
    fwrite(ptr, elem_size, 1, f);
    ```

    如果有 header，例如文件开头存长度：

    ```c
    fseek(f, sizeof(size_t) + i * elem_size, SEEK_SET);
    ```

17. **Reading a line of input**

    固定缓冲区：

    ```c
    char buf[100];

    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        /* use buf */
    }
    ```

    去掉换行：

    ```c
    buf[strcspn(buf, "\n")] = '\0';
    ```

    如果要动态读取任意长度：

    ```c
    char *line = NULL;
    size_t size = 0;
    size_t len = 0;
    int c;

    while ((c = fgetc(f)) != EOF && c != '\n') {
        if (len + 1 >= size) {
            size_t new_size = size == 0 ? 16 : size * 2;
            char *tmp = realloc(line, new_size);
            if (tmp == NULL) {
                free(line);
                return NULL;
            }
            line = tmp;
            size = new_size;
        }

        line[len++] = (char)c;
    }

    if (line != NULL) {
        line[len] = '\0';
    }
    ```

18. **Tokenizing a string**

    常见方法：

    ```c
    strtok
    ```

    Example:

    ```c
    char *token;

    token = strtok(str, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    ```

    注意：

    ```c
    strtok modifies the original string
    ```

    所以如果不能改原字符串，要先 copy：

    ```c
    char *copy = malloc(strlen(str) + 1);
    strcpy(copy, str);
    ```

19. **Tidy spaces**

    常见目标：

    ```
    remove extra spaces
    trim beginning and end
    make multiple spaces into one
    ```

    常用两个 index：

    ```c
    size_t read = 0;
    size_t write = 0;
    int in_space = 0;
    ```

    结构：

    ```c
    while (str[read] != '\0') {
        if (isspace((unsigned char)str[read])) {
            if (!in_space && write > 0) {
                str[write++] = ' ';
                in_space = 1;
            }
        } else {
            str[write++] = str[read];
            in_space = 0;
        }
        read++;
    }

    if (write > 0 && str[write - 1] == ' ') {
        write--;
    }

    str[write] = '\0';
    ```

20. **Fibonacci sequence**

    普通版本：

    ```c
    unsigned long a = 0;
    unsigned long b = 1;
    unsigned long next;
    size_t i;

    for (i = 0; i < n; i++) {
        printf("%lu\n", a);
        next = a + b;
        a = b;
        b = next;
    }
    ```

    动态数组版本：

    ```c
    unsigned long *fib = malloc(n * sizeof(unsigned long));
    if (fib == NULL) {
        return NULL;
    }

    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    ```

    注意处理：

    ```c
    n == 0
    n == 1
    ```

21. **Multiplication table**

    动态二维数组通常有两种方式。

    **One block**

    ```c
    int *table = malloc(rows * cols * sizeof(int));
    ```

    访问：

    ```c
    table[i * cols + j]
    ```

    **Array of pointers**

    ```c
    int **table = malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        table[i] = malloc(cols * sizeof(int));
    }
    ```

    释放：

    ```c
    for (i = 0; i < rows; i++) {
        free(table[i]);
    }
    free(table);
    ```

    更推荐 one block，简单、安全。

22. **Currency exchange rates**

    一般结构：

    ```c
    typedef struct {
        char code[4];
        double rate;
    } Rate;
    ```

    读取文件：

    ```c
    while (fscanf(f, "%3s %lf", code, &rate) == 2) {
        /* store or compare */
    }
    ```

    转换：

    ```c
    amount_in_target = amount / from_rate * to_rate;
    ```

    或者如果 rate 是 against EUR：

    ```c
    eur = amount / source_rate;
    target = eur * target_rate;
    ```

23. **Municipality statistics**

    通常会有：

    ```c
    struct Municipality {
        char *name;
        int population;
        double area;
    };
    ```

    常见任务：

    ```c
    read file
    store dynamic array
    calculate total / average / density
    sort by population/name
    print result
    ```

    读取时常见模式：

    ```c
    Municipality *arr = NULL;
    size_t count = 0;
    size_t capacity = 0;
    ```

    扩容：

    ```c
    if (count == capacity) {
        size_t new_capacity = capacity == 0 ? 8 : capacity * 2;
        Municipality *tmp = realloc(arr, new_capacity * sizeof(Municipality));
        if (tmp == NULL) {
            /* free old data */
            return NULL;
        }
        arr = tmp;
        capacity = new_capacity;
    }
    ```

24. **Common error-handling structure**

    最重要的是失败时释放已经申请的内存。

    Example:

    ```c
    char **arr = malloc(n * sizeof(char *));
    if (arr == NULL) {
        return NULL;
    }

    for (i = 0; i < n; i++) {
        arr[i] = malloc(strlen(src[i]) + 1);
        if (arr[i] == NULL) {
            size_t j;

            for (j = 0; j < i; j++) {
                free(arr[j]);
            }

            free(arr);
            return NULL;
        }

        strcpy(arr[i], src[i]);
    }
    ```

25. **Useful headers**

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    ```

    For variadic functions:

    ```c
    #include <stdarg.h>
    ```

    For time:

    ```c
    #include <time.h>
    ```

26. **Checklist before submitting**

    **Memory**

    Check:

    ```c
    malloc result checked?
    realloc uses temporary pointer?
    all allocated memory freed?
    nested allocations freed correctly?
    ```

    Never do:

    ```c
    arr = realloc(arr, new_size);
    ```

    Better:

    ```c
    tmp = realloc(arr, new_size);
    if (tmp == NULL) {
        free(arr);
        return NULL;
    }
    arr = tmp;
    ```

    **Files**

    Check:

    ```c
    fopen result checked?
    fclose called?
    fscanf return value checked?
    fread/fwrite return value checked?
    binary file uses "rb" or "wb"?
    ```

    **Generic functions**

    Check:

    ```c
    void * converted to char *?
    index uses i * sz?
    memcpy used for copy?
    memcmp or comparator used for compare?
    temporary buffer freed?
    ```

    **Strings**

    Check:

    ```c
    strlen(str) + 1
    strcpy after allocation
    '\0' added manually when needed
    fgets newline removed
    strtok modifies original string
    ```

27. **Mental template for solving Part 3 tasks**

    ```
    1. Is the data size known?
       yes -> malloc once
       no  -> use realloc with capacity

    2. Is the data type known?
       yes -> normal typed pointer
       no  -> void * + char * + size

    3. Is data stored in file?
       text file  -> fscanf / fgets / fprintf
       binary file -> fread / fwrite / fseek

    4. Does struct contain pointers?
       yes -> deep copy and custom free function

    5. Does function return allocated memory?
       caller must free it

    6. Can allocation fail?
       write cleanup path
    ```

28. **Most reusable helper functions**

    **Swap generic elements**

    ```c
    int swap(void *a, void *b, size_t sz) {
        void *tmp = malloc(sz);

        if (tmp == NULL) {
            return 0;
        }

        memcpy(tmp, a, sz);
        memcpy(a, b, sz);
        memcpy(b, tmp, sz);

        free(tmp);
        return 1;
    }
    ```

    **Duplicate string**

    ```c
    char *my_strdup(const char *s) {
        char *copy;

        if (s == NULL) {
            return NULL;
        }

        copy = malloc(strlen(s) + 1);
        if (copy == NULL) {
            return NULL;
        }

        strcpy(copy, s);
        return copy;
    }
    ```

    **Free string array**

    ```c
    void free_strings(char **arr, size_t n) {
        size_t i;

        if (arr == NULL) {
            return;
        }

        for (i = 0; i < n; i++) {
            free(arr[i]);
        }

        free(arr);
    }
    ```

    **Dynamic array growth**

    ```c
    int grow_array(void **arr, size_t *cap, size_t elem_size) {
        void *tmp;
        size_t new_cap;

        new_cap = (*cap == 0) ? 8 : (*cap * 2);

        tmp = realloc(*arr, new_cap * elem_size);
        if (tmp == NULL) {
            return 0;
        }

        *arr = tmp;
        *cap = new_cap;
        return 1;
    }
    ```

29. **Summary**

    ```
    malloc creates memory
    free releases memory
    void * makes code generic
    char * lets us move byte by byte
    memcpy copies generic data
    memcmp compares raw bytes
    FILE * connects program to files
    fscanf/fgets read text
    fread/fwrite read binary
    fseek jumps inside files
    struct organizes related data
    linked list stores dynamic elements
    ```

## Common mistakes

-
