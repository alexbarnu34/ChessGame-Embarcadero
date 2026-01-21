//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessState.h"
#include "ChessBoard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ChessState::ChessState(ChessBoard* board, PlayerColor color, GameStatus status){
	this->board= board;
	this->color=color;
	this->status=status;
}

ChessBoard* ChessState::getBoard(){
	return this->board;
}

PlayerColor ChessState::getColor()const {
    return this->color;
}

void ChessState:: setColor(PlayerColor newColor) {
    this->color = newColor;
}
