NAME = weapon
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS = $(SRCS:%.cpp=object/%.o)

all: dir $(NAME)

dir:
	@mkdir -p object

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

object/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@if [ -e object ]; then rm -r object ; fi

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
