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
  Menu = MainMenu1
  OldCreateOrder = True
  OnMouseDown = FormMouseDown
  PixelsPerInch = 96
  TextHeight = 15
  object Edit1: TEdit
    Left = 96
    Top = 40
    Width = 121
    Height = 23
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 232
    Top = 40
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 367
    Top = 40
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'Edit3'
  end
  object StringGrid1: TStringGrid
    Left = 31
    Top = 144
    Width = 578
    Height = 289
    DefaultColWidth = 30
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
    OnClick = StringGrid1Click
  end
  object RadioButton1: TRadioButton
    Left = 511
    Top = 17
    Width = 113
    Height = 17
    Caption = 'circulo'
    Checked = True
    TabOrder = 4
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 511
    Top = 40
    Width = 113
    Height = 17
    Caption = 'Pintar'
    TabOrder = 5
  end
  object MainMenu1: TMainMenu
    Left = 16
    object MenuEnt1: TMenuItem
      Caption = 'Menu Ent'
      object SumaDig1: TMenuItem
        Caption = 'SumaDig'
        OnClick = SumaDig1Click
      end
      object SumaDig2: TMenuItem
        Caption = 'SumaDigPrimos'
        OnClick = SumaDig2Click
      end
      object DevuelveDigMenor1: TMenuItem
        Caption = 'DevuelveDigMenor'
        OnClick = DevuelveDigMenor1Click
      end
    end
    object Cadenas1: TMenuItem
      Caption = 'Cadenas'
    end
    object Vectores1: TMenuItem
      Caption = 'Vectores'
      object SumadeElem1: TMenuItem
        Caption = 'SumadeElem'
      end
    end
    object Matrices1: TMenuItem
      Caption = 'Matrices'
      object CargarMatriz21: TMenuItem
        Caption = 'CargarMatriz^2'
        OnClick = CargarMatriz21Click
      end
    end
  end
end
