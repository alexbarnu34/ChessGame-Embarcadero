#ifndef ChessStateH
#define ChessStateH
#include "Enum.h"

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
    GameStatus getStatus() const;
	void setColor(PlayerColor newColor);
    void setStatus(GameStatus stat);
};
#endif


