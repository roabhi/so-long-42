NAME  = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = 	rm -rf
MLXFLAGS = -L ./mlx/ -lmlx -framework OpenGL -framework Appkit -lz

SRC = src/so_long.c

LIBFT = libft/libft.a
OBJ = ${SRC:%.c=%.o}

all:	${NAME}

${NAME}:	${OBJ}
			make -C libft
			${CC} ${SRC} ${LIBFT} ${MXFLAGS} ${FLAGS} -o ${NAME}

%o:			%.c
			${CC} ${FLAGS} -Imlx -c $< -o $@

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re
