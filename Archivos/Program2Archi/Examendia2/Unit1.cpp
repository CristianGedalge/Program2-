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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   nomArch="alumnos.dat";
   pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
   if(pf->fail())
   {
	   pf=new fstream(nomArch.c_str(),ios::out|ios::binary);
   }
   pf->close();
   delete(pf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
	RegAlumno reg;
	Boolean habilitar=false;
	Word codi=StrToInt(Edit1->Text);
	pf=new fstream(nomArch.c_str(),ios::in|ios::binary) ;
	if(!pf->fail())
	{
		 while(!pf->eof()&&!habilitar)
		 {
			 pf->read((char *)&reg,sizeof(reg));
			 if(!pf->eof())
			 {
				 habilitar=codi==reg.codigo;
			 }
		 }
		 if(habilitar)
		 {
		   Edit2->Text=reg.nombre;
		   Edit3->Text=reg.direccion;
		   MaskEdit1->Text=IntToStr(reg.fecha.dia)+"/"+IntToStr(reg.fecha.mes)+"/"+IntToStr(reg.fecha.año);
		 }
		 else
		 {
			 Edit2->Text="";
			 Edit3->Text="";
			 MaskEdit1->Text="";
         }
	}
	pf->close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	RegAlumno reg,regNuevo;
	bool hallado=false;
	AnsiString aux;
	regNuevo.codigo=StrToInt(Edit1->Text);
	 aux=Edit2->Text;
	strcpy(regNuevo.nombre,aux.c_str());
	aux=Edit3->Text;
	strcpy(regNuevo.direccion,aux.c_str());
	aux=MaskEdit1->Text;
	regNuevo.fecha.dia=StrToInt(aux.SubString(1,2));
	regNuevo.fecha.mes=StrToInt(aux.SubString(4,2));
	regNuevo.fecha.año=StrToInt(aux.SubString(7,4));
	pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary);  //esto nos permite leer y escribir si lo utilizamos pero no ambos a la vez
	if(!pf->fail())
	{
		while(!pf->eof()&&!hallado)
		{
			pf->read((char *)&reg,sizeof(reg));
			if(!pf->eof())
			{
				hallado=reg.codigo==regNuevo.codigo;
			}
		}
		if(hallado)      //actualizar
		{
			pf->seekg(-sizeof(reg),ios::cur);
			pf->write((char *)&regNuevo,sizeof(regNuevo));

		}
		else         //agregar
		{
		  pf=new fstream(nomArch.c_str(),ios::app|ios::binary);
		  pf->write((char*)&regNuevo,sizeof(regNuevo));
		}

		pf->close();
		delete(pf);


		Edit1->Text="";
		Edit2->Text="";
		Edit3->Text="";
		MaskEdit1->Text="";
		Edit1->SetFocus();
	}
}
//---------------------------------------------------------------------------
   void Mayuscula(char v[])
   {
	  for (int i = 1; i <=strlen(v); i++) {
		 v[i]=toupper(v[i]);
	  }
   }


void __fastcall TForm1::Button3Click(TObject *Sender)
{
   RegAlumno reg;
   byte mul;
   pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary);
	   if(!pf->fail())
	   {
		   while(!pf->eof())
		   {
			   pf->read((char *)&reg,sizeof(reg));
			   if(!pf->eof())
			   {
				  for(int i=0;i<strlen(reg.direccion);i++)
				  {
					  reg.direccion[i]=toupper(reg.direccion[i]);
				  }
				  pf->seekp(-sizeof(reg),ios::cur);     //-48
				  pf->write((char *)&reg,sizeof(reg));
				  mul++;
				  pf->seekg(mul*sizeof(reg));
				  pf->seekp(mul*sizeof(reg));

			   }
		   }
	   }
	   pf->close();
	   delete(pf);


}
//---------------------------------------------------------------------------

/*Cardinal Cv(char v[]){
  AnsiString s="";
  for(int i=0;i<strlen(v);i++)
  {
	 s=s+v[i];

  }
  return StrToInt(s);
}  */
/*void listado(Cardinal aux)
{
   AnsiString linea;//linea para copiar al text;
   AnsiString linea2;
	Cardinal num;
	RegAlumno reg;
	byte m=0;

	fstream pf(nomArch.c_str(),ios::in|ios::binary);
	fstream texto("listado.txt",ios::out);
	if(!pf.fail())
	{
		while(!pf.eof())
		{
			pf.read((char*)&reg,sizeof(reg));
			if(!pf.eof())
			{

			  if(reg.fecha.dia==aux)
			  {
				 linea2=reg.nombre;
				 linea=IntToStr(reg.fecha.dia)+"/"+IntToStr(reg.fecha.mes)+"/"+IntToStr(reg.fecha.año);
				 m++;

				 for(int i=1;i<=linea2.Length();i++)
				 {
					 texto.put(linea2[i]);
				 }
				 texto.put(' ');
				 for(int i=1;i<=linea.Length();i++)
				 {
					 texto.put(linea[i]);
				 }
				 //pf.seekp(m*sizeof(reg));
				 texto.put(10);

			  }
			}
		}
	}
	pf.close();
	texto.close();
 }
  */

void __fastcall TForm1::Button4Click(TObject *Sender)
{

   Cardinal aux=StrToInt(Edit4->Text);
   AnsiString linea;//linea para copiar al text;
   AnsiString linea2;
	Cardinal num;
	RegAlumno reg;
	byte m=0;

	fstream pf(nomArch.c_str(),ios::in|ios::binary);
	fstream texto("listado.txt",ios::out);
	if(!pf.fail())
	{
		while(!pf.eof())
		{
			pf.read((char*)&reg,sizeof(reg));
			if(!pf.eof())
			{

			  if(reg.fecha.dia==aux)
			  {
				 linea2=reg.nombre;
				 linea=IntToStr(reg.fecha.dia)+"/"+IntToStr(reg.fecha.mes)+"/"+IntToStr(reg.fecha.año);
				 m++;

				 for(int i=1;i<=linea2.Length();i++)
				 {
					 texto.put(linea2[i]);
				 }
				 texto.put(' ');
				 for(int i=1;i<=linea.Length();i++)
				 {
					 texto.put(linea[i]);
				 }
				 //pf.seekp(m*sizeof(reg));
				 texto.put(10);

			  }
			}
		}
	}
	pf.close();
	texto.close();
}
//---------------------------------------------------------------------------

