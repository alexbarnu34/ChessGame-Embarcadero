#include "ChessRules.h"
#include "ChessPiece.h"
#include "ChessMove.h"
#include "ChessBoard.h"
#include "ChessState.h"
#pragma package(smart_init)
#include <windows.h>
#include <vector>
#include <string>
using namespace std;


bool ChessRules::isValidMove(ChessMove* move, ChessState* state) {
	if (move->gettoX() < 0 || move->gettoX() > 7 || move->gettoY() < 0 || move->gettoY() > 7) {
		return false;
	}

	ChessPiece* pieceToMove = state->getBoard()->getPieceAt(move->getfromX(), move->getfromY());
	if (pieceToMove == nullptr || pieceToMove->getColor() != state->getColor()) {
		return false;
	}

	ChessPiece* targetPiece = state->getBoard()->getPieceAt(move->gettoX(), move->gettoY());
	if (targetPiece != nullptr && targetPiece->getColor() == pieceToMove->getColor()) {
		return false; 
	}

	vector<ChessMove> possibleMoves = pieceToMove->getPossibleMoves(*(state->getBoard()));
	bool found = false;
	for (const auto& m : possibleMoves) {
		if (m.gettoX() == move->gettoX() && m.gettoY() == move->gettoY()) {
			found = true;
			break;
		}
	}

	if (!found) return false;

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
					if (!board->isKingInCheckAfterMove(m, new ChessState(board, color,GameStatus::Running))) {
                        return false;
                    }
                }
            }
        }
    }
	return true;
}

bool ChessRules::hasValidMoves(PlayerColor color, ChessBoard* board, ChessState* state) {
    OutputDebugString(L"--- Incepe verificarea hasValidMoves ---");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ChessPiece* p = board->getPieceAt(i, j);
            if (p != nullptr && p->getColor() == color) {

                UnicodeString msg = UnicodeString("Verific piesa: ") +
                                    p->getType_piece().c_str() +
                                    " la [" + IntToStr(i) + "," + IntToStr(j) + "]";

                OutputDebugString(msg.c_str());

                vector<ChessMove> possible = p->getPossibleMoves(*board);
                for (auto& m : possible) {
                    if (this->isValidMove(&m, state)) {
                        OutputDebugString(L"  [OK] Am gasit o mutare valida! Jucatorul nu e blocat.");
                        return true;
                    }
                }
            }
        }
    }
    OutputDebugString(L"!!! [FINAL] Nu am gasit nicio mutare valida. Sah-Mat sau Pat!");
    return false;
}

