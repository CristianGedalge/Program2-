//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
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
	TMenuItem *MenuEnt1;
	TMenuItem *SumaDig1;
	TMenuItem *SumaDig2;
	TStringGrid *StringGrid1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TMenuItem *Cadenas1;
	TMenuItem *Vectores1;
	TMenuItem *Matrices1;
	TMenuItem *CargarMatriz21;
	TMenuItem *SumadeElem1;
	TMenuItem *DevuelveDigMenor1;
	void __fastcall SumaDig1Click(TObject *Sender);
	void __fastcall SumaDig2Click(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall CargarMatriz21Click(TObject *Sender);
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall DevuelveDigMenor1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
