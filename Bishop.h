//---------------------------------------------------------------------------

#ifndef BishopH
#define BishopH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class ChessBoard;
class ChessMove;

class Bishop:public ChessPiece{
	public:
	Bishop(PlayerColor Color,int x, int y);
	virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board)const override ;
};
#endif
