//---------------------------------------------------------------------------

#ifndef KnightH
#define KnightH
#include "ChessMove.h"
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class ChessPiece;
class ChessBoard;
class Knight:public ChessPiece{
public:
	Knight(PlayerColor color, int x, int y);
	virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board)const override;
};
#endif
