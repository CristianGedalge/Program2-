object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 400
  ClientWidth = 646
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 16
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 160
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 311
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
  end
  object StringGrid1: TStringGrid
    Left = 112
    Top = 80
    Width = 320
    Height = 33
    DefaultColWidth = 30
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
  end
  object StringGrid2: TStringGrid
    Left = 112
    Top = 119
    Width = 313
    Height = 242
    ColCount = 3
    DefaultColWidth = 35
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 72
    object NEnt1: TMenuItem
      Caption = 'NEnt'
      object SumaDigitos1: TMenuItem
        Caption = 'SumaDigitos'
        OnClick = SumaDigitos1Click
      end
      object SumaDig1: TMenuItem
        Caption = 'SumaDigPares'
        OnClick = SumaDig1Click
      end
      object SumaDigImpar1: TMenuItem
        Caption = 'SumaDigImpar'
        OnClick = SumaDigImpar1Click
      end
      object SumaDigPrimos1: TMenuItem
        Caption = 'SumaDigPrimos'
        OnClick = SumaDigPrimos1Click
      end
      object MenorDig1: TMenuItem
        Caption = 'MenorDig'
        OnClick = MenorDig1Click
      end
      object MenorAlFinal1: TMenuItem
        Caption = 'MenorAlFinal'
        OnClick = MenorAlFinal1Click
      end
      object OrdenarMayaMen1: TMenuItem
        Caption = 'OrdenarMayaMen'
        OnClick = OrdenarMayaMen1Click
      end
      object MayorAlFinal1: TMenuItem
        Caption = 'MayorAlFinal'
        OnClick = MayorAlFinal1Click
      end
      object OrdenarMenaMay1: TMenuItem
        Caption = 'OrdenarMenaMay'
        OnClick = OrdenarMenaMay1Click
      end
    end
    object Cadenas1: TMenuItem
      Caption = 'Cadenas'
      object Cant1: TMenuItem
        Caption = 'CantVocales'
        OnClick = Cant1Click
      end
      object Inverso11: TMenuItem
        Caption = 'Inverso 1'
        OnClick = Inverso11Click
      end
      object Inverso21: TMenuItem
        Caption = 'Inverso 2'
        OnClick = Inverso21Click
      end
      object Inverso31: TMenuItem
        Caption = 'Inverso 3'
        OnClick = Inverso31Click
      end
      object Inverso41: TMenuItem
        Caption = 'Inverso 4'
        OnClick = Inverso41Click
      end
      object Inverso51: TMenuItem
        Caption = 'Inverso 5'
        OnClick = Inverso51Click
      end
      object Inverso61: TMenuItem
        Caption = 'Inverso 6'
        OnClick = Inverso61Click
      end
      object Inverso71: TMenuItem
        Caption = 'Inverso 7'
        OnClick = Inverso71Click
      end
      object EsAlfabetochar1: TMenuItem
        Caption = 'EsAlfabeto(char)'
        OnClick = EsAlfabetochar1Click
      end
      object EliminarNoLetras1: TMenuItem
        Caption = 'EliminarNoLetras'
        OnClick = EliminarNoLetras1Click
      end
    end
    object Vectores1: TMenuItem
      Caption = 'Vectores'
      object Dimensionar1: TMenuItem
        Caption = 'Dimensionar'
        OnClick = Dimensionar1Click
      end
      object CargarRandom1: TMenuItem
        Caption = 'CargarRandom'
        OnClick = CargarRandom1Click
      end
      object SumadeElementos1: TMenuItem
        Caption = 'SumadeElementos'
        OnClick = SumadeElementos1Click
      end
      object SumadeElem21: TMenuItem
        Caption = 'SumadeElem2'
        OnClick = SumadeElem21Click
      end
      object SumadeElem31: TMenuItem
        Caption = 'SumadeElem3'
        OnClick = SumadeElem31Click
      end
      object BusquedaBinaria1: TMenuItem
        Caption = 'BusquedaBinaria'
        OnClick = BusquedaBinaria1Click
      end
      object Verificarsiestaordenado1: TMenuItem
        Caption = 'VerificarSiEstaOrden'
        OnClick = Verificarsiestaordenado1Click
      end
      object BubbleSort1: TMenuItem
        Caption = 'BubbleSort'
        OnClick = BubbleSort1Click
      end
      object SelectSort1: TMenuItem
        Caption = 'SelectSort'
        OnClick = SelectSort1Click
      end
      object VectoraNum1: TMenuItem
        Caption = 'VectoraNum'
        OnClick = VectoraNum1Click
      end
      object NumaVector1: TMenuItem
        Caption = 'NumaVector'
        OnClick = NumaVector1Click
      end
      object Insertar1: TMenuItem
        Caption = ' InsertarNumEnVectorOrdenado'
        OnClick = Insertar1Click
      end
    end
    object Matrices1: TMenuItem
      Caption = 'Matrices'
      object Dimensionar2: TMenuItem
        Caption = 'Dimensionar'
        OnClick = Dimensionar2Click
      end
      object SumadeElem1: TMenuItem
        Caption = 'CargarRandom'
        OnClick = SumadeElem1Click
      end
      object CargarXFilas1: TMenuItem
        Caption = 'CargarXFilas'
        OnClick = CargarXFilas1Click
      end
      object SumarRando1: TMenuItem
        Caption = 'SumarRando'
        OnClick = SumarRando1Click
      end
      object CargarCuadrado1: TMenuItem
        Caption = 'CargarCuadrado(2 parametros)'
        OnClick = CargarCuadrado1Click
      end
      object CargarCuadra1param1: TMenuItem
        Caption = 'CargarCuadra(1 param)'
        OnClick = CargarCuadra1param1Click
      end
      object CargaCuadradoliteral1: TMenuItem
        Caption = 'CargaCuadradoliteral'
        OnClick = CargaCuadradoliteral1Click
      end
      object Cuadrada1: TMenuItem
        Caption = 'Cuadrada'
        OnClick = Cuadrada1Click
      end
    end
    object MatricesComoVectores1: TMenuItem
      Caption = 'MatricesComoVectores'
      object ContarX2: TMenuItem
        Caption = 'ContarX'
        OnClick = ContarX2Click
      end
      object SumarMatriz1: TMenuItem
        Caption = 'SumarMatriz'
        OnClick = SumarMatriz1Click
      end
      object CargarFilas1: TMenuItem
        Caption = 'CargarFilas'
        OnClick = CargarFilas1Click
      end
      object b1: TMenuItem
        Caption = 'BusqueBina'
        OnClick = b1Click
      end
      object OrdenarMatriz1: TMenuItem
        Caption = 'OrdenarMatriz'
        OnClick = OrdenarMatriz1Click
      end
      object CargarTriangularsuperior1: TMenuItem
        Caption = 'CargarTriangularSuperior'
        OnClick = CargarTriangularsuperior1Click
      end
    end
  end
end
