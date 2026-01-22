#include <vcl.h>
#pragma hdrstop

#include "Meniu.h"
#include "GameFormUnit.h"
#include <System.Classes.hpp>

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    IdTCPServer1->Active = false;
    if (IdTCPClient1->Connected()) {
        IdTCPClient1->Disconnect();
    }

    Application->Terminate();
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    try {
        IdTCPServer1->DefaultPort = 12345;
        IdTCPServer1->Active = true;

        Form2 = new TForm2(this);

        Form2->setLocalPlayerColor(PlayerColor::White);

        Form2->Show();
        this->Hide();
    } catch (const Exception &e) { ShowMessage("Eroare: " + e.Message); }
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    try {
        IdTCPClient1->Host = Edit1->Text;
        IdTCPClient1->Port = 12345;
        IdTCPClient1->Connect();

        Form2 = new TForm2(this);
        Form2->setLocalPlayerColor(PlayerColor::Black);

        Form2->Show();
        this->Hide();
    } catch (const Exception &e) { ShowMessage("Eroare: " + e.Message); }
}

void __fastcall TForm1::IdTCPServer1Execute(TIdContext *AContext)
{
    try {
        if (!AContext->Connection->IOHandler->InputBufferIsEmpty() ||
             AContext->Connection->IOHandler->CheckForDataOnSource(10))
        {
            UnicodeString msg = AContext->Connection->IOHandler->ReadLn();

            if (!msg.IsEmpty()) {
                TThread::Synchronize(nullptr, [this, msg]() {
                    if (Form2 != nullptr) Form2->ApplyRemoteMove(msg);
                });
            }
        }
    } catch (const Exception &e) {
        TThread::Synchronize(nullptr, [this]() {
            if (Form2 && Form2->Visible) {
                Form2->ApplyRemoteMove("QUIT");
            }
        });
    }
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if (IdTCPClient1->Connected()) {
        if (!IdTCPClient1->IOHandler->InputBufferIsEmpty()) {
            UnicodeString msg = IdTCPClient1->IOHandler->ReadLn();
            Form2->ApplyRemoteMove(msg);
        }
    }
}
