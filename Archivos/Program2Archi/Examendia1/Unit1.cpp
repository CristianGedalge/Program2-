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
void  IsRamiro(AnsiString cadena, ofstream  &fo )
{
  if(cadena=="Ramiro")
  {
	cadena="María José";
  }
	 for (int i = 1; i <=cadena.Length();i++) {
		 fo.put(cadena[i]);
	 }

}

void CambiarCadena(AnsiString nomArch)
{
	 AnsiString s="María Jesús";
	 AnsiString s2;
	 char x;
	 ifstream fi(nomArch.c_str());
	 ofstream fo("temporal.tmp");
	 if(!fi.fail())
	 {
		 while(!fi.eof())
		 {
				  s2="";
				  x=fi.get();

					while(x!=' '&&x!=10 &&!fi.eof())
					{
					  s2=s2+x;
					  x=fi.get();
					}
					IsRamiro(s2,fo);
					if(!fi.eof())
					{
					   fo.put(x);
					}
		 }
	 }

	fi.close();
	fo.close();
	remove(nomArch.c_str());  //eliminamos el arcivo de entrada
	rename("temporal.tmp",nomArch.c_str());
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 if(OpenTextFileDialog1->Execute())
	 {
		  CambiarCadena(OpenTextFileDialog1->FileName);
	 }
}
//---------------------------------------------------------------------------

void IsMJ(AnsiString s,ofstream &fo)
{
	if(s=="María José")
	{
		s="Ramiro";
    }
	for (int i = 1; i <=s.Length(); i++) {
		 fo.put(s[i]);
	}
}
void CambiarCadena2(AnsiString nomArch)
{
	AnsiString s2;
	char x;
	ifstream fi(nomArch.c_str());
	ofstream fo("temporal.tmp");
	if(!fi.fail())
	{

		 while(!fi.eof()){
		   s2="";
		   x=fi.get();
		   while(!fi.eof()&& x!=' '&& x!=10)
		   {
			 s2=s2+x;
			 x=fi.get();

		   }
		   if(x==' '&& s2=="María"&& !fi.eof())
		   {
			 s2=s2+x;
			 x=fi.get();
			 while(x!=' '&& x!=10&& !fi.eof())
			 {
				s2=s2+x;
				x=fi.get();
			 }
			 IsMJ(s2,fo);
			 if(!fi.eof())
				 fo.put(x);
		   }
		   else
		   {
			  IsMJ(s2,fo);
              if(!fi.eof())
				 fo.put(x);
		   }
		 }
	}
	fi.close();
	fo.close();
	remove(nomArch.c_str());
	rename("temporal.tmp",nomArch.c_str());
}



void CambiarCadena3(AnsiString nomArch)
{
	AnsiString s2;
	char x;
	ifstream fi(nomArch.c_str());
	ofstream fo("temporal.tmp");
	if(!fi.fail())
	{

		 while(!fi.eof()){
		   s2="";
		   x=fi.get();
		   while(!fi.eof()&& x!=' '&& x!=10)
		   {
			 s2=s2+x;
			 x=fi.get();
			 if(s2=="María"&&x==' ')
			 {
				 s2=s2+x;
				 x=fi.get();
             }
		   }
		   IsMJ(s2,fo);
		   if(!fi.eof())
		   {
			   fo.put(x);
		   }

		 }

	}

	fi.close();
	fo.close();
	remove(nomArch.c_str());
	rename("temporal.tmp",nomArch.c_str());
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
	{
		CambiarCadena3(OpenTextFileDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

void EndUpper(AnsiString s,ofstream &fo)
{
	byte pos=s.Length();
	if(!(s[pos]>=0x41 && s[pos]<=0x5A))
	{
	   s[pos] =s[pos]-0x20;  // de Lowercase a Upercase
	}

	for (int i = 1; i <=pos; i++) {
		 fo.put(s[i]);
	}

}
void Ejer2(AnsiString nomArch)
{
	AnsiString s2;
	char x;
	ifstream fi(nomArch.c_str());
	ofstream fo("temporal.tmp");
	if(!fi.fail())
	{
		while(!fi.eof())
		{
			s2="";
			x=fi.get();
			while(!fi.eof()&&x!=' '&&x!=10)
			{
				 s2=s2+x;
				 x=fi.get();
			}
			EndUpper(s2,fo);
			if(!fi.eof())
			{
			   fo.put(x);
			}
		}
    }
	fi.close();
	fo.close();
	remove(nomArch.c_str());
	rename("temporal.tmp",nomArch.c_str());
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{

	if(OpenTextFileDialog1->Execute())
	{
		Ejer2(OpenTextFileDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

