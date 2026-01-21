//---------------------------------------------------------------------------

#ifndef ChessStateH
#define ChessStateH
#include "Enum.h"
//---------------------------------------------------------------------------

//enum class PlayerColor {White, Black};
//enum class GameStatus {Running, Check, Checkmate, Draw, Abandoned};

class ChessBoard;

class ChessState{
	ChessBoard* board;
	PlayerColor color;
	GameStatus status;
	public:
    ChessState();
	ChessState(ChessBoard* board,PlayerColor color,GameStatus status);
	ChessBoard* getBoard();
	PlayerColor getColor() const;
    void setColor(PlayerColor newColor);
};
#endif


