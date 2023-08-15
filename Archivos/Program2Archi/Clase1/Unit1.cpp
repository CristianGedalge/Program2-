//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void CargarV(AnsiString nomA,TStringGrid *v)
{
   //	char nom [30];
   //	strcpy(nom,"texto2.txt");
	Cardinal i=0;
	char x;
	ifstream f(nomA.c_str());
	if(!f.fail())     //si fallo en abrir no hace nada false
	{
		while(!f.eof())
		{
			x=f.get();
			if(!f.eof()){
			   v->Cells[i][0]=IntToStr(x);
			   i++;
			}
		}
		v->ColCount=i;
	}
	f.close();
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{

	if(OpenTextFileDialog1->Execute()){
	   CargarV(OpenTextFileDialog1->FileName,StringGrid1);
	}

}
//---------------------------------------------------------------------------
bool IsVocal(char a)
{
	AnsiString s="aeiouAEIOU�����";
	return s.Pos(a)>0 ;
}
int ContVocales( AnsiString nomA)
{
	fstream f(nomA.c_str());
	Cardinal c=0;
	if(!f.fail())
	{
	  while(!f.eof())
	  {
		   if(IsVocal(f.get()))
		   {
			  c++;
		   }
      }
	}
	f.close();
	return c;
}
//en los archivos.txt utf-8 no cuenta las vocales especiales(�)en ansi es normal
void __fastcall TForm1::Button2Click(TObject *Sender)
{
		if(OpenTextFileDialog1->Execute()){
			 Edit2->Text=ContVocales(OpenTextFileDialog1->FileName);
		}
}
//---------------------------------------------------------------------------
