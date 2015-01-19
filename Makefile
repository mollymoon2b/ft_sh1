NAME = abruti
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = 
SRC			=	main.c \
				ft_count_arg.c \
				ft_display_prompt.c \
				ft_dup_environ.c \
				ft_exec_bin.c \
				ft_exit.c \
				ft_get_envhome.c \
				ft_get_envoldpwd.c \
				ft_get_envpath.c \
				ft_get_envpwd.c \
				ft_get_pwd.c \
				ft_print_environ.c \
				ft_parse_input.c \
				ft_fork.c 		\
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

