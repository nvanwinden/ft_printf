/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 20:42:59 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/28 15:02:31 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_struct_zero_minus(va_list ap, t_struct *arg, const char **str)
{
	if (**str == '0')
	{
		arg->zero = 1;
		while (**str == '0')
			(*str)++;
	}
	if (**str == '-')
	{
		arg->zero = 0;
		arg->minus = 1;
		while (**str == '-')
			(*str)++;
		if (**str == '*')
		{
			arg->width = va_arg(ap, int);
			if (arg->width < 0)
				arg->width = arg->width * -1;
			(*str)++;
		}
	}
}

static void	init_struct_period(va_list ap, t_struct *arg, const char **str)
{
	arg->period = 1;
	(*str)++;
	if (**str == '*')
	{
		arg->precision = va_arg(ap, int);
		if (arg->precision < 0)
		{
			arg->period = 0;
			arg->precision = 0;
		}
		(*str)++;
	}
	else
		arg->precision = get_digit(str);
}

static void	init_struct_asterisk(va_list ap, t_struct *arg, const char **str)
{
	arg->width = va_arg(ap, int);
	if (arg->width < 0)
	{
		arg->width = arg->width * -1;
		arg->minus = 1;
		arg->zero = 0;
	}
	(*str)++;
	if (**str == '.')
		init_struct_period(ap, arg, str);
}

int			parse_flag(va_list ap, const char **str)
{
	t_struct	arg;

	ft_bzero(&arg, sizeof(t_struct));
	if (ft_strchr("cpsdiuxX%", *(*str) + 1))
	{
		arg.noflag = 1;
		return (check_conv(ap, str, &arg));
	}
	while (**str)
	{
		(*str)++;
		if (**str == '0' || **str == '-')
			init_struct_zero_minus(ap, &arg, str);
		if (ft_isdigit(**str))
			arg.width = get_digit(str);
		if (**str == '.')
			init_struct_period(ap, &arg, str);
		if (**str == '*')
			init_struct_asterisk(ap, &arg, str);
		if (ft_strchr("cspdiuxX%", **str))
			return (check_conv(ap, str, &arg));
	}
	return (-1);
}
