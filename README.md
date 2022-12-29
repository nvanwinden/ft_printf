# ft_printf

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

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

[Read the full subject](https://github.com/nvanwinden/ft_printf/blob/main/en.subject.pdf).

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
	ft_printf("Now you can %s %c bunch of %s\n", "use", 'a', "format specifiers");
	ft_printf("The address of num is %p\n", &num);
	ft_printf( "%s%09d\n","Leading zeros: ", 42);
	ft_printf("Precision 42: |%42s|\n", "Fortytwo");
	ft_printf("Lowercase 42 hex: %x\n", 42);
	ft_printf("Uppercase 42 hex: %X\n", 42);
	ft_printf("Minimum length, left-justified: |%-10s|\n", "Hello");
	ft_printf("A string with a minimum length: |%10s|\n", "Hello");
	ft_printf("An asterisk to specify minimum length: |%*s|\n", 10, "Hello");

	return (0);
}
```
#### Output

```
Hello, World!
Now you can use a bunch of format specifiers
The address of num is 0x7ff7bd543588
Leading zeros: 000000042
Precision 42: |                                  Fortytwo|
Lowercase 42 hex: 2a
Uppercase 42 hex: 2A
Minimum length, left-justified: |Hello     |
A string with a minimum length: |     Hello|
An asterisk to specify minimum length: |     Hello|
```
