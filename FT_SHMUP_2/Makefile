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

NAME				=	ft_shmup

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MD -g3
RM					=	rm -rf
NO_PRINT_DIR		=	--no-print-directory

SRCS_FILES			=	\
						main.c \


SRCS_DIR			=	./srcs
SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_FILES			=	$(SRCS_FILES:.c=.o)
DEPS_FILES			=	$(SRCS_FILES:.c=.d)
OBJS_DIR			=	./obj
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
DEPS				=	$(addprefix $(OBJS_DIR)/,$(DEPS_FILES))

HEADER_DIR			=	./includes
HEADER_FILES		=	ft_shmup.h
HEADER				=	$(addprefix $(HEADER_DIR)/, $(HEADER_FILES))
HEADER_INC			=	-I $(HEADER_DIR)

NCURSES				=	-lncurses

FT_DIR				=	./libft
FT					=	$(FT_DIR)/libft.a
FT_INC				=	-I $(FT_DIR)/include
FT_FLAGS			=	-L $(FT_DIR) -l ft

.PHONY: all
all:				$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
					@mkdir -p $(@D)	
					@printf "$(CYAN)[Compiling]$(RESET) $<\n"
					@$(CC) $(CFLAGS) $(HEADER_INC) -c $< -o $@

$(NAME):			$(OBJS)
					@printf "$(YELLOW)[Linking]  $(RESET) %s\n" $@
					@$(CC) $(CFLAGS) $(OBJS) $(NCURSES) -o $(NAME)
					@echo "$(GREEN_BOLD)✓ $(NAME) is ready!$(RESET)"

.PHONY: clean
clean:
					@echo "$(RED_BOLD)[Cleaning]$(RESET)"
					@$(RM) $(OBJS_DIR)

.PHONY: fclean
fclean:				clean
					@$(RM) $(NAME)
					@echo "$(RED_BOLD)✓ project is fully cleaned!$(RESET)"

.PHONY: re
re:					fclean
					@$(MAKE) $(NO_PRINT_DIR) all

-include $(DEPS)