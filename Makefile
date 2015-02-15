NAME = ft_minishell1
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = 
SRC =	srcs/core/main.c 			\
	srcs/core/ft_display_prompt.c \
	srcs/core/ft_dup_environ.c 	\
	srcs/core/ft_exec_bin.c 		\
	srcs/core/ft_exit.c 			\
	srcs/core/ft_get_env.c 		\
	srcs/core/ft_parse_input.c 	\
	srcs/core/ft_cd.c 			\
	srcs/core/ft_unsetenv.c 		\
	srcs/core/ft_setenv.c 		\
	srcs/inputs/ft_arrows.c 		\
	srcs/inputs/ft_arrows2.c 		\
	srcs/inputs/ft_special.c		\
	srcs/inputs/ft_charmanage.c 	\
	srcs/inputs/ft_cursor.c 		\
	srcs/inputs/ft_delete.c 		\
	srcs/inputs/ft_env.c 			\
	srcs/inputs/ft_imputs.c 		\
	srcs/inputs/ft_clean.c 			\
	srcs/inputs/ft_lstrmanage.c 	\
	srcs/inputs/ft_managechar.c 	\
	srcs/inputs/ft_put.c 			\
	srcs/inputs/ft_moves.c			\
	srcs/inputs/ft_free_strarray.c	\
	srcs/inputs/ft_envtools.c		\
	srcs/inputs/ft_envtools2.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	make -C includes/libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L ./includes/libft -l ft -L /usr/lib -ltermcap

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 

