#include "Pawn.hpp"

Pawn::Pawn(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("pawn"), _id(0)
{

}

Pawn::Pawn(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("pawn"), _id(id)
{
    std::cout << "Pawn placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, this, 0);
    board.showBoard();
}
Pawn::Pawn(const Pawn &pawn) : _pos_x(pawn._pos_x), _pos_y(pawn._pos_y), _init_x(pawn._pos_x), _init_y(pawn._pos_x), _type(pawn._type), _id(pawn._id)
{
}

Pawn::~Pawn(void)
{
}

Pawn &Pawn::operator= (const Pawn &pawn)
{
    return (*this);
}

int *Pawn::getPos(void)
{
    int *ret= NULL;
    return (ret);
}

int Pawn::move(int x, int y, Board &board, int silence)
{
    if(board.isKingInCheck("white"))
    {
        std::cout << "King in check" << std::endl;
        return 0;
    }
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;
    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // Check for standard move (1 square forward)
    if (dx == 0 && dy == 1) 
    {
        if (board.isTaken(x, y) == 0)
        {
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
    // Check for initial double move (2 squares forward from start)
    else if (dx == 0 && dy == 2 && this->_pos_y == this->_init_y)
    {
        if (board.isTaken(x, y) == 0 && board.isTaken(x, y - 1) == 0)
        {
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
                std::cout << "WhitePawn moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
                board.showBoard();
                return 1;
            }
        }
        else
        {
            std::cout << "Square occupied" << std::endl;
            if (silence == 0)
                addLogMessage("Square occupied");
        }
    }
    // Check for capture move (1 square diagonally)
    else if (std::abs(dx) == 1 && dy == 1)
    {
        if (board.isTaken(x, y) == 2)
        {
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
                std::cout << "WhitePawn captured piece at " << this->_pos_x << " " << this->_pos_y << std::endl;
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
        std::cout << "Invalid WhitePawn move" << std::endl;
        if (silence == 0)
            addLogMessage("Invalid WhitePawn move");
    }

    return 0;
}


std::string Pawn::getType(void)
{
    return (this->_type);
}
int Pawn::getId(void)
{
    return (this->_id);
}

bool Pawn::canAttack(int x, int y, Board &board) {
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;

    // Assuming pawn is white; reverse the condition for black
    return (dx == 1 && (dy == 1 || dy == -1));
}

void        Pawn::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}
