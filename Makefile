# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/24 10:05:00 by nvan-win      #+#    #+#                  #
#    Updated: 2020/08/28 11:10:34 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
HEADER_FILE = ft_printf.h
INC_DIR = ./includes/
SRC_DIR = ./src/
LIBFT_DIR = ./libft/
REG_OBJ_FILES =		check_conv.o \
					ft_printf.o \
					get_digit.o \
					numlen_hex.o \
					numlen.o \
					parse_flag.o \
					putchar_len.o \
					write_char.o \
					write_hex.o \
					write_int_dec.o \
					write_pct.o \
					write_ptr.o \
					write_str.o \
					write_uint.o \

all: $(NAME)

$(NAME): $(REG_OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.a ./$(NAME)
	ar -rcs $(NAME) $(REG_OBJ_FILES)

%.o: $(SRC_DIR)%.c $(INC_DIR)$(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(REG_OBJ_FILES)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
