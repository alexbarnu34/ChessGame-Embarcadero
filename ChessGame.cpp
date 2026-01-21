//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessGame.h"
#include "Enum.h"
#include "ChessMove.h"
#include "ChessRules.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

ChessGame* ChessGame::instance=nullptr;

ChessGame::ChessGame(){
	this->board = new ChessBoard();
	this->state = new ChessState(this->board, PlayerColor::White,GameStatus::Running);
	this->board->InitializeDefaultPosition();
    initGame();
}

ChessGame* ChessGame::getInstance(){
	if(instance==nullptr){
		instance= new ChessGame();
	}
	return instance;
}

void ChessGame :: initGame(){
	  ChessBoard* b= this->state->getBoard();
	  b->clear();

	b->setPieceAt(0, 0, new Rook(PlayerColor::Black, 0, 0));
    b->setPieceAt(0, 1, new Knight(PlayerColor::Black, 0, 1));
    b->setPieceAt(0, 2, new Bishop(PlayerColor::Black, 0, 2));
    b->setPieceAt(0, 3, new Queen(PlayerColor::Black, 0, 3));
    b->setPieceAt(0, 4, new King(PlayerColor::Black, 0, 4));
    b->setPieceAt(0, 5, new Bishop(PlayerColor::Black, 0, 5));
    b->setPieceAt(0, 6, new Knight(PlayerColor::Black, 0, 6));
	b->setPieceAt(0, 7, new Rook(PlayerColor::Black, 0, 7));

    for (int j = 0; j < 8; j++) {
        b->setPieceAt(1, j, new Pawn(PlayerColor::Black, 1, j));
	}

    for (int j = 0; j < 8; j++) {
        b->setPieceAt(6, j, new Pawn(PlayerColor::White, 6, j));
	}

    b->setPieceAt(7, 0, new Rook(PlayerColor::White, 7, 0));
    b->setPieceAt(7, 1, new Knight(PlayerColor::White, 7, 1));
    b->setPieceAt(7, 2, new Bishop(PlayerColor::White, 7, 2));
    b->setPieceAt(7, 3, new Queen(PlayerColor::White, 7, 3));
    b->setPieceAt(7, 4, new King(PlayerColor::White, 7, 4));
    b->setPieceAt(7, 5, new Bishop(PlayerColor::White, 7, 5));
    b->setPieceAt(7, 6, new Knight(PlayerColor::White, 7, 6));
    b->setPieceAt(7, 7, new Rook(PlayerColor::White, 7, 7));
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

ChessState* ChessGame::getState(){
      return this->state;
}

ChessBoard* ChessGame::getBoard(){
	return this->board;
}
