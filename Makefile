NAME  = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = 	rm -rf
SRC =	src/so_long.c \
		src/setup.c \
		src/map.c \
		src/map_validator.c \
		src/assets.c \
		src/display.c \
		src/interactive.c \
		src/errors.c \
		src/destroy.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c 


LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

%.o:%.c
		${CC} ${CFLAGS} -I minilibx/ -I libft/ -c $< -o $@

all: makelibs	${NAME}

makelibs : 
			make -C libft
			make -C minilibx

${NAME}:	${OBJ} so_long.h
			${CC} ${CFLAGS} -g -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework Appkit ${OBJ} -o $(NAME)
clean:
			${RM} ${OBJ}
			make clean -C libft 
			make clean -C minilibx

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft 			

re:			fclean all

.PHONY:		all clean fclean re makelibs
 

