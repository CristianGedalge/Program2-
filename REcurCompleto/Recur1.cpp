//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recur1.h"
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
byte SumaDig(Cardinal x)
{
  byte s;
  if(x<10) //caso  base
  {
	s=x;
  }
  else      // caso general
	s=x%10+SumaDig(x/10);
  return s;
}


void __fastcall TForm1::SumaDigitos1Click(TObject *Sender)
{
  Edit2->Text=SumaDig(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
byte SumDigPrim(Cardinal x)
{
  byte s;
  if(x<10)
  {
	if(x==2||x==3||x==5||x==7)
	  s=x;
  }
  else
  {
	byte r=x%10;
	if(r==2||r==3||r==5||r==7)
	{
	  s=r+SumDigPrim(x/10);
	}
	else
	  s=SumDigPrim(x/10);
  }
  return s;
}

void __fastcall TForm1::SumaDigPrimos1Click(TObject *Sender)
{
  Edit2->Text=SumDigPrim(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------



byte menor(Cardinal x)
{
  byte s;
  if(x<10)
	s=x;
  else
  {
	if( menor(x/10)<x%10)
	  s=menor(x/10);
	else
	  s=x%10;
  }
  return s;
}

void __fastcall TForm1::MenorDig1Click(TObject *Sender)
{
  Edit2->Text=menor(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void MenorAlfinal(Cardinal &x)
{
  if(x<10) //caso base n=1;
  {
  }
  else
  {
	byte a=x%10;
	x=x/10;
	MenorAlfinal(x);
	byte b=x%10;
	if(a<=b)
	{
	  x=x*10+a;
	}
	else
	{
	  b=x%10;
	  x=x/10;
	  x=x*10+a;
	  x=x*10+b;
	}
  }
}




/*void menorfinal(Cardinal &x)
{
  if(x<10)
  {
  }
  else
  {
	byte a=x%10;

	x=x/10;
	menorfinal(x);
	byte b=x%10;

	if(a<=b)
	{
	   x= x*10+a;
	}
	else
	{
	  x=x/10;
	  x=x*10+a;
	  x=x*10+b;

	}
  }
}
*/


void __fastcall TForm1::MenorAlFinal1Click(TObject *Sender)
{
  Cardinal z=StrToInt(Edit1->Text);
  MenorAlfinal(z);
  Edit1->Text=z;
}
//---------------------------------------------------------------------------
void OrdenarMayaMen(Cardinal &x){
  if(x>10)
  {
	MenorAlfinal(x);
	byte a=x%10;
	x=x/10;
	OrdenarMayaMen(x);
	x=x*10+a;
  }
}
void __fastcall TForm1::OrdenarMayaMen1Click(TObject *Sender)
{
  Cardinal z=StrToInt(Edit1->Text);
  OrdenarMayaMen(z) ;
  Edit1->Text=z ;
}
//---------------------------------------------------------------------------


byte Sumapares(Cardinal x)
{
byte s;
  if(x<10)
  {
	if(x%2==0)
	  s=x;
	else
	  s=0;
  }
  else
  {
	byte a=x%10;
	if(x%2==0)
	{
	  s=Sumapares(x/10)+a;
	}
	else
	  s=Sumapares(x/10);
  }
  return s;
}

void __fastcall TForm1::SumaDig1Click(TObject *Sender)
{
   Edit2->Text=Sumapares(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
byte SumaImp(Cardinal x)
{
  byte s;
  if(x<10)
  {
	if(x%1!=0)
	  s=x;
	else
	  s=0;
  }
  else
  {
	byte a =x%10;
	if(a%2!=0)
	  s=SumaImp(x/10)+a;
	else
	  s=SumaImp(x/10);
  }
  return s;

}
void __fastcall TForm1::SumaDigImpar1Click(TObject *Sender)
{
  Edit2->Text=SumaImp(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void MayorAlFinal(Cardinal &x)     //143
{
  if(x>=10)
  {
	byte a=x%10;     //3  //4
	x=x/10;          //14  //1
	MayorAlFinal(x);
	byte b=x%10;
	if(a>=b)
	  x=x*10+a;   //14
	else
	{
	  x=x/10;       //1
	  x=x*10+a;     //13
	  x=x*10+b;     //134
	}
  }
}

void __fastcall TForm1::MayorAlFinal1Click(TObject *Sender)
{
  Cardinal z=StrToInt(Edit1->Text);
  MayorAlFinal(z);
  Edit1->Text=z;
}
//---------------------------------------------------------------------------
void OrdenarMenaMay(Cardinal &x)
{
  if(x>=10)
  {
	MayorAlFinal(x);
	byte a=x%10;
	x=x/10;
	OrdenarMenaMay(x);
	x=x*10+a;
  }
}


void __fastcall TForm1::OrdenarMenaMay1Click(TObject *Sender)
{
  Cardinal z=StrToInt(Edit1->Text);
  OrdenarMenaMay(z);
  Edit1->Text=z;
}
//---------------------------------------------------------------------------
bool IsVowel(char n)
{
  String vow="aeiouAEIOU��������������";
  return vow.Pos(n)>0;

}
byte CantVowels(String x)
{

  byte c;
  if(x=="")
	c=0;
  else
  {
	char n=x[1];
	x.Delete(1,1);
	c = CantVowels(x);
	if(IsVowel(n))
	  c++;
  }
  return c;
}
void __fastcall TForm1::Cant1Click(TObject *Sender)
{
  Edit2->Text=CantVowels(Edit1->Text);
}
//---------------------------------------------------------------------------
String Inverso1(String x)
{
  String s="";
  if(x=="")
  {

  }
  else
  {
	char a=x[1];
	x.Delete(1,1);
	s=Inverso1(x);
	s=s+a;
  }
  return s;
}
void __fastcall TForm1::Inverso11Click(TObject *Sender)
{
  Edit2->Text=Inverso1(Edit1->Text);
}
//---------------------------------------------------------------------------
String Inverso2(String x)      //po
{
  Byte lg=x.Length();
  String s="";
  if(lg>0)
  {
	Char a=x[lg];   //o
	x.Delete(lg,1); //po
	s=AnsiString(a)+Inverso2(x);
  }
  return s;
}
void __fastcall TForm1::Inverso21Click(TObject *Sender)
{
  Edit2->Text=Inverso2(Edit1->Text);
}
//---------------------------------------------------------------------------
String Inverso3(String x)   // 2 1eros elemts de la cadena
{
  String s;
  byte lg= x.Length();
  if(lg<2)
	s=x;
  else
  {
	String r=x.SubString(1,2);     //pollo
	x.Delete(1,2);
	s=Inverso3(x);
	s= s + r[2]+r[1];
  }
  return s;
}

void __fastcall TForm1::Inverso31Click(TObject *Sender)
{
  Edit2->Text=Inverso3(Edit1->Text);
}
//---------------------------------------------------------------------------
String Inverso4(String x)         // 2 last elemts of the String
{
  byte n=x.Length();
  String s;
  if(n<2)
	s=x;
  else
  {
	String r=x.SubString(n-1,2);
	x.Delete(n-1,2);
	s=Inverso4(x);
	s= AnsiString(r[2])+AnsiString(r[1])+s;
  }
  /*String s="";
  String t="pollo";
  String r=t+s;
  return r;  --->F*/
  return s;
}
void __fastcall TForm1::Inverso41Click(TObject *Sender)
{
  Edit2->Text=Inverso4(Edit1->Text);
}
//---------------------------------------------------------------------------
String Inverso5(String x)
{
  String s;
  byte n=x.Length();
  if(n<2)
  {
	s=x;
  }
  else
  {
	char a1=x[1];
	char a2=x[n];
	x.Delete(n,1);
	x.Delete(1,1);
	s=AnsiString(a2)+Inverso5(x)+a1;//ojo se anota ansi si no es s tal vez
  }
  return s;
}
void __fastcall TForm1::Inverso51Click(TObject *Sender)
{
  Edit2->Text=Inverso5(Edit1->Text);
}
//---------------------------------------------------------------------------
String Inverso6(String x)           //menor de la derecha
{
  byte n=x.Length();
  String s;
  if(n<2)
  {
	s=x;
  }
  else
  {
	String a=x.SubString(n-n/2+1,n/2);//o
	x.Delete(n-n/2+1,n/2);
	s=Inverso6(a)+Inverso6(x);

  }
  return s;
}
void __fastcall TForm1::Inverso61Click(TObject *Sender)
{
  Edit2->Text=Inverso6(Edit1->Text);
}
//---------------------------------------------------------------------------
String Inverso7(String x)                     //cadena impar menor cant elemt de la izq;
{                                             //  "  "  par  mitad  de elemt de la cadena parte izq
  byte lg=x.Length();
  String s;
  if(lg<2)
  {
   s=x;
  }
  else
  {
	String a=x.SubString(1,lg/2);
	x.Delete(1,lg/2);
	s=Inverso7(x)+Inverso7(a);
  }
  return s;
}
void __fastcall TForm1::Inverso71Click(TObject *Sender)
{
  Edit2->Text=Inverso7(Edit1->Text);
}
//---------------------------------------------------------------------------
bool IsAlphabet(AnsiString x)
{

  String s="abcdefghijklmn�opqrstuvwxyzABCDEFGHIJKLMN�OPQRSTUVWXYZ�������������";
  /*if(s.Pos(x)>0)
	r=1;
  else
	r=0; */
  return (s.Pos(x)>0);//?1:0;
}
void __fastcall TForm1::EsAlfabetochar1Click(TObject *Sender)
{
  String  s;
  if(IsAlphabet(Edit1->Text))
	s="True";
  else
	s="False";
  Edit2->Text=s;
}
//---------------------------------------------------------------------------
void EliminarNoAlphabeto (String &x)        //procedimiento
{
	if(x=="")
	{
	 x="";
	}
	else
	{
	  char a=x[1];
	  x.Delete(1,1);
	  EliminarNoAlphabeto(x);
	  if(IsAlphabet(a)|| a==' ')             //char 1 comilla
		x= String(a)+x;
	}
}

void __fastcall TForm1::EliminarNoLetras1Click(TObject *Sender)
{
  String z=Edit1->Text;
  EliminarNoAlphabeto(z);
  Edit2->Text=z;
}
//---------------------------------------------------------------------------
int sumaelemts(TStringGrid *v,byte n)
{
  int s;
  if(n==0)
	s=0;
  else
	s=sumaelemts(v,n-1)+StrToInt(v->Cells[n-1][0]);
  return s;
}
void __fastcall TForm1::SumadeElementos1Click(TObject *Sender)
{
  Edit2->Text=sumaelemts(StringGrid1,StringGrid1->ColCount);

}
//---------------------------------------------------------------------------

//

void CargarRandom(TStringGrid *v,byte n)
{
  if(n==0)
	v->ColCount=0;
  else
  {
	 //CargarRandom(v,n-1);
	 v->Cells[n-1][0]=Random(20);
	 CargarRandom(v,n-1);
	 v->ColCount=n;
	//CargarRandom(,n-1)
  }
}

void __fastcall TForm1::CargarRandom1Click(TObject *Sender)
{
  CargarRandom(StringGrid1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Dimensionar1Click(TObject *Sender)
{
 StringGrid1->ColCount=StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------
int suma2v(TStringGrid *v,byte a,byte lg)       //
{
  int s;
  byte n=lg-a+1;
  if(n==0)
	s=0;
  else
	s=suma2v(v,a+1,lg)+StrToInt(v->Cells[a][0]);
  return s;
}
void __fastcall TForm1::SumadeElem21Click(TObject *Sender)
{
  Edit2->Text=suma2v(StringGrid1,0,StringGrid1->ColCount-1);
}
//---------------------------------------------------------------------------

int suma3(TStringGrid *v,byte a,byte n)    //123
{
  int s;
  if(n==0)
	s=0;
  else if(n==1)
	s=StrToInt(v->Cells[a][0]);
  else
  {
	 byte n1=n/2;
	 byte p=a+n/2;
	 byte n2=n-n1;
	 s=suma3(v,a,n1) +suma3(v,p,n2);
  }
  return s;
}

void __fastcall TForm1::SumadeElem31Click(TObject *Sender)
{
  Edit2->Text=suma3(StringGrid1,0,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
//para esto debemos introducir un vector ordenado
bool BusqBina(TStringGrid *v,byte a ,byte b,byte x) //a=0    b=4    n=5
{                                                   //pos.i  pos.f  tama�o
  byte n=b-a+1;
  bool bandera;
  if(n==0)
  {
	bandera=false;
  }
  else if(n==1)
	bandera= (x==StrToInt(v->Cells[a][0]));
  else
  {
	byte a1=(a+b)/2;
	if(x==StrToInt(v->Cells[a1][0]))
	  bandera=true;
	else
	{
	  if(x>StrToInt(v->Cells[a1][0]))
		 bandera =BusqBina(v,a1+1,b,x);
	  else
		 bandera =BusqBina(v,a,a1-1,x);
	}
  }
  return bandera;
}
void __fastcall TForm1::BusquedaBinaria1Click(TObject *Sender)
{
  if(BusqBina(StringGrid1,0,StringGrid1->ColCount-1,Edit2->Text.ToInt()))
	Edit3->Text="Si est�";
  else
	Edit3->Text ="No est�" ;
}
//---------------------------------------------------------------------------
bool VerifEstaOrden(TStringGrid *v,byte n)
{
  bool bandera;
  if(n==1)
	bandera=true;
  else
  {
	if(StrToInt(v->Cells[n-2][0])<=StrToInt(v->Cells[n-1][0]))
	  bandera=VerifEstaOrden(v,n-1);
	else
	  bandera=false;
  }
  return bandera;
}


void __fastcall TForm1::Verificarsiestaordenado1Click(TObject *Sender)
{
  if(VerifEstaOrden(StringGrid1 , StringGrid1->ColCount))
	Edit3->Text="Esta en Orden";
  else
	Edit3->Text="NoEsta en Orden";

}
//---------------------------------------------------------------------------

void LLevarMayorAlFinal(TStringGrid *v,byte n)

{
  if(n>1)
  {
	byte v1=StrToInt(v->Cells[n-1][0]);
	LLevarMayorAlFinal(v,n-1);

	if( StrToInt(v->Cells[n-2][0])>StrToInt(v->Cells[n-1][0]))
	{
	  v->Cells[n-1][0]=v->Cells[n-2][0];
	  v->Cells[n-2][0]=v1;
	}
  }
}
void BubbleSort(TStringGrid *v, byte n)
{
  if(n>1)
  {
	  LLevarMayorAlFinal(v,n);
	  BubbleSort(v,n-1);

  }
}

void __fastcall TForm1::BubbleSort1Click(TObject *Sender)
{
  BubbleSort(StringGrid1,StringGrid1->ColCount);
  //LLevarMayorAlFinal(StringGrid1,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SelectSort1Click(TObject *Sender)
{
  Edit2->Text=20;//hay un metodo nuevo no lo hice por que no tenia tiempo
}
//---------------------------------------------------------------------------
String Num(TStringGrid *v,byte n)
{
 String s;
 if(n==1)
   s=v->Cells[0][0];
 else
 {
	s= Num(v,n-1) +v->Cells[n-1][0];
 }
 return s;
}
void __fastcall TForm1::VectoraNum1Click(TObject *Sender)
{
  String s=Num(StringGrid1,StringGrid1->ColCount);
  if(Num(StringGrid1, StringGrid1->ColCount)=="")
	Edit1->Text="";
  else
	Edit1->Text= StrToInt(s);
}

//v[1,23,4] =1234
//v[]="";
//---------------------------------------------------------------------------
void NumAVector(TStringGrid *v,Cardinal num,byte n)
{
  if(num>100)
  {
	v->Cells[n-1][0]=num%100;
	NumAVector(v,num/100,n-1);
  }
  else
  {
	  v->Cells[0][0]=num;
  }
}
void __fastcall TForm1::NumaVector1Click(TObject *Sender)
{
  String c=StrToInt(Edit1->Text);
  StringGrid1->ColCount= (c.Length()+1)/2;
  NumAVector(StringGrid1,Edit1->Text.ToInt(),StringGrid1->ColCount);
}

//41231 de 2 en dos=v[4,12,31]
//---------------------------------------------------------------------------
void InsertNumVec(TStringGrid *v,byte &n,byte x)                //[2] x=3 =>[3,2]
{
  if(n==0)                                                      // [2] x=1 =>[2 1]
  {
	v->Cells[0][0]=x;
	n=1;
  }
  else
  {
	if(x>=StrToInt(v->Cells[n-1][0]))
	{
	  byte aux= StrToInt(v->Cells[n-1][0]);
	  n--;
	  InsertNumVec(v,n,x);
	  v->Cells[n][0]=aux;
	  n++;
	}
	else
	{
	  v->Cells[n][0]=x;
	  n++;
	}
  }
}
void __fastcall TForm1::Insertar1Click(TObject *Sender)
{
  byte n=StringGrid1->ColCount;
  InsertNumVec(StringGrid1,n,Edit1->Text.ToInt());
  StringGrid1->ColCount=n;
  //v[6,3,1]  5 ->v[6,5,3,1]
  //v[]  2 ->Nofunciona para vector vacio
  //v[1] 5 ->v[5,1]
  //ojo solo funciona con vectores descendentes

}
//---------------------------------------------------------------------------
/*void InsertarVectorPos(TStringGrid *v,byte &n,byte pos,byte num){
	if(n>pos){
	Cardinal aux = StrToInt(v->Cells[n-1][0]);
		n--;
		InsertarVectorPos(v,n,pos,num);
		n++;
		v->Cells[n-1][0]=aux;
	}
	else{
		n++;
		v->Cells[n-1][0] = num;
	}
}
void __fastcall TForm2::InsertarendichaPossms1Click(TObject *Sender)
{
	byte num = StrToInt(InputBox("","Numero: ",""));
	byte pos = StrToInt(InputBox("","Posicion a insertar: ",""));
	byte n = StrToInt(StringGrid1->ColCount);
	InsertarVectorPos(StringGrid1,n,pos,num);
	StringGrid1->ColCount = n;
	//  Ej: v[3,5,2,1,8]   num = 4 ; pos = 2
	//	 => v[3,5,4,2,1,8]
}*/

void __fastcall TForm1::Dimensionar2Click(TObject *Sender)
{
   StringGrid2->RowCount=StrToInt(Edit1->Text);
   StringGrid2->ColCount = StrToInt(Edit2->Text);
}
//---------------------------------------------------------------------------

void CargFila(TStringGrid *m,byte f,byte c)
{
  if(c==0)
  {
	m->ColCount=c ;
  }
  else
  {
	m->Cells[c-1][f]=Random(10);
	CargFila(m,f,c-1);
  }
}
void CargRand(TStringGrid *m,byte f,byte c)
{
  if(f==0)
  {
	  m->ColCount=c;
	  m->RowCount=f;
  }
  else
  {
	f--;
	CargRand(m,f,c);
	CargFila( m,f,c);
  }
}

void __fastcall TForm1::SumadeElem1Click(TObject *Sender)
{
  byte f=Edit1->Text.ToInt();
  byte c=Edit2->Text.ToInt();
  CargRand(StringGrid2,f,c);
  StringGrid2->ColCount=c;
  StringGrid2->RowCount=f;
}
//---------------------------------------------------------------------------
void CargXFilas(TStringGrid *m,byte  f,byte c,byte cf ,byte cc,int i)
{

	if(cf>f)
	{
		m->ColCount=c;
		m->RowCount=f;
	}
	else
	{
		if(cc!=c)
		{
			m->Cells[cc-1][cf-1]= i;
			cc++;
			i++;
			CargXFilas(m,f,c,cf,cc,i);
		}
		else
		{
			m->Cells[cc-1][cf-1]= i;
			cc=1;
			cf++;
			i++;
			CargXFilas(m,f,c,cf,cc,i);

		}
	}
}

/*     |1  2  3  4|
	   |5  6  7  8|
  4x4= |9  10 11 12|
	   |13 14 15 16| */
void __fastcall TForm1::CargarXFilas1Click(TObject *Sender)
{
	byte f=StrToInt(Edit1->Text);
	byte c=StrToInt(Edit2->Text);
	CargXFilas(StringGrid2,f,c,1,1,1);
}
//---------------------------------------------------------------------------
int SumaMR(TStringGrid *m,byte f,byte c){
   int suma;
   if(f==0){
	suma=0;
   }
   else
   {
   if(c>1)
	  suma=StrToInt(m->Cells[c-1][f-1])+SumaMR(m,f,c-1);
   else
	  suma=StrToInt(m->Cells[c-1][f-1])+SumaMR(m,f-1,m->ColCount);
   }
   return suma;
}

void __fastcall TForm1::SumarRando1Click(TObject *Sender)
{
	byte f,c;
	f= StringGrid2->RowCount;
	c=StringGrid2->ColCount;
	Edit3->Text=SumaMR(StringGrid2,f,c);
}
//---------------------------------------------------------------------------
void CargFil(TStringGrid *m,byte f,byte c)
{
	if(c==1)
	{
	   m->Cells[c-1][f-1]=f;
	}else
	{
	   m->Cells[c-1][f-1]=f;
	   CargFil(m,f,c-1);
	}
}
void CargCol(TStringGrid *m,byte f,byte c)
{
	if(f==1)
	{
		m->Cells[c-1][f-1]=c;
	}else
	{
		m->Cells[c-1][f-1]=c;
		CargCol(m,f-1,c) ;
	}
}

void CargarCuadrada(TStringGrid *m,byte f,byte c)
{
	if(f==1&& c==1)
	{
      m->Cells[0][0]=f;
	}
	else
	{
		CargFil(m,f,c);
		CargCol(m,f-1,c);
		CargarCuadrada(m,f-1,c-1);
	}
}
 //2 parametros
/*     |1 2 3 4|
	   |2 2 3 4|
  4x4= |3 3 3 4|
	   |4 4 4 4| */

void __fastcall TForm1::CargarCuadrado1Click(TObject *Sender)
{
	byte f=StrToInt(Edit1->Text);
	byte c=StrToInt(Edit2->Text);
	CargarCuadrada(StringGrid2,f,c);
	StringGrid2->RowCount=f;
	StringGrid2->ColCount=c;

}
//---------------------------------------------------------------------------
void CargCuadr(TStringGrid *m,byte n)
{
	if(n==0)
	{
	   m->ColCount=0;
	   m->RowCount=0;
	}else if(n==1)
	{
	   m->Cells[0][0]=n;
	}
	else
	{
	   CargFil(m,n,n);
	   CargCol(m,n-1,n);
	   CargCuadr(m,n-1);
    }
}
//un parametro
/*   |1 2 3 4|
	 |2 2 3 4|
  4= |3 3 3 4|
	 |4 4 4 4|*/
void __fastcall TForm1::CargarCuadra1param1Click(TObject *Sender)
{
   byte n=StrToInt(Edit1->Text);
   CargCuadr(StringGrid2,n);
   StringGrid2->ColCount=n;
   StringGrid2->RowCount=n;
}
//---------------------------------------------------------------------------
void chargefil(TStringGrid *m,byte f,byte c,byte guiaC,byte num)
{
	if(guiaC<=c )
	{
		m->Cells[c-1][f-1]= num ;
		c--;;
		chargefil(m,f,c,guiaC,num);
	}
}

  void chargecol(TStringGrid *m,byte f,byte c,byte guiaf,byte num)
{
	if(f>guiaf)
	{
	  m->Cells[c-1][f-1]= num;
	  chargecol(m,f-1,c,guiaf,num);
	}
}
void  CargCuadrlit(TStringGrid *m,byte fmxm,byte mxm,byte num )
{
	if(mxm/2+1==fmxm+1)
	{
	  m->ColCount=mxm;
	  m->RowCount=mxm;
	}
	else
	{
	  byte cmxm=fmxm;
	  chargefil(m,fmxm,cmxm,mxm+1-cmxm,num);          //filaAbajo
	  chargefil(m,mxm-(fmxm-1),cmxm,mxm+1-cmxm,num);            //filaEncima
	  chargecol(m,fmxm-1,cmxm,mxm+1-fmxm,num);                  //columnaderacha
	  chargecol(m,fmxm-1,mxm+1-cmxm,mxm+1-fmxm,num);          //columna izquierda
	  CargCuadrlit(m,fmxm-1,mxm, num-1);
	}
}

 /*  |2 2 2 2|
	 |2 1 1 2|
  4= |2 1 1 2|
	 |2 2 2 2|*/
void __fastcall TForm1::CargaCuadradoliteral1Click(TObject *Sender)
{

	byte mxm=StrToInt(Edit1->Text);
	byte num=(mxm+1)/2;
	CargCuadrlit(StringGrid2,mxm,mxm,num);

}
//---------------------------------------------------------------------------

void fil(TStringGrid*m,byte c,byte inc)
{
	if(c!=0)
	{
		m->Cells[c-1][inc-1]=inc;
		fil(m,c-1,inc);
    }
}

void col(TStringGrid *m,byte f,byte c,byte mxm,byte inc)
{
	if(f<=mxm)
	{
		m->Cells[c-1][f-1]= inc;
		col(m,f+1,c,mxm,inc);
	}

}
void cuadradamxm(TStringGrid *m,byte size,byte mxm,byte inc)
{
	if(size==1)
	{
	   m->Cells[0][mxm-1]=inc;
	   m->ColCount=mxm;
	   m->RowCount=mxm;
	}
	else if(size==0)
	{
	   m->ColCount=0;
	   m->RowCount=0 ;
	}
	else
	{
	  fil(m,size,inc);
	  col(m,inc,size,mxm,inc);
	  cuadradamxm(m,size-1,mxm,inc+1);

	}
}
void __fastcall TForm1::Cuadrada1Click(TObject *Sender)
{
	byte size=StrToInt(Edit1->Text);
	cuadradamxm(StringGrid2 ,size,size,1);
}
//---------------------------------------------------------------------------
//MATRIZ COMO VECTOR
//Es una MAtriz tratada como un vector
byte ContarX(TStringGrid *v,byte N,int x){
  byte r;
  if(N==0){
	 r=0;
  }
  else
  {
	  byte n=v->ColCount;
	  r=ContarX(v,N-1,x);
	  if(x==v->Cells[(N-1)%n][(N-1)/n])
	  {
		  r++;
	  }
  }
  return r;
}

void __fastcall TForm1::ContarX2Click(TObject *Sender)
{
	Edit2->Text=ContarX(StringGrid2,StringGrid2->ColCount*StringGrid2->ColCount,StrToInt(Edit1->Text)) ;
}
//--------------------------------------------------------------------------
int Sumita(TStringGrid *v,byte N,byte n)
{
	int s;
	if(N==0)
	{
		s=0;
	}
	else
	{
		s=StrToInt(v->Cells[(N-1)%n][(N-1)/n])+Sumita(v,N-1,n);
	}
	return s;
}

void __fastcall TForm1::SumarMatriz1Click(TObject *Sender)
{
	Edit1->Text=Sumita(StringGrid2,StringGrid2->RowCount*StringGrid2->ColCount,StringGrid2->ColCount);
}
//---------------------------------------------------------------------------
void MvcargFil(TStringGrid *v,byte N,byte n)
{
	if(N==0)
	{
	}
	else
	{
		v->Cells[(N-1)%n][(N-1)/n]=N;
		MvcargFil(v,N-1,n);
    }
}

void __fastcall TForm1::CargarFilas1Click(TObject *Sender)
{
	MvcargFil(StringGrid2,StrToInt(Edit1->Text)*StrToInt(Edit2->Text),StrToInt(Edit2->Text));
	StringGrid2->RowCount=StrToInt(Edit1->Text);
	StringGrid2->ColCount= StrToInt(Edit2->Text);
}
//---------------------------------------------------------------------------
byte Elemay(TStringGrid *v,byte N,byte n,byte &fil, byte &col)
{
	byte may;
	if(N==1 )
	{
	   may=StrToInt(v->Cells[(N-1)%n][(N-1)/n]);
	   fil=(N-1)/n;
	   col=(N-1)%n;
	}
	else
	{
		byte ant= StrToInt(v->Cells[(N-1)%n][(N-1)/n]);
		byte pos=Elemay(v,N-1,n,fil,col);
		if(ant>=pos){
			may=ant;
			fil=(N-1)/n;
			col= (N-1)%n;
		}
		else
		{
			may=pos;
		}
	}
	return may;
}
void OrdenarMatriz(TStringGrid *v,byte N,byte n)
{
	if(N==1)
	{

	}
	else
	{
	   byte fil=0;
	   byte col=0;
	   byte mayor=Elemay(v,N,n,fil,col);
	   if(fil==(N-1)/n && col==(N-1)%n){

	   }
	   else
	   {
		  v->Cells[col][fil]=v->Cells[(N-1)%n][(N-1)/n];
		  v->Cells[(N-1)%n][(N-1)/n]= mayor;
	   }
	   OrdenarMatriz(v,N-1,n);
	}

}

BusBin(TStringGrid *v,byte a,byte b,byte n,byte buscar)
{

	bool flag;
	byte N=b-a+1;
	if(N==0)
	{
		flag=false;
	}
	else if(N==1)
	{
		flag=buscar==v->Cells[a/n][a/n];
    }
	else
	{
		byte lon=(a+b)/2;          //5
		if(buscar==v->Cells[lon%n][lon/n])
		{
			flag=true;
		}
		else if( buscar<v->Cells[lon%n][lon/n])
		{
			flag=BusBin(v,a-1,b,n,buscar);
		}
		else
		{
			flag=BusBin(v,a+1,b,n,buscar);
		}

	}
	return flag;
}

void __fastcall TForm1::b1Click(TObject *Sender)
{
	 OrdenarMatriz(StringGrid2,StringGrid2->RowCount*StringGrid2->ColCount,StringGrid2->ColCount);
	 bool flag=BusBin(StringGrid2,0,StringGrid2->RowCount*StringGrid2->ColCount,StringGrid2->ColCount,StrToInt(Edit1->Text));
	 if(flag)
		ShowMessage("El numero "+Edit1->Text +" si esta en la matriz");
	 else
		ShowMessage("El numero "+Edit1->Text +" no esta en la matriz");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarMatriz1Click(TObject *Sender)
{
	 OrdenarMatriz(StringGrid2,StringGrid2->RowCount*StringGrid2->ColCount,StringGrid2->ColCount);
}
//---------------------------------------------------------------------------
void CargarTriSuperior(TStringGrid *v,int m,byte n,byte guian)
{
	if(m==0)
	{
	   v->ColCount=  n;
	   v->RowCount=n;
	}
	else
	{
	  v->Cells[(m-1)%n][(m-1)/n]=guian;
	  if(((m-1)%n)+1==guian)
		  CargarTriSuperior(v,m-guian,n,guian-1);
	  else
		  CargarTriSuperior(v,m-1,n,guian);
	}
}
/*   |1 1 1 1|
	 |  2 2 2|
  4= |    3 3|
	 |      4|*/
void __fastcall TForm1::CargarTriangularsuperior1Click(TObject *Sender)
{
	byte n=StrToInt(Edit1->Text);
	int m=n*n;
	CargarTriSuperior(StringGrid2 ,m,n,n);
}
//---------------------------------------------------------------------------

