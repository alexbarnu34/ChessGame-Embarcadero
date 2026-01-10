//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessGame.h"
#include "Enum.h"
#include "Knight.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

ChessGame::ChessGame(){
	this->state = new ChessState(this->board, PlayerColor::White);
}

ChessGame* ChessGame::getInstance(){
	if(instance==nullptr){
		instance= new ChessGame();
	}
	return instance;
}

void ChessGame :: initGame(){
      this->state.getBoard()->clear();

	this->state.getBoard()->setPieceAt(1, 0, new Knight(PlayerColor::White,1,0 ));
	this->state.getBoard()->setPieceAt(6, 0, new Knight(PlayeColor::Black,6,0));
}
