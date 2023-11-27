# Colors
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m
CYAN		= \033[36m
GREEN_BOLD	= \033[1;32m

NAME		:=	ft_shmup

CC			:=	c++
CFLAGS		:=	-g3 -Wall -Wextra -Werror

OBJ_FOLDER	:=	objs
SRC_FOLDER	:=	srcs
INCLUDES	:=	-I includes/
NCURSES		:=	-lncurses

HEADERFILE	:=	includes/ft_shmup.h \
				includes/Bullet.h \
				includes/GameBoard.h \
				includes/Ship.h

SRCS		:=	main.cpp \
				Bullet.cpp \
				GameBoard.cpp \
				resetTerminal.cpp \
				Ship.cpp

OBJS		:=	$(SRCS:%.cpp=$(OBJ_FOLDER)/%.opp)

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(YELLOW)[Linking]$(RESET) %s\n" $<
	$(CC) $(CFLAGS) $(NCURSES) $(OBJS) -o $(NAME)
	@echo "$(GREEN_BOLD)$(NAME) is ready ! ✓ $(RESET)"

$(OBJS): $(OBJ_FOLDER)/%.opp: $(SRC_FOLDER)/%.cpp $(HEADERFILE)
	@mkdir -p $(@D)
	@printf "$(CYAN)[Compiling]$(RESET) %s\n" $<
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@printf "$(GREEN)[Cleaning]$(RESET) object files\n"
	rm -fr $(OBJ_FOLDER)

fclean: clean
	@printf "$(GREEN)[Cleaning]$(RESET) $(NAME)\n"
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re