//---------------------------------------------------------------------------

#ifndef QueenH
#define QueenH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class ChessBoard;
class ChessMove;

class Queen:public ChessPiece{
	public:
	Queen(PlayerColor Color, int x, int y);
    virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board) const override;
};
#endif
