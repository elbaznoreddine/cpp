CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
SRC = main.cpp
OBJ=$(SRC:.cpp=.o)
NAME = find

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp easyfind.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all 