# 42-libft

The first project of the core curriculum of 42 Berlin. 

A comprehensive static library of fundamental C functions, recreated from scratch to understand low-level programming concepts and memory management.

This project serves as the foundation for all subsequent 42 projects, emphasizing memory safety, defensive programming, and understanding the building blocks that make modern software possible. 

## Code Standards (Norminette)

The project follows the Norminette, a strict set of coding rules borrowed from Linux kernel development best practices:

- **Line Length**: Maximum 80 characters per line
- **Function Length**: Maximum 25 lines per function
- **Variable Declaration**: Separate declaration and assignment
- **Braces**: Opening braces on new lines
- **Forbidden Constructs**: No `for` loops (while loops allowed), no `switch` statements
- **Memory Safety**: All allocations must be protected and freed

These constraints teach disciplined coding and prepare students for real-world embedded and system programming.

## Project Structure

The functions are logically organized into categorized directories for better maintainability:

### **`string/`** - String Manipulation (14 functions)
- `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`
- `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup` 
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- `ft_strmapi`, `ft_striteri`

### **`memory/`** - Memory Operations (7 functions)
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_memchr`, `ft_memcmp`, `ft_calloc`

### **`character/`** - Character Classification (7 functions)
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`
- `ft_isprint`, `ft_toupper`, `ft_tolower`

### **`conversion/`** - Type Conversions (6 functions)
- `ft_atoi`, `ft_atol`, `ft_itoa`
- `ft_itox`, `ft_itoxx`, `ft_itoxp` (hexadecimal conversions)

### **`output/`** - File Descriptor Output (4 functions)
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### **`list/`** - Linked List Operations (9 functions)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`
- `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### **`ft_printf/`** - Custom Printf Implementation
- Almost complete printf reimplementation with format specifiers
- Supports: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`

## What I Learned

### Memory Management Fundamentals
- **Pointer Safety**: Never assume pointer validity - always check for NULL before dereferencing
- **Standard Library Quirks**: Recreating stdlib functions reveals their unexpected behaviors (e.g., `strlen(NULL)` crashes by design)
- **Memory Boundaries**: Understanding how functions like `memcpy` vs `memmove` handle overlapping memory regions
- **Allocation Patterns**: Every `malloc()` must have a corresponding `free()`, and `malloc(0)` returns a valid pointer that must be freed

### C Language 
- **Keywords**: Proper use of `const`, `static`, `inline` modifiers
- **Macros vs Functions**: When to use preprocessor macros vs inline functions
- **Function Pointers**: Implementing higher-order functions like `ft_lstmap` and `ft_strmapi`
- **Variadic Functions**: Building `ft_printf` with variable argument lists

## Security Concerns in Common C functions

### The `strncpy` Problem
```c
// DANGEROUS: strncpy doesn't guarantee null-termination
char dest[10];
strncpy(dest, "very long string", 10);  // dest is NOT null-terminated!
printf("%s", dest);  // Buffer overflow when reading past array bounds
```

**Safer Alternative:**
```c
// ft_strlcpy guarantees null-termination and returns string length
size_t len = ft_strlcpy(dest, src, sizeof(dest));
if (len >= sizeof(dest)) {
    // Handle truncation
}
```

### Memory Allocation Failures
```c
// Always guard system calls
char *ptr = malloc(size);
if (!ptr) {
    // Handle allocation failure gracefully
    return (ERROR_CODE);
}
// Use the pointer...
free(ptr);
ptr = NULL;  // Prevent use-after-free
```

**Testing malloc failures:**
```bash
# Limit memory to force malloc failures
ulimit -v 50000  # Limit virtual memory to ~50MB
./your_program   # Test how your program handles allocation failures
```

### Buffer Overflow Prevention
Many standard C functions are inherently unsafe:

- `strcpy()` → Use `ft_strlcpy()`
- `strcat()` → Use `ft_strlcat()`  
- `gets()` → **NEVER USE** (removed from C11)
- `sprintf()` → Use `snprintf()` or bounds-checked alternatives

## The ft_printf Implementation

### Security Advantages Over Standard printf

**Format String Attack Prevention:**
```c
#include  <stdio.h> 
void main(int argc, char **argv)
{
	// This line is safe
	printf("%s\n", argv[1]);

	// This line is vulnerable
	printf(argv[1]);
}

```

**Buffer Overflow Protection:**
- Our `ft_printf` implementation includes careful bounds checking
- All conversions validate input ranges before processing
- Memory allocations for string building are size-controlled

**Supported Format Specifiers:**
- `%c` - Character
- `%s` - String (handles NULL gracefully)
- `%p` - Pointer (with proper 0x prefix)
- `%d`, `%i` - Signed integers
- `%u` - Unsigned integers  
- `%x`, `%X` - Hexadecimal (lowercase/uppercase)
- `%%` - Literal percent sign

### Why Custom Printf Matters
1. **Learning**: Understanding format parsing, variadic arguments, number conversion
2. **Control**: No reliance on external libraries in systems programming
3. **Security**: Can implement additional safety checks beyond standard library
4. **Performance**: Optimized for specific use cases without unused features

## Building the Library

```bash
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove library and objects
make re     # Rebuild everything
make dev    # Build with debug flags (-g)
```

## Usage Example

```c
#include "libft.h"

int main(void)
{
    char    *str;
    t_list  *list;
    
    // Safe string operations
    str = ft_strdup("Hello, 42!");
    if (!str)
        return (1);
        
    ft_printf("String length: %d\n", ft_strlen(str));
    
    
    // Linked list operations
    list = ft_lstnew(str);
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("World!")));
    
    ft_printf("List size: %d\n", ft_lstsize(list));
    
    // Cleanup
    ft_lstclear(&list, free);
    return (0);
}
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -I. your_program.c -L. -lft
```
## References
https://owasp.org/www-community/attacks/Format_string_attack
```

