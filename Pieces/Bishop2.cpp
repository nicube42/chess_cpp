#include "Bishop2.hpp"

Bishop2::Bishop2(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("bishop"), _id(0)
{

}

Bishop2::Bishop2(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("bishop"), _id(id)
{
    std::cout << "Bishop placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, 0, this);
    board.showBoard();
}
Bishop2::Bishop2(const Bishop2 &bishop) : _pos_x(bishop._pos_x), _pos_y(bishop._pos_y), _init_x(bishop._pos_x), _init_y(bishop._pos_x), _type(bishop._type), _id(bishop._id)
{
}

Bishop2::~Bishop2(void)
{
}

Bishop2 &Bishop2::operator= (const Bishop2 &bishop)
{
    return (*this);
}

int *Bishop2::getPos(void)
{
    int ret[2];

    ret[0] = this->_pos_x;
    ret[1] = this->_pos_y;

    return (ret);
}

int Bishop2::move(int x, int y, Board &board, int silence)
{
    // Calculate the difference in x and y coordinates from the current position
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;

    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // Check if movement is diagonal (absolute values of dx and dy should be equal)
    if (std::abs(dx) != std::abs(dy))
    {
        std::cout << "Invalid bishop move" << std::endl;
        return 0;
    }

    // Determine the direction of movement
    int stepX = (dx > 0) ? 1 : -1;
    int stepY = (dy > 0) ? 1 : -1;

    // Check for pieces blocking the way
    int checkX = this->_pos_x + stepX;
    int checkY = this->_pos_y + stepY;
    while (checkX != x && checkY != y)
    {
        if (board.isTaken(checkX, checkY) != 0)
        {
            std::cout << "Path blocked" << std::endl;
            if (silence == 0)
                addLogMessage("Path blocked");
            return 0;
        }
        checkX += stepX;
        checkY += stepY;
    }

    // Check if the target square is empty or has an enemy piece
    if (board.isTaken(x, y) == 2)
    {
        std::cout << "Square occupied by friendly piece" << std::endl;
        if (silence == 0)
            addLogMessage("Square occupied by friendly piece");
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
        std::cout << "Bishop moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
        board.showBoard();
        return 1;
    }
    else
    {
        std::cout << "Error in moving the bishop" << std::endl;
        if (silence == 0)
            addLogMessage("Error in moving the bishop");
    }

    return 0;
}

std::string Bishop2::getType(void)
{
    return (this->_type);
}
int Bishop2::getId(void)
{
    return (this->_id);
}

bool Bishop2::canAttack(int x, int y, Board &board) {
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;

    // Check if target is on a diagonal
    if (std::abs(dx) != std::abs(dy)) {
        return false;
    }

    int stepX = (dx > 0) ? 1 : -1;
    int stepY = (dy > 0) ? 1 : -1;

    int i = this->_pos_x + stepX;
    int j = this->_pos_y + stepY;

    while (i != x && j != y) {
        if (board.isTaken(i, j)) {
            return false; // Path blocked
        }
        i += stepX;
        j += stepY;
    }

    return true;
}

void        Bishop2::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}
