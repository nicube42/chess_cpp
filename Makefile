SRC = main.cpp \
		Pieces/White/Pawn.cpp \
		Pieces/APieces.cpp \
		Board/Board.cpp \
		Pieces/APieces2.cpp \
		Pieces/Black/Pawn2.cpp \
		Pieces/White/Rook.cpp \
		Pieces/Black/Rook2.cpp \
		Pieces/White/Horse.cpp \
		Pieces/Black/Horse2.cpp \
		Pieces/White/Bishop.cpp \
		Pieces/Black/Bishop2.cpp \
		Pieces/White/Queen.cpp \
		Pieces/Black/Queen2.cpp \
		Pieces/White/King.cpp \
		Pieces/Black/King2.cpp

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
