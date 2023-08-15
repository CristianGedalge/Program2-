object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 302
  ClientWidth = 649
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 40
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 34
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 136
    Top = 106
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit2'
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 168
    Width = 585
    Height = 49
    ColCount = 14
    DefaultColWidth = 40
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 4
    RowHeights = (
      24)
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 296
    Top = 16
  end
end
