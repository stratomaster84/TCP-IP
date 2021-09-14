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


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(ClientSocket1->Active) ClientSocket1->Close();
        if(Edit2->Text == "Главный сервер"){
                ClientSocket1->Port = StrToInt(Edit3->Text);
                ClientSocket1->Address = "192.168.0.62";
                ClientSocket1->Open();
        }
        else if(Edit2->Text.Length() > 0){
                ClientSocket1->Port = StrToInt(Edit3->Text);
                ClientSocket1->Address = Edit2->Text;
                ClientSocket1->Open();
        }

}
//---------------------------------------------------------------------------



void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
        Memo1->Lines->Add(Socket->ReceiveText());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        StatusBar1->SimpleText =
                "Соединение с сервером установлено";

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        StatusBar1->SimpleText = "Ошибка!";
        ErrorCode = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{

      ClientSocket1->Close();
      StatusBar1->SimpleText = "Соединение разорвано";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
        ClientSocket1->Close();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
                if(ClientSocket1->Active){
                        int i,len = Memo2->Lines->Count-1;
                        ClientSocket1->Socket->SendText("Я:  " + Memo2->Lines->Strings[0]);
                        for(i= 1;i<len;i++)
                                ClientSocket1->Socket->SendText("      " + Memo2->Lines->Strings[i] + "\r\n");
                        ClientSocket1->Socket->SendText("      " + Memo2->Lines->Strings[i]);
                        Memo2->Clear();
                }
                else
                       StatusBar1->SimpleText =
                                "Соединение не установлено";



}
//---------------------------------------------------------------------------

