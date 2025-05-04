# ============================ #
#         COMPILATION          #
# ============================ #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MAKEFLAGS += --no-print-directory

# ============================ #
#           COULEURS           #
# ============================ #

RESET = "\033[0m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"

# ============================ #
#        INCLUDE & NORM        #
# ============================ #

NAME = so_long
INCLUDES = -Iinclude -Iget_next_line

# ============================ #
#           FICHIERS           #
# ============================ #

SRCS = \
	src/so_long.c \
	src/ft_init_game.c \
	src/ft_push_map.c \
	src/ft_get_map.c \
	src/fonction/ft_putstr_fd.c \
	src/fonction/ft_strncmp.c \
	src/error/ft_error.c \
	get_next_line_fd/get_next_line.c \
	get_next_line_fd/get_next_line_utils.c

OBJS_DIR = poubelle
OBJS = $(SRCS:.c=.o)
OBJS := $(patsubst %, $(OBJS_DIR)/%, $(OBJS))

# ============================ #
#           COMMANDES          #
# ============================ #

all: $(NAME)
	@echo $(GREEN)✔ Compilation terminée avec succès !$(RESET)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(BLUE)→ Compilation de So Long...$(RESET)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo $(YELLOW)→ Suppression des fichiers objets et de l'exécutable 🗑️$(RESET)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
