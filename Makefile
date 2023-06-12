NAME = so_long
SRC = 	main.c \
		sources/hooks/hooks.c \
		sources/imports/import_sprites_1.c \
		sources/imports/import_sprites_2.c \
		sources/pre-game/arguments_parsing.c \
		sources/pre-game/check_map_errors.c \
		sources/pre-game/map_init.c \
		sources/pre-game/map_modifications.c \
		sources/pre-game/mlx_functions.c \
		sources/pre-game/pathfinding.c \
		sources/pre-game/readmap.c \

OBJ = main.o \
		hooks.o \
		import_sprites_1.o \
		import_sprites_2.o \
		arguments_parsing.o \
		check_map_errors.o \
		map_init.o \
		map_modifications.o \
		mlx_functions.o \
		pathfinding.o \
		readmap.o \

CFLAGS = -Wall -Wextra -Werror
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
	@gcc $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME) 
	@echo $(GREEN)"	- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "  - Making object files..." $(NONE)
	@gcc $(CFLAGS) -c $(SRC)

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
