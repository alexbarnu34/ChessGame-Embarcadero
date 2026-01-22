#include <vcl.h>
#pragma hdrstop

#include "GameFormUnit.h"
#include "ChessGame.h"
#include "ChessPiece.h"
#include "ChessRules.h"
#include <string>
#include <Vcl.XPStyleActnCtrls.hpp>
#include "Meniu.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

__fastcall TForm2::TForm2(TComponent* Owner): TForm(Owner)
{
    game = ChessGame::getInstance();
    game->getState()->getBoard()->InitializeDefaultPosition();
}

void __fastcall TForm2::FormCreate(TObject *Sender)
{
    ChessGame::getInstance()->initGame();
}

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form1->IdTCPServer1->Active = false;
    if (Form1->IdTCPClient1->Connected()) {
        Form1->IdTCPClient1->Disconnect();
    }

    if (this->Visible) {
        Application->Terminate();
    }
}

void __fastcall TForm2::btnBackClick(TObject *Sender)
{
    UnicodeString signal = "QUIT";
    if (Form1->IdTCPServer1->Active) {
        TList *list = Form1->IdTCPServer1->Contexts->LockList();
        try {
            for (int i = 0; i < list->Count; i++) {
                ((TIdContext*)list->Items[i])->Connection->IOHandler->WriteLn(signal);
            }
        } __finally { Form1->IdTCPServer1->Contexts->UnlockList(); }
    }
    else if (Form1->IdTCPClient1->Connected()) {
		Form1->IdTCPClient1->IOHandler->WriteLn(signal);
	}

	Form1->IdTCPServer1->Active = false;
	if (Form1->IdTCPClient1->Connected()) Form1->IdTCPClient1->Disconnect();

	this->Hide();
	Form1->Show();
}

void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int cellSize = 60;
	int clickedRow = Y / cellSize;
    int clickedCol = X / cellSize;

    if (clickedRow > 7 || clickedCol > 7) return;

    if (!game->pieceSelected) {
        ChessPiece* p = game->getState()->getBoard()->getPieceAt(clickedRow, clickedCol);

        if (p != nullptr && p->getColor() == game->getState()->getColor() && p->getColor() == localPlayerColor) {
            game->selectedX = clickedRow;
            game->selectedY = clickedCol;
            game->pieceSelected = true;

            game->currentValidMoves.clear();
            ChessRules referee;
            vector<ChessMove> allPossible = p->getPossibleMoves(*(game->getState()->getBoard()));

            for (auto& m : allPossible) {
                if (referee.isValidMove(&m, game->getState())) {
                    game->currentValidMoves.push_back(m);
                }
            }
            this->Invalidate();
        }
    }
    else {
        if (game->makeMove(game->selectedX, game->selectedY, clickedRow, clickedCol)) {

            UnicodeString moveMsg = IntToStr(game->selectedX) + "," +
                                    IntToStr(game->selectedY) + "," +
                                    IntToStr(clickedRow) + "," +
                                    IntToStr(clickedCol);

            if (Form1->IdTCPServer1->Active) {
                TList *list = Form1->IdTCPServer1->Contexts->LockList();
                try {
                    for (int i = 0; i < list->Count; i++) {
                        TIdContext *Context = (TIdContext *)list->Items[i];
                        Context->Connection->IOHandler->WriteLn(moveMsg);
                    }
                } __finally {
                    Form1->IdTCPServer1->Contexts->UnlockList();
                }
            }
            else if (Form1->IdTCPClient1->Connected()) {
                Form1->IdTCPClient1->IOHandler->WriteLn(moveMsg);
                OutputDebugString(L"CLIENT: Mutare trimisă către server.");
            }

            GameStatus currentStatus = game->getState()->getStatus();
            if (currentStatus != GameStatus::Running) {
                UnicodeString mesaj = "Jocul s-a terminat! ";
                if (currentStatus == GameStatus::WhiteWins) mesaj += "A câștigat Albastru!";
                else if (currentStatus == GameStatus::BlackWins) mesaj += "A câștigat Roșu!";
                else if (currentStatus == GameStatus::Draw) mesaj += "Remiză!";
                ShowMessage(mesaj);
            }
        }

        game->pieceSelected = false;
        game->currentValidMoves.clear();
        this->Invalidate();
    }
}

void __fastcall TForm2::FormPaint(TObject *Sender)
{
    int size = 60;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Canvas->Brush->Color = ((i + j) % 2 == 0) ? clWhite : clSilver;
            if (game->pieceSelected && i == game->selectedX && j == game->selectedY) {
                Canvas->Brush->Color = clYellow;
            }
            Canvas->FillRect(Rect(j * size, i * size, (j + 1) * size, (i + 1) * size));

            for (auto& m : game->currentValidMoves) {
                if (m.gettoX() == i && m.gettoY() == j) {
                    Canvas->Brush->Color = TColor(0x99FF99);
                    Canvas->FillRect(Rect(j * size + 20, i * size + 20, (j + 1) * size - 20, (i + 1) * size - 20));
                }
            }

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

void TForm2::ApplyRemoteMove(UnicodeString msg) {
  if (msg == "QUIT") {
        Form1->IdTCPServer1->Active = false;
        if (Form1->IdTCPClient1->Connected()) {
            Form1->IdTCPClient1->Disconnect();
        }

        ShowMessage("Adversarul a părăsit jocul.");

        this->Hide();
        Form1->Show();
        return;
    }

    try {
        std::unique_ptr<TStringList> list(new TStringList());
        list->CommaText = msg;

        if (list->Count == 4) {
            int x1 = StrToInt(list->Strings[0]);
            int y1 = StrToInt(list->Strings[1]);
            int x2 = StrToInt(list->Strings[2]);
            int y2 = StrToInt(list->Strings[3]);

            game->makeMove(x1, y1, x2, y2);
            this->Invalidate();
        }
    } catch (...) {
        OutputDebugString(L"Eroare la procesarea mesajului.");
    }
}

