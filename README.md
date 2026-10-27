*This project has been created as part of the 42 curriculum by nide-wil.*

# Libft

## Description

**Libft** is a foundational project in the 42 school curriculum. The objective is to re-code a subset of standard C library (`libc`) functions—along with additional utility functions and linked list manipulations—from scratch, adhering strictly to the **42 Norm**.

Since C programmers frequently rely on standard helper functions for string manipulation, memory management, and data structures, creating `libft.a` allows students to build a deep, hands-on understanding of low-level memory handling, pointers, and dynamic data structures. This library serves as a reusable toolbox for many future projects in the 42 C curriculum (such as *get_next_line* and *ft_printf*).

## Technical Features & Library Overview

The compiled static library `libft.a` contains functions categorized into three main sections:

### 1. Libc Functions (Standard C Library Prototypes)

Functions designed to mimic the behavior of standard C library functions (`<string.h>`, `<stdlib.h>`, `<ctype.h>`):

* **Memory Operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

* **String Checks & Conversions:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_atoi`

* **String Manipulation:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`

### 2. Additional Utility Functions

Higher-level helper functions for string allocation, splitting, and output formatting:

* `ft_substr` — Extracts a substring from a string given a starting index and length.

* `ft_strjoin` — Concatenates two strings into a new dynamically allocated string.

* `ft_strtrim` — Trims specified characters from the beginning and end of a string.

* `ft_split` — Splits a string into an array of strings based on a specified delimiter.

* `ft_itoa` — Converts an integer value into a null-terminated string representation.

* `ft_strmapi` — Applies a function to each character of a string to create a new string.

* `ft_striteri` — Applies a function in-place to each character of a string with its index.

* `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd` — Output utility functions to write primitives to a specific file descriptor.

### 3. Linked List Functions

Functions for creating and manipulating singly linked lists using the `t_list` structure:

* `ft_lstnew` — Allocates and initializes a new list element.

* `ft_lstadd_front` — Adds an element to the beginning of a list.

* `ft_lstadd_back` — Adds an element to the end of a list.

* `ft_lstsize` — Counts the number of nodes in a list.

* `ft_lstlast` — Returns the last node of a list.

* `ft_lstdelone` — Deletes and frees a single node using a custom function.

* `ft_lstclear` — Deletes and frees a node and all its successors.

* `ft_lstiter` — Iterates through a list and applies a function to the content of each node.

* `ft_lstmap` — Iterates through a list, applies a function to create a new list, and handles memory errors gracefully.

## Instructions

### Compilation

The project comes with a rule-compliant `Makefile` that compiles all source files (including libc, additional utilities, and linked lists) using `cc` with `-Wall -Wextra -Werror` flags.

To compile the library:

```bash
make
```

### Cleaning Up

* To remove all compiled object files (`.o`):

  ```bash
  make clean
  ```

* To remove object files and the generated library binary (`libft.a`):

  ```bash
  make fclean
  ```

* To re-compile the entire library from scratch:

  ```bash
  make re
  ```

### Usage in Personal Projects

To include `libft.a` in your own C projects:

1. Include the header file in your code:

   ```c
   #include "libft.h"
   ```

2. Compile your C file with `libft.a`:

   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

## Testing

To verify that your functions work correctly, you can save any of the code snippets below into a temporary file (e.g., `test.c`) and compile it alongside your static library:

```bash
cc -Wall -Wextra -Werror test.c -L. -lft -o test
./test
```

Here are categorized examples to test your functions:

### 1. Character Checks (`<ctype.h>`) & Conversions

```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    // ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
    printf("ft_isalpha('A') = %d (attendu: != 0)\n", ft_isalpha('A'));
    printf("ft_isdigit('7') = %d (attendu: != 0)\n", ft_isdigit('7'));
    printf("ft_isalnum('z') = %d (attendu: != 0)\n", ft_isalnum('z'));
    printf("ft_isascii(127) = %d (attendu: != 0)\n", ft_isascii(127));
    printf("ft_isprint(' ') = %d (attendu: != 0)\n", ft_isprint(' '));

    // ft_atoi & ft_itoa
    printf("ft_atoi(\"-4256\") = %d (attendu: -4256)\n", ft_atoi("   -4256"));
    
    char *str = ft_itoa(-1337);
    if (str) {
        printf("ft_itoa(-1337) = %s (attendu: -1337)\n", str);
        free(str);
    }
    return (0);
}
```

### 2. Memory Manipulation

```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    // ft_bzero
    char buf[5] = "AAAA";
    ft_bzero(buf, 3);
    printf("ft_bzero sur \"AAAA\" (3 octets) -> buf[0]: %d, buf[3]: '%c'\n", buf[0], buf[3]);

    // ft_calloc
    int *arr = (int *)ft_calloc(3, sizeof(int));
    if (arr) {
        printf("ft_calloc alloue et initialise : arr[0] = %d, arr[2] = %d\n", arr[0], arr[2]);
        free(arr);
    }
    return (0);
}
```

### 3. Memory Operations & Character Casing

```c
#include <stdio.h>
#include "libft.h"

int main(void)
{
    // ft_toupper & ft_tolower
    printf("ft_toupper('a') = %c (attendu: 'A')\n", ft_toupper('a'));
    printf("ft_tolower('Z') = %c (attendu: 'z')\n", ft_tolower('Z'));

    // ft_memset & ft_memcpy
    char buf[10] = "123456789";
    ft_memset(buf, 'A', 3);
    printf("ft_memset -> %s (attendu: AAA456789)\n", buf);

    char dest[10];
    ft_memcpy(dest, "hello", 6);
    printf("ft_memcpy -> %s (attendu: hello)\n", dest);

    // ft_memchr & ft_memcmp
    char *found = ft_memchr("hello", 'l', 5);
    printf("ft_memchr -> %s (attendu: llo)\n", found ? found : "NULL");
    printf("ft_memcmp = %d (attendu: 0)\n", ft_memcmp("abc", "abc", 3));

    return (0);
}
```

### 4. String & Memory Manipulation

```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    // ft_strlen & ft_strdup
    printf("ft_strlen(\"Hello\") = %zu (attendu: 5)\n", ft_strlen("Hello"));
    char *dup = ft_strdup("42");
    if (dup) {
        printf("ft_strdup(\"42\") = %s\n", dup);
        free(dup);
    }

    // ft_strlcpy & ft_strlcat
    char dst[10] = "Hi";
    ft_strlcpy(dst, "Hello", sizeof(dst));
    printf("ft_strlcpy -> %s (attendu: Hello)\n", dst);
    ft_strlcat(dst, "!", sizeof(dst));
    printf("ft_strlcat -> %s (attendu: Hello!)\n", dst);

    // ft_strchr, ft_strrchr & ft_strnstr
    printf("ft_strchr(\"hello\", 'e') = %s (attendu: ello)\n", ft_strchr("hello", 'e'));
    printf("ft_strrchr(\"hello\", 'l') = %s (attendu: lo)\n", ft_strrchr("hello", 'l'));
    printf("ft_strnstr(\"hello world\", \"world\", 11) = %s (attendu: world)\n", ft_strnstr("hello world", "world", 11));

    // ft_strncmp & ft_memmove
    printf("ft_strncmp(\"abc\", \"abd\", 2) = %d (attendu: 0)\n", ft_strncmp("abc", "abd", 2));
    char mem[10] = "12345";
    ft_memmove(mem + 1, mem, 3);
    printf("ft_memmove -> %s (attendu: 11235)\n", mem);

    return (0);
}
```

### 5. Advanced String Utilities & File Descriptors

```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Fonctions auxiliaires pour mapi et iteri
void iter_func(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32; // Passage en majuscule
}

char mapi_func(unsigned int i, char c)
{
    (void)i;
    return (c + 1);
}

int main(void)
{
    // ft_substr, ft_strjoin, ft_strtrim
    char *sub = ft_substr("Hello World", 0, 5);
    char *join = ft_strjoin("Hello ", "World");
    char *trim = ft_strtrim("xxHelloaxx", "x");
    
    printf("ft_substr = %s (attendu: Hello)\n", sub ? sub : "NULL");
    printf("ft_strjoin = %s (attendu: Hello World)\n", join ? join : "NULL");
    printf("ft_strtrim = %s (attendu: Helloa)\n", trim ? trim : "NULL");
    free(sub); free(join); free(trim);

    // ft_split
    char **tab = ft_split("hello,world,42", ',');
    if (tab) {
        for (int i = 0; tab[i]; i++) {
            printf("ft_split[%d] = %s\n", i, tab[i]);
            free(tab[i]);
        }
        free(tab);
    }

    // ft_strmapi & ft_striteri
    char *mapi = ft_strmapi("abc", mapi_func);
    char str_iter[] = "hello";
    ft_striteri(str_iter, iter_func);
    printf("ft_strmapi = %s (attendu: bcd)\n", mapi ? mapi : "NULL");
    printf("ft_striteri = %s (attendu: HELLO)\n", str_iter);
    free(mapi);

    // File descriptors (_fd) - Écriture sur la sortie standard (fd 1)
    ft_putstr_fd("--- Test _fd functions ---\n", 1);
    ft_putstr_fd("ft_putstr_fd: Hello 42!\n", 1);
    ft_putchar_fd('C', 1);
    ft_putendl_fd(" (ft_putchar_fd + ft_putendl_fd)", 1);
    ft_putstr_fd("ft_putnbr_fd: ", 1);
    ft_putnbr_fd(-42, 1);
    ft_putchar_fd('\n', 1);
    return (0);
}
```

### 6. Linked List Functions

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void del_content(void *content)
{
    free(content);
}

void iter_content(void *content)
{
    printf("[%s] ", (char *)content);
}

void *map_content(void *content)
{
    // Fonction simple pour ft_map : duplique le contenu (ou retourne une modification)
    return (strdup((char *)content));
}

int main(void)
{
    // ft_lstnew, ft_lstadd_front, ft_lstadd_back
    t_list *head = ft_lstnew(strdup("node 1"));
    ft_lstadd_back(&head, ft_lstnew(strdup("node 2")));
    ft_lstadd_front(&head, ft_lstnew(strdup("node 0")));

    // ft_lstsize & ft_lstlast
    printf("ft_lstsize = %d (attendu: 3)\n", ft_lstsize(head));
    
    t_list *last = ft_lstlast(head);
    printf("ft_lstlast content = %s (attendu: node 2)\n", (char *)last->content);

    // ft_lstiter
    printf("ft_lstiter result: ");
    ft_lstiter(head, iter_content);
    printf("\n");

    // ft_lstdelone (test sur un élément isolé)
    t_list *elem_to_del = ft_lstnew(strdup("temp"));
    ft_lstdelone(elem_to_del, del_content);
    printf("ft_lstdelone executed successfully\n");

    // ft_lstmap
    t_list *mapped_list = ft_lstmap(head, map_content, del_content);
    printf("ft_lstmap size = %d (attendu: 3)\n", ft_lstsize(mapped_list));
    ft_lstclear(&mapped_list, del_content);

    // ft_lstclear (sur la liste principale)
    ft_lstclear(&head, del_content);
    printf("ft_lstclear done, head = %p (attendu: (nil))\n", (void *)head);

    return (0);
}

```
## Resources

### References

* [C Standard Library Reference (cppreference.com)](https://en.cppreference.com/w/c) — Detailed specifications for standard C library functions.

* `man` pages — `man 3 memset`, `man 3 memcpy`, `man 3 strlcpy`, etc., directly in the Linux terminal.

### Artificial Intelligence Usage

AI was used solely to assist in writing and formatting this `README.md` file. The code itself was written entirely by hand without AI assistance.
