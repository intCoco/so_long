NAME = so_long

SRC = 	sources/main.c \
		sources/display/game_display.c \
		sources/hooks/update.c \
		sources/hooks/inputs_management.c \
		sources/imports/import_sprites.c \
		sources/in-game/char_management.c \
		sources/in-game/player_management.c \
		sources/pre-game/arguments_parsing.c \
		sources/pre-game/check_map_errors.c \
		sources/pre-game/map_init.c \
		sources/pre-game/mlx_functions.c \
		sources/pre-game/pathfinding.c \
		sources/pre-game/readmap.c \
		sources/utils.c \

OBJ = 	main.o \
		game_display.o \
		update.o \
		inputs_management.o \
		import_sprites.o \
		char_management.o \
		player_management.o \
		arguments_parsing.o \
		check_map_errors.o \
		map_init.o \
		mlx_functions.o \
		pathfinding.o \
		readmap.o \
		utils.o \

NAME_BONUS = so_long_bonus

SRC_BONUS = 	sources_bonus/main_bonus.c \
				sources_bonus/display/chars_display_bonus.c \
				sources_bonus/display/events_display_bonus.c \
				sources_bonus/display/game_display_bonus.c \
				sources_bonus/display/map_display_bonus.c \
				sources_bonus/display/pokemon_display_bonus.c \
				sources_bonus/display/walls_display_bonus.c \
				sources_bonus/hooks/update_bonus.c \
				sources_bonus/hooks/inputs_management_bonus.c \
				sources_bonus/imports/import_sprites_1_bonus.c \
				sources_bonus/imports/import_sprites_2_bonus.c \
				sources_bonus/in-game/char_management_bonus.c \
				sources_bonus/in-game/enemy_management_bonus.c \
				sources_bonus/in-game/exit_management_bonus.c \
				sources_bonus/in-game/player_management_bonus.c \
				sources_bonus/in-game/pokemon_management_bonus.c \
				sources_bonus/pre-game/arguments_parsing_bonus.c \
				sources_bonus/pre-game/check_map_errors_bonus.c \
				sources_bonus/pre-game/map_init_bonus.c \
				sources_bonus/pre-game/map_modifications_bonus.c \
				sources_bonus/pre-game/mlx_functions_bonus.c \
				sources_bonus/pre-game/pathfinding_bonus.c \
				sources_bonus/pre-game/readmap_bonus.c \
				sources_bonus/utils_bonus.c \

OBJ_BONUS = 	main_bonus.o \
				chars_display_bonus.o \
				events_display_bonus.o \
				game_display_bonus.o \
				map_display_bonus.o \
				pokemon_display_bonus.o \
				walls_display_bonus.o \
				update_bonus.o \
				inputs_management_bonus.o \
				import_sprites_1_bonus.o \
				import_sprites_2_bonus.o \
				char_management_bonus.o \
				enemy_management_bonus.o \
				exit_management_bonus.o \
				player_management_bonus.o \
				pokemon_management_bonus.o \
				arguments_parsing_bonus.o \
				check_map_errors_bonus.o \
				map_init_bonus.o \
				map_modifications_bonus.o \
				mlx_functions_bonus.o \
				pathfinding_bonus.o \
				readmap_bonus.o \
				utils_bonus.o \

CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR)
MLX_DIR = /home/chuchard/Desktop/solongfixed/minilibx/minilibx-linux
LINKS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd libft/libft.a

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
	@echo $(CURSIVE)$(RED) "  - Removing $(NAME)..." $(NONE)
	@echo $(CURSIVE)$(RED) "  - Removing $(NAME_BONUS)..." $(NONE)
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
