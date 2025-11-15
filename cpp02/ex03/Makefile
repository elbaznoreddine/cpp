CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp

OBJ = $(SRC:.cpp=.o)

NAME = point

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Fixed.hpp Point.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all