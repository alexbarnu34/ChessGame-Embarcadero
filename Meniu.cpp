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
//---------------------------------------------------------------------------

// ... restul de include-uri ...

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    // Oprim orice activitate de rețea care ar putea rula în fundal pe Form1
    IdTCPServer1->Active = false;
    if (IdTCPClient1->Connected()) {
        IdTCPClient1->Disconnect();
    }

    // Închidem tot
    Application->Terminate();
}

void __fastcall TForm1::Button1Click(TObject *Sender) // START SERVER
{
    try {
        // 1. Pornim Serverul
        IdTCPServer1->DefaultPort = 12345;
        IdTCPServer1->Active = true;

        // 2. Creăm instanța și o legăm la variabila GLOBALĂ Form2
        // Nu mai scrie "TForm2 *fereastra =", scrie direct "Form2 ="
        Form2 = new TForm2(this);

        // 3. Setăm culoarea (metoda privată din Form2)
        Form2->setLocalPlayerColor(PlayerColor::White);

        // 4. Afișăm jocul
        Form2->Show();
        this->Hide();
    } catch (const Exception &e) { ShowMessage("Eroare: " + e.Message); }
}

void __fastcall TForm1::Button2Click(TObject *Sender) // CONNECT CLIENT
{
    try {
        IdTCPClient1->Host = Edit1->Text;
        IdTCPClient1->Port = 12345;
        IdTCPClient1->Connect();

        // Legăm la variabila globală Form2
        Form2 = new TForm2(this);
        Form2->setLocalPlayerColor(PlayerColor::Black);

        Form2->Show();
        this->Hide();
    } catch (const Exception &e) { ShowMessage("Eroare: " + e.Message); }
}

void __fastcall TForm1::IdTCPServer1Execute(TIdContext *AContext)
{
   UnicodeString msg = AContext->Connection->IOHandler->ReadLn();

    // Verificăm dacă Form2 există înainte de a-l apela
    if (!msg.IsEmpty() && Form2 != nullptr) {
        TThread::Synchronize(nullptr, [msg]() {
            Form2->ApplyRemoteMove(msg);
        });
    }
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if (IdTCPClient1->Connected()) {
        if (!IdTCPClient1->IOHandler->InputBufferIsEmpty()) {
            UnicodeString msg = IdTCPClient1->IOHandler->ReadLn();
            // ATENȚIE: Trimitem mesajul către Form2
            Form2->ApplyRemoteMove(msg);
        }
    }
}
