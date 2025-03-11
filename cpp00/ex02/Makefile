CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Phonebook

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
