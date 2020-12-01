/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 10:46:20 by nvan-win      #+#    #+#                 */
/*   Updated: 2020/08/28 10:30:30 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_struct
{
	char			conversion;
	int				len;
	int				negative;
	int				noflag;
	int				zero;
	int				minus;
	int				period;
	int				width;
	int				precision;
	int				spaces;
	int				zeros;
}					t_struct;

int					ft_printf(const char *str, ...);
int					parse_flag(va_list ap, const char **str);
int					check_conv(va_list ap, const char **str, t_struct *arg);
int					putchar_len(char c, int len);
int					get_digit(const char **str);
int					numlen(int num);
int					numlen_hex(unsigned long num);
int					write_char(va_list ap, t_struct *arg, const char **str);
int					write_str(va_list ap, t_struct *arg, const char **str);
int					write_int_dec(va_list ap, t_struct *arg, const char **str);
int					write_uint(va_list ap, t_struct *arg, const char **str);
int					write_hex(va_list ap, t_struct *arg, const char **str);
int					write_ptr(va_list ap, t_struct *arg, const char **s);
int					write_pct(t_struct *arg, const char **str);

#endif
