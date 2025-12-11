//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessRules.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <vector>
using namespace std;
bool ChessRules::isValidMove(ChessMove* move,ChessState* state){
	  ChessPiece* getPieceToMove= state->getBoard()->getPieceAt(move->gefromX(),move->gettoY());

	  if(getPieceToMove==nullptr){
		return false;
	  }

	  char typepiece=state->getBoard()->getPieceAt(move->gefromX(),move->gettoY())->getType();

	  if(state->getColor()!=getPieceToMove->getColor()){
			return false;
	  }

	  vector<ChessMove> possiblemoves= getPieceToMove->getPossibleMoves(state->getBoard());
	  vector<ChessMove> goToMove;
	  for(auto possiblemove: possiblemoves){
			if(possiblemove.gettoX()== move ->gettoX() && possiblemove.gettoY() == move ->gettoY()){
				goToMove.push_back(possiblemove);
			}
	  }

	  if(goToMove.empty()){
			return false;
	  }

	  ChessPiece* getPieceToPosition=state->getBoard()->getPieceAt(move->gettoX(),move->gettoY());
	  if(getPieceToPosition!=nullptr && getPieceToMove->getColor()==getPieceToPosition->getColor()){
		return false;
	  }

	  if((move->gettoX()>=0 && move->gettoX()<8)==false){
		return false;
	  }else if((move->gettoY()>=0 && move->gettoY()<8)==false){
		return false;
	  }

	  return true;
}
