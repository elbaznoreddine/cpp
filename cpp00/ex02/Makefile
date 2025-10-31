CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

NAME = account

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Account.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all