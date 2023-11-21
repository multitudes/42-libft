CFLAGS=-Wall -Wextra -Werror

# part 1 - 23 functions
# part 2 - 11 functions
MANDATORY= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SOURCES=$(MANDATORY)
OBJECTS=$(SOURCES:.c=.o)

NAME=libft.a
	
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
	
clean:
	@echo ""
	@echo "==================\ncleaning all obj files and executables"
	rm -rf tmp $(OBJECTS) 
	rm -rf tmp $(BONUS_OBJECTS)
	rm -rf `find . -name "*.dSYM" -print`
	find  .  -name "*.c~" -delete -print
	rm -Rf tmp
	rm -f a.out

fclean: clean
	@echo
	@echo "==================\nRemoving ${NAME}"
	rm -f $(NAME)
	rm -f $(NAME_BONUS)


re: fclean all

# ========== bonus ==============

BONUS= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME_BONUS=libft.a

BONUS_SRC=$(BONUS)
BONUS_OBJECTS=$(BONUS_SRC:.c=.o)
BONUS_OBJECTS+=$(OBJECTS) 

bonus: $(BONUS_OBJECTS)
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJECTS)
	ar rcs $@ $(BONUS_OBJECTS)
	ranlib $@

dev: CFLAGS=-g -Werror -Wall -Wextra
dev: all
