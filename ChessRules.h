//---------------------------------------------------------------------------

#ifndef ChessRulesH
#define ChessRulesH
#include "Enum.h"
//---------------------------------------------------------------------------
class ChessBoard;
class ChessMove;
class ChessState;

class ChessRules{
	public:
	ChessRules()=default;
	bool isValidMove(ChessMove* move, ChessState* state);
	bool isChecked(PlayerColor color, ChessBoard* board);
    bool isCheckmate(PlayerColor color, ChessBoard* board)
};
#endif
