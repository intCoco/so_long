NAME = so_long

SRC = 	sources/main.c \
		sources/display/chars_display.c \
		sources/display/events_display.c \
		sources/display/game_display.c \
		sources/display/map_display.c \
		sources/display/pokemon_display.c \
		sources/display/walls_display.c \
		sources/hooks/update.c \
		sources/hooks/inputs_management.c \
		sources/imports/import_sprites_1.c \
		sources/imports/import_sprites_2.c \
		sources/in-game/char_management.c \
		sources/in-game/enemy_management.c \
		sources/in-game/exit_management.c \
		sources/in-game/player_management.c \
		sources/in-game/pokemon_management.c \
		sources/pre-game/arguments_parsing.c \
		sources/pre-game/check_map_errors.c \
		sources/pre-game/map_init.c \
		sources/pre-game/map_modifications.c \
		sources/pre-game/mlx_functions.c \
		sources/pre-game/pathfinding.c \
		sources/pre-game/readmap.c \
		sources/utils.c \

OBJ = 	main.o \
		chars_display.o \
		events_display.o \
		game_display.o \
		map_display.o \
		pokemon_display.o \
		walls_display.o \
		update.o \
		inputs_management.o \
		import_sprites_1.o \
		import_sprites_2.o \
		char_management.o \
		enemy_management.o \
		exit_management.o \
		player_management.o \
		pokemon_management.o \
		arguments_parsing.o \
		check_map_errors.o \
		map_init.o \
		map_modifications.o \
		mlx_functions.o \
		pathfinding.o \
		readmap.o \
		utils.o \

NAME_BONUS = so_long_bonus

SRC_BONUS = 	sources/main.c \
				sources/display/chars_display.c \
				sources/display/events_display.c \
				sources/display/game_display.c \
				sources/display/map_display.c \
				sources/display/pokemon_display.c \
				sources/display/walls_display.c \
				sources/hooks/update.c \
				sources/hooks/inputs_management.c \
				sources/imports/import_sprites_1.c \
				sources/imports/import_sprites_2.c \
				sources/in-game/char_management.c \
				sources/in-game/enemy_management.c \
				sources/in-game/exit_management.c \
				sources/in-game/player_management.c \
				sources/in-game/pokemon_management.c \
				sources/pre-game/arguments_parsing.c \
				sources/pre-game/check_map_errors.c \
				sources/pre-game/map_init.c \
				sources/pre-game/map_modifications.c \
				sources/pre-game/mlx_functions.c \
				sources/pre-game/pathfinding.c \
				sources/pre-game/readmap.c \
				sources/utils.c \

OBJ_BONUS = 	main.o \
				chars_display.o \
				events_display.o \
				game_display.o \
				map_display.o \
				pokemon_display.o \
				walls_display.o \
				update.o \
				inputs_management.o \
				import_sprites_1.o \
				import_sprites_2.o \
				char_management.o \
				enemy_management.o \
				exit_management.o \
				player_management.o \
				pokemon_management.o \
				arguments_parsing.o \
				check_map_errors.o \
				map_init.o \
				map_modifications.o \
				mlx_functions.o \
				pathfinding.o \
				readmap.o \
				utils.o \

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo $(CURSIVE)$(GRAY) "  - Compiling libft..." $(NONE)
	@make -C libft/
	@echo $(CURSIVE)$(GRAY) "  - Compiling $(NAME_BONUS)..." $(NONE)
	@gcc $(CFLAGS) $(OBJ_BONUS) $(LINKS) -o $(NAME_BONUS) 
	@echo $(GREEN)"	- Compiled -"$(NONE)

$(OBJ_BONUS): $(SRC_BONUS)
	@echo $(CURSIVE)$(GRAY) "  - Making object files..." $(NONE)
	@gcc $(CFLAGS) -c $(SRC_BONUS)

clean:
	@echo $(CURSIVE)$(RED) "  - Removing libft object files..." $(NONE)
	@make clean -C libft/
	@echo $(CURSIVE)$(RED) "  - Removing object files..." $(NONE)
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@echo $(CURSIVE)$(RED) "  - Removing libft.a..." $(NONE)
	@make fclean -C libft/
	@echo $(CURSIVE)$(RED) "  - Removing $(NAME_BONUS)..." $(NONE)
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
