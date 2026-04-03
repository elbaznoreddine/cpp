CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
SRC = main.cpp Span.cpp
OBJ=$(SRC:.cpp=.o)
NAME = span

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Span.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all 