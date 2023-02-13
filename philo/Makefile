# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:00:48 by tcasale           #+#    #+#              #
#    Updated: 2023/02/10 10:33:38 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= $(wildcard srcs/*.c)

OBJS		= $(SRCS:.c=.o)

HEADER		= includes

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

all :		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
			$(CC) $(OBJS) -o $(NAME)

sanitize : $(OBJS)
			$(CC) $(OBJS) -fsanitize=thread -o $(NAME)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
