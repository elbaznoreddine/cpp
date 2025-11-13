CPPFLAGS = -Wall -Wextra -Werror -std=c++98 
CPP = c++

SRC = Fixed.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = fixed

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Fixed.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all