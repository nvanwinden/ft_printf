/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   numlen_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 12:28:57 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/14 12:30:45 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	numlen_hex(unsigned long num)
{
	int		i;

	i = 0;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}
