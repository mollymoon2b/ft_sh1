NAME = abruti
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = 
SRC			=	main.c 				\
				ft_display_prompt.c \
				ft_dup_environ.c 	\
				ft_exec_bin.c 		\
				ft_exit.c 			\
				ft_get_env.c 		\
				ft_parse_input.c 	\
				ft_fork.c 			\
				get_next_line.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L libft -lft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 

