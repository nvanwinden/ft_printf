/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 19:20:37 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/26 13:07:09 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	putstr_len(char *s, int len)
{
	int count;

	count = 0;
	while (len > 0)
	{
		ft_putchar_fd(*s, 1);
		len--;
		s++;
		count++;
	}
	return (count);
}

static int	print_str(char *str, t_struct *arg, int len)
{
	int count;

	count = 0;
	if (arg->minus == 0 && arg->zero == 0)
		count = putchar_len(' ', arg->spaces);
	else if (arg->zero == 1)
		count = putchar_len('0', arg->spaces) + count;
	putstr_len(str, len);
	if (arg->minus == 1)
		count = putchar_len(' ', arg->spaces) + count;
	return (count) + len;
}

int			write_str(va_list ap, t_struct *arg, const char **s)
{
	char	*str;
	int		len;

	(*s)++;
	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (arg->noflag == 1)
		return (putstr_len(str, len));
	if (arg->period == 1 && arg->precision < len)
		len = arg->precision;
	if (arg->width >= len)
	{
		if (arg->period == 1)
			arg->spaces = arg->width - len;
		else
			arg->spaces = arg->width - arg->precision - len;
	}
	return (print_str(str, arg, len));
}
