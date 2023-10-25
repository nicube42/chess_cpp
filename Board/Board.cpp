#include "Board.hpp"

Board::~Board()
{
}

Board::Board()
{
    std::cout << "New board created" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            this->_pos[i][j] = "empty";
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            this->_wPiece[i][j] = 0;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            this->_bPiece[i][j] = 0;
    }
}

Board::Board(const Board &board)
{

}

Board &Board::operator= (const Board &board)
{

}

int    Board::setPiece(std::string type, int x, int y, APieces *piece, APieces2 *piece2)
{
    if (!piece2)
    {
        this->_wPiece[x][y] = piece;
    }
    if (!piece)
    {
        this->_bPiece[x][y] = piece2;
    }
    //if (this->_pos[x][y] == "empty")
        this->_pos[x][y] = type;
        std::cout << "Piece set in board class" << std::endl;
        return (1);
    std::cout << "Error setting in board class" << std::endl;
    this->_wPiece[x][y] = 0;
    this->_wPiece[x][y] = 0;
    return (0);
}

int    Board::removePiece(std::string type, int x, int y)
{
    if (this->_pos[x][y] == "empty")
    {
        std::cout << "No piece to remove" << std::endl;
        return (0);
    }
    this->_pos[x][y] = "empty";
    this->_bPiece[x][y] = 0;
    this->_wPiece[x][y] = 0;
    std::cout << "Piece removed from board" << std::endl;
    return (1);
}


void Board::showBoard(void) {
    std::string rotated[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            rotated[7 - j][i] = _pos[i][j];
    }

    // Displaying x-axis
    std::cout << "    "; // spacing for y-axis labels
    for (int i = 0; i < 8; i++)
    {
        std::cout << " " << i << "  "; // Assuming you want 1-based indexes for display
    }
    std::cout << std::endl;
    
    std::cout << "    "; // spacing for y-axis labels
    for (int i = 0; i < 8; i++)
    {
        std::cout << "--- "; 
    }
    std::cout << std::endl;

    for (int i = 0; i < 8; i++)
    {
        // Displaying y-axis
        std::cout << 7 - i << " | ";

        for (int j = 0; j < 8; j++)
        {
            if (rotated[i][j] == "empty") {
                std::cout << "[ ] ";
            } 
            else
            {
                std::cout << "[" << rotated[i][j][0] << "] ";
            }
        }
        std::cout << std::endl;
    }
}

int Board::isTaken(int x, int y)
{
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
    {
        if (this->_pos[x][y] == "empty")
            return (0);
    }
    if (this->_wPiece[x][y] != 0)
        return (1);
    return (2);
}

APieces	*Board::getTypeW(int x, int y)
{
    return (this->_wPiece[x][y]);
}

APieces2 *Board::getTypeB(int x, int y)
{
    return (this->_bPiece[x][y]);
}

bool Board::isPathClear(int startX, int startY, int endX, int endY) {
    int stepX = (startX == endX) ? 0 : (startX < endX) ? 1 : -1;
    int stepY = (startY == endY) ? 0 : (startY < endY) ? 1 : -1;

    int i = startX + stepX;
    int j = startY + stepY;

    while (i != endX || j != endY) {
        if (_pos[i][j] != "empty") {
            return false; // Found a piece in the path
        }
        i += stepX;
        j += stepY;
    }
    return true;
}

bool Board::isUnderAttack(int x, int y, std::string playerColor, Board &board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (_pos[i][j] != "empty") {
                if (playerColor == "white" && _bPiece[i][j] && _bPiece[i][j]->canAttack(x, y, board)) {
                    return true;
                } else if (playerColor == "black" && _wPiece[i][j] && _wPiece[i][j]->canAttack(x, y, board)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::isKingInCheck(std::string playerColor) {
    // Find the king's position
    int kingX, kingY;
    if (playerColor == "white")
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (this->_pos[i][j] == "king" && this->_wPiece[i][j] != 0)
                    kingX = i, kingY = j;
            }
        }
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (this->_pos[i][j] == "king" && this->_bPiece[i][j] != 0)
                    kingX = i, kingY = j;
            }
        }
    }

    // Check if the king's position is under attack
    return isUnderAttack(kingX, kingY, playerColor, *this);
}

// bool Board::isCheckmate(std::string playerColor) {
//     if (!isKingInCheck(playerColor)) {
//         return false;
//     }

//     // Get all possible moves for the player
//     std::vector<Move> allMoves = getAllPossibleMovesForColor(playerColor);

//     // For each move, see if it would result in the king being out of check
//     for (const Move& move : allMoves) {
//         // Make a copy of the board
//         Board tempBoard = *this;
        
//         // Try the move on the temporary board
//         tempBoard.movePiece(move.startX, move.startY, move.endX, move.endY);
        
//         // If the move results in the king not being in check, it's not a checkmate
//         if (!tempBoard.isKingInCheck(playerColor)) {
//             return false;
//         }
//     }

//     return true;
// }

bool Board::testAllLegalMoves(std::string color)
{
    // Iterate over the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            
            // Check for a white piece at this position
            if (_wPiece[i][j] != nullptr && color == "white") {
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        APieces* originalSource = _wPiece[i][j];
                        APieces* originalDestination = _wPiece[x][y];

                        if (_wPiece[i][j]->move(x, y, *this, 1) == 1) {
                            _wPiece[i][j] = originalSource;
                            _wPiece[x][y] = originalDestination;
                            return true;
                        }
                    }
                }
            }

            // Check for a black piece at this position
            if (_bPiece[i][j] != nullptr && color == "black") {
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        APieces2* originalSource = _bPiece[i][j];
                        APieces2* originalDestination = _bPiece[x][y];

                        if (_bPiece[i][j]->move(x, y, *this, 1) == 1) {
                            _bPiece[i][j] = originalSource;
                            _bPiece[x][y] = originalDestination;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

