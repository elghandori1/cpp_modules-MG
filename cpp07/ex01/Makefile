NAME=iter
CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
FILE=main.cpp
INCLUDE=iter.hpp
OBJ=$(FILE:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
$(OBJ):$(INCLUDE)

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)

re:fclean all