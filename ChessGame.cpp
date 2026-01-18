//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessGame.h"
#include "Enum.h"
#include "Knight.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

ChessGame* ChessGame::instance=nullptr;

ChessGame::ChessGame(){
	this->board = new ChessBoard();
	this->state = new ChessState(this->board, PlayerColor::White,GameStatus::Running);
}

ChessGame* ChessGame::getInstance(){
	if(instance==nullptr){
		instance= new ChessGame();
	}
	return instance;
}

void ChessGame :: initGame(){
	  this->state->getBoard()->clear();

	this->state->getBoard()->setPieceAt(1, 0, new Knight(PlayerColor::White,1,0 ));
	this->state->getBoard()->setPieceAt(6, 0, new Knight(PlayerColor::Black,6,0));
}

bool ChessGame::makeMove(int fromX, int fromY, int toX, int toY) {
	ChessMove move(fromX, fromY, toX, toY);
    ChessRules referee;

	if (referee.isValidMove(&move, state)) {

        board->movePiece(fromX, fromY, toX, toY);

        PlayerColor nextColor = (state->getColor() == PlayerColor::White)
                                ? PlayerColor::Black : PlayerColor::White;
        state->setColor(nextColor);

		return true;
    }

	return false;
}
