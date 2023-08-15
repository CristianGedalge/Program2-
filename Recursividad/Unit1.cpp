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
byte Suma(Cardinal x)
{ byte s;
  if(x<10)//caso base
	s=x;
  else  //caso general
  {
	s=x%10+Suma(x/10);
  }

  return s;

}
void __fastcall TForm1::SumaDig1Click(TObject *Sender)
{
  Edit2->Text=Suma(StrToInt(Edit1->Text));


}
//---------------------------------------------------------------------------
byte SumaPrim(Cardinal x)
{ byte s;
  if(x<10)
  {
	if(x==2|| x==3 ||x==5||x==7)
	  s=x;
	else
      s=0;
  }
  else
  {
	s=SumaPrim(x/10);
	x=x%10;
	if(x==2|| x==3 ||x==5||x==7)
	  s +=x;
  }
  return s;
}
void __fastcall TForm1::SumaDig2Click(TObject *Sender)
{
  Edit2->Text=SumaPrim(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void Pintar(TCanvas*A,int x,int y,TColor colAnt,TColor colNew)
{
if(A->Pixels[x][y]==colAnt)
{
  A->Pixels[x][y]=colNew;
  Pintar(A,x,y-1,colAnt,colNew);
  Pintar(A,x,y+1,colAnt,colNew);
  Pintar(A,x-1,y,colAnt,colNew);
  Pintar(A,x+1,y,colAnt,colNew);

}
}


void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   if(RadioButton1->Checked){
	 Canvas->Pen->Width=3;
	 Canvas->Ellipse (X-50,Y-50,X+50,Y+50);
   }
   if(RadioButton2->Checked)
   {
	 Pintar(Canvas,X,Y,Canvas->Pixels[X][Y],clRed);
   }
}
//---------------------------------------------------------------------------
void LlenarF2(TStringGrid *A,byte f,byte d,byte a,byte n)
{
  if(n>0){
	LlenarF2(A,f,d,a+1,n-1);
	A->Cells[a][f]=d;
  }
}
void LlenarC2(TStringGrid *A,byte c,byte d,byte a,byte n)
{
  if(n>0){
	LlenarC2(A,c,d,a+1,n-1);
	A->Cells[c][a]=d;
  }
}
void CargarL(TStringGrid *A,byte m)
{
  if(m>0)
  {
	CargarL(A,m-1);
	LlenarF2(A,m-1,m,0,m);

	LlenarC2(A,m-1,m,0,m);
  }
}

void __fastcall TForm1::CargarMatriz21Click(TObject *Sender)
{
  StringGrid1->ColCount=StringGrid1->RowCount;
  CargarL(StringGrid1,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------
void CargarC(TStringGrid *A,byte fa,byte fb,byte ca,byte cb)
{
  byte m=fb-fa-1;byte n=cb-ca+1;
  LlenarF2(A,fa,(n-1)/2,ca,n);
  LlenarF2(A,fb,(n-1)/2,ca,n);
  LlenarF2(A,ca,(n-1)/2,fa,m);
  LlenarF2(A,cb,(n-1)/2,fb,m);
}





//---------------------------------------------------------------------------
byte SumaEleVec()
{


}


//---------------------------------------------------------------------------



byte Menor(Cardinal x)
{
  byte sp;
  if(x<10)
   sp=x;
  else
  {
	if(Menor(x/10)<x%10)
	  sp=Menor(x/10);
	else
	 sp=x%10;
  }
  return sp;
}




void __fastcall TForm1::DevuelveDigMenor1Click(TObject *Sender)
{
  Edit2->Text=Menor(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

