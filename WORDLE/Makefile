# Colors
RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
CYAN    = \033[36m

NAME		:=	wordle

CC			:=	c++
CFLAGS		:=	-g3 -Wall -Wextra -Werror
INCFLAGS	:=	-I ./includes/

OBJ_FOLDER	:=	objs
SRC_FOLDER	:=	srcs

HEADERFILE	:=	includes/Parser.h 
SRCS		:=	main.cpp \
				Parser.cpp

OBJS		:=	$(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(YELLOW)[Linking]$(RESET) %s\n" $@
	$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp $(HEADERFILE)
	@mkdir -p $(@D)
	@printf "$(CYAN)[Compiling]$(RESET) %s\n" $<
	$(CC) $(CFLAGS) $(INCFLAGS) -o $@ -c $<

clean:
	@printf "$(GREEN)[Cleaning]$(RESET) object files\n"
	rm -fr $(OBJ_FOLDER)

fclean: clean
	@printf "$(GREEN)[Cleaning]$(RESET) $(NAME)\n"
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re