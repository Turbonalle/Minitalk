NAME = libft.a
SRC =	src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c \
		src/ft_isdigit.c src/ft_isprint.c src/ft_itoa.c src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c \
		src/ft_memmove.c src/ft_memset.c src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c \
		src/ft_putstr_fd.c src/ft_split.c src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c \
		src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c src/ft_strncmp.c src/ft_strnstr.c \
		src/ft_strrchr.c src/ft_strtrim.c src/ft_substr.c src/ft_tolower.c src/ft_toupper.c \
		src/ft_lstadd_back.c src/ft_lstadd_front.c src/ft_lstclear.c src/ft_lstdelone.c src/ft_lstiter.c \
		src/ft_lstlast.c src/ft_lstmap.c src/ft_lstnew.c src/ft_lstsize.c \
		ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
OBJECTS =	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
			ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
			ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
			ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o \
			ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o \
			ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o \
			ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o \
			ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o \
			ft_printf.o ft_printf_utils.o
LIBFT_H =	includes/libft.h
PRINTF_H =	includes/ft_printf.h
FLAGS = -Wall -Wextra -Werror

.PHONY: all

all: $(NAME)

$(NAME):
	@cc $(FLAGS) -I $(LIBFT_H) -I $(PRINTF_H) -c $(SRC)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all