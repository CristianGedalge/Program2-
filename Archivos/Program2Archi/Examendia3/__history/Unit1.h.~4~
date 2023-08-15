//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Menus.hpp>
#include <fstream>
//---------------------------------------------------------------------------
struct TFecha
{
	byte dia;
	byte mes;
	Word año;
};

struct RegAlumno       //nueva estructura
{
	Word codigo;       //
	char nombre[31];
	char direccion[21];
	TFecha fecha;
	byte marca;       //marca de borrado logico
};

struct RegAlumno2     //antigua estructura
{
	Word codigo;
	char nombre[31];
	char direccion[21];
	TFecha fecha;
};

struct RegFecha{
	TFecha fecha;
	Cardinal pos;
};
/*struct RegAlumno2     //antigua antigua estructura
{
	Word codigo;
	char nombre[21];
	char direccion[21];
	TFecha fecha;
};    */

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
	TButton *Button3;
	TMainMenu *MainMenu1;
	TMenuItem *Archivo1;
	TMenuItem *Indice1;
	TMenuItem *Listado1;
	TMenuItem *Pornombre1;
	TMenuItem *Porcodigo1;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TMenuItem *Porfecha1;
	TMenuItem *VerificarMenor1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	//void __fastcall Porcodigo1Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	//void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Porfecha1Click(TObject *Sender);
	void __fastcall VerificarMenor1Click(TObject *Sender);
private:	// User declarations
	AnsiString nomArch;
	fstream *pf;    //puntero de archivo de datos
	fstream *pfi;   //puntero de archivo indice
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void Mostrar(RegAlumno reg);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
