//---------------------------------------------------------------------------

#pragma hdrstop

#include "Rook.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include <vector>
//---------------------------------------------------------------------------
using namespace std;

Rook::Rook(PlayerColor color,int x, int y):ChessPiece(PlayerColor,int x,int y){

}

vector<ChessMove> Rook::getPossibleMoves(const ChessBoard& board) const {
	int x_current=this->getX();
	int y_current=this->getY();
	vector<ChessMove> moves;

	for(int i=x_current-1;i>=0;i--){
	   ChessPiece* found_piece= board.getPieceAt(i,y_current);
	   if(found_piece == nullptr){
		moves.push_back(ChessMove(x_current,y_current,i,y_current));
	   }else if(found_piece->getColor()!=this->getColor()){
		   moves.push_back(ChessMove(x_current,y_current,found_piece->getX(),found_piece->getY()));
	   }else{
		   break;
	   }
	}

	for(int i=x_current+1;i<8;i++){
	   ChessPiece* found_piece= board.getPieceAt(i,y_current);
	   if(found_piece == nullptr){
		moves.push_back(ChessMove(x_current,y_current,i,y_current));
	   }else if(found_piece->getColor()!=this->getColor()){
		   moves.push_back(ChessMove(x_current,y_current,found_piece->getX(),found_piece->getY()));
	   }else{
		   break;
	   }
	}

	for(int i=y_current-1;i>=0;i--){
	   ChessPiece* found_piece= board.getPieceAt(x_current,i);
	   if(found_piece == nullptr){
		moves.push_back(ChessMove(x_current,y_current,x_current,i));
	   }else if(found_piece->getColor()!=this->getColor()){
		   moves.push_back(ChessMove(x_current,y_current,found_piece->getX(),found_piece->getY()));
	   }else{
		   break;
	   }
	}

	for(int i=y_current+1;i<8;i++){
	   ChessPiece* found_piece= board.getPieceAt(x_current,i);
	   if(found_piece == nullptr){
		moves.push_back(ChessMove(x_current,y_current,x_current,i));
	   }else if(found_piece->getColor()!=this->getColor()){
		   moves.push_back(ChessMove(x_current,y_current,found_piece->getX(),found_piece->getY()));
	   }else{
		   break;
	   }
	}

	return moves;
}
#pragma package(smart_init)
