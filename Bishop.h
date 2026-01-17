//---------------------------------------------------------------------------

#ifndef BishopH
#define BishopH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class Bishop:public class ChessPiece{
	public:
	Bishop(PlayerColor Color,int x, int y);
	virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board)const override ;
};
#endif
