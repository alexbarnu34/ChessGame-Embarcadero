//---------------------------------------------------------------------------

#pragma hdrstop

#include "Knight.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
Knight::Knight(PlayerColor color, int x, int y): ChessPiece(color, x, y)
{
    this->type_piece = "Knight";
}


// 1. Verificăm semnătura: scoatem 'override' și folosim 'std::' peste tot
vector<ChessMove> Knight::getPossibleMoves(const ChessBoard& board) const {
    vector<ChessMove> moves;
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    // Folosește direct membrii clasei dacă sunt PositionX/Y sau getX()/getY()
	int x_actual = this->getX();
    int y_actual = this->getY();

    for (int i = 0; i < 8; i++) {
        int poz_x = x_actual + dx[i];
        int poz_y = y_actual + dy[i];

        if (poz_x >= 0 && poz_x < 8 && poz_y >= 0 && poz_y < 8) {
            // VERIFICARE CRITICĂ:
            ChessPiece* target = board.getPieceAt(poz_x, poz_y);
            if (target == nullptr || target->getColor() != this->color) {
                moves.push_back(ChessMove(x_actual, y_actual, poz_x, poz_y));
            }
        }
    }
    return moves;
}
