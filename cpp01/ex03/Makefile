CPPFLAGS = -Wall -Wextra -Werror -std=c++98 
CPP = c++

SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = weapon

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all