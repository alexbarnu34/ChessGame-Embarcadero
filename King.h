//---------------------------------------------------------------------------

#ifndef KingH
#define KingH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class King:public class ChessPiece{
	public:
	King(PlayerColor Color,int x, int y):ChessPiece(PlayerColor, int x, int y);
    virtual vector<ChessMove> getPossibleMoves (const CHessBoard& board) const override;
};
#endif
