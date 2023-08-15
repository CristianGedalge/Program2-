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
int Ejer2(TStringGrid *v, byte n)     //v[1,3,5,2]=2-9=-7
{
  int s;
  if(n==0)
	s=0;
  else
  {
	byte a=StrToInt(v->Cells[n-1][0]);        // 2 1
	if(a%2==0)
		s=a+Ejer2(v,n-1);
	else
		s=-(a)+Ejer2(v,n-1);
  }

  return s;
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Edit2->Text=Ejer2(StringGrid1,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  StringGrid1->ColCount=StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------
String num(byte n)
{
  String s;

  if(n==0)
	s="";
  else
	s=  String(n)+num(n-1);
  return s;

}
void Cargar(TStringGrid *v,byte n)
{
  if(n==1)
	v->Cells[0][0]=1;
  else
  {
	v->Cells[n-1][0]=num(n);
	Cargar(v,n-1);

  }

}

//5=[1,21,321,4321,54321]
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Cargar(StringGrid1,Edit1->Text.ToInt());
  StringGrid1->ColCount=Edit1->Text.ToInt();
}
//---------------------------------------------------------------------------
int Ejer11(TStringGrid *v, byte n,byte num)
{
  int s;
  if(n==0)
	s=0;
  else
  {
	if(num%2!=0){
	s=StrToInt(v->Cells[n-1][0])+Ejer11(v,n-1,num+1);        // 2 1
	}

	else {
	s=Ejer11(v,n-1,num+1);
	}
  }

  return s;
}
 //[1,4,6,8,7]= 14 //sumar las posiciones impares
 // 5 4 3 2 1
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   Edit2->Text=Ejer11(StringGrid1,StringGrid1->ColCount,1);
}
//---------------------------------------------------------------------------
String tomar( String &cadena)
{
   byte lon=cadena.Length();
   String s;
	if(cadena.Length()%2==0)
	{
		s= cadena.SubString(lon-1,2 );
		cadena=cadena.SubString(1,lon-2) ;
	}
	else {
	 s=cadena.SubString(lon,1);
	 cadena=cadena.SubString(1,lon-1);
	}
	return s;
}

void Ejer222(TStringGrid *v,String cadena,int tama){
	if(tama==1)
	{
	   v->Cells[0][0]=tomar(cadena);
	}else{
		  v->Cells[tama-1][0]=tomar(cadena);
		  Ejer222(v,cadena,tama-1);
	}
}

//helados=[he,la,do,s];
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	 Ejer222(StringGrid1,Edit1->Text,((Edit1->Text.Length()-1)/2)+1);
  StringGrid1->ColCount=(((Edit1->Text.Length()-1)/2)+1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
   byte tamaño=StrToInt(Edit1->Text);
   StringGrid1->ColCount=tamaño;
}
//---------------------------------------------------------------------------

