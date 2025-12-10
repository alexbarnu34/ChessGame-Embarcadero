//---------------------------------------------------------------------------

#ifndef KnightH
#define KnightH
//---------------------------------------------------------------------------
#endif
class Knight:public ChessPiece{
public:
	Knight(PlayerColor color, int x, int y);
	virtual vector<ChessMove> getPosibleMoves(const ChessBoard* board)const override;
};
