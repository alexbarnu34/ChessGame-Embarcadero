//---------------------------------------------------------------------------

#ifndef ChessStateH
#define ChessStateH
//---------------------------------------------------------------------------
#endif

#include "ChessBoard.h"

enum class PlayerColor {White, Black};
enum class GameStatus {Running, Check, Checkmate, Draw, Abandoned};

class ChessState{
	ChessBoard* board;
	PlayerColor color;
	GameStatus status;
	public:
	ChessState(ChessBoard* board,PlayerColor color,GameStatus status);
	ChessBoard* getBoard();
    PlayerColor* getColor();
};
