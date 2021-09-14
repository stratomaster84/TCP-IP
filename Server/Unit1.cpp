//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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

void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        if(ServerSocket1->Socket->ActiveConnections != 1)
                StatusBar1->SimpleText =  "Попытка второго соединения";
        else
                StatusBar1->SimpleText =  "Соединение разорвано";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString _msg = Socket->ReceiveText();
        Memo1->Lines->Add(_msg);
        Socket->SendText(_msg);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ServerSocket1->Port = StrToInt(Edit2->Text);
        ServerSocket1->Open();
        StatusBar1->SimpleText = "Сервер прослушивает порт " + IntToStr(ServerSocket1->Port);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == VK_RETURN){
        if(!ServerSocket1->Socket->ActiveConnections){
                StatusBar1->SimpleText = "Соединение не установлено";
        }
        else{
                ServerSocket1->Socket->Connections[0]->SendText("Сервер:  " + Edit1->Text);
                Memo1->Lines->Add("Сервер:  " + Edit1->Text);
                Edit1->Text = "";
        }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
       StatusBar1->SimpleText = "Ошибка!";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
        ServerSocket1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        if(ServerSocket1->Socket->ActiveConnections != 1){
                Socket->Close();
                return;
        }

        StatusBar1->SimpleText = "Соединение с IP: " +
                Socket->RemoteAddress + " установлено";

}
//---------------------------------------------------------------------------


