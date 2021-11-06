CC = gcc

NAME = fdf

SRC = get_next_line.c\
		window.c \
		helper.c \
		main.c \
		operations.c \
		output.c \
		helper1.c \

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): all

all:	linked_objects $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a $(OBJ) -o $(NAME)

linked_objects:
	make -C ./libft
	make -C ./mlx
	gcc $(FLAGS) $(SRC) -c

clean:
	rm -f *.o
	rm -f libft/*.o
	rm -f libft/*.a
	rm -f mlx/*.o
	rm -f mlx/*.a

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
