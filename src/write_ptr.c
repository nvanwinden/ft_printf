/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 21:44:01 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/28 09:17:09 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	putnbr_ptr(unsigned long n)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else if (n >= 10 && n <= 15)
		ft_putchar_fd((5 - (15 - n)) + 97, 1);
	else
	{
		putnbr_ptr(n / 16);
		putnbr_ptr(n % 16);
	}
}

static int	print_ptr(t_struct *arg, unsigned long num, int len)
{
	int count;

	count = 0;
	if (arg->minus == 0)
		count = putchar_len(' ', arg->spaces);
	ft_putstr_fd("0x", 1);
	if (arg->zeros > 0)
		count = putchar_len('0', arg->zeros) + count;
	if (len > 0)
		putnbr_ptr(num);
	if (arg->minus == 1)
		count = putchar_len(' ', arg->spaces) + count;
	return (len + count + 2);
}

int			write_ptr(va_list ap, t_struct *arg, const char **str)
{
	unsigned long	num;
	int				len;

	(*str)++;
	num = va_arg(ap, unsigned long);
	len = numlen_hex(num);
	if (arg->noflag == 1)
	{
		ft_putstr_fd("0x", 1);
		putnbr_ptr(num);
		return (len + 2);
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
		arg->zeros = arg->width - len - 2;
	if (arg->width > arg->precision)
		arg->spaces = arg->width - arg->zeros - len - 2;
	return (print_ptr(arg, num, len));
}
