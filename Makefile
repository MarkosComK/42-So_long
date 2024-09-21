# COLORS
RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE = $(shell printf "\33[32;40m")

# Detect the OS
UNAME_S := $(shell uname -s)

# Your existing targets and rules here
LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./minilibx-linux/
MLX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c \

SOURCES_DIR		=	sources
BONUS_DIR		=	bonus

HEADER			=	./includes/so_long.h

SOURCES			=	$(wildcard $(SOURCES_DIR)/*.c) $(wildcard $(SOURCES_DIR)/*/*.c)
SOURCES_BONUS			=	$(wildcard $(BONUS_DIR)/*.c) $(wildcard $(BONUS_DIR)/*/*.c)

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS			= 	$(SOURCES_BONUS:.c=.o)

NAME			=	so_long

CC				=	cc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g 
INCLUDES		= -L ./libraries/libft

# Set platform-specific flags
ifeq ($(UNAME_S),Linux)
    CFLAGS += -I/usr/include/X11
    MLXFLAGS += -L. -lXext -L. -lX11
endif

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -I/opt/X11/include
    MLXFLAGS += -L/opt/X11/lib -lX11 -lX11 -lXext -lXrandr -lXcursor -lXinerama -lXxf86vm -lXrender -lX11-xcb -lXfixes
endif

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

TEST = val.sh

all:	$(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(INCLUDES) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	@make --silent -C $(LIBFT_PATH)

bonus: $(NAME)_bonus

$(NAME)_bonus:	$(LIBFT) $(MLX) $(MINILIBX_PATH) $(OBJECTS_BONUS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(INCLUDES) $(MLX) $(MLXFLAGS) -o $(NAME)_bonus

$(MLX): $(MINILIBX_PATH)
	@rm -rf minilibx-linux/.git
	@make -C $^ > /dev/null 2>&1

$(MINILIBX_PATH):
	@echo "\033[1;35m[ ✔ ] Preparing minilibx...\033[0m"
	@git clone https://github.com/42Paris/minilibx-linux.git > /dev/null 2>&1
	@clear
	@echo "$(TITLE) $(PURPLE)"
	@echo "  ███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗   "
	@echo "  ██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝   "
	@echo "  ███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗  "
	@echo "  ╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║  "
	@echo "  ███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝  "
	@echo "  ╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝   "
	@echo "  $(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━[$(RESET)Made with $(RED)♥ $(RESET)by $(PURPLE)@marsoare$(TITLE)]━━━━"
	@echo "$(RESET)"

clean:
	@$(MAKE) --silent -C $(LIBFT_PATH) clean
	@$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:	clean
	@$(MAKE) --silent -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(NAME)_bonus
	@$(RM) $(NAME) $(NAME)

re:	fclean clean all

test: re
	./$(TEST)

.PHONY: clean fclean bonus all re
