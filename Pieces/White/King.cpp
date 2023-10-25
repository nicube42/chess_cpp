#include "King.hpp"

King::King(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("king"), _id(0)
{

}

King::King(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("king"), _id(id)
{
    std::cout << "King placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, this, 0);
    board.showBoard();
}
King::King(const King &king) : _pos_x(king._pos_x), _pos_y(king._pos_y), _init_x(king._pos_x), _init_y(king._pos_x), _type(king._type), _id(king._id)
{
}

King::~King(void)
{
}

King &King::operator= (const King &king)
{
    return (*this);
}

int *King::getPos(void)
{
    int *ret= NULL;
    return (ret);
}

int King::castle(int x, int y, Board &board) {
    // Check if the king has moved before
    if (this->_pos_x != this->_init_x || this->_pos_y != this->_init_y) {
        std::cout << "King has moved before, can't castle" << std::endl;
        addLogMessage("Rook has moved before, can't castle");
        return 0;
    }

    // Identify which side to castle
    int rookX;
    if (x > this->_pos_x) {
        // Kingside castling
        rookX = 7;
    } else {
        // Queenside castling
        rookX = 0;
    }

    // Check if the rook has moved before
    if (1 == 2) {
        std::cout << "Rook has moved before, can't castle" << std::endl;
        addLogMessage("Rook has moved before, can't castle");
        return 0;
    }

    // Check if the path between the king and the rook is clear
    if (!board.isPathClear(this->_pos_x, this->_pos_y, rookX, this->_pos_y)) {
        std::cout << "Path not clear for castling" << std::endl;
        addLogMessage("Path not clear for castling");
        return 0;
    }

    // Check if the squares the king moves across and the square it ends up on are safe
    int step = (x > this->_pos_x) ? 1 : -1;
    for (int i = this->_pos_x; i != x + step; i += step) {
        if (board.isUnderAttack(i, this->_pos_y, "white", board)) {
            std::cout << "King can't move through or to a square under attack" << std::endl;
            addLogMessage("Square under attack");
            return 0;
        }
    }

    // Move the king and the rook
    int newRookX = (rookX == 7) ? 5 : 3;
    board.setPiece(this->_type, x, y, this, 0);
    board.setPiece("rook", newRookX, y, board.getTypeW(rookX, y), 0);
    APieces *piece = board.getTypeW(rookX, y);
    piece->setPos(newRookX, y);
    board.removePiece(this->_type, this->_pos_x, this->_pos_y);
    board.removePiece("rook", rookX, y);
    this->_pos_x = x;
    this->_pos_y = y;

    std::cout << "Castling done!" << std::endl;
    board.showBoard();

    return 1;
}

int King::move(int x, int y, Board &board, int silence)
{
    if ((this->_pos_x - 2 == x || this->_pos_x + 2 == x) && this->_pos_y == y)
        return(castle(x, y, board));
    // Calculate the difference in x and y coordinates from the current position
    int dx = std::abs(x - this->_pos_x);
    int dy = std::abs(y - this->_pos_y);

    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // The king can move only one square in any direction
    if (dx > 1 || dy > 1)
    {
        std::cout << "Invalid king move" << std::endl;
        if (silence == 0)
            addLogMessage("Invalid king move");
        return 0;
    }

    // Check if the target square is empty or has an enemy piece
    if (board.isTaken(x, y) == 1)
    {
        std::cout << "Square occupied by friendly piece" << std::endl;
        if (silence == 0)
            addLogMessage("Square occupied by friendly piece");
        return 0;
    }

    // Execute the move
    if (board.setPiece(this->_type, x, y, this, nullptr))
    {
        board.removePiece(this->_type, this->_pos_x, this->_pos_y);
        int oldX = this->_pos_x, oldY = this->_pos_y;
        this->_pos_x = x;
        this->_pos_y = y;
        if(board.isKingInCheck("white"))
        {
            board.removePiece(this->_type, x, y);
            board.setPiece(this->_type, oldX, oldY, this, 0);
            this->_pos_x = oldX;
            this->_pos_y = oldY;
            std::cout << "King in check" << std::endl;
            if (silence == 0)
                addLogMessage("King checked");
            return 0;
        }
        std::cout << "King moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
        board.showBoard();
        return 1;
    }
    else
    {
        std::cout << "Error in moving the king" << std::endl;
        if (silence == 0)
            addLogMessage("Error moving the knight");
    }

    return 0;
}



std::string King::getType(void)
{
    return (this->_type);
}
int King::getId(void)
{
    return (this->_id);
}

bool King::canAttack(int x, int y, Board &board) {
    int dx = std::abs(x - this->_pos_x);
    int dy = std::abs(y - this->_pos_y);

    return (dx <= 1 && dy <= 1 && (dx != 0 || dy != 0));
}

void        King::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}
