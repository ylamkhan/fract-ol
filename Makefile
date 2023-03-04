NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = hook.c\
	Mandelbrot.c\
	Julia.c\
	main.c\
	libft.c\
	hook_mandelbrot.c\
	bonus_fractol_puissances_3.c\
	bonus_hook.c\

OBJ = $(SRC:%.c=%.o)

all:$(NAME)

$(NAME):$(OBJ)
		$(CC) $(CFLAGS) $(SRC) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	 $(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re


