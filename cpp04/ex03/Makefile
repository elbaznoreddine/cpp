CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = animal

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all