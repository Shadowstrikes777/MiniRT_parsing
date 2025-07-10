NAME		= libft.a
CC			= gcc
AR			= ar rcs
RM			= rm -f
RMDIR		= $(RM) -r
CFLAGS		= -Wall -Werror -Wextra -g
INC_DIR		= ./Includes/
SRC_DIR		= ./Sources/
INC_FILES	=	libft.h

SRCS_FILES 	=	ft_calloc.c  \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c    \
				ft_lstadd_back_bonus.c  \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_printf.c \
				ft_ptr.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbrbase.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_atoi.c \
				ft_bzero.c ft_error.c free_utils.c ft_atol.c \

SOURCES = $(addprefix $(SRC_DIR), $(SRCS_FILES))
INCLUDES = $(addprefix $(INC_DIR), $(INC_FILES))
OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
		@$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	@$(CC) -c -I $(INC_DIR) -o $@ $< $(CFLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
