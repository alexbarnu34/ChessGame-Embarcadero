//---------------------------------------------------------------------------

#ifndef ChessRulesH
#define ChessRulesH
//---------------------------------------------------------------------------

class ChessMove;
class ChessState;

class ChessRules{
	ChessRules()=delete;
	public:
	static bool isValidMove(ChessMove* move, ChessState* state);

};
#endif
