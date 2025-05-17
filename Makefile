# ============================ #
#         COMPILATION          #
# ============================ #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -L$(MINILIBX_DIR) -lmlx -Imlx -lXext -lX11 -lm -L$(LIBFT_DIR) -lft
MAKEFLAGS += --no-print-directory

# ============================ #
#           COULEURS           #
# ============================ #

RESET = "\033[0m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"

# ============================ #
#            Minilibx          #
# ============================ #

MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# ============================ #
#            INCLUDE           #
# ============================ #

NAME = so_long
INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# ============================ #
#           FICHIERS           #
# ============================ #

SRCS = \
	src/so_long.c \
	src/ft_push_map.c \
	src/ft_get_map.c \
	src/ft_play_game.c \
	src/ft_init_img.c \
	src/ft_key_move.c \
	src/fonction/ft_putstr_fd.c \
	src/error/ft_error.c \
	src/error/ft_close_window.c \
	src/error/ft_check_map.c \
	src/error/ft_check_map_utils.c

OBJS_DIR = obj
OBJS = $(SRCS:.c=.o)
OBJS := $(patsubst %, $(OBJS_DIR)/%, $(OBJS))

# ============================ #
#           COMMANDES          #
# ============================ #

all: $(LIBFT) $(MINILIBX) $(NAME)
	@echo $(GREEN)✔ Compilation terminée avec succès !$(RESET)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo $(BLUE)→ Compilation de Libft...$(RESET)
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@echo $(BLUE)→ Compilation de Mililibx...$(RESET)
	@$(MAKE) -C $(MINILIBX_DIR)


$(NAME): $(OBJS)
	@echo $(BLUE)→ Compilation de So Long...$(RESET)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) > /dev/null

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C $(MINILIBX_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	

fclean: clean
	@echo $(YELLOW)→ Suppression des fichiers objets 🗑️$(RESET)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
