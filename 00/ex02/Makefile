NAME = account
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP #-g -fsanitize=address
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
INCDIR = -I../include
LIBDIR =
LIBS =

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR)$(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS) Account.hpp

clean:
	rm -f $(OBJS) *.d

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
