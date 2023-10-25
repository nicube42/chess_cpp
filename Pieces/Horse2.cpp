#include "Horse2.hpp"

Horse2::Horse2(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("horse"), _id(0)
{

}

Horse2::Horse2(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("horse"), _id(id)
{
    std::cout << "Horse placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, 0, this);
    board.showBoard();
}
Horse2::Horse2(const Horse2 &horse) : _pos_x(horse._pos_x), _pos_y(horse._pos_y), _init_x(horse._pos_x), _init_y(horse._pos_x), _type(horse._type), _id(horse._id)
{
}

Horse2::~Horse2(void)
{
}

Horse2 &Horse2::operator= (const Horse2 &horse)
{
    return (*this);
}

int *Horse2::getPos(void)
{
    int ret[2];

    ret[0] = this->_pos_x;
    ret[1] = this->_pos_y;

    return (ret);
}

int Horse2::move(int x, int y, Board &board, int silence)
{

    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // Calculate the difference in x and y coordinates from the current position
    int dx = std::abs(this->_pos_x - x);
    int dy = std::abs(this->_pos_y - y);

    // Check if the movement is valid for a knight (L-shape)
    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2)))
    {
        std::cout << "Invalid knight move" << std::endl;
        if (silence == 0)
            addLogMessage("Invalid knight move");
        return 0;
    }

    // Check if the target square is empty or has an enemy piece (assuming a function isEnemyPiece is defined)
    if (board.isTaken(x, y) == 2)
    {
        std::cout << "Square occupied" << std::endl;
        if (silence == 0)
            addLogMessage("Square occupied");
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
            if (silence == 0)
                addLogMessage("King checked");
            return 0;
        }
        std::cout << "Knight moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
        board.showBoard();
        return 1;
    }
    else
    {
        std::cout << "Error in moving the knight" << std::endl;
        if (silence == 0)
            addLogMessage("Error moving the knight");
    }

    return 0;
}


std::string Horse2::getType(void)
{
    return (this->_type);
}
int Horse2::getId(void)
{
    return (this->_id);
}

bool Horse2::canAttack(int x, int y, Board &board) {
    int dx = std::abs(x - this->_pos_x);
    int dy = std::abs(y - this->_pos_y);

    return ((dx == 2 && dy == 1) || (dx == 1 && dy == 2));
}

void        Horse2::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}
