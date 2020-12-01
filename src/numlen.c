/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   numlen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 10:08:14 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/19 09:43:48 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		numlen(int num)
{
	int		i;

	i = 0;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}
