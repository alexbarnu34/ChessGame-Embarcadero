//---------------------------------------------------------------------------

#pragma hdrstop

#include "King.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include "Enum.h"
#include <vector>
//---------------------------------------------------------------------------
using namespace std;

King::King(PlayerColor Color, int x, int y ):ChessPiece(Color,x,y){
	this->type_piece = "King";
}

vector<ChessMove> King::getPossibleMoves(const ChessBoard& board) const {
	int x_current = this->getX();
	int y_current = this->getY();
	vector<ChessMove> moves;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
		int nx = x_current + dx[i];
        int ny = y_current + dy[i];

        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			ChessPiece* found_piece = board.getPieceAt(nx, ny);
			if (found_piece == nullptr || found_piece->getColor() != this->getColor()) {
                moves.push_back(ChessMove(x_current, y_current, nx, ny));
            }
        }
    }
    return moves;
}
#pragma package(smart_init)
