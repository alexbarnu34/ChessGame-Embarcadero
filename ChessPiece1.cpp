//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessPiece1.h"
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

int ChessPiece::getX(){
	return this->PositionX;
}

int ChessPiece::getY(){
    return this->PositionY;
}
