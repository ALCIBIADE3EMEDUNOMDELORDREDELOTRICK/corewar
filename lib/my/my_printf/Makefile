##
## EPITECH PROJECT, 2025
## my_printf
## File description:
## Makefile
##

SRC = 	my_printf.c \
        conversion_specifiers/flags.c \
        conversion_specifiers/float.c \
        conversion_specifiers/my_put_add.c \
        conversion_specifiers/my_put_nbr.c \
        conversion_specifiers/my_put_unsigned_dec.c \
        conversion_specifiers/my_putchar.c \
        conversion_specifiers/my_putnbr_base.c \
        conversion_specifiers/my_putstr.c \
        conversion_specifiers/my_strlen.c \
        conversion_specifiers/notation_e.c \
        conversion_specifiers/my_nbrlen_base.c \
        lenght_modifier/my_putnbr_base_long.c \
		lenght_modifier/my_putnbr_base_long_long.c \
		lenght_modifier/my_putnbr_base_short.c \
		lenght_modifier/my_putnbr_base_short_short.c \
        lenght_modifier/flag_h.c \
        lenght_modifier/flag_l.c \
        lenght_modifier/flag_q.c

TEST_SRC = tests/test_printf.c \

OBJ = 	$(SRC:.c=.o)

NAME =	libmy.a

TEST_NAME = unit_tests

all:	$(NAME)

%.o: %.c
	@epiclang -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@rm -f *.gc*

re:	fclean all

unit_tests:	all
	@epiclang -o $(TEST_NAME) $(TEST_SRC) $(SRC) -L./ -lmy --coverage -lcriterion -lgcov

tests_run: unit_tests
	@./$(TEST_NAME)
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/
