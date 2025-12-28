CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
CPP = c++

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

NAME = aform
DEPS = $(OBJ:.o=.d)
all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
	rm -rf $(DEPS)

re: fclean all