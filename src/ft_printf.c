/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 22:50:41 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/29 16:33:23 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ret = 0;
	while (*str)
	{
		if (*str == '%')
			ret = parse_flag(ap, &str) + ret;
		else
		{
			ft_putchar_fd(*str, 1);
			ret++;
			str++;
		}
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
	}
	va_end(ap);
	return (ret);
}
