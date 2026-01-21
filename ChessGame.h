//---------------------------------------------------------------------------

#ifndef ChessGameH
#define ChessGameH
#include "ChessBoard.h"
#include "ChessState.h"
//---------------------------------------------------------------------------
class ChessGame{
	ChessBoard* board;
	ChessState* state;
	static ChessGame* instance;

	ChessGame();

	public:
	void initGame();

	ChessGame copy(const ChessGame& obj)=delete;

	static ChessGame* getInstance();

	ChessState* getState();

    ChessBoard* getBoard();

    bool makeMove(int fromX, int fromY, int toX, int toY);

	int selectedX, selectedY;

	bool pieceSelected;
};

#endif
