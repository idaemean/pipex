# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 11:29:11 by iczarnie          #+#    #+#              #
#    Updated: 2022/09/20 20:15:48 by iczarnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c utils.c

CFLAGS = -Wall -Wextra -Werror

LIBFT 	= libft/libft.a

CC = gcc

all: $(NAME)

$(NAME): $(SRC) libft/libft.a
	$(CC) $(SRC) $(CFLAGS) -g libft.a -o $(NAME)

libft/libft.a:
			make -C libft
			cp libft/libft.a .
clean: 
			rm -f $(OBJS)
			cd libft && $(MAKE) clean

fclean: 	clean 
			$(RM) $(NAME) libft.a
			cd libft && $(MAKE) fclean

re:			fclean $(NAME)

.PHONY: all clean fclean re 