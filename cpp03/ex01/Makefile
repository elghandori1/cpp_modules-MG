
NAME = ScavTrap

SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all