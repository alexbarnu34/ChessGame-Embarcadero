//---------------------------------------------------------------------------

#ifndef KnightH
#define KnightH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class ChessBoard;
class ChessMove;

class Knight:public ChessPiece{
public:
	Knight(PlayerColor color, int x, int y);
	virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board)const override;
};
#endif
