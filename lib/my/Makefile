##
## EPITECH PROJECT, 2025
## makfile
## File description:
## used to compile your library
##

SRC     = my_str_to_word_array.c 	\
		  free_array.c				\
		  file_len.c				\
		  get_buffer.c				\
		  my_is_num.c				\
		  push_front.c				\
		  len_array.c				\
		  my_put_nbr.c				\
		  my_strcmp.c				\
		  my_strcat.c				\
		  push_back.c				\
		  my_strn.c					\
		  search_node.c				\
		  compose_str.c				\
		  my_strlen.c				\
		  my_strdup.c				\
		  len_node.c				\
		  node_to_array.c			\
		  my_str_name.c				\
		  directory.c				\
		  my_getnbr.c				\

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

all:	do_print $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
	cp my.h ../../include/

do_print:
	make -C my_printf

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h
	make fclean -C my_printf

re: fclean all
