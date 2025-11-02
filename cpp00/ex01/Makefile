CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = Phonebook.cpp Contact.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = phonebook

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Phonebook.hpp Contact.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all