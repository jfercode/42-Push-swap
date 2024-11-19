# Static library name
NAME = libft.a

# Compiler and compiler flags
CC = cc
C_FLAGS = -Wall -Werror -Wextra -g3 -I $(HEADER_DIR)

# Directories
HEADER_DIR = ./
OBJ_DIR = obj

# Source files
SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strncmp.c ft_memcmp.c ft_atoi.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_calloc.c ft_bzero.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_atol.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile .c files into .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[1;33mCOMPILING $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executable
clean:
		@echo "\033[1;31mCLEANING OBJECT FILES AND EXECUTABLES FROM LIBFT...\033[0m" 
	rm -rf $(OBJ_DIR)
	rm -f ./test_program
	@echo "\033[32mCLEANING LIBFT DONE\033[0m"

# Full clean (including library)
fclean: clean
	rm -f $(NAME)
	@echo "\033[32mLIBFT CLEAR\033[0m"

# Rebuild the project
re: fclean all
	@echo "\033[1;34mREBUILDING LIBFT LIBRARY...\033[0m"

.PHONY: all clean fclean re
