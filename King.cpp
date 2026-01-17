//---------------------------------------------------------------------------

#pragma hdrstop

#include "King.h"
//---------------------------------------------------------------------------
using namespace std;

vector<ChessMove> King::getPossibleMoves(const ChessBoard& board) const {
	int x_current = this->getX();
	int y_current = this->getY();
	vector<ChessMove> moves;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

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
