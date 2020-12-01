/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_int_dec.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 09:06:17 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/28 09:17:13 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_int_dec(t_struct *arg, int num)
{
	int count;

	count = 0;
	if (arg->minus == 0)
		count = putchar_len(' ', arg->spaces);
	if (arg->negative == 1 && num > -2147483648)
	{
		num = num * -1;
		ft_putchar_fd('-', 1);
	}
	else if (num == -2147483648)
		ft_putchar_fd('-', 1);
	if (arg->zeros > 0)
		count = putchar_len('0', arg->zeros) + count;
	if (num == -2147483648)
		ft_putstr_fd("2147483648", 1);
	else if (arg->len > 0)
		ft_putnbr_fd(num, 1);
	if (arg->minus == 1)
		count = putchar_len(' ', arg->spaces) + count;
	return (arg->len + count);
}

int			write_int_dec(va_list ap, t_struct *arg, const char **str)
{
	int		num;

	(*str)++;
	num = va_arg(ap, int);
	if (arg->noflag == 1)
	{
		ft_putnbr_fd(num, 1);
		return (numlen(num));
	}
	arg->len = numlen(num);
	if (num < 0)
		arg->negative = 1;
	if (arg->period == 1 && num == 0)
	{
		arg->zeros = arg->precision;
		arg->len = 0;
	}
	if (arg->precision > (arg->len - arg->negative))
		arg->zeros = arg->precision - arg->len + arg->negative;
	if (arg->zero == 1 && arg->width > arg->len &&
			arg->period == 0 && arg->minus == 0)
		arg->zeros = arg->width - arg->len;
	if (arg->width > arg->precision)
		arg->spaces = arg->width - arg->zeros - arg->len;
	return (print_int_dec(arg, num));
}
