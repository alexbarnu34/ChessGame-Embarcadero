//---------------------------------------------------------------------------

#ifndef KnightH
#define KnightH
//---------------------------------------------------------------------------
#endif
#include "ChessPiece1.h"
#include "ChessMove.h"
#include "ChessBoard.h"
class Knight:public ChessPiece{
public:
	Knight(PlayerColor color, int x, int y);
	virtual vector<ChessMove> getPosibleMoves(const ChessBoard* board)const override;
};
