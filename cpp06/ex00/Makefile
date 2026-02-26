CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
SRC = main.cpp ScalarConverter.cpp
OBJ=$(SRC:.cpp=.o)
NAME = convert

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp ScalarConverter.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all 