object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 355
  ClientWidth = 632
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label5: TLabel
    Left = 224
    Top = 8
    Width = 185
    Height = 25
    Caption = 'ABM Alumnos.dat'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 146
    Top = 57
    Width = 71
    Height = 25
    Caption = 'Codigo:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 136
    Top = 97
    Width = 81
    Height = 25
    Caption = 'Nombre:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 124
    Top = 141
    Width = 93
    Height = 25
    Caption = 'Direccion:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 94
    Top = 192
    Width = 140
    Height = 25
    Caption = 'Fecha de Nac.:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 249
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 248
    Top = 104
    Width = 273
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 248
    Top = 148
    Width = 273
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
  end
  object MaskEdit1: TMaskEdit
    Left = 250
    Top = 192
    Width = 120
    Height = 21
    EditMask = '!99/99/0000;1;_'
    MaxLength = 10
    TabOrder = 3
    Text = '  /  /    '
  end
  object Button1: TButton
    Left = 142
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Guardar'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 285
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Eliminar '
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 400
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Reestructurar'
    TabOrder = 6
    OnClick = Button3Click
  end
end
