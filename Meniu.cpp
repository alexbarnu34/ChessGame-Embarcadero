//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Meniu.h"
#include "GameFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
#include "Meniu.h"
#include "GameFormUnit.h"
void __fastcall TForm1::btnStartClick(TObject *Sender)
{
   this->Hide();
   TForm2 *fereastraJoc = new TForm2(this);
   fereastraJoc->Show();
}
//---------------------------------------------------------------------------

