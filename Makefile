CFLAGS=-Wall -Wextra -Werror

MANDATORY= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c

SOURCES=$(MANDATORY)
OBJECTS=$(SOURCES:.c=.o)

NAME=libft.a

LDLIBS=-lm -lbsd
	
# the target build
all: $(NAME) tests 

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
	
clean:
	@echo ""
	@echo "==================\ncleaning all obj files and executables"
	rm -rf tmp $(OBJECTS) $(TESTS)
	rm -f *.o
	rm -f tests/tests.log
	rm -rf `find . -name "*.dSYM" -print`
	find  .  -name ".*~" -delete -print
	rm -Rf tmp
	rm -f a.out

fclean: clean
	@echo
	@echo "==================\nRemoving ${NAME}"
	rm -f $(NAME)
	rm -f $(NAME_BONUS)


re: fclean all

# ========== bonus ==============

BONUS= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

NAME_BONUS=libft_bonus.a

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
