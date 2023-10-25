SRC = main.cpp Pawn.cpp APieces.cpp Board.cpp APieces2.cpp Pawn2.cpp Rook.cpp Rook2.cpp Horse.cpp Horse2.cpp Bishop.cpp Bishop2.cpp Queen.cpp Queen2.cpp King.cpp King2.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f

# Assuming SFML is installed in the default location
SFML_INC = -I/opt/homebrew/Cellar/sfml/2.6.0/include/
SFML_LIB = -L/opt/homebrew/Cellar/sfml/2.6.0/lib
SFML_LINK = -lsfml-graphics -lsfml-window -lsfml-system

# Added SFML includes and libraries to your flags
CPPFLAGS = $(SFML_INC) -std=c++11 #-Wall -Wextra -Werror -std=c++98 -pedantic
LDFLAGS = $(SFML_LIB) $(SFML_LINK)

NAME = chess

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
