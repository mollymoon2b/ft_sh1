NAME = ft_minishell1
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = 
SRC =	main.c 			\
	ft_display_prompt.c \
	ft_dup_environ.c 	\
	ft_exec_bin.c 		\
	ft_exit.c 			\
	ft_get_env.c 		\
	ft_parse_input.c 	\
	ft_fork.c 			\
	ft_cd.c 			\
	ft_unsetenv.c 		\
	ft_setenv.c 		\
	ft_arrows.c 		\
	ft_charmanage.c 	\
	ft_cursor.c 		\
	ft_delete.c 		\
	ft_env.c 			\
	ft_imputs.c 		\
	ft_clean.c 			\
	ft_lstrmanage.c 	\
	ft_managechar.c 	\
	ft_put.c 			\
	ft_moves.c			\
	ft_strasplit.c		\
	ft_free_strarray.c	\
	ft_envtools.c		\
	ft_envtools2.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L ./libft -l ft -L /usr/lib -ltermcap

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 

