# Static library name
NAME = ft_printf.a

# Compiler and compiler flags
CC = cc
C_FLAGS = -Wall -Werror -Wextra -g3 -I $(HEADER_DIR)

# Directories
HEADER_DIR = ./
OBJ_DIR = obj

# Source files
SRC_FILES = ft_printf.c ft_printf_utils.c 
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
	@echo "\033[1;31mCLEANING OBJECT FILES AND EXECUTABLES FROM FT_PRINTF...\033[0m" 
	rm -rf $(OBJ_DIR)
	rm -f ./test_program
	@echo "\033[32mCLEANING PRINTF DONE\033[0m"

# Full clean (including library)
fclean: clean
	rm -f $(NAME)
	@echo "\033[32mPRINTF CLEAR\033[0m"

# Rebuild the project
re: fclean all
	@echo "\033[1;34mREBUILDING FT_PRINTF LIBRARY...\033[0m"

.PHONY: all clean fclean re
