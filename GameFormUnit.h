//---------------------------------------------------------------------------

#ifndef GameFormUnitH
#define GameFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.ToolWin.hpp>
#include <IdContext.hpp>
#include "Enum.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class ChessGame;

class TForm2 : public TForm
{
__published:
	TActionMainMenuBar *ActionMainMenuBar1;
	TActionMainMenuBar *ActionMainMenuBar2;
	TButton *btnBack;
	void __fastcall btnBackClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall FormPaint(TObject *Sender);
private:

	ChessGame* game;
    PlayerColor localPlayerColor;

public:
	__fastcall TForm2(TComponent* Owner);
	void ApplyRemoteMove(UnicodeString msg);
    void setLocalPlayerColor(PlayerColor color) {
        localPlayerColor = color;
    }
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
