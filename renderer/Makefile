
NAME=miniRT

SRC= src/root.c \
 	src/tools.c \
  src/vector.c src/normal_vector.c\
	src/vector2.c src/ray_tracing.c \
	 src/intersection.c src/mlx_func.c\
	src/camera.c src/color.c src/surface_normale.c\
	src/world.c src/shading.c \
	
OBJ = ${SRC:.c=.o}

CC = gcc

%.o: %.c
	make -C mlx_linux
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@

all : ${NAME}

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	make -C mlx_linux clean
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re