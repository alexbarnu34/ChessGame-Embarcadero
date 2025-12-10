//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessRules.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool ChessRules::isValidMove(ChessMove* move,ChessState* state){
	  ChessPiece* getPieceToMove= state->getBoard()->getPieceAt(move->gefromX(),move->gettoY());

	  if(getPieceToMove==nullptr){
		return false;
	  }

	  char typepiece=state->getBoard()->getPieceAt(move->gefromX(),move->gettoY())->getType();

	  if(state->getColor()!=getPieceToMove->getColor()){
			return false;
	  }
}