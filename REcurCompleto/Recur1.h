//---------------------------------------------------------------------------

#ifndef Recur1H
#define Recur1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TMainMenu *MainMenu1;
	TMenuItem *NEnt1;
	TMenuItem *SumaDigitos1;
	TMenuItem *SumaDigPrimos1;
	TMenuItem *MenorDig1;
	TMenuItem *MenorAlFinal1;
	TMenuItem *OrdenarMayaMen1;
	TMenuItem *SumaDig1;
	TMenuItem *SumaDigImpar1;
	TMenuItem *MayorAlFinal1;
	TMenuItem *OrdenarMenaMay1;
	TMenuItem *Cadenas1;
	TMenuItem *Cant1;
	TMenuItem *Inverso11;
	TMenuItem *Inverso21;
	TMenuItem *Inverso31;
	TMenuItem *Inverso41;
	TMenuItem *Inverso51;
	TMenuItem *Inverso61;
	TMenuItem *Inverso71;
	TMenuItem *EsAlfabetochar1;
	TMenuItem *EliminarNoLetras1;
	TMenuItem *Vectores1;
	TMenuItem *Matrices1;
	TStringGrid *StringGrid1;
	TMenuItem *SumadeElementos1;
	TMenuItem *CargarRandom1;
	TMenuItem *Dimensionar1;
	TMenuItem *SumadeElem21;
	TMenuItem *SumadeElem31;
	TMenuItem *BusquedaBinaria1;
	TMenuItem *Verificarsiestaordenado1;
	TMenuItem *BubbleSort1;
	TMenuItem *SelectSort1;
	TMenuItem *VectoraNum1;
	TMenuItem *NumaVector1;
	TMenuItem *Insertar1;
	TStringGrid *StringGrid2;
	TMenuItem *Dimensionar2;
	TMenuItem *SumadeElem1;
	TMenuItem *CargarXFilas1;
	TMenuItem *SumarRando1;
	TMenuItem *CargarCuadrado1;
	TMenuItem *CargarCuadra1param1;
	TMenuItem *CargaCuadradoliteral1;
	TMenuItem *Cuadrada1;
	TMenuItem *MatricesComoVectores1;
	TMenuItem *ContarX2;
	TMenuItem *SumarMatriz1;
	TMenuItem *CargarFilas1;
	TMenuItem *b1;
	TMenuItem *OrdenarMatriz1;
	TMenuItem *CargarTriangularsuperior1;
	void __fastcall SumaDigitos1Click(TObject *Sender);
	void __fastcall SumaDigPrimos1Click(TObject *Sender);
	void __fastcall MenorDig1Click(TObject *Sender);
	void __fastcall MenorAlFinal1Click(TObject *Sender);
	void __fastcall OrdenarMayaMen1Click(TObject *Sender);
	void __fastcall SumaDig1Click(TObject *Sender);
	void __fastcall SumaDigImpar1Click(TObject *Sender);
	void __fastcall MayorAlFinal1Click(TObject *Sender);
	void __fastcall OrdenarMenaMay1Click(TObject *Sender);
	void __fastcall Cant1Click(TObject *Sender);
	void __fastcall Inverso11Click(TObject *Sender);
	void __fastcall Inverso21Click(TObject *Sender);
	void __fastcall Inverso31Click(TObject *Sender);
	void __fastcall Inverso41Click(TObject *Sender);
	void __fastcall Inverso51Click(TObject *Sender);
	void __fastcall Inverso61Click(TObject *Sender);
	void __fastcall Inverso71Click(TObject *Sender);
	void __fastcall EsAlfabetochar1Click(TObject *Sender);
	void __fastcall EliminarNoLetras1Click(TObject *Sender);
	void __fastcall SumadeElementos1Click(TObject *Sender);
	void __fastcall CargarRandom1Click(TObject *Sender);
	void __fastcall Dimensionar1Click(TObject *Sender);
	void __fastcall SumadeElem21Click(TObject *Sender);
	void __fastcall SumadeElem31Click(TObject *Sender);
	void __fastcall BusquedaBinaria1Click(TObject *Sender);
	void __fastcall Verificarsiestaordenado1Click(TObject *Sender);
	void __fastcall BubbleSort1Click(TObject *Sender);
	void __fastcall SelectSort1Click(TObject *Sender);
	void __fastcall VectoraNum1Click(TObject *Sender);
	void __fastcall NumaVector1Click(TObject *Sender);
	void __fastcall Insertar1Click(TObject *Sender);
	void __fastcall Dimensionar2Click(TObject *Sender);
	void __fastcall SumadeElem1Click(TObject *Sender);
	void __fastcall CargarXFilas1Click(TObject *Sender);
	void __fastcall SumarRando1Click(TObject *Sender);
	void __fastcall CargarCuadrado1Click(TObject *Sender);
	void __fastcall CargarCuadra1param1Click(TObject *Sender);
	void __fastcall CargaCuadradoliteral1Click(TObject *Sender);
	void __fastcall Cuadrada1Click(TObject *Sender);
	void __fastcall ContarX2Click(TObject *Sender);
	void __fastcall SumarMatriz1Click(TObject *Sender);
	void __fastcall CargarFilas1Click(TObject *Sender);
	void __fastcall b1Click(TObject *Sender);
	void __fastcall OrdenarMatriz1Click(TObject *Sender);
	void __fastcall CargarTriangularsuperior1Click(TObject *Sender);






private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
