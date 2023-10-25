#include "King2.hpp"

King2::King2(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("king"), _id(0)
{

}

King2::King2(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("king"), _id(id)
{
    std::cout << "King placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, 0, this);
    board.showBoard();
}
King2::King2(const King2 &king) : _pos_x(king._pos_x), _pos_y(king._pos_y), _init_x(king._pos_x), _init_y(king._pos_x), _type(king._type), _id(king._id)
{
}

King2::~King2(void)
{
}

King2 &King2::operator= (const King2 &king)
{
    return (*this);
}

int *King2::getPos(void)
{
    int ret[2];

    ret[0] = this->_pos_x;
    ret[1] = this->_pos_y;

    return (ret);
}

int King2::castle(int x, int y, Board &board) {
    // Check if the king has moved before
    if (this->_pos_x != this->_init_x || this->_pos_y != this->_init_y) {
        std::cout << "King has moved before, can't castle" << std::endl;
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
        return 0;
    }

    // Check if the path between the king and the rook is clear
    if (!board.isPathClear(this->_pos_x, this->_pos_y, rookX, this->_pos_y)) {
        std::cout << "Path not clear for castling" << std::endl;
        return 0;
    }

    // Check if the squares the king moves across and the square it ends up on are safe
    int step = (x > this->_pos_x) ? 1 : -1;
    for (int i = this->_pos_x; i != x + step; i += step) {
        if (board.isUnderAttack(i, this->_pos_y, "black", board)) {
            std::cout << "King can't move through or to a square under attack" << std::endl;
            return 0;
        }
    }

    // Move the king and the rook
    int newRookX = (rookX == 7) ? 5 : 3;
    board.setPiece(this->_type, x, y, 0, this);
    board.setPiece("rook", newRookX, y, 0, board.getTypeB(rookX, y));
    APieces2 *piece = board.getTypeB(rookX, y);
    piece->setPos(newRookX, y);
    board.removePiece(this->_type, this->_pos_x, this->_pos_y);
    board.removePiece("rook", rookX, y);
    this->_pos_x = x;
    this->_pos_y = y;

    std::cout << "Castling done!" << std::endl;
    board.showBoard();

    return 1;
}


int King2::move(int x, int y, Board &board)
{
    if ((this->_pos_x - 2 == x || this->_pos_x + 2 == x) && this->_pos_y == y)
        return(castle(x, y, board));
    if (this->_pos_x + 2 == x && this->_pos_y == y)
        return(castle(x, y, board));
    if (this->_pos_x == x && this->_pos_y == y)
        return 0;
        
    // Calculate the difference in x and y coordinates from the current position
    int dx = std::abs(x - this->_pos_x);
    int dy = std::abs(y - this->_pos_y);

    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // The king can move only one square in any direction
    if (dx > 1 || dy > 1)
    {
        std::cout << "Invalid king move" << std::endl;
        return 0;
    }

    // Check if the target square is empty or has an enemy piece
    if (board.isTaken(x, y) == 2)
    {
        std::cout << "Square occupied by friendly piece" << std::endl;
        return 0;
    }

    if (board.isTaken(x, y) == 1)
        board.removePiece("", x, y);

    // Execute the move
    if (board.setPiece(this->_type, x, y, 0, this))
    {
        board.removePiece(this->_type, this->_pos_x, this->_pos_y);
        int oldX = this->_pos_x, oldY = this->_pos_y;
        this->_pos_x = x;
        this->_pos_y = y;
        if(board.isKingInCheck("black"))
        {
            board.removePiece(this->_type, x, y);
            board.setPiece(this->_type, oldX, oldY, 0, this);
            this->_pos_x = oldX;
            this->_pos_y = oldY;
            std::cout << "King in check" << std::endl;
            return 0;
        }
        std::cout << "King moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
        board.showBoard();
        return 1;
    }
    else
    {
        std::cout << "Error in moving the king" << std::endl;
    }

    return 0;
}



std::string King2::getType(void)
{
    return (this->_type);
}
int King2::getId(void)
{
    return (this->_id);
}

bool King2::canAttack(int x, int y, Board &board) {
    int dx = std::abs(x - this->_pos_x);
    int dy = std::abs(y - this->_pos_y);

    return (dx <= 1 && dy <= 1 && (dx != 0 || dy != 0));
}

void        King2::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}
