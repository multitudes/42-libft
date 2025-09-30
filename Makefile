# added -fPIE -fPIC because compiling on mac m1 and linux
# sometimes gave weird errors
CFLAGS=-fPIE -fPIC -Wall -Wextra -Werror -I.
CC=cc

# ============================================================================
# SOURCE FILE ORGANIZATION
# ============================================================================

# String manipulation functions
STRING_SOURCES = src/string/ft_strlen.c src/string/ft_strchr.c src/string/ft_strrchr.c \
	src/string/ft_strncmp.c src/string/ft_strnstr.c src/string/ft_strdup.c \
	src/string/ft_substr.c src/string/ft_strjoin.c src/string/ft_strtrim.c \
	src/string/ft_split.c src/string/ft_strmapi.c src/string/ft_striteri.c \
	src/string/ft_strlcpy.c src/string/ft_strlcat.c

# Memory manipulation functions
MEMORY_SOURCES = src/memory/ft_memset.c src/memory/ft_bzero.c src/memory/ft_memcpy.c \
	src/memory/ft_memmove.c src/memory/ft_memchr.c src/memory/ft_memcmp.c \
	src/memory/ft_calloc.c

# Character classification and transformation functions
CHARACTER_SOURCES = src/character/ft_isalpha.c src/character/ft_isdigit.c \
	src/character/ft_isalnum.c src/character/ft_isascii.c src/character/ft_isprint.c \
	src/character/ft_toupper.c src/character/ft_tolower.c

# Conversion functions (ASCII to int, int to string)
CONVERSION_SOURCES = src/conversion/ft_atoi.c src/conversion/ft_atol.c \
	src/conversion/ft_itoa.c src/conversion/ft_itox.c src/conversion/ft_itoxp.c \
	src/conversion/ft_itoxx.c

# Output functions (file descriptor output)
OUTPUT_SOURCES = src/output/ft_putchar_fd.c src/output/ft_putstr_fd.c \
	src/output/ft_putendl_fd.c src/output/ft_putnbr_fd.c

# Linked list functions (bonus)
LIST_SOURCES = src/list/ft_lstnew.c src/list/ft_lstadd_front.c src/list/ft_lstsize.c \
	src/list/ft_lstlast.c src/list/ft_lstadd_back.c src/list/ft_lstdelone.c \
	src/list/ft_lstclear.c src/list/ft_lstiter.c src/list/ft_lstmap.c

# Combine all core libft sources
SOURCES = $(STRING_SOURCES) $(MEMORY_SOURCES) $(CHARACTER_SOURCES) \
	$(CONVERSION_SOURCES) $(OUTPUT_SOURCES) $(LIST_SOURCES)

# ============================================================================
# ADDITIONAL COMPONENTS
# ============================================================================

# ft_printf subdirectory
PRINTF_PATH = ft_printf
SOURCES_PRINTF = $(addprefix $(PRINTF_PATH)/, ft_printf.c pr_.c pr_c.c pr_s.c pr_p.c pr_x.c pr_xx.c \
base16_utils.c base16_utils2.c pr_i.c err.c pr_u.c utils.c utilsflags.c utilsflags2.c)
SOURCES += $(SOURCES_PRINTF)

# get_next_line subdirectory
GNL_PATH = get_next_line
SOURCES_GNL = $(addprefix $(GNL_PATH)/, get_next_line.c get_next_line_utils.c \
get_next_line_utils.c) 
SOURCES += $(SOURCES_GNL)

OBJECTS = $(SOURCES:.c=.o)

# this rule below is redundant but I leave it for clarity
# %.o: %.c 
# 	$(CC) $(CFLAGs) -c $< -o $@

NAME=libft.a
	
all: $(NAME)

# $@: Represents the target. In the context of my rule $(LIBFT): $(OBJECTS),
# it refers to $(LIBFT)
# $^: Represents all the prerequisites of the rule. 
# In the same context, $^ refers to $(OBJECTS)
# Then I have an ar command with the options 
# r (insert new files), c (create a new archive), 
# and s (write an object-file index into the archive).
$(NAME): $(OBJECTS)
	ar rcs $@ $^
	
clean:
	@echo ""
	@echo "==================\ncleaning all libft obj files and executables"
	rm -rf $(OBJECTS)
	@find . -name "*.dSYM" -delete -print
	@find . -name "*.c~" -delete -print
	@rm -f a.out

fclean: clean
	@echo
	@echo "==================\nRemoving ${NAME}"
	rm -f $(NAME)

re: fclean all

dev: CFLAGS=-g -Werror -Wall -Wextra
dev: all

