# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 21:19:05 by moel-gha          #+#    #+#              #
#    Updated: 2024/09/17 22:30:12 by moel-gha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Weapon
CC	= g++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRC = HumanA.cpp HumanB.cpp main.cpp  Weapon.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) 
fclean: clean
		rm -f $(NAME)

re: fclean all