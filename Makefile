NAME  = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = 	rm -rf
SRC =	src/so_long.c \
		src/setup.c \
		src/map.c \
		src/assets.c \
		src/display.c \
		src/interactive.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c 


LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

#.c.o: ${CC} ${FLAGS} -I mlx.h -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJ}
			make -C libft
			make -C minilibx
			mv minilibx/libmlx.a .
			${CC} ${FLAGS} -g ${LIBFT} -L. -lmlx -framework OpenGL -framework Appkit ${OBJ} -o $(NAME)
clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}
			make  -C libft/ fclean 
			make  -C minilibx/ clean

re:			fclean all

.PHONY:		all clean fclean re


