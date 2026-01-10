//---------------------------------------------------------------------------

#ifndef ChessBoardH
#define ChessBoardH
//---------------------------------------------------------------------------
#include <vector>

class ChessPiece;
class ChessMove;
class ChessState;

class ChessBoard{
	ChessPiece* t[8][8];
	public:
	ChessBoard();
	ChessPiece* getPieceAt(int x , int y);
	void setPieceAt(int x, int y, ChessPiece* piece);
	void movePiece(int fromX, int fromY, int toX, int toY);
	void InitializeDefaultPosition();
	bool isKingInCheckAfterMove(ChessMove& move,ChessState* state);
	bool tryMove(ChessMove& move);
};
#endif
