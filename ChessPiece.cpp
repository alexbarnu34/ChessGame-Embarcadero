#pragma hdrstop

#include "ChessPiece.h"
#include "ChessBoard.h"
#include "ChessMove.h"

#pragma package(smart_init)

ChessPiece::ChessPiece(PlayerColor c,int x, int y){
	this->color=c;
	this->PositionX=x;
	this->PositionY=y;
}

PlayerColor ChessPiece::getColor()const{
    return this->color;
}

int ChessPiece::getX() const{
	return this->PositionX;
}

int ChessPiece::getY() const{
    return this->PositionY;
}

string ChessPiece::getType_piece() const{
    return this->type_piece;
}

void ChessPiece::setX(int x){
	this->PositionX=x;
}

void ChessPiece::setY(int y){
	this->PositionY=y;
}

void ChessPiece::setPositionTo(int toX,int toY){
	this->PositionX= toX;
    this->PositionY= toY;
}

void ChessPiece:: setType_piece(string t_piece){
	this->type_piece=t_piece;
}
