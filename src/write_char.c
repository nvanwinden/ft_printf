/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/17 13:38:55 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/24 11:43:45 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			write_char(va_list ap, t_struct *arg, const char **str)
{
	char	ch;
	int		count;

	(*str)++;
	ch = va_arg(ap, int);
	count = 0;
	if (arg->noflag == 1)
	{
		ft_putchar_fd(ch, 1);
		return (1);
	}
	if (arg->width > 1)
		arg->spaces = arg->width - 1;
	if (arg->zero == 1)
		arg->zeros = arg->width - 1;
	if (arg->minus == 0 && arg->zero == 0)
		count = putchar_len(' ', arg->spaces);
	else if (arg->zeros > 0)
		count = putchar_len('0', arg->zeros) + count;
	ft_putchar_fd(ch, 1);
	if (arg->minus == 1)
		count = putchar_len(' ', arg->spaces);
	return (count + 1);
}
