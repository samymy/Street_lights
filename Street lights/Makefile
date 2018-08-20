NAME = street_lights

SRC =	main.cpp \
		Parser.cpp \
		Range.cpp

OBJ = $(SRC:.cpp=.o)

INC =	Parser.hpp \
		Range.hpp

FLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(OBJ): $(INC)

.cpp.o:
	@g++ $(FLAGS) -c $<

$(NAME): $(OBJ)
	@g++ $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
