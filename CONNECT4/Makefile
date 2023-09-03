RESET				=	\033[0m
RED					=	\033[0;31m
RED_BOLD			=	\033[1;31m
GREEN				=	\033[0;32m
GREEN_BOLD			=	\033[1;32m
YELLOW				=	\033[0;33m
YELLOW_BOLD			=	\033[1;33m
CYAN				=	\033[0;36m
CYAN_BOLD			=	\033[1;36m
PURPLE				=	\033[1;35m
ERASE				=	\033[2K\033[1A\r

NAME				=	connect4

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MD
RM					=	rm -rf
NO_PRINT_DIR		=	--no-print-directory

SRCS_FILES			=	\
						main.c \
						free.c \
						init_data.c \
						is_bot_active.c \
						parse_grid_size.c \
						print_grid.c 


SRCS_DIR			=	./srcs
SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_FILES			=	$(SRCS_FILES:.c=.o)
DEPS_FILES			=	$(SRCS_FILES:.c=.d)
OBJS_DIR			=	./obj
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
DEPS				=	$(addprefix $(OBJS_DIR)/,$(DEPS_FILES))

HEADER_DIR			=	./includes
HEADER_FILES		=	connect4.h
HEADER				=	$(addprefix $(HEADER_DIR)/, $(HEADER_FILES))
HEADER_INC			=	-I $(HEADER_DIR)

FT_DIR				=	./libft
FT					=	$(FT_DIR)/libft.a
FT_INC				=	-I $(FT_DIR)/include
FT_FLAGS			=	-L $(FT_DIR) -l ft

.PHONY: all
all:				libft $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(FT)
					@mkdir -p $(@D)	
					@printf "$(CYAN)[Compiling]$(RESET) $<\n"
					@$(CC) $(CFLAGS) $(FT_INC) $(HEADER_INC) -c $< -o $@

$(NAME):			$(OBJS) $(FT)
					@printf "$(YELLOW)[Linking]  $(RESET) %s\n" $@
					@$(CC) $(CFLAGS) $(OBJS) $(FT_FLAGS) -o $(NAME)
					@echo "$(GREEN_BOLD)✓ $(NAME) is ready!$(RESET)"

.PHONY: libft
libft:
					@echo "$(PURPLE)[Making]    Libft $(RESET)"
					@$(MAKE) $(NO_PRINT_DIR) -C $(FT_DIR) | sed "s/^make\[[0-9]\]: //;s/^/\x1b[36m[libft]\x1b[0m /"

.PHONY: clean
clean:
					@echo "$(RED_BOLD)[Cleaning]$(RESET)"
					@$(RM) $(OBJS_DIR)
					@$(MAKE) $(NO_PRINT_DIR) -C $(FT_DIR) clean

.PHONY: fclean
fclean:				clean
					@$(RM) $(NAME)
					@$(MAKE) $(NO_PRINT_DIR) -C $(FT_DIR) fclean
					@echo "$(RED_BOLD)✓ project is fully cleaned!$(RESET)"

.PHONY: re
re:					fclean
					@$(MAKE) $(NO_PRINT_DIR) all

-include $(DEPS)