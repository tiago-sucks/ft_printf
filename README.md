*This project has been created as part of the 42 curriculum by tsimao-g*

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

The implementation follows a **linear parsing algorithm** with a **dispatch pattern** for format handling:

#### Core Algorithm: Linear String Parsing

```
1. Initialize va_list to access variadic arguments
2. Initialize character counter (len = 0)
3. FOR each character in format string:
   a. IF character is '%':
      - Advance to next character (specifier)
      - DISPATCH to appropriate handler based on specifier
      - Add returned length to counter
   b. ELSE:
      - Write character directly to stdout
      - Increment counter
4. Cleanup va_list
5. Return total character count
```

#### Performance

**Time**: **Linear scaling** - The algorithm processes each character in the format string exactly once. If you double the input size, the processing time roughly doubles.

**Memory**: **Logarithmic scaling** - The recursive number conversion functions use the call stack. For a number like 1000, the function calls itself 4 times (1000 > 100 > 10 > 1). The memory used grows very slowly compared to the number size.

#### Why This Algorithm?

1. **Single-Pass Efficiency**: The format string is traversed exactly once, minimizing overhead.

2. **Immediate Output**: Characters are written directly via `write()` without intermediate buffering, reducing memory usage.

3. **Recursive Base Conversion**: For `ft_putnbr` and `ft_puthex`, recursion naturally handles digit ordering (most significant first) without requiring:
   - Pre-calculated digit count
   - Temporary buffer allocation
   - String reversal

   Example for number 42 in decimal:
   ```
   ft_putnbr(42) > ft_putnbr(4) > writes '4' > returns > writes '2'
   ```

4. **Dispatch Pattern over Function Pointers**: The `ft_conversion` function uses if-else chains rather than a function pointer table because:
   - Only 9 specifiers exist (minimal performance difference)
   - Simpler to read and debug
   - No initialization overhead
   - Compiler can optimize the comparisons efficiently

### Data Structures

#### 1. `va_list` (Variadic Argument List)

The core data structure enabling variable argument handling:

```c
va_list vargs;
va_start(vargs, str);    // Initialize after last fixed parameter
va_arg(vargs, type);     // Extract next argument with specified type
va_end(vargs);           // Cleanup
```

**Justification**: `va_list` is the only portable way in C to handle functions with unknown argument counts at compile time. It provides sequential access to arguments pushed on the stack.

#### 2. Character Array as Lookup Table

For hexadecimal conversion in `ft_puthex`:

```c
char *base = "0123456789abcdef";  // or uppercase variant
```

**Justification**: Using a string as a lookup table provides instant digit-to-character conversion via direct indexing (`base[remainder]`), avoiding conditional logic for each hex digit.

#### 3. Implicit Stack (Recursion)

The recursive functions use the call stack to:
- Store intermediate division results
- Ensure correct digit ordering (MSB first)
- Handle sign separately before recursion

**Trade-off**: Recursion depth is bounded by the number of digits (max ~20 for 64-bit numbers in decimal), making stack overflow practically impossible for valid inputs.

### Error Handling Strategy

All output functions return `-1` on `write()` failure, propagating errors upward:

```c
if (write(1, &c, 1) == -1)
    return (-1);
```

This ensures `ft_printf` can detect and report I/O errors, matching the behavior of standard `printf()` which returns a negative value on output error.

### Design Decisions Summary

| Decision | Alternative | Justification |
|----------|-------------|---------------|
| Recursive conversion | Iterative with buffer | Simpler code, automatic digit ordering |
| Direct `write()` | Buffered output | Lower memory, simpler implementation |
| If-else dispatch | Function pointer table | Clearer code for small specifier set |
| Return length counting | Void functions | Matches `printf()` specification |

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
