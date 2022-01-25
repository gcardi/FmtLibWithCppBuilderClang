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
  PixelsPerInch = 96
  TextHeight = 15
  object Button1: TButton
    Left = 24
    Top = 24
    Width = 97
    Height = 25
    Action = actTest
    TabOrder = 0
  end
  object ActionList1: TActionList
    Left = 160
    Top = 32
    object actTest: TAction
      Caption = 'Test'
      Hint = 'Just a simple test'
      OnExecute = actTestExecute
    end
  end
end
