//---------------------------------------------------------------------------

#ifndef ChessRulesH
#define ChessRulesH
//---------------------------------------------------------------------------

class ChessMove;
class ChessState;

class ChessRules{
	ChessRules()=default;
	public:
	bool isValidMove(ChessMove* move, ChessState* state);
	bool isChecked(PlayerColor color, ChessBoard* board);

};
#endif
