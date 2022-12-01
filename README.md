# ft_printf
Codam [42 Network] project: the aim of this project is to recode the libc function **printf**.

__Project requirements__:

- The function prototype should be `int ft_printf(const char *, ...);` in which the first parameter is the string that should be written to stdout and the second parameter the variable number of arguments.
- It must not do the buffer management like the real printf
- It will manage the following conversions: `c` `s` `p` `d` `i` `u` `x` `X` `%`
- It will manage any combination of the following flags: `-` `0` `.` `*` and minimum field width with all conversions
- You must use the command `ar` to create your library

__Skills__:

- Rigor
- Algorithms & AI

[Read the full subject]().

## Instructions :clipboard:

### Clone repo

`git clone https://github.com/nvanwinden/ft_printf.git`

### Make

Run `make` to create the `libftprintf.a` library.

### Compile

`gcc libftprintf.a main.c`

### Include ft_printf in your project

```C
#include "includes/ft_printf.h"

int main () {

	int num = 42;

	ft_printf("Hello, %s\n", "World!");
	ft_printf("Now you can go %s use %c bunch of %s\n", "wild", 'a', "format specifiers");
	ft_printf("The address of num is %p\n", &num);
	ft_printf("%-20s%-10d\n", "Left adjusted", num);
	ft_printf( "%s%09d\n","Leading zeros: ", 42);

	return (0);
}
```
