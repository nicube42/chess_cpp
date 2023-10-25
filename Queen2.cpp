#include "Queen2.hpp"

Queen2::Queen2(void) : _pos_x(0), _pos_y(0), _init_x(0), _init_y(0), _type("queen"), _id(0)
{

}

Queen2::Queen2(int x, int y, Board &board, int id) : _pos_x(x), _pos_y(y), _init_x(x), _init_y(y), _type("queen"), _id(id)
{
    std::cout << "Queen placed on board in position " << this->_pos_x << " " << this->_pos_y << std::endl;
    board.setPiece(this->_type, x, y, 0, this);
    board.showBoard();
}
Queen2::Queen2(const Queen2 &queen) : _pos_x(queen._pos_x), _pos_y(queen._pos_y), _init_x(queen._pos_x), _init_y(queen._pos_x), _type(queen._type), _id(queen._id)
{
}

Queen2::~Queen2(void)
{
}

Queen2 &Queen2::operator= (const Queen2 &queen)
{
    return (*this);
}

int *Queen2::getPos(void)
{
    int ret[2];

    ret[0] = this->_pos_x;
    ret[1] = this->_pos_y;

    return (ret);
}

int Queen2::move(int x, int y, Board &board)
{
    if (this->_pos_x == x && this->_pos_y == y)
        return 0;

    // Calculate the difference in x and y coordinates from the current position
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;

    bool isDiagonal = std::abs(dx) == std::abs(dy);
    bool isStraight = this->_pos_x == x || this->_pos_y == y;

    // Check if the movement is either straight or diagonal
    if (!isDiagonal && !isStraight)
    {
        std::cout << "Invalid queen move" << std::endl;
        return 0;
    }

    // Determine the direction of movement
    int stepX = dx != 0 ? (dx > 0 ? 1 : -1) : 0;
    int stepY = dy != 0 ? (dy > 0 ? 1 : -1) : 0;

    // Check for pieces blocking the way
    int checkX = this->_pos_x + stepX;
    int checkY = this->_pos_y + stepY;
    while (checkX != x || checkY != y)
    {
        if (board.isTaken(checkX, checkY) != 0)
        {
            std::cout << "Path blocked" << std::endl;
            return 0;
        }
        checkX += stepX;
        checkY += stepY;
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
        std::cout << "Queen moved to pos " << this->_pos_x << " " << this->_pos_y << std::endl;
        board.showBoard();
        return 1;
    }
    else
    {
        std::cout << "Error in moving the queen" << std::endl;
    }

    return 0;
}


std::string Queen2::getType(void)
{
    return (this->_type);
}
int Queen2::getId(void)
{
    return (this->_id);
}

bool Queen2::canAttack(int x, int y, Board &board) {
    // Horizontal or vertical check (Rook logic)
    if (this->_pos_x == x || this->_pos_y == y) {
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

    // Diagonal check (Bishop logic)
    int dx = x - this->_pos_x;
    int dy = y - this->_pos_y;

    if (std::abs(dx) == std::abs(dy)) {
        int stepX = (dx > 0) ? 1 : -1;
        int stepY = (dy > 0) ? 1 : -1;

        int i = this->_pos_x + stepX;
        int j = this->_pos_y + stepY;

        while (i != x && j != y) {
            if (board.isTaken(i, j) != 0) {
                return false; // Path blocked
            }
            i += stepX;
            j += stepY;
        }

        return true;
    }

    return false;
}

void        Queen2::setPos(int x, int y)
{
    this->_pos_x = x;
    this->_pos_y = y;
}