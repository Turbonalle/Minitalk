SHELL = /bin/bash
EXE_S = server
EXE_C = client
SRC_S = server.c
SRC_C = client.c
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror
LIBFLAGS = -Lft_printf -lftprintf

.PHONY: all run clean fclean re

all: $(EXE_S) $(EXE_C)
	@$(MAKE) -C ./ft_printf
$(EXE_S): server.o
	@cc $(FLAGS) $(SRC_S) -o $(EXE_S) $(LIBFLAGS)
	@echo "Server compiled!"
$(EXE_C): client.o
	@cc $(FLAGS) $(SRC_C) -o $(EXE_C) $(LIBFLAGS)
	@echo "Client compiled!"

clean: $(OBJECTS)
	@$(MAKE) clean -C ./ft_printf
	@rm -f $(OBJECTS)
	@echo "Object files removed!"

fclean: clean
	@$(MAKE) fclean -C ./ft_printf
	@rm -f $(EXE_S) $(EXE_C)
	@echo "Executables removed!"

re: fclean all