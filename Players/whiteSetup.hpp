#include "../Pieces/APieces.hpp"
#include "../Pieces/Pawn.hpp"
#include "../Pieces/Rook.hpp"
#include "../Pieces/Horse.hpp"
#include "../Pieces/Bishop.hpp"
#include "../Pieces/Queen.hpp"
#include "../Pieces/King.hpp"

struct WhiteBoardSetup
{
    APieces* pawn;
    APieces* pawn2;
    APieces* pawn3;
    APieces* pawn4;
    APieces* pawn5;
    APieces* pawn6;
    APieces* pawn7;
    APieces* pawn8;
    APieces* rook;
    APieces* rook2;
    APieces* horse;
    APieces* horse2;
    APieces* bishop;
    APieces* bishop2;
    APieces* queen;
    APieces* king;

    WhiteBoardSetup(Board *board)
    {
        pawn = new Pawn(0, 1, *board, 1);
        pawn2 = new Pawn(1, 1, *board, 2);
        pawn3 = new Pawn(2, 1, *board, 3);
        pawn4 = new Pawn(3, 1, *board, 4);
        pawn5 = new Pawn(4, 1, *board, 5);
        pawn6 = new Pawn(5, 1, *board, 6);
        pawn7 = new Pawn(6, 1, *board, 7);
        pawn8 = new Pawn(7, 1, *board, 8);
        rook = new Rook(0, 0, *board, 1);
        rook2 = new Rook(7, 0, *board, 2);
        horse = new Horse(6, 0, *board, 1);
        horse2 = new Horse(1, 0, *board, 2);
        bishop = new Bishop(2, 0, *board, 1);
        bishop = new Bishop(5, 0, *board, 2);
        queen = new Queen(3, 0, *board, 1);
        king = new King(4, 0, *board, 1);
    }

    ~WhiteBoardSetup() {
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
        delete horse;
        delete horse2;
        delete bishop;
        delete bishop2;
        delete queen;
        delete king;
    }

    int getIdByPiece(APieces *piece)
    {
       return (piece->getId());
    }
};
