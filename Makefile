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

MINILIBX_PATH	=	./libraries/minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c \

SOURCES_DIR		=	sources

HEADER			=	./includes/so_long.h

SOURCES			=	$(wildcard $(SOURCES_DIR)/*.c)

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	so_long

CC				=	cc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
INCLUDES		= -L ./libraries/libft -lft

# Set platform-specific flags
ifeq ($(UNAME_S),Linux)
    CFLAGS += -I/usr/include/X11
    MLXFLAGS += -L/usr/lib/X11 -lX11
endif

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -I/opt/X11/include
    MLXFLAGS += -L/opt/X11/lib -lX11 -lX11 -lXext -lXrandr -lXcursor -lXinerama -lXxf86vm -lXrender -lX11-xcb -lXfixes
endif

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
				@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(INCLUDES) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				@make --silent -C $(LIBFT_PATH)

$(MINILIBX):
				@make --silent -C $(MINILIBX_PATH)
				@clear
				@echo
				@echo
				@echo "$(TITLE)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
				@echo "$(PURPLE)"
				@echo "                   )                               /=>                                   "
				@echo "                   (  +____________________/\\/\\___ / /|                                  "
				@echo "                   .''._____________'._____      / /|/\\                                  "
				@echo "                  : () :              :\\ ----\\|    \\ )                                   "
				@echo "                   '..'______________.'0|----|      \\                                    "
				@echo "                     0_0/____/        \\                                                  "
				@echo "                                       |----    /----\\                                   "
				@echo "                                       || -\\\\ --|      \\                                  "
				@echo "                                       ||   || ||\\      \\                                "
				@echo "                                       \\\\____// '|      \\                                 "
				@echo "                Bang! Bang!                     .'/       |                              "
				@echo "                                               .:/        |                              "
				@echo "                                                :/_________|                             "
				@echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━[$(RESET)Made with $(RED)♥ $(RESET)by $(PURPLE)@marsoare$(TITLE)]━━"
				@echo
				@echo
				@echo "$(GREEN) Successfully compiled so_long."
				@echo
				@echo

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all
