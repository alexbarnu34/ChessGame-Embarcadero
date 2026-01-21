//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChessBoard.h"
#include "ChessState.h"
#include <ChessPiece.h>
#include "ChessMove.h"
#include "ChessRules.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
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

void ChessBoard::movePiece(int fromX, int fromY, int toX, int toY) {
	ChessPiece* pieceToMove = t[fromX][fromY];
	ChessPiece* targetPiece = t[toX][toY];

    if (targetPiece != nullptr) {
        delete targetPiece;
    }

    t[toX][toY] = pieceToMove;
    t[fromX][fromY] = nullptr;

}

void ChessBoard::InitializeDefaultPosition() {
	clear();

	t[0][0] = new Rook(PlayerColor::Black, 0, 0);
	t[0][1] = new Knight(PlayerColor::Black, 0, 1);
	t[0][2] = new Bishop(PlayerColor::Black, 0, 2);
	t[0][3] = new Queen(PlayerColor::Black, 0, 3);
	t[0][4] = new King(PlayerColor::Black, 0, 4);
	t[0][5] = new Bishop(PlayerColor::Black, 0, 5);
	t[0][6] = new Knight(PlayerColor::Black, 0, 6);
	t[0][7] = new Rook(PlayerColor::Black, 0, 7);
	for (int i = 0; i < 8; i++) t[1][i] = new Pawn(PlayerColor::Black, 1, i);

    for (int i = 0; i < 8; i++) t[6][i] = new Pawn(PlayerColor::White, 6, i);
	t[7][0] = new Rook(PlayerColor::White, 7, 0);
	t[7][1] = new Knight(PlayerColor::White, 7, 1);
	t[7][2] = new Bishop(PlayerColor::White, 7, 2);
	t[7][3] = new Queen(PlayerColor::White, 7, 3);
	t[7][4] = new King(PlayerColor::White, 7, 4);
	t[7][5] = new Bishop(PlayerColor::White, 7, 5);
	t[7][6] = new Knight(PlayerColor::White, 7, 6);
	t[7][7] = new Rook(PlayerColor::White, 7, 7);
}

