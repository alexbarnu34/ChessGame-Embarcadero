#ifndef RookH
#define RookH
#include "ChessPiece.h"

class ChessBoard;
class ChessMove;

class Rook:public ChessPiece{
public:
	Rook(PlayerColor color, int x, int y);
	virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board)const override ;
};
#endif
