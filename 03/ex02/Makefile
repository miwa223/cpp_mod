NAME	= fragtrap
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS	= $(SRCS:%.cpp=objects/%.o)
DEPENDS	= $(OBJS:%.o=objects/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

objects/%.o: %.cpp
	@if [ ! -d objects ]; then mkdir objects ; fi
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@if [ -d objects ]; then rm -r objects ; fi

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPENDS)
.PHONY: all clean fclean re
