# ft_printf

## Description

**ft_printf** is a project that recreates the standard C library function `printf()`. This project is part of the 42 curriculum and aims to understand variadic functions, string parsing, and formatted output in C.

The goal is to implement a custom version of `printf()` that handles  format specifiers and produces formatted output to the standard output stream. This project reinforces knowledge of:
- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- String parsing and manipulation
- Type conversion and formatting
- Memory management
- Modular programming

The implementation must handle multiple conversion specifiers (c, s, p, d, i, u, x, X, %) and return the total number of characters printed, mirroring the behavior of the original `printf()`.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will generate the `libftprintf.a` static library.

### Available Make Rules

- `make` or `make all` - Compiles the library
- `make clean` - Removes object files
- `make fclean` - Removes object files and the library
- `make re` - Recompiles the entire library from scratch

### Usage

Include the header in your C file:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    count = ft_printf("Hello, %s!\n", "world");
    ft_printf("Characters printed: %d\n", count);
    
    ft_printf("Number: %d, Hex: %x, Pointer: %p\n", 42, 255, &count);
    
    return (0);
}
```

### Supported Format Specifiers

- `%c` - Prints a single character;
- `%s` - Prints a string;
- `%p` - Prints a pointer address in hexadecimal format;
- `%d` - Prints a decimal (base 10) number;
- `%i` - Prints an integer in base 10;
- `%u` - Prints an unsigned decimal number;
- `%x` - Prints a number in hexadecimal (lowercase);
- `%X` - Prints a number in hexadecimal (uppercase);
- `%%` - Prints a percent sign;

## Algorithm and Data Structure

### Algorithm Choice

The implementation follows a **state machine parsing approach** with modular handler functions:

1. **String Traversal**: Iterate through the format string character by character
2. **Format Detection**: When a `%` is encountered, enter format specifier parsing mode
3. **Specifier Dispatch**: Based on the character following `%`, call the appropriate handler function
4. **Character Counting**: Track and return the total number of characters printed

This approach was chosen because:
- **Simplicity**: Easy to understand and maintain
- **Modularity**: Each format specifier has its own handler function, making the code modular and testable
- **Efficiency**: Single pass through the format string with O(n) time complexity
- **Extensibility**: New format specifiers can be added by creating new handler functions

### Data Structure

The implementation primarily uses:

**Variadic Function Mechanism** (`va_list`):
- A `va_list` variable stores the state needed to traverse variable arguments
- Used to retrieve arguments dynamically based on format specifiers
- Essential for handling an unknown number of arguments at compile time

**Character Buffer Strategy**:
- Direct output using `write()` system call for individual characters or strings
- No intermediate buffering for simplicity (though this could be optimized with a buffer)
- Each handler function returns the number of characters written

**Function Pointer Alternative** (optional optimization):
- Could implement a lookup table mapping format characters to handler functions
- Would replace the if-else chain with array indexing for O(1) specifier lookup
- Trade-off: Slightly more complex initialization for marginal performance gain

The chosen structure prioritizes **code clarity and correctness** over premature optimization, as the performance difference is negligible for typical use cases. The modular function design makes testing and debugging straightforward, which is critical for this foundational project.

## Resources

### Documentation
- [printf - Linux Manual Page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions - GNU C Library](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [stdarg.h - C Standard Library](https://en.cppreference.com/w/c/variadic)

### Tutorials
- [Understanding printf](https://www.cprogramming.com/tutorial/printf-format-strings.html)
- [Variadic Functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/)

### AI Usage

AI assistance was used in the following ways during this project:

**Tasks Assisted by AI:**
- **Algorithm Research**: Exploring different parsing strategies and their trade-offs
- **Debugging Support**: Identifying edge cases and potential bugs in format specifier handling
- **Code Review**: Validating the logic of conversion functions (especially hexadecimal and pointer formatting)
- **Documentation**: Structuring this README and explaining technical concepts clearly

**Parts of the Project Using AI:**
- **Research Phase**: Understanding variadic functions and printf internals
- **Testing Strategy**: Designing comprehensive test cases for edge cases (NULL pointers, maximum values, etc.)
- **Documentation**: Writing clear explanations of algorithm choices and formatting this README

**Parts Developed Without AI:**
- **Core Implementation**: All source code was written manually
- **Logic Design**: The overall architecture and function design decisions were made independently
- **Testing**: Manual testing and verification of output against original printf

AI was used as a learning tool and documentation aid, not as a code generator. All implementation decisions and actual code were produced through personal understanding and problem-solving.