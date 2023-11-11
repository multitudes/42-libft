CFLAGS=-Wall -Wextra -Werror

SOURCES=$(wildcard ft_*.c)
OBJECTS=$(SOURCES:.c=.o)

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

BONUS=$(patsubst .c,%,_bonus.c)

NAME=libft.a

#maybe not needed
LDLIBS=-lm
	
# the target build
all: $(NAME) tests

dev: CFLAGS=-g -Werror -Wall -Wextra
dev: all

$(NAME): temp $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

temp:
	@mkdir -p tmp
	
.PHONY: tests
tests: LDLIBS += $(NAME)
tests: $(TESTS)
	sh ./tests/runtests.sh
	
#dont have valgrind on mac so need to test this on linux
valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

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

.PHONY: bonus
bonus: LDLIBS += $(NAME)
bonus: _bonus
