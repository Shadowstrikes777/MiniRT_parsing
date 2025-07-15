# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 15:54:03 by mmaevani          #+#    #+#              #
#    Updated: 2025/07/15 07:39:55 by mihrakot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux 
RM = rm -f

OBJ_DIR = ./obj/
SRC_DIR = ./src/
INC_DIR = ./includes/
LIBFT = ./libft
MINILIBX = ./minilibx-linux/

# Source files
SRCS = main.c infile_handle.c file_copy.c bigbridge.c \
		nls_parse.c init.c utils.c ambient_parse.c \
		parse.c camera_parse.c parse_coord.c \
		parse_or.c light_parse.c plane_parse.c \
		plane_vect.c plane_coord.c data_clean.c \
		sphere_parse.c spcoord.c cylinder_parse.c \
		cylinder_measures.c cylinder_vector.c add_parse.c \
 		tools.c \
  		vec_00.c normal_vector.c\
		vec_01.c Raytracer.c \
		intersection.c key_input.c\
		camera.c color.c Normale.c\
		inter_rot.c shade.c handle_err.c\

OBJ = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
INCS = minirt.h
IFLAGS = -I$(INC_DIR) -I$(LIBFT)/Includes -I/usr/include -Imlx_linux
LFLAGS = -L$(LIBFT) -lft -L $(MINILIBX) -lmlx -lm -lXext -lX11 -lz
DB_FLAGS = -g3

# Add full path for sources
SRCS := $(addprefix $(SRC_DIR), $(SRCS))

all: $(NAME)

debug: CFLAGS += $(DB_FLAGS)
debug: re

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "\033[1;32mBuilding $@\033[0m\n"
	$(MAKE) -C $(LIBFT) --no-print-directory
	$(MAKE) -C $(MINILIBX) --no-print-directory
	$(CC) -o $@ $(OBJ) $(LFLAGS) $(CFLAGS)
	@echo "\033[1;32mDone ✅\033[0m\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(addprefix $(INC_DIR), $(INCS))
	@echo "\033[1;33mCompiling $<\033[0m\n"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(IFLAGS) -o $@ $<
	@echo "\033[1;33mDone ✅\033[0m\n"

$(OBJ_DIR):
	@echo "\033[1;34mCreating $(OBJ_DIR)\033[0m\n"
	@mkdir -p $(OBJ_DIR)
	@echo "\033[1;34mDone ✅\033[0m\n"

clean:
	@echo "\033[1;31mCleaning object files...\033[0m"
	@$(MAKE) -C $(LIBFT) --no-print-directory clean
	@$(MAKE) -C $(MINILIBX) --no-print-directory clean
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[1;31mDone ✅\033[0m\n"

fclean: clean
	@echo "\033[1;31mFull clean, removing binaries...\033[0m"
	@$(MAKE) -C $(LIBFT) --no-print-directory fclean
	@$(MAKE) -C $(MINILIBX) --no-print-directory clean
	@$(RM) -f $(NAME)
	@echo "\033[1;31mDone ✅\033[0m\n"

re: fclean all

.PHONY: all debug clean fclean re $(OBJ_DIR)
