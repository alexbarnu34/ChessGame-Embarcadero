#ifndef ChessPieceH
#define ChessPieceH

#include <vector>
#include "Enum.h"
#include <string>

using namespace std;

class ChessBoard;
class ChessMove;

class ChessPiece {
protected:
	PlayerColor color;
	int PositionX, PositionY;
	string type_piece;

public:
	ChessPiece(PlayerColor c, int x, int y);
	virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board) const = 0;
	virtual ~ChessPiece() = default;
	PlayerColor getColor()const;
	int getX() const;
	int getY() const;
    string getType_piece() const;
	void setX(int x);
	void setY(int y);
    void setPositionTo(int toX,int toY);
    void setType_piece(string t_piece) ;

};
#endif
