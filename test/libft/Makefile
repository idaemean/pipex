# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 11:26:33 by iczarnie          #+#    #+#              #
#    Updated: 2021/11/25 11:26:33 by iczarnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_strtrim.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_memcpy.c \
		ft_split.c 

BS_SRC 	=	ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

BS_OBJS	=	$(BS_SRC:.c=.o)

OBJS 	= 	$(SRCS:.c=.o)

NAME 	= libft.a 

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

RM 		= rm -f

all: 	$(NAME)

$(NAME):	 $(OBJS)
				ar rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS) $(BS_OBJS)

fclean: 	clean 
				$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS) $(BS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BS_OBJS)

# so:
# 	$(CC) -nostartfiles -fPIC $(FLAGS) -c $(SRCS)
# 	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re bonus