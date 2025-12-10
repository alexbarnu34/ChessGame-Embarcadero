//---------------------------------------------------------------------------

#ifndef ChessGameH
#define ChessGameH
//---------------------------------------------------------------------------
#endif

ChessGame::instance=nullptr;
class ChessGame{

	static ChessGame* instance;

	ChessGame(){}

	public:
	ChessGame copy(const ChessGame& obj)=delete;

	static ChessGame* getInstance();

};