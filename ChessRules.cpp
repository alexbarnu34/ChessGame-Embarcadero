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


bool ChessRules::isChecked(PlayerColor color, ChessBoard* board) {
    int kingX = -1;
    int kingY = -1;

	for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
			ChessPiece* p = board->getPieceAt(i, j);

            if (p != nullptr && p->getColor() == color && p->getType_piece() == "King") {
                kingX = i;
                kingY = j;
				break;
			}
		}
		if (kingX != -1) break;
    }

	if (kingX == -1) return false;

    for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ChessPiece* enemyPiece = board->getPieceAt(i, j);

			if (enemyPiece != nullptr && enemyPiece->getColor() != color) {
				vector<ChessMove> enemyMoves = enemyPiece->getPossibleMoves(*board);

				for (const auto& move : enemyMoves) {
					if (move.gettoX() == kingX && move.gettoY() == kingY) {
						return true;
                    }
				}
			}
		}
	}

	return false;
}

bool ChessRules::isCheckmate(PlayerColor color, ChessBoard* board) {
	if (!isChecked(color, board)) return false;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ChessPiece* p = board->getPieceAt(i, j);
			if (p != nullptr && p->getColor() == color) {
				vector<ChessMove> moves = p->getPossibleMoves(*board);
				for (auto& m : moves) {
					if (!board->isKingInCheckAfterMove(m, new ChessState(board, color))) {
                        return false;
                    }
                }
            }
        }
    }
	return true;
}

