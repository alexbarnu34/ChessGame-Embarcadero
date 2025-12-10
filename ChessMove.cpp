//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessMove.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ChessMove::ChessMove(int  fromX,int  fromY,int toX, int toY){
  this->fromX= fromX;
  this->fromY= fromY;
  this->toX = toX;
  this->toY = toY;
};

int getfromX() const {
    return this->fromX;
}

int getfromY()const{
	return this->fromY;
}

int gettoX()const{
	return this->toX;
}

int gettoY()const{
    return this->toY;
}
