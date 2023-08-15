//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <fstream>
//---------------------------------------------------------------------------
struct TFecha
{
	byte dia;
	byte mes;
	Word año;
};

struct RegAlumno
{
	Word codigo;
	char nombre[21];
	char direccion[21];
	TFecha fecha;
};
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label5;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label3;
	TEdit *Edit3;
	TLabel *Label4;
	TMaskEdit *MaskEdit1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	AnsiString nomArch;
	fstream *pf;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
