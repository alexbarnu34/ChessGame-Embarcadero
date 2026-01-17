//---------------------------------------------------------------------------

#ifndef QueenH
#define QueenH
#include "ChessPiece.h"
//---------------------------------------------------------------------------
class Queen:public class ChessPiece{
	public:
	Queen(PlayerColor Color, int x, int y);
    virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board) const override;
};
#endif
