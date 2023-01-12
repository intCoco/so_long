NAME = solong.out
SRC = 	main.c \
		pathfinding.c \
		readmap.c \
		hooks.c \
		import_sprites.c \
		mlx_functions.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED='\033[0;31m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "  - Compiling libft..." $(NONE)
	@make -C libft/
	@echo $(CURSIVE)$(GRAY) "  - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"	- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "  - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n	- Done -"

clean:
	@echo $(CURSIVE)$(RED) "  - Removing libft object files..." $(NONE)
	@make clean -C libft/
	@echo $(CURSIVE)$(RED) "  - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(RED) "  - Removing libft.a..." $(NONE)
	@make fclean -C libft/
	@echo $(CURSIVE)$(RED) "  - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all
