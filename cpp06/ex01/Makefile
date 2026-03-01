CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
SRC = main.cpp Serializer.cpp
OBJ=$(SRC:.cpp=.o)
NAME = serializer
all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.c Serializer.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all