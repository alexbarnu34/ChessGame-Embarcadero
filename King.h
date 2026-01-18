//---------------------------------------------------------------------------

#ifndef KingH
#define KingH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class ChessBoard;
class ChessMove;

class King:public  ChessPiece{
	public:
	King(PlayerColor Color,int x, int y);
    virtual vector<ChessMove> getPossibleMoves (const ChessBoard& board) const override;
};
#endif
