# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 12:01:27 by aneumann          #+#    #+#              #
#    Updated: 2025/05/16 14:27:49 by aneumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp Dog.cpp Cat.cpp Animal.cpp
OBJ = $(SRC:.cpp=.o)
NAME = animal

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
