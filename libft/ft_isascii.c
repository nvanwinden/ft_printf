/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/18 15:50:55 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/05/08 13:28:26 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 000 && c <= 0177)
		return (1);
	else
		return (0);
}
