CFLAGS=-Wall -Wextra -Werror

SOURCES=$(wildcard ft_*.c)
OBJECTS=$(SOURCES:.c=.o)

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

NAME=libft.a

#maybe not needed
LDLIBS=-lm
	
# the target build
all: $(NAME) tests

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
	
clean:
	rm -rf tmp $(OBJECTS) $(TESTS)
	rm -f *.o
	rm -f tests/tests.log
	rm -rf `find . -name "*.dSYM" -print`
	find  .  -name ".*~" -delete -print
	rm -Rf tmp
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

# ========== bonus and test area! ==============

BONUS_SRC=$(wildcard ft_*_bonus.c)
BONUS_OBJECTS=$(BONUS_SRC:.c=.o)

bonus: $(OBJECTS) += $(BONUS_OBJECTS)
bonus: $(NAME) tests

.PHONY: tests
tests: LDLIBS += $(NAME)
tests: $(TESTS)
	sh ./tests/runtests.sh

dev: CFLAGS=-g -Werror -Wall -Wextra
dev: all

#dont have valgrind on mac so need to test this on linux
valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)
