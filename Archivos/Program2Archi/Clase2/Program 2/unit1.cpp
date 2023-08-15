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
bool EsLetra(char c)
{
	AnsiString let="qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLKÑZXCVBNMáéíóúÁÉÍÓÚ";
	return let.Pos(c)>0;
}

bool EsSigno(char c)
{
	AnsiString signos=".,";
	return signos.Pos(c)>0;
}
//Limpia todo lo que no sea letras a excepcion de ".,"  (el txt debe ser Ansi yno utf-8)
void  Limpiar(AnsiString nomA){
   char x;
   ifstream fi(nomA.c_str());       //fileinput           de lectura
   ofstream fo("temporal.tmp");     //fileoutput          de escritura
   if(!fi.fail())  //tuvo error al abrir
   {
	   while(!fi.eof())
	   {
		  x=fi.get();
		  if(!fi.eof())
		  {
			  if(EsLetra(x)|| EsSigno(x)||x==10)
			  {
				  fo.put(x); //
			  }
		  }
	   }
   }
   fi.close();
   fo.close();
   remove(nomA.c_str());  //eliminamos el arcivo de entrada
   rename("temporal.tmp",nomA.c_str()); //renombramos el tmp con el nombre del archivo deentrada
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   if(OpenTextFileDialog1->Execute())
   {
	   Limpiar(OpenTextFileDialog1->FileName);
   }
}
//---------------------------------------------------------------------------

//visualiza todo lo que hay en un archivo txt ansi

void Visualizar(AnsiString nom,TMemo *m)
{
	char x;
	AnsiString s="";
	m->Lines->Clear();
	ifstream fi(nom.c_str());                 //abrir modo lectura
	if(!fi.fail()){
	   while(!fi.eof())
	   {
		  x =fi.get();
		  if(!fi.eof())
		  {
			 if(x==10)
			 {
				 m->Lines->Add(s);         //salto de linea;
				 s="";
			 }
			 else
			 {
				 s=s+x;
			 }
		  }

	   }
	   if(s!="")
	   {
		  m->Lines->Add(s);
	   }else
	   {
		  m->Lines->Add(s);
       }
	}
	fi.close();

}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 if(OpenTextFileDialog1->Execute())
	 {
	   Visualizar(OpenTextFileDialog1->FileName, Memo1);
	 }
}
//---------------------------------------------------------------------------
//Guarda lo que escribamos en el memo en un txt en el disco xd creo pero esta easy
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(SaveTextFileDialog1->Execute())
	 {
		 Memo1->Lines->SaveToFile(SaveTextFileDialog1->FileName+".txt");
	 }
}
//---------------------------------------------------------------------------

