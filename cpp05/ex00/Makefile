CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
CPP = c++

SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)

NAME = bureaucrat

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Bureaucrat.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all