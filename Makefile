SRC = main.cpp Pieces/Pawn.cpp Pieces/APieces.cpp Board/Board.cpp Pieces/APieces2.cpp Pieces/Pawn2.cpp Pieces/Rook.cpp Pieces/Rook2.cpp Pieces/Horse.cpp Pieces/Horse2.cpp Pieces/Bishop.cpp Pieces/Bishop2.cpp Pieces/Queen.cpp Pieces/Queen2.cpp Pieces/King.cpp Pieces/King2.cpp
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
