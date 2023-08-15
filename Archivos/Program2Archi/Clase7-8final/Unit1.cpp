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
				 habilitar=(codi==reg.codigo)&&(reg.marca==0);
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
				hallado=(reg.codigo==regNuevo.codigo);
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
//ojo el reestructurar solo se puede hacer una vez nada más como el pato lucas este truco solo se puede hacer una vez xd
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	RegAlumno reg;//new Estructura
	RegAlumno2 reg2;//antigua Estructura
	fstream fi(nomArch.c_str(),ios::in|ios::binary);
	fstream fo("temporal.tmp",ios::out|ios::binary);
	if(!fi.fail()) //hubo fallas en abrir el archivo
	{
		while(!fi.eof())          // llego al fin del archivo
		{
			fi.read((char *)&reg2,sizeof(reg2));
			if(!fi.eof())
			{
				reg.codigo=reg2.codigo;
				strcpy(reg.nombre,reg2.nombre); //reg.nombre=reg2.nombre;
				strcpy(reg.direccion,reg2.direccion);
				reg.fecha=reg2.fecha;
                reg.marca=0;
				fo.write((char *)&reg,sizeof(reg));
			}
		}
	}
	fi.close();
	fo.close();
	remove(nomArch.c_str());
	rename("temporal.tmp",nomArch.c_str());
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Boolean bandera=false;
	RegAlumno reg;                                  //formato binary
	fstream f(nomArch.c_str(),ios::in|ios::out|ios::binary);
	Word codi=StrToInt(Edit1->Text);
	if(!f.fail())
	{
		while(!f.eof()&& !bandera)
		{
			f.read((char *)&reg,sizeof(reg));
			if(!f.eof())
			{
				bandera= codi==reg.codigo;
			}
		}
		if(bandera)
		{
			reg.marca=1;          //donde esta al puntero
			f.seekg(-sizeof(reg),ios::cur);//usamospararetroceder el
			f.write((char *)&reg,sizeof(reg));
			Edit1->Text="";
			Edit2->Text="";
			Edit3->Text="";
			MaskEdit1->Text="";
		}
	}
	f.close();
}
//---------------------------------------------------------------------------
   ///menu
void __fastcall TForm1::Porcodigo1Click(TObject *Sender)
{
	 RegAlumno reg;
	 RegIdxCod regIdx;  //Crear el archivo indice por codigo
	 fstream fd(nomArch.c_str(),ios::in|ios::binary);
	 fstream fi("codigo.idx",ios::out|ios::binary);
	 if(!fd.fail())
	 {
		 while(!fd.eof())
		 {
			regIdx.pos=fd.tellg();//Devuelve la posicion del puntero
			fd.read((char *)&reg,sizeof(reg));
			if(!fd.eof())
			{
				regIdx.codigo=reg.codigo;
				fi.write((char*)&regIdx,sizeof(regIdx));
			}
		 }
	 }
	 fd.close();
	 fi.close();

}
//---------------------------------------------------------------------------
void TForm1::Mostrar(RegAlumno reg)
{
	Edit1->Text=reg.codigo;
	Edit2->Text=reg.nombre;
	Edit3->Text=reg.direccion;
	MaskEdit1->Text=IntToStr(reg.fecha.dia)+"/"+IntToStr(reg.fecha.mes)+"/" +IntToStr(reg.fecha.año);
}

void __fastcall TForm1::Button6Click(TObject *Sender)    //btn Avanzar
{
	RegAlumno reg;
	RegIdxCod regIdx;     Cardinal p;
	pfi->read((char *)&regIdx,sizeof(regIdx));
	if(pfi->eof())
	{
		Button6->Enabled=false;//btn avanzar;
		Button5->Enabled=true;//btn retroceder;
		pfi->close();
		pfi->open("codigo.idx",ios::in|ios::binary);
		pfi->seekg(0,ios::end);  //puntero lo enviamos al final
		pfi->seekg(0,ios::end);  //no quiso obedecer con un cmndo asi que lo puse 2 veces xd
		p=pfi->tellg();         //una manera de ver si mi puntero avanzo la cantidad de bits  correspondiente
	}
	else{


	   pf->seekg(regIdx.pos,ios::beg);
	   pf->read((char *)&reg,sizeof(reg));
	   Mostrar(reg);
	   Button5->Enabled=true;//btn retroceder
	}
}
//---------------------------------------------------------------------------
//REtroceder....
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	RegAlumno reg;
	RegIdxCod regIdx;
	Cardinal p;
	p=pfi->tellg();
	if(p<=sizeof(regIdx))
	{
		Button5->Enabled=false;  //btn retroceder
	}
	else
	{
	   pfi->seekg(-2*sizeof(regIdx),ios::cur);  //16.o.2*8
	   pfi->read((char *)&regIdx,sizeof(regIdx));
	   pf->seekg(regIdx.pos,ios::beg);
	   pf->read((char *)&reg,sizeof(reg));
	   Mostrar(reg);
	   Button6->Enabled=true;   //btn avanzar
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	RegAlumno reg;
  RegIdxCod regIdx;
  pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
  pfi=new fstream("codigo.idx",ios::in|ios::binary);
  if (!pfi->fail()) {
	Button4->Enabled=false;
	Button6->Enabled=true;
	Button5->Enabled=false;
	Button7->Enabled=true;
	pfi->read((char *)&regIdx,sizeof(regIdx));
	if (!pfi->eof()) {
		pf->seekg(regIdx.pos,ios::beg);
		pf->read((char *)&reg,sizeof(reg));
		if (!pf->eof()) {
			Edit1->Text=reg.codigo;
			Edit2->Text=reg.nombre;
			Edit3->Text=reg.direccion;
			MaskEdit1->Text=IntToStr(reg.fecha.dia)+"/"+IntToStr(reg.fecha.mes)+"/"+IntToStr(reg.fecha.año);
		}
	}
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
   Button7->Enabled=false;   //btn
   Button6->Enabled=false;  //btn
   Button5->Enabled=false; //btn
   Button4->Enabled=false;//btn iniciar
   pf->close();
   pfi->close();
   delete(pf);
   delete(pfi);
}
//---------------------------------------------------------------------------
void TForm1::Ordenar(AnsiString ArchIdx)
{
	RegIdxCod ireg,jreg,kreg;
	Cardinal i,j,k;
	fstream i(ArchIdx.c_str(),ios::in|ios::out|ios::binary);
	if(!fi.fail())
	{
	   i=0; j=1;
		while(i<j){ //mientras no haya terminado de ordenar
		   i=fi.tellg();
		   //buscando el menor
		   j=i
		   fi.seekg(i,ios::beg);
		   while(!fi.eof())
		   {
			  j=fi.tellg();
			  fi.read((char *)&jreg,sizeof(jreg));
			  if(!fi.eof())
			  {
				 if(j==i){    //si es el primero
				 k=j;
				 kreg=jreg;
				 ireg=jreg;
				 }else
				 {
					 if(jreg.codigo<kreg.codigo)
					 {
						k=j;
						kreg=jreg;
					 }

				 }
			  }
		   }

		   fi.close();
		   fi.open(ArchIdx.c_str(),ios::in|ios::out|ios::binary);
		   if(i!=k)
		   {
			   fi.seekg(K,ios::beg);
			   fi.write((char *)&ireg,sizeof(ireg));
			   fi.seekg(i,ios::beg);
			   fi.write((char *)&kreg,sizeof(kreg));

		   }
		   i=i+sizeof(ireg);
		   j=j-sizeof(jreg);

		}
	}
    fi.close();
}

void __fastcall TForm1::PorCodigo2Click(TObject *Sender)
{
    Ordenar("codigo.idx");
}
//---------------------------------------------------------------------------

