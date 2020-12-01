/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_uint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 20:35:08 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/26 11:06:05 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	numlen_u(unsigned int num)
{
	int		i;

	i = 0;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static void	putnbr_u(unsigned int n)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else
	{
		putnbr_u(n / 10);
		putnbr_u(n % 10);
	}
}

static int	print_u(t_struct *arg, int num, int len)
{
	int count;

	count = 0;
	if (arg->minus == 0)
		count = putchar_len(' ', arg->spaces);
	if (arg->zeros > 0)
		count = putchar_len('0', arg->zeros) + count;
	if (len > 0)
		putnbr_u(num);
	if (arg->minus == 1)
		count = putchar_len(' ', arg->spaces) + count;
	return (len + count);
}

int			write_uint(va_list ap, t_struct *arg, const char **str)
{
	int	num;
	int	len;

	(*str)++;
	num = va_arg(ap, unsigned int);
	len = numlen_u(num);
	if (arg->noflag == 1)
	{
		putnbr_u(num);
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
	return (print_u(arg, num, len));
}
