.PHONY : all clean fclean re

NAME = so_long
FLAGS = -Wall -Wextra -Werror -g

MLX = mlx/libmlx.a
GNL = gnl/gnl.a

SRC =  main.c free.c check_arg.c read_map.c check_map.c is_valid_path.c\
	   display_image.c key_hook.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(MLX) $(GNL) $(OBJ) 
	gcc $(FLAGS) $(OBJ) $(GNL) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

$(OBJ): %.o: %.c inc/so_long.h
	gcc $(FLAGS) -c $< -o $@

$(MLX):
	make -C mlx

$(GNL):
	make -C gnl

clean:
	make -C gnl clean
	make -C mlx clean
	rm -f *.o

fclean: clean
	make -C gnl fclean
	rm -f $(NAME)

re: fclean all



