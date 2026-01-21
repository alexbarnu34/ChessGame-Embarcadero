//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queen.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
using namespace std;

Queen :: Queen(PlayerColor Color,int x, int y):ChessPiece(Color,  x,  y){
       this->type_piece = "Queen";
}

vector<ChessMove> Queen::getPossibleMoves(const ChessBoard& board) const {
    int x_curr = this->getX();
    int y_curr = this->getY();
    vector<ChessMove> moves;

    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int d = 0; d < 8; d++) {
        for (int i = 1; i < 8; i++) {
            int nx = x_curr + i * dx[d];
            int ny = y_curr + i * dy[d];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                ChessPiece* target = board.getPieceAt(nx, ny);
                if (target == nullptr) {
                    moves.push_back(ChessMove(x_curr, y_curr, nx, ny));
                } else {
                    if (target->getColor() != this->getColor()) {
                        moves.push_back(ChessMove(x_curr, y_curr, nx, ny));
                    }
                    break;
                }
            } else break;
        }
    }
    return moves;
}