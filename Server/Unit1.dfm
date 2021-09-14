object Form1: TForm1
  Left = 195
  Top = 162
  Width = 658
  Height = 406
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Server'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 160
    Top = 8
    Width = 39
    Height = 20
    Caption = #1055#1086#1088#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 348
    Width = 642
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object Memo1: TMemo
    Left = 24
    Top = 48
    Width = 601
    Height = 249
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object Button1: TButton
    Left = 368
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Start Server'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 24
    Top = 312
    Width = 601
    Height = 21
    TabOrder = 3
    OnKeyDown = Edit1KeyDown
  end
  object Edit2: TEdit
    Left = 208
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '112'
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 189
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    OnClientError = ServerSocket1ClientError
    Left = 8
    Top = 8
  end
end
