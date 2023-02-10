SHELL = /bin/bash
NAME = minitalk
EXE_S = server
EXE_C = client
SRC_S = server.c
SRC_C = client.c
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror

.PHONY: all run clean fclean re

all: $(NAME)

$(NAME):
	$(MAKE) -C ./ft_printf
	cc $(FLAGS) $(SRC_S) -o $(EXE_S) -I -Lft_printf -lftprintf
	echo "Minitalk:	Server compiled!"
	cc $(FLAGS) $(SRC_C) -o $(EXE_C) -I -Lft_printf -lftprintf
	echo "Minitalk:	Client compiled!"

clean:
	clear
	@$(MAKE) clean -C ./ft_printf
	@rm -f $(OBJECTS)
	@echo "Minitalk:	Object files removed!"

fclean: clean
	@$(MAKE) fclean -C ./ft_printf
	@rm -f $(EXE_S) $(EXE_C)
	@echo "Minitalk:	Executables removed!"

re: fclean all