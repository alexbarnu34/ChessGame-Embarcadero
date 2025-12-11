//---------------------------------------------------------------------------

#ifndef ChessBoardH
#define ChessBoardH
//---------------------------------------------------------------------------
#endif
#include <ChessMove.h>
class ChessBoard{
	ChessPiece* [8][8] t;
	public:
	ChessBoard();
	ChessPiece* getPieceAt(int x , int y);
	void setPieceAt(int x, int y, ChessPiece* piece);
	void movePiece(int fromX, int fromY, int toX, int toY);
	void InitializeDefaultPosition();
	bool isKingInCheckAfterMove(ChessMove& move,ChessState* state);
    bool tryMove(ChessMove& move);
};
