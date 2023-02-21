NAME = libftprintf.a
EXE = exe.out
SRC = ft_printf.c ft_printf_utils.c
OBJECTS = *.o
HEADER = ft_printf.h
FLAGS = -Wall -Wextra -Werror

.PHONY: all run clean fclean re

all: $(NAME)

$(NAME):
	@$(MAKE) -C ../libft
	@cp ../libft/libft.a $(NAME)
	@cc $(FLAGS) -I $(HEADER) -c $(SRC)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Ft_printf:	Compiled!"

clean:
	@$(MAKE) clean -C ../libft
	@rm -f $(OBJECTS)
	@echo "Ft_printf:	Object files removed!"

fclean: clean
	@$(MAKE) fclean -C ../libft
	@rm -f $(NAME) $(EXE)
	@echo "Ft_printf:	Library removed!"

re: fclean all