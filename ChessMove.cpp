//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessMove.h"
#include "ChessPiece.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ChessMove::ChessMove(int  fromX,int  fromY,int toX, int toY){
  this->fromX= fromX;
  this->fromY= fromY;
  this->toX = toX;
  this->toY = toY;
  this->piece=nullptr;
};

int ChessMove::getfromX() const {
	return this->fromX;
}

int ChessMove::getfromY() const{
	return this->fromY;
}

int ChessMove::gettoX() const{
	return this->toX;
}

int ChessMove::gettoY()const{
    return this->toY;
}
