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
