/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_digit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 12:09:28 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/26 12:09:32 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_digit(const char **str)
{
	int	ret;

	ret = 0;
	while (ft_isdigit(**str))
	{
		ret = (ret * 10) + (**str - '0');
		(*str)++;
	}
	return (ret);
}
