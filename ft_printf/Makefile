# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 15:38:14 by damoncad          #+#    #+#              #
#    Updated: 2024/02/09 15:50:08 by damoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MANDATORY_SRCS = ft_printf.c print_hex.c print_ptr.c print_str.c print_digit.c un_digit.c
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
HEADER = ft_printf.h
all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	ar rc ${NAME} ${MANDATORY_OBJS}
	ranlib ${NAME}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $< -o $@
clean:
	rm -f ${MANDATORY_OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all
.PHONY: all clean fclean re bonus