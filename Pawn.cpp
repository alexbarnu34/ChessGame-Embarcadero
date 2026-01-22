//---------------------------------------------------------------------------

#pragma hdrstop

#include "Pawn.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include <vector>
//---------------------------------------------------------------------------
using namespace std;

Pawn ::Pawn(PlayerColor Color,int x, int y):ChessPiece (Color, x,  y){
	this->type_piece = "Pawn";
}

vector<ChessMove> Pawn::getPossibleMoves(const ChessBoard& board) const  {
    int x = this->getX();
    int y = this->getY();
	vector<ChessMove> moves;
    int direction = (this->getColor() == PlayerColor::White) ? -1 : 1;

	int nextX = x + direction;
	if (nextX >= 0 && nextX < 8 && board.getPieceAt(nextX, y) == nullptr) {
        moves.push_back(ChessMove(x, y, nextX, y));

		int startRow = (this->getColor() == PlayerColor::White) ? 6 : 1;
        int doubleNextX = x + 2 * direction;
        if (x == startRow) {
			if (doubleNextX >= 0 && doubleNextX < 8 && board.getPieceAt(doubleNextX, y) == nullptr) {
				moves.push_back(ChessMove(x, y, doubleNextX, y));
			}
		}
    }

    int diagY[] = {y - 1, y + 1};
    for (int nextY : diagY) {
        if (nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8) {
            ChessPiece* target = board.getPieceAt(nextX, nextY);
            if (target != nullptr && target->getColor() != this->getColor()) {
                moves.push_back(ChessMove(x, y, nextX, nextY));
            }
        }
    }
    return moves;
}

#pragma package(smart_init)
