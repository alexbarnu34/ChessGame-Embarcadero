//---------------------------------------------------------------------------

#ifndef ChessPiece1H
#define ChessPiece1H
//---------------------------------------------------------------------------
#endif
#include <vector>
#include <ChessMove.h>

using namespace std;

class ChessPiece {
private:
	PlayerColor color;
	int PositionX, PositionY;
    char type_piece;

public:
    ChessPiece(PlayerColor c, int x, int y);
	virtual vector<ChessMove> getPossibleMoves(const ChessBoard& board) const = 0;
	virtual ~ChessPiece() = default;
	PlayerColor getColor()const;
	int getX();
    int getY();
};