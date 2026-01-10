//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessPiece.h"
#include "ChessBoard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ChessPiece::ChessPiece(PlayerColor c,int x, int y){
	this->color=c;
	this->PositionX=x;
	this->PositionY=y;
}

PlayerColor ChessPiece::getColor(){
    return this->color;
}

int ChessPiece::getX() const{
	return this->PositionX;
}

int ChessPiece::getY() const{
    return this->PositionY;
}
