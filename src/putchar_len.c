/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   putchar_len.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 09:43:24 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/24 11:52:02 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		putchar_len(char c, int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		ft_putchar_fd(c, 1);
		len--;
		count++;
	}
	return (count);
}
