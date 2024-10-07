# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 18:06:23 by moel-gha          #+#    #+#              #
#    Updated: 2024/09/18 18:06:24 by moel-gha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = replace
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

OBJS = main.o Replace.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Replace.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Replace.o: Replace.cpp Replace.hpp
	$(CXX) $(CXXFLAGS) -c Replace.cpp

clean:
	rm -f $(TARGET) $(OBJS)
	
fclean: clean
		rm -f $(NAME)

re: fclean all
