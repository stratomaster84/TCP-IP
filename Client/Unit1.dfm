object Form1: TForm1
  Left = 249
  Top = 159
  Width = 598
  Height = 665
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Client'
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
    Left = 152
    Top = 16
    Width = 56
    Height = 20
    Caption = #1057#1077#1088#1074#1077#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 152
    Top = 40
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
  object Button1: TButton
    Left = 368
    Top = 24
    Width = 129
    Height = 25
    Caption = 'Connect/Disconnect'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 24
    Top = 96
    Width = 545
    Height = 265
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 607
    Width = 582
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object Edit2: TEdit
    Left = 216
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '192.168.0.62'
  end
  object Edit3: TEdit
    Left = 216
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '112'
  end
  object Memo2: TMemo
    Left = 24
    Top = 376
    Width = 545
    Height = 153
    ScrollBars = ssBoth
    TabOrder = 5
  end
  object Button2: TButton
    Left = 24
    Top = 544
    Width = 75
    Height = 25
    Caption = #1055#1086#1089#1083#1072#1090#1100
    TabOrder = 6
    OnClick = Button2Click
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 189
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 16
    Top = 8
  end
end
