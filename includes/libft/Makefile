# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #\

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE =
SRC =	ft_memset.c				\
		ft_bzero.c				\
		ft_isalnum.c 			\
		ft_isalpha.c 			\
		ft_isascii.c 			\
		ft_isdigit.c 			\
		ft_isprint.c 			\
		ft_memcpy.c				\
		ft_memccpy.c			\
		ft_memmove.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memset.c 			\
		ft_memset.c 			\
		ft_strlen.c				\
		ft_strdup.c				\
		ft_strcpy.c				\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strncat.c			\
		ft_strstr.c				\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_putendl.c 			\
		ft_putendl_fd.c 		\
		ft_putnbr.c 			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_strchr.c				\
		ft_memalloc.c			\
		ft_memdel.c 			\
		ft_strnew.c 			\
		ft_strdel.c 			\
		ft_strclr.c 			\
		ft_striter.c 			\
		ft_striteri.c 			\
		ft_strmap.c 			\
		ft_strmapi.c 			\
		ft_strequ.c 			\
		ft_strsub.c 			\
		ft_strnequ.c 			\
		ft_strlcat.c 			\
		ft_strjoin.c 			\
		ft_strrchr.c 			\
		ft_strnstr.c 			\
		ft_putnbr_fd.c 			\
		ft_strtrim.c 			\
		ft_isspace.c 			\
		ft_atoi.c 				\
		ft_strsplit.c 			\
		ft_itoa.c 				\
		ft_lstnew.c 			\
		ft_lstdelone.c 			\
		ft_strtoupper.c 		\
		ft_strtolower.c 		\
		ft_strdel_double_sp.c 	\
		ft_strdup_tabtosp.c     \
		ft_strndup.c 			\
		ft_char_to_inc.c 		\
		ft_strasplit.c 			\
		ft_strsplitint.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re