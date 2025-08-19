CXX=c++
CFLAGS=-std=c++17 -Wall -Wextra -Werror -I../../utility
NAME=1

SRCS=1.cpp
OBJS=$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re