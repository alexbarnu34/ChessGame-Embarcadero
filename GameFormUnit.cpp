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
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
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
