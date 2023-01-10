# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:00:48 by tcasale           #+#    #+#              #
#    Updated: 2023/01/10 15:17:20 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosopher

SRCS		= $(wildcard srcs/*.c)

OBJS		= $(SRCS:.c=.o)

HEADER		= includes

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

all :		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :
			$(CC) $(OBJS) -o $(NAME)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
