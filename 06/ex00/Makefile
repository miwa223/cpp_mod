NAME		= convert
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRCS		= main.cpp Convert.cpp DetectType.cpp StrToOtherTypes.cpp DisplayResults.cpp
OBJ_DIR 	= objects
OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPENDS		= $(OBJS:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPENDS)
.PHONY: all clean fclean re
