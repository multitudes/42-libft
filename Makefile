# added -fPIE -fPIC because compiling on mac m1 and linux
# sometimes gave weird errors
# added -I. to include current directory for header files
CFLAGS=-fPIE -fPIC -Wall -Wextra -Werror -I.
CC=cc

# Organized by functionality categories
STRING_PATH = string
STRING_SOURCES = $(addprefix $(STRING_PATH)/, ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c)

MEMORY_PATH = memory
MEMORY_SOURCES = $(addprefix $(MEMORY_PATH)/, ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_calloc.c)

CHARACTER_PATH = character
CHARACTER_SOURCES = $(addprefix $(CHARACTER_PATH)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c)

CONVERSION_PATH = conversion
CONVERSION_SOURCES = $(addprefix $(CONVERSION_PATH)/, ft_atoi.c ft_atol.c ft_itoa.c \
	ft_itox.c ft_itoxx.c ft_itoxp.c)

OUTPUT_PATH = output
OUTPUT_SOURCES = $(addprefix $(OUTPUT_PATH)/, ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c)

LIST_PATH = list
LIST_SOURCES = $(addprefix $(LIST_PATH)/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

# Combine all sources
SOURCES = $(STRING_SOURCES) $(MEMORY_SOURCES) $(CHARACTER_SOURCES) $(CONVERSION_SOURCES) \
	$(OUTPUT_SOURCES) $(LIST_SOURCES)

PRINTF_PATH = ft_printf
SOURCES_PRINTF = $(addprefix $(PRINTF_PATH)/, ft_printf.c pr_.c pr_c.c pr_s.c pr_p.c pr_x.c pr_xx.c \
	base16_utils.c base16_utils2.c pr_i.c err.c pr_u.c utils.c utilsflags.c utilsflags2.c)

# Add ft_printf sources to the main sources
SOURCES += $(SOURCES_PRINTF)

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

