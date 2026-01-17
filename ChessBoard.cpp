//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessBoard.h"
#include "ChessState.h"
#include <ChessPiece.h>
#include "ChessMove.h"
#include "ChessRules.h"
#include <vector>
#include <string>
using namespace std;
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
	int fromX = move.getfromX();
    int fromY = move.getfromY();
    int toX = move.gettoX();
    int toY = move.gettoY();

	ChessPiece* piece = t[fromX][fromY];

	if (piece == nullptr) {
		return false;
	}

	if (toX >= 0 && toX < 8 && toY >= 0 && toY < 8) {

		ChessPiece* targetPiece = t[toX][toY];

        if (targetPiece == nullptr) {
            return true;
        }

        if (piece->getColor() != targetPiece->getColor()) {
            return true;
        }
    }

    return false;
}

bool ChessBoard::isKingInCheckAfterMove(ChessMove& move, ChessState* state) {

	ChessPiece* pieceToMove = getPieceAt(move.getfromX(), move.getfromY());
	ChessPiece* capturedPiece = getPieceAt(move.gettoX(), move.gettoY());

	setPieceAt(move.gettoX(), move.gettoY(), pieceToMove);
	setPieceAt(move.getfromX(), move.getfromY(), nullptr);

	ChessRules referee;
    bool inCheck = referee.isChecked(state->getColor(), this);

	setPieceAt(move.getfromX(), move.getfromY(), pieceToMove);
    setPieceAt(move.gettoX(), move.gettoY(), capturedPiece);

    return inCheck;
}

void ChessBoard::clear() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (t[i][j] != nullptr) {
                delete t[i][j];
				t[i][j] = nullptr;
            }
        }
    }
}

void ChessBoard::setPieceAt(int x, int y, ChessPiece* piece) {
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		t[x][y] = piece;
	}
}

ChessPiece* ChessBoard::getPieceAt(int x, int y) const {
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		return t[x][y];
    }
    return nullptr;
}
