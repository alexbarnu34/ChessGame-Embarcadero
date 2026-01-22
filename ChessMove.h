#ifndef ChessMoveH
#define ChessMoveH

class ChessPiece;

class ChessMove {
	int fromX, fromY;
	int toX, toY;
	ChessPiece* piece;
	public:
	ChessMove(int  fromX,int  fromY,int toX, int toY);
	int getfromX()const;
	int getfromY()const;
	int gettoX()const;
	int gettoY()const;
};
#endif
