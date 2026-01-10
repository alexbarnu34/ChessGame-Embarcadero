//---------------------------------------------------------------------------

#ifndef ChessGameH
#define ChessGameH
#include "ChessBoard.h"
#include "ChessState.h"
//---------------------------------------------------------------------------

ChessGame::instance=nullptr;
class ChessGame{
	ChessBoard board;
	ChessState state;
	static ChessGame* instance;

	ChessGame(){}

	public:
	void initGame();

	ChessGame copy(const ChessGame& obj)=delete;

	static ChessGame* getInstance();

};

#endif
