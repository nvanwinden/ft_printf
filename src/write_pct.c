/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_pct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/13 18:28:12 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/26 12:00:54 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			write_pct(t_struct *arg, const char **str)
{
	int		count;

	count = 0;
	(*str)++;
	if (arg->noflag == 1)
	{
		ft_putchar_fd('%', 1);
		return (count + 1);
	}
	if (arg->width > 1)
		arg->spaces = arg->width - 1;
	if (arg->zero == 1)
		arg->zeros = arg->width - 1;
	if (arg->minus == 0 && arg->zero == 0)
		count = putchar_len(' ', arg->spaces);
	else if (arg->zeros > 0)
		count = putchar_len('0', arg->zeros) + count;
	ft_putchar_fd('%', 1);
	if (arg->minus == 1)
		count = putchar_len(' ', arg->spaces);
	return (count + 1);
}
