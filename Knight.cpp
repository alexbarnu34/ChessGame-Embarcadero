//---------------------------------------------------------------------------

#pragma hdrstop

#include "Knight.h"
#include "ChessBoard.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
Knight::Knight(PlayerColor color, int x, int y): ChessPiece(color, x, y)
{

}

#include <vector> // Asigură-te că e prima linie
#include "Knight.h"
#include "ChessMove.h"

// ... (constructorul rămâne la fel)

// 1. Verificăm semnătura: scoatem 'override' și folosim 'std::' peste tot
vector<ChessMove> Knight::getPossibleMoves(const ChessBoard& board) const  {
    vector<ChessMove> moves;

    // 2. Definim coordonatele relativ la poziția curentă 🐴
    // Calul se mișcă: (±1, ±2) și (±2, ±1)
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    // 3. Obținem coordonatele actuale o singură dată pentru eficiență
    int x_actual = this->getX();
    int y_actual = this->getY();

    for (int i = 0; i < 8; i++) {
        int poz_x = x_actual + dx[i];
        int poz_y = y_actual + dy[i];

        // 4. Verificăm dacă suntem în interiorul tablei (0-7) 🏁
        if (poz_x >= 0 && poz_x < 8 && poz_y >= 0 && poz_y < 8) {
            // Adăugăm mutarea folosind constructorul clasei ChessMove
            moves.push_back(ChessMove(x_actual, y_actual, poz_x, poz_y));
        }
    }

    return moves;
}
