NAME = zombieHorde
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS) *.d

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
