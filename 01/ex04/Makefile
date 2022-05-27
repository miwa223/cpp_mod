NAME = replace
TEST_NAME = dotest
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRCS = main.cpp File.cpp
TEST_SRCS = Test.cpp File.cpp
OBJS = $(SRCS:%.cpp=object/%.o)
TEST_OBJS = $(TEST_SRCS:%.cpp=test_object/%.o)

all: dirs $(NAME)

test: dirs $(TEST_NAME)

dirs:
	@mkdir -p object test_object

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

object/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(TEST_NAME): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test_object/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(TEST_OBJS)
	@if [ -e object ]; then rm -r object ; fi
	@if [ -e test_object ]; then rm -r test_object ; fi

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re
