/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/10 10:16:41 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/28 10:06:03 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	putnbr_hex(unsigned long n, t_struct *arg)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else if (n >= 10 && n <= 15 && arg->conversion == 'x')
		ft_putchar_fd((5 - (15 - n)) + 97, 1);
	else if (n > 9 && n < 16 && arg->conversion == 'X')
		ft_putchar_fd((5 - (15 - n)) + 65, 1);
	else
	{
		putnbr_hex(n / 16, arg);
		putnbr_hex(n % 16, arg);
	}
}

static int	print_hex(t_struct *arg, unsigned long num, int len)
{
	int count;

	count = 0;
	if (arg->minus == 0)
		count = putchar_len(' ', arg->spaces);
	if (arg->zeros > 0)
		count = putchar_len('0', arg->zeros) + count;
	if (len > 0)
		putnbr_hex(num, arg);
	if (arg->minus == 1)
		count = putchar_len(' ', arg->spaces) + count;
	return (len + count);
}

int			write_hex(va_list ap, t_struct *arg, const char **str)
{
	unsigned long	num;
	int				len;

	(*str)++;
	num = va_arg(ap, unsigned int);
	len = numlen_hex(num);
	if (arg->noflag == 1)
	{
		putnbr_hex(num, arg);
		return (len);
	}
	if (arg->period == 1 && num == 0)
	{
		arg->zeros = arg->precision;
		len = 0;
	}
	if (arg->precision > len)
		arg->zeros = arg->precision - len;
	if (arg->zero == 1 && arg->width > len &&
			arg->period == 0 && arg->minus == 0)
		arg->zeros = arg->width - len;
	if (arg->width > arg->precision)
		arg->spaces = arg->width - arg->zeros - len;
	return (print_hex(arg, num, len));
}
