#include "APieces2.hpp"
#include "Pawn2.hpp"
#include "Rook2.hpp"
#include "Horse2.hpp"
#include "Bishop2.hpp"
#include "Queen2.hpp"
#include "King2.hpp"

struct BlackBoardSetup
{
    APieces2* pawn;
    APieces2* pawn2;
    APieces2* pawn3;
    APieces2* pawn4;
    APieces2* pawn5;
    APieces2* pawn6;
    APieces2* pawn7;
    APieces2* pawn8;
    APieces2* rook;
    APieces2* rook2;
    APieces2* horse;
    APieces2* horse2;
    APieces2* bishop;
    APieces2* bishop2;
    APieces2* queen;
    APieces2* king;

    BlackBoardSetup(Board *board)
    {
        pawn = new Pawn2(0, 6, *board, 1);
        pawn2 = new Pawn2(1, 6, *board, 2);
        pawn3 = new Pawn2(2, 6, *board, 3);
        pawn4 = new Pawn2(3, 6, *board, 4);
        pawn5 = new Pawn2(4, 6, *board, 5);
        pawn6 = new Pawn2(5, 6, *board, 6);
        pawn7 = new Pawn2(6, 6, *board, 7);
        pawn8 = new Pawn2(7, 6, *board, 8);
        rook = new Rook2(7, 7, *board, 1);
        rook2 = new Rook2(0, 7, *board, 2);
        horse = new Horse2(6, 7, *board, 1);
        horse2 = new Horse2(1, 7, *board, 2);
        bishop = new Bishop2(2, 7, *board, 1);
        bishop2 = new Bishop2(5, 7, *board, 2);
        queen = new Queen2(3, 7, *board, 1);
        king = new King2(4, 7, *board, 1);
    }

    ~BlackBoardSetup() {
        delete pawn;
        delete pawn2;
        delete pawn3;
        delete pawn4;
        delete pawn5;
        delete pawn6;
        delete pawn7;
        delete pawn8;
        delete rook;
        delete rook2;
        delete king;
    }

    int getIdByPiece(APieces2 *piece)
    {
       return (piece->getId());
    }
};
