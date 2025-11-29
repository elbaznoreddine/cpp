CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-3g -fsanitize=address
CPP = c++

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp  Character.cpp  MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

NAME = animal

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp AMateria.hpp Ice.hpp Cure.hpp Character.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all