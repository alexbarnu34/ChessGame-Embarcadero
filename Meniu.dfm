object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClick = Button1Click
  TextHeight = 15
  object Button1: TButton
    Left = 152
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Start Server'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 223
    Top = 256
    Width = 121
    Height = 23
    TabOrder = 1
    Text = '127.0.0.1'
  end
  object Button2: TButton
    Left = 344
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Connect Server'
    TabOrder = 2
    OnClick = Button2Click
  end
  object IdTCPServer1: TIdTCPServer
    Bindings = <>
    DefaultPort = 0
    OnExecute = IdTCPServer1Execute
    Left = 576
    Top = 32
  end
  object IdTCPClient1: TIdTCPClient
    ConnectTimeout = 0
    Port = 0
    ReadTimeout = -1
    Left = 576
    Top = 96
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 560
    Top = 360
  end
end
