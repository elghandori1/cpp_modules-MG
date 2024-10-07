# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 18:06:52 by moel-gha          #+#    #+#              #
#    Updated: 2024/09/18 18:06:53 by moel-gha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
CC	= g++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRC = main.cpp Harl.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) 
fclean: clean
		rm -f $(NAME)

re: fclean all