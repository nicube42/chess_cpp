#include "Pawn2.hpp"

Pawn2::Pawn2(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("pawn"), _id(0)
{

}

Pawn2::Pawn2(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("pawn"), _id(id)
{
    std::cout << "Pawn placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, 0, this);
    board.showBoard();
}
Pawn2::Pawn2(const Pawn2 &pawn) : _pos_x(pawn._pos_x), _pos_y(pawn._pos_y), _init_x(pawn._pos_x), _init_y(pawn._pos_x), _type(pawn._type), _id(pawn._id)
{
}

Pawn2::~Pawn2(void)
{
}

Pawn2 &Pawn2::operator= (const Pawn2 &pawn)
{
    return (*this);
}

int *Pawn2::getPos(void)
{
    int ret[2];

    ret[0] = this->_pos_x;
    ret[1] = this->_pos_y;

    return (ret);
}

int    Pawn2::move(int x, int y, Board &board)
{
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;
    
    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // Check for standard move (1 square forward)
    if (dx == 0 && dy == -1) 
    {
        if (board.isTaken(x, y) == 0)
        {
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
                std::cout << "BlackPawn moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
                board.showBoard();
                return 1;
            }
        }
        else
        {
            std::cout << "Square occupied" << std::endl;
        }
    }
    // Check for initial double move (2 squares forward from start)
    else if (dx == 0 && dy == -2 && this->_pos_y == this->_init_y)
    {
        if (board.isTaken(x, y) == 0 && board.isTaken(x, y + 1) == 0)
        {
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
                std::cout << "WhitePawn moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
                board.showBoard();
                return 1;
            }
        }
        else
        {
            std::cout << "Square occupied" << std::endl;
        }
    }
    // Check for capture move (1 square diagonally)
    else if ((dx == 1 || dx == -1) && dy == -1)
    {
        if (board.isTaken(x, y) == 1)
        {
            board.removePiece("", x, y);
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
                std::cout << "Black Pawn captured piece at " << this->_pos_x << " " << this->_pos_y << std::endl;
                board.showBoard();
                return 1;
            }
        }
        else
        {
            std::cout << "No enemy piece to capture" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid pawn move" << std::endl;
    }

    return 0;
}

std::string Pawn2::getType(void)
{
    return (this->_type);
}
int Pawn2::getId(void)
{
    return (this->_id);
}

bool Pawn2::canAttack(int x, int y, Board &board) {
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;

    // Assuming pawn is white; reverse the condition for black
    return (dx == 1 && (dy == 1 || dy == -1));
}

void        Pawn2::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}