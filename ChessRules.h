//---------------------------------------------------------------------------

#ifndef ChessRulesH
#define ChessRulesH
//---------------------------------------------------------------------------
#endif
#include "ChessMove.h"
#include "ChessState.h"
class ChessRules{
	ChessRules()=delete;
	public:
	static bool isValidMove(ChessMove* move, ChessState* state);

};