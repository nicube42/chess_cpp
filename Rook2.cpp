#include "Rook2.hpp"

Rook2::Rook2(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("rook"), _id(0)
{

}

Rook2::Rook2(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("rook"), _id(id)
{
    std::cout << "Rook placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, 0, this);
    board.showBoard();
}
Rook2::Rook2(const Rook2 &rook) : _pos_x(rook._pos_x), _pos_y(rook._pos_y), _init_x(rook._pos_x), _init_y(rook._pos_x), _type(rook._type), _id(rook._id)
{
}

Rook2::~Rook2(void)
{
}

Rook2 &Rook2::operator= (const Rook2 &rook)
{
    return (*this);
}

int *Rook2::getPos(void)
{
    int ret[2];

    ret[0] = this->_pos_x;
    ret[1] = this->_pos_y;

    return (ret);
}

int Rook2::move(int x, int y, Board &board)
{
    bool validMove = true;

    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // If moving horizontally (along a rank)
    if(this->_pos_y == y) 
    {
        int step = (x > this->_pos_x) ? 1 : -1;
        for(int i = this->_pos_x + step; i != x; i += step)
        {
            if(board.isTaken(i, y) != 0)
            {
                validMove = false;
                if (i == y && board.isTaken(x, i) == 1)
                    validMove = true;
                break;
            }
        }
    }
    // If moving vertically (along a file)
    else if(this->_pos_x == x)
    {
        int step = (y > this->_pos_y) ? 1 : -1;
        for(int i = this->_pos_y + step; i != y; i += step)
        {
            if(board.isTaken(x, i) != 0)
            {
                validMove = false;
                if (i == y && board.isTaken(x, i) == 1)
                    validMove = true;
                break;
            }
        }
    }
    else
    {
        validMove = false;
    }

    if (board.isTaken(x, y) == 2)
        validMove = false;

    if(validMove)
    {
        if (board.isTaken(x, y) == 1)
            board.removePiece("", x, y);
        if(board.setPiece(this->_type, x, y, 0, this))
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
            std::cout << "Rook moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
            board.showBoard();
            return 1;
        }
        else
        {
            std::cout << "Case not empty" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid rook move" << std::endl;
    }

    return 0;
}


std::string Rook2::getType(void)
{
    return (this->_type);
}
int Rook2::getId(void)
{
    return (this->_id);
}

bool Rook2::canAttack(int x, int y, Board &board) {
    // Check if it's not on the same row or column
    if (this->_pos_x != x && this->_pos_y != y) {
        return false;
    }

    int stepX = (this->_pos_x == x) ? 0 : (this->_pos_x < x) ? 1 : -1;
    int stepY = (this->_pos_y == y) ? 0 : (this->_pos_y < y) ? 1 : -1;

    int i = this->_pos_x + stepX;
    int j = this->_pos_y + stepY;

    while (i != x || j != y) {
        if (board.isTaken(i, j) != 0) {
            return false; // Path blocked
        }
        i += stepX;
        j += stepY;
    }

    return true;
}

void        Rook2::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}