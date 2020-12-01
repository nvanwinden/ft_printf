/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_conv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 18:30:49 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/28 10:27:03 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_conv(va_list ap, const char **str, t_struct *arg)
{
	if (**str == 'c')
		return (write_char(ap, arg, str));
	else if (**str == 's')
		return (write_str(ap, arg, str));
	else if (**str == 'p')
		return (write_ptr(ap, arg, str));
	else if (**str == 'i' || **str == 'd')
		return (write_int_dec(ap, arg, str));
	else if (**str == 'u')
		return (write_uint(ap, arg, str));
	else if (**str == 'x' || **str == 'X')
	{
		arg->conversion = **str;
		return (write_hex(ap, arg, str));
	}
	else if (**str == '%')
		return (write_pct(arg, str));
	else
		return (-1);
}
