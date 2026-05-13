##
## EPITECH PROJECT, 2025
## my_printf
## File description:
## Makefile
##

SRC =	src/main.c						\
		src/op.c						\
		src/flags/check_flag.c			\
		src/flags/prog_nb.c				\
		src/flags/prog_a.c				\
		src/flags/help.c				\
		src/flags/nbr_cycles.c			\
		src/initialisation/init.c		\
		src/file_management/get_file.c	\
		src/robots/init_robot.c			\
		src/parsing.c					\

OBJ = 	$(SRC:.c=.o)

NAME =	corewar

all:	$(NAME)

$(NAME): do_lib $(OBJ)
	epiclang -o $(NAME) $(SRC) -lmy -Llib lib/my/my_printf/libmy.a

do_lib:
	make -C lib/my/

clean:
	@rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	@rm -f $(NAME)

re:	fclean all
