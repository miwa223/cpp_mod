NAME	= materia
CC		= clang++ #
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP -g -fsanitize=leak
SRCS	= main.cpp Character.cpp MateriaSource.cpp \
			AMateria.cpp Ice.cpp Cure.cpp
OBG_DIR = objects
OBJS	= $(SRCS:%.cpp=$(OBG_DIR)/%.o)
DEPENDS	= $(OBJS:%.o=$(OBG_DIR)/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBG_DIR)/%.o: %.cpp
	@mkdir -p $(OBG_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@if [ -d $(OBG_DIR) ]; then rm -r $(OBG_DIR) ; fi

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPENDS)
.PHONY: all clean fclean re
