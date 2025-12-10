//---------------------------------------------------------------------------

#ifndef ChessMoveH
#define ChessMoveH
//---------------------------------------------------------------------------
#endif

class ChessMove {
	int fromX, fromY;
	int toX, toY;
	ChessPiece* piece;
	public:
	ChessMove(int  fromX,int  fromY,int toX, int toY);
	int gefromX()const;
	int gefromY()const;
	int gettoX()const;
	int gettoY()const;
};