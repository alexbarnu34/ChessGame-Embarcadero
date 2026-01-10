//---------------------------------------------------------------------------

#ifndef ChessPieceH
#define ChessPieceH
//---------------------------------------------------------------------------
#include <vector>
#include "Enum.h"
#include "ChessPiece.h"
#include "ChessMove.h"

using namespace std;

class ChessBoard;

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
	int getX() const;
	int getY() const;
};
#endif
