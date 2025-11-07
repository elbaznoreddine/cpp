CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
CPP = c++

SRC = Harl.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = harlFilter

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Harl.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all