//---------------------------------------------------------------------------

#ifndef PawnH
#define PawnH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class ChessBoard;
class ChessMove;

class Pawn :public ChessPiece{
	Pawn(PlayerColor Color, int x, int y);
    virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board) const override;
};
#endif
