# Static library name
NAME = push_swap.a

# Compiler and rules
CC = cc
CFLAGS = -Wall -Werror -Wextra 

# Directories
OBJ_DIR = obj
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft

# Sources
SRC_FILES = push_swap.c push_swap_utils.c
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# # Sub-sources
FT_PRINTF_OBJS = $(FT_PRINTF_DIR:.c=.o)
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ft_printf.a
 
LIBFT_OBJS = $(LIBFT_DIR:.c=.o)
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Default rule
all: $(NAME)

$(NAME): $(OBJ_FILES) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	@echo "\033[1;32mCREATING STATIC LIBRARY $@\033[0m"
	ar rcs $@ $^

# Rule to compile .c files into .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[1;33mCOMPILING $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the ft_printf library
$(FT_PRINTF_LIB):
	@echo "\033[1;35mCOMPILING FT_PRINTF LIBRARY...\033[0m"
	$(MAKE) -C $(FT_PRINTF_DIR)

# Rule to compile the libft library
$(LIBFT_LIB):
	@echo "\033[1;35mCOMPILING LIBFT LIBRARY...\033[0m"
	$(MAKE) -C $(LIBFT_DIR)

# Rule to clean object files and executables
clean:
		@echo "\033[1;31mCLEANING OBJECT FILES AND EXECUTABLES...\033[0m" 
		rm -rf $(OBJ_DIR)
		rm -f ./test_program
		$(MAKE) -C $(FT_PRINTF_DIR) clean
		$(MAKE) -C $(LIBFT_DIR) clean	
		@echo "\033[1;32mCLEANING DONE.\033[0m"

# Rule for full clean
fclean:	clean
		@echo "\033[1;31mDELETING FILES $(NAME)...\033[0m"
		rm -f $(NAME)
		$(MAKE) -C $(FT_PRINTF_DIR) fclean
		$(MAKE) -C $(LIBFT_DIR) fclean		
		@echo "\033[1;32mALL CLEANED UP.\033[0m" 

# Rule to rebuild the project
re:		fclean all
		@echo "\033[1;34mREBUILDING THE PROJECT...\033[0m"

# Rule to run tests
test:	$(NAME) 
		@echo "\033[1;36mCOMPILING AND RUNNING TESTS...\033[0m"
		$(CC) $(CFLAGS) -o test_program $(OBJ_DIR)/push_swap.o $(NAME) $(FT_PRINTF_LIB) $(LIBFT_LIB)
		@./test_program $(PARAMS)

.PHONY:	all clean fclean re test
