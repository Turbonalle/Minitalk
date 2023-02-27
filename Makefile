NAME = both
SHELL = /bin/bash
EXE_S = server
EXE_C = client
SRC_S = server.c
SRC_C = client.c
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror
LIBFLAGS = -Llibft -lft

.PHONY: all run clean fclean re

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(EXE_S) $(EXE_C)

$(EXE_S): server.o
	@$(MAKE) -C ./libft
	@cc $(FLAGS) $(SRC_S) -o $(EXE_S) $(LIBFLAGS)
	@echo "Server compiled!"
$(EXE_C): client.o
	@$(MAKE) -C ./libft
	@cc $(FLAGS) $(SRC_C) -o $(EXE_C) $(LIBFLAGS)
	@echo "Client compiled!"

clean: $(OBJECTS)
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJECTS)
	@echo "Object files removed!"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(EXE_S) $(EXE_C)
	@echo "Executables removed!"

re: fclean all