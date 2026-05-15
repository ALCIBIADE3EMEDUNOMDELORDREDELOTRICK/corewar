##
## EPITECH PROJECT, 2025
## my_printf
## File description:
## Makefile
##

SRC =	src/main.c						\
		src/free/free_all.c				\
		src/op.c						\
		src/flags/check_flag.c			\
		src/flags/prog_nb.c				\
		src/flags/prog_a.c				\
		src/loop/main_loop.c			\
		src/flags/help.c				\
		src/flags/nbr_cycles.c			\
		src/initialisation/init.c		\
		src/dump/dump.c					\
		src/dump/win.c					\
		src/file_management/get_file.c	\
		src/robots/init_robot.c			\
		src/action/cycle_action.c		\
		src/action/die_cycle.c			\
		src/action/live.c				\
		src/action/add.c				\
		src/action/and.c				\
		src/action/ld.c					\
		src/action/fork.c				\
		src/action/ldi.c				\
		src/action/lfork.c				\
		src/action/lld.c				\
		src/action/lldi.c				\
		src/action/my_xor.c				\
		src/action/or.c					\
		src/action/print.c				\
		src/action/st.c					\
		src/action/sti.c				\
		src/action/sub.c				\
		src/action/zjmp.c				\
		src/action/tools.c				\
		src/robots/sort.c				\

SRC_BONUS =	src/main.c						\
		src/free/free_all.c				\
		src/op.c						\
		src/flags/check_flag.c			\
		src/flags/prog_nb.c				\
		src/flags/prog_a.c				\
		src/loop/main_loop.c			\
		src/flags/help.c				\
		src/flags/nbr_cycles.c			\
		src/initialisation/init.c		\
		bonus/dump_bonus.c					\
		bonus/robot_draw.c					\
		bonus/arena_bonus.c					\
		bonus/text.c					\
		src/dump/win.c					\
		src/file_management/get_file.c	\
		src/robots/init_robot.c			\

OBJ = 	$(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME =	corewar

all:	$(NAME)

$(NAME): do_lib $(OBJ)
	epiclang -o $(NAME) $(SRC) -lmy -Llib lib/my/my_printf/libmy.a

do_lib:
	make -C lib/my/

bonus: do_lib $(OBJ_BONUS)
	epiclang -o $(NAME) $(SRC_BONUS) -lmy -Llib lib/my/my_printf/libmy.a -lcsfml-graphics -lcsfml-window -lcsfml-system

clean:
	@rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	@rm -f $(OBJ_BONUS)
	@rm -f $(NAME)

re:	fclean all
