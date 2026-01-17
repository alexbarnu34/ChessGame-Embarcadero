//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessRules.h"
#include "ChessPiece.h"
#include "ChessMove.h"
#include "ChessBoard.h"
#include "ChessState.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <vector>
#include <string>
using namespace std;


bool ChessRules::isValidMove(ChessMove* move,ChessState* state){
	  ChessPiece* getPieceToMove= state->getBoard()->getPieceAt(move->getfromX(),move->gettoY());

	  if(getPieceToMove==nullptr){
		return false;
	  }

	  string typepiece=state->getBoard()->getPieceAt(move->getfromX(),move->gettoY())->getType_piece();

	  if(state->getColor()!=getPieceToMove->getColor()){
			return false;
	  }

	  vector<ChessMove> possiblemoves= getPieceToMove->getPossibleMoves(*(state->getBoard()));
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

	  if (state->getBoard()->isKingInCheckAfterMove(*move, state)) {
		return false;
	}

	  return true;
}

/*
bool ChessRules::isValidMove(ChessMove* move, ChessState* state) {

    // (PAS 1) VERIFICARE LIMITĂ (Out of Bounds) - MUTATĂ SUS
    // Se verifică destinația. Simplificat din logica ta:
    if (move->getToX() < 0 || move->getToX() >= 8 ||
        move->getToY() < 0 || move->getToY() >= 8) {
        return false;
    }

    // Obținem piesa de mutat (de la poziția de start)
    ChessPiece* pieceToMove = state->getBoard()->getPieceAt(move->getFromX(), move->getFromY());

    // (PAS 2) VERIFICARE DE BAZĂ: Piesă/Culoare
    if (pieceToMove == nullptr) {
        return false; // Nu există piesă la start
    }
    if (state->getColor() != pieceToMove->getColor()) {
        return false; // Nu e tura ta
    }

    // (PAS 3) VERIFICARE DESTINAȚIE INIȚIALĂ (Piesă proprie?)
    ChessPiece* pieceToPosition = state->getBoard()->getPieceAt(move->getToX(), move->getToY());
    if (pieceToPosition != nullptr && pieceToMove->getColor() == pieceToPosition->getColor()) {
        return false; // Destinația este ocupată de piesa ta
    }

    // (PAS 4) VERIFICARE POLIMORFICĂ (Regula de mișcare a piesei)
    std::vector<ChessMove> possibleMoves = pieceToMove->getPossibleMoves(state->getBoard());

    bool moveFound = false;
    for (const auto& possibleMove : possibleMoves) {
        // ATENȚIE: possibleMove este obiect (punct!)
        if (possibleMove.getToX() == move->getToX() && possibleMove.getToY() == move->getToY()) {
            moveFound = true;
            break;
        }
    }
    if (!moveFound) {
        return false; // Mutarea este ilegală (ex: Calul mută drept)
    }

    // (PAS 5) VERIFICARE FINALĂ (ȘAH/SIGURANȚĂ REGE) - Urmează
    // Aici vom apela funcția isKingInCheckAfterMove

    return true; // Toate verificările au trecut. Mutarea este legală.
}
*/
