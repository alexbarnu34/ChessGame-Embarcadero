//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessBoard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ChessBoard::ChessBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			t[i][j] = nullptr;
		}
	}
}

bool ChessBoard::tryMove(ChessMove& move){
	for(auto row:this->t){
		for(auto piece: row){
				if(piece->getX()==move.gefromX() && piece->getY()== move.gefromY()){
					if(move.gettoX()>=0 && move.gettoX()<8 && move.gettoY()>=0 && move.gettoY()<8){
						   if(this->t[(move.gettoX()][(move.gettoY()]!=nullptr && piece->getColor()!=this->t[(move.gettoX()][(move.gettoY()]){
								return true;
						   }
					}
			}
		}
	}
}

bool ChessBoard::isKingInCheckAfterMove(ChessMove& move,ChessState* state){
	int king_poz_x=8;
	int king_poz_y=8;
	vector<int> move_to_x_opponent;
	vector<int> move_to_y_opponent;
	for(auto row:this->t){
		for(auto piece:row){
			if(piece->type_piece=="King" && piece->color==state->getColor()){
				king_poz_x=piece->getX();
				king_poz_y=piece->getY();
			}
		}
	}

	for(auto row:this->t){
		for(auto opponent:row){
			 vector<ChessMove> OpponentPossibleMoves = opponent->getPossibleMoves(state->getBoard()) ;
			 for(auto opponentmove:OpponentPossibleMoves){

			 }
		}
	}

}
