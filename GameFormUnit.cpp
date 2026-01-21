//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GameFormUnit.h"
#include "ChessGame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner): TForm(Owner)
{
	game = ChessGame::getInstance();
    fromX = -1;
    fromY = -1;
	isPieceSelected = false;

    game->getState()->getBoard()->InitializeDefaultPosition();
}
//---------------------------------------------------------------------------
#include "GameFormUnit.h"
void __fastcall TForm2::btnBackClick(TObject *Sender)
{
	this->Close();
    if (this->Owner != nullptr) {
		((TForm*)Owner)->Show();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	ChessGame::getInstance()->initGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
		Application->Terminate();
}

void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int cellSize = 60;

	int clickedRow = Y / cellSize;
	int clickedCol = X / cellSize;

	if (!pieceSelected) {
        ChessPiece* p = game->getState()->getBoard()->getPieceAt(clickedRow, clickedCol);

		if (p != nullptr && p->getColor() == game->getState()->getColor()) {
			selectedX = clickedRow;
            selectedY = clickedCol;
            pieceSelected = true;
        }
    }
	else {
		if (game->makeMove(selectedX, selectedY, clickedRow, clickedCol)) {
			this->Invalidate();
		} else {
			ShowMessage("Mutare nepermisa!");
		}

		pieceSelected = false;
    }
}

void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int cellSize = 60;

	int clickedRow = Y / cellSize;
	int clickedCol = X / cellSize;

	if (clickedRow > 7 || clickedCol > 7) return;

	if (!game->pieceSelected) {
		ChessPiece* p = game->getState()->getBoard()->getPieceAt(clickedRow, clickedCol);

        if (p != nullptr && p->getColor() == game->getState()->getColor()) {
            game->selectedX = clickedRow;
            game->selectedY = clickedCol;
            game->pieceSelected = true;

            this->Invalidate();
        }
    }
    else {
        // --- AL DOILEA CLICK: Mutarea piesei ---
		// Încercăm să facem mutarea prin ChessGame
        if (game->makeMove(game->selectedX, game->selectedY, clickedRow, clickedCol)) {
			// Mutare reușită! (makeMove a schimbat deja rândul în spate)
        } else {
			//pot pune mesaj ca nu e posibil
        }

        game->pieceSelected = false;

		this->Invalidate();
    }
}

void __fastcall TForm2::FormPaint(TObject *Sender)
{
    int size = 60;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Culori simple pentru pătrățele
            Canvas->Brush->Color = ((i + j) % 2 == 0) ? clWhite : clSilver;

            // Evidențiem pătrățelul selectat
            if (game->pieceSelected && i == game->selectedX && j == game->selectedY) {
                Canvas->Brush->Color = clYellow;
            }

            Canvas->FillRect(Rect(j * size, i * size, (j + 1) * size, (i + 1) * size));

            // Desenăm textul piesei
            ChessPiece* p = game->getBoard()->getPieceAt(i, j);
            if (p != nullptr) {
                Canvas->Brush->Style = bsClear;
                Canvas->Font->Color = (p->getColor() == PlayerColor::White) ? clBlue : clRed;
                Canvas->TextOut(j * size + 10, i * size + 20, p->getType_piece().c_str());
                Canvas->Brush->Style = bsSolid;
            }
        }
    }
}
