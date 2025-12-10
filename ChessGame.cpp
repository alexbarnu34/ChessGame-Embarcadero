//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessGame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ChessGame* ChessGame::getInstance(){
	if(instance==nullptr){
		instance= new ChessGame();
	}
	return instance;
}

