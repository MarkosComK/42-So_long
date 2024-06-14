# COLORS
RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE = $(shell printf "\33[32;40m")

LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c \

SOURCES_BONUS	=	so_long_bonus.c \

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

HEADER			=	$(SOURCES_DIR)/so_long.h
HEEADER_BONUS	=	$(BONUS_DIR)/so_long_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

CC				=	cc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
				@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
					@$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

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

.PHONY:			all clean fclean re libft minilibx bonus
