#ifndef BOARD_HPP

# define BOARD_HPP

# include <iostream>
# include <string>
# include "../Pieces/APieces2.hpp"
# include "../Pieces/APieces.hpp"

class	APieces;
class	APieces2;

class	Board
{
	private:
		std::string             _pos[8][8];
		APieces					*_wPiece[8][8];
		APieces2				*_bPiece[8][8];

    public:
		~Board();
        Board();
        Board(const Board &board);

        Board &operator= (const Board &board);

		APieces		*getTypeW(int x, int y);
		APieces2	*getTypeB(int x, int y);

        int		removePiece(std::string type, int x, int y);
        int		setPiece(std::string type, int x, int y, APieces *piece, APieces2 *piece2);
        void	showBoard(void);
		void	initPieceMap(void);
		int 	isTaken(int x, int y);

		bool isUnderAttack(int x, int y, std::string playerColor, Board &board);
		bool isPathClear(int startX, int startY, int endX, int endY);
		bool isKingInCheck(std::string playerColor);
		//bool isCheckmate(std::string playerColor);
		bool testAllLegalMoves(std::string color);

};

#endif
