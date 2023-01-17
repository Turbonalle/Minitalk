SHELL = /bin/bash
EXE_S = server
EXE_C = client
SRC_S = server.c
SRC_C = client.c
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror -g

.PHONY: all run clean fclean re

all:
	@cc $(FLAGS) $(SRC_S) -o $(EXE_S)
	@echo "Server compiled!"
	@cc $(FLAGS) $(SRC_C) -o $(EXE_C)
	@echo "Client compiled!"

clean: $(OBJECTS)
	@rm -f $(OBJECTS)
	@echo "Object files removed!"

fclean: clean
	@rm -f $(EXE_S) $(EXE_C)
	@echo "Executables removed!"

re: fclean all