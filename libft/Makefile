NAME = libft.a
CC = gcc

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

SRCBONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \


OBJ = $(SRC:%.c=%.o)

OBJBONUS = $(SRCBONUS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): ${OBJ} libft.h
	ar rcs $(NAME) $(OBJ)
	ranlib ${NAME}

clean:
	$(RM) $(OBJ) $(OBJBONUS)
	@echo "OBJ deleted"
	$(RM) bonus

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) deleted"

bonus:  $(OBJ) $(OBJBONUS)
		@ar rcs $(NAME) $(OBJ) $(OBJBONUS)
		ranlib ${NAME}
		touch bonus

re: fclean all


.PHONY: all clean fclean re bonus

