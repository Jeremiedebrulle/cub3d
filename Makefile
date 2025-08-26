 MAKEFLAGS += --no-print-directory

# Compiler and flags
CC      = gcc
CFLAGS  = -g -Wall -Wextra -Werror
MLXFLAGS = -Imlx_linux -lXext -lX11 -lm -lz

# Project name
NAME    = Cub3d

# Directories
SRC_DIR = srcs
OBJ_DIR = build
INC_DIR = includes
LIBFT_DIR = Libft
MLX_DIR = mlx_linux

# Source files (relative to SRC_DIR)
SRC_FILES = \
	parsing/args_parsing.c \
	parsing/config_helpers.c \
	parsing/config_parsing.c \
	parsing/file_parsing.c \
	parsing/map_parsing.c \
	parsing/map_helpers.c \
	parsing/utils.c \
	init/init.c \
	game/game_on.c \
	game/movement.c \
	game/dda.c \
	exit.c \
	main.c

# Full paths
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX   = $(MLX_DIR)/libmlx.a

# Build all
all: $(NAME)

# Build your Cub3d project only (no rebuilding mlx or libft)
build: $(OBJS)
	@$(CC) $(CFLAGS) $^ -I$(INC_DIR) $(MLXFLAGS) -o $(NAME)

# Link final executable
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $^ -I$(INC_DIR) $(MLXFLAGS) -o $@

# Compile object files and create subdirectories as needed
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

# Build libraries
$(LIBFT): FORCE
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX): FORCE
	@$(MAKE) -s -C $(MLX_DIR)

# Clean build files
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLX_DIR) clean

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
