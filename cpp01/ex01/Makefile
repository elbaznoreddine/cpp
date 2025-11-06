CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = Zombie.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = zombie

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Zombie.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all