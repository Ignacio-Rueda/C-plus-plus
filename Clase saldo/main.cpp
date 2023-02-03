#include <iostream>
#include<vector>
#include <fstream>
#include <string>
#include<cstring> // para poder llamar a la funcion strtok
using namespace std;
class Fecha
{
    private:
    int dia;
    int mes;
    int ano;
    public:
    void Set(int d,int m,int a)
    {
        dia=d;
        mes=m;
        ano=a;
     }
     Fecha()
     {
        dia=1;
        mes=1;
        ano=1991;
     }
     Fecha (int d,int m,int a)
     {
        dia=d;
        mes=m;
        ano=a;
     }

    int getdia()
    {
        return dia;
    }
    int getmes()
    {
        return mes;
    }
    int getano()
    {
        return ano;
    }
    bool Comprobar_fecha(Fecha F1)
    {
        bool fecha_correcta=true;
        int a=F1.getano();
        int m=F1.getmes();
        int d=F1.getdia();
           if(a>0&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d>=1&&d<=31)||((m==4||m==6||m==9||m==11))&&(d>=1&&d<=30)||((a%4==0||a%400==0&&a%100!=0)&&(m==2)&&(d>=1&&d<=29))||((m==2)&&(d>=1&&d<=28)))
        {
            fecha_correcta=true;
        }
            else
        {
            fecha_correcta=false;
        }
        return fecha_correcta;

    }
    void Imprimir()
    {
    cout<<dia<<"/"<<mes<<"/"<<ano<<endl;
    }
};
class Saldo
{
    private:
    double Saldo_total=0;
    vector<Fecha>Fecha_movimiento;
    vector<double>Registro_movimientos;
    public:
    void Set(double s,vector<Fecha>F_m,vector<double>R_m)
    {
        Saldo_total=s;
        Fecha_movimiento=F_m;
        Registro_movimientos=R_m;
    }
    Saldo()
    {   vector<Fecha>v;
        vector<double>v1;
        Saldo_total=0;
        for(int j=0;j<v.size();j++)
        {
            Fecha_movimiento.push_back(v.at(j));
        }
        for(int j=0;j<v1.size();j++)
        {
            Registro_movimientos.push_back(v1.at(j));
            Saldo_total+=v1.at(j);
        }
    }
    Saldo(vector<Fecha>&F_m,vector<double>&R_m)
    {
        for(int j=0;j<F_m.size();j++)
        {
            Fecha_movimiento.push_back(F_m.at(j));
        }
          for(int j=0;j<R_m.size();j++)
        {
            Registro_movimientos.push_back(R_m.at(j));
            Saldo_total+=R_m.at(j);
        }

    }
        double getSaldo_total()
        {
            return Saldo_total;
        }
    vector<Fecha>getFecha_movimiento()
        {
            return Fecha_movimiento;
        }
    vector<double>getRegistro_movimientos()
        {
        return Registro_movimientos;
        }
    bool Numeros_rojos(float Saldo_total)
        {
            bool NumerosRojos=false;
            if(Saldo_total<500)
            {
                NumerosRojos=true;
            }
            return NumerosRojos;
        }
        void SaldoTotal()
        {
            double suma=0;
            for(int x=0;x<Registro_movimientos.size();x++)
            {
                suma+=Registro_movimientos.at(x);
            }
            Saldo_total=suma;        }
    void Resumen_gastos(vector<Fecha>F_M,vector<double>R_M)
    {
        double suma=0;
        double media=0;
        int movimientos=0;
        int ano=0;
        int mes=0;
        for(int j=0;j<F_M.size();j++)
        {
            if(F_M.at(j).getano()>ano)
            {
                ano=F_M.at(j).getano();
            }

        }
           for(int j=0;j<F_M.size();j++)
        {
            if(F_M.at(j).getmes()>mes&&F_M.at(j).getano()==ano)
            {
                mes=F_M.at(j).getmes();
            }

        }

           for(int j=0;j<F_M.size();j++)
        {
            if((F_M.at(j).getmes()==mes)&&(F_M.at(j).getano()==ano)&&F_M.at(j).getdia()>=1/*(R_M.at(j)<0)*/)

            {
                if(R_M.at(j)<0)
                {
                    cout<<F_M.at(j).getdia()<<"/"<<F_M.at(j).getmes()<<"/"<<F_M.at(j).getano()<<endl;
                    cout<<R_M.at(j)<<"€"<<endl;
                    suma+=R_M.at(j);
                }
                movimientos++;
            }

        }

                media=suma/movimientos;

                cout<<"LA MEDIA DE GASTO DURANTE EL ULTIMO MES HA SIDO:"<<endl;
                cout<<media<<"EUROS"<<endl;

    }
    void Imprimir()
    {
        for(int i=0;i<Fecha_movimiento.size();i++)
        {
                Fecha_movimiento.at(i).Imprimir();
                cout<<Registro_movimientos.at(i)<<endl;
        }
                cout<<Saldo_total<<endl;

    }


};
class Persona
{   private:
    string nombre,apellido1,apellido2,DNI,ciudad;
    int edad;
    Saldo MOVIMIENTO;
    vector<Fecha>fecha;
    public:
        void Setta(vector<Fecha>f)
        {   vector<Fecha>fecha;
        for(int x=0;x<f.size();x++)
        {
            fecha.push_back(f.at(x));
        }

        }
        void Set(string n,string a1,string a2,string dni,string ciu,int ed)
    {
        nombre=n;
        apellido1=a1;
        apellido2=a2;
        DNI=dni;
        ciudad=ciu;
        edad=ed;
    }
    Persona()
    {   nombre="a";
        apellido1="a";
        apellido2="a";
        DNI="a";
        ciudad="a";
        edad=0;
    }
    Persona(string n,string a1,string a2,string dni,string ciu,int ed)
    {
        Set(n,a1,a2,dni,ciu,ed);
    }
    void SetMOVIMIENTO(Saldo m)
    {
        MOVIMIENTO=m;
    }
    Saldo getMOVIMIENTO()
    {
        return MOVIMIENTO;
    }
    vector<Fecha>getfecha()
    {
        return fecha;
    }
    string getnombre()
    {
        return nombre;
    }
    string getapellido1()
    {
        return apellido1;
    }
    string getapellido2()
    {
        return apellido2;
    }
    string getDNI()
    {
        return DNI;
    }
    string getciudad()
    {
        return ciudad;
    }
    int getedad()
    {
        return edad;
    }

    void Imprimir_fecha(vector<Saldo>fecha)
    {
        for(int x=0;x<fecha.size();x++)
        {
            fecha.at(x).Imprimir();
        }
    }

    void Imprimir()
    {
        cout<<nombre<<" "<<apellido1<<" "<<apellido2<<" "<<DNI<<" "<<ciudad<<" "<<edad<<" "<<"aNos"<<" "<<endl;
    }
    void Imprimo()
    {   for(int x=0;x<getMOVIMIENTO().getFecha_movimiento().size();x++)
        {getMOVIMIENTO().getFecha_movimiento().at(x).Imprimir();
        cout<<getMOVIMIENTO().getRegistro_movimientos().at(x)<<endl;
        cout<<getMOVIMIENTO().getSaldo_total();
        }
    }

};

    vector<Fecha>copia(vector<Fecha>movimientos)
    {
        vector<Fecha>copio;
        for(int j=0;j<movimientos.size();j++)
        {
            copio.push_back(movimientos.at(j));
        }
        return copio;
    }
    /*vector<Persona>Personas_En_Numeros_Rojos(vector<Persona>Almacen_datos,vector<Persona>&Resultado)//FUNCION PARA DETECTAR QUIENES ESTÁN EN NÚMEROS ROJOS;
    {   double saldo=0;
        Saldo S;
        for(int j=0;j<Almacen_datos.size();j++)
        {
           saldo=Almacen_datos.at(j).getsaldo();
           bool resultado=S.Numeros_rojos(saldo);
           if(resultado==1)
           {
            Resultado.push_back(Almacen_datos.at(j));
           }
        }
        return Resultado;    }
    vector<Persona>Personas_con_mas_dinero(vector<Persona>Almacen_datos,vector<Persona>&Personas_con_mas_dinero)
    {   double cantidad_dinero=0;
        for(int j=0;j<Almacen_datos.size();j++)
        {
            if(Almacen_datos.at(j).getsaldo()>cantidad_dinero)
            {
                cantidad_dinero=Almacen_datos.at(j).getsaldo();
            }
        }
        for(int j=0;j<Almacen_datos.size();j++)
        {
            if(Almacen_datos.at(j).getsaldo()==cantidad_dinero&&Almacen_datos.at(j).getsaldo()>500)
            {
                Personas_con_mas_dinero.push_back(Almacen_datos.at(j));            }
        }

        return Personas_con_mas_dinero;
    }
    vector<Persona>Personas_con_MENOS_dinero(vector<Persona>Almacen_datos,vector<Persona>&Resultado_Personas_Menos_Dinero)
    {  double cantidad_dinero=0;

            cantidad_dinero=Almacen_datos.at(0).getsaldo();

        for(int j=0;j<Almacen_datos.size()-1;j++)
        {
            int siguiente=j+1;
            if(Almacen_datos.at(j).getsaldo()<Almacen_datos.at(siguiente).getsaldo()&&Almacen_datos.at(j).getsaldo()<=cantidad_dinero)
            {
                cantidad_dinero=Almacen_datos.at(j).getsaldo();
            }
            else if (Almacen_datos.at(siguiente).getsaldo()<Almacen_datos.at(j).getsaldo()&&Almacen_datos.at(siguiente).getsaldo()<=cantidad_dinero)
            {
                cantidad_dinero=Almacen_datos.at(siguiente).getsaldo();
            }
        }
        for(int j=0;j<Almacen_datos.size();j++)
        {
            if(Almacen_datos.at(j).getsaldo()==cantidad_dinero)
            {
                Resultado_Personas_Menos_Dinero.push_back(Almacen_datos.at(j));
            }
        }
        return Resultado_Personas_Menos_Dinero;

    }
    vector<Persona>Reparto_Riqueza(vector<Persona>Persona_con_mas_dinero,vector<Persona>Numeros_Rojos,vector<Persona>&roja)
    {   double Dinero_en_total=0;
        double Dinero_numeros_rojos=0;
        double PorcentajePersonas=0;
        double total=0;
        for(int j=0;j<Persona_con_mas_dinero.size();j++)
        {
            Dinero_en_total+=(Persona_con_mas_dinero.at(j).getsaldo()-500);
        }
        for(int j=0;j<Numeros_Rojos.size();j++)
        {
            Dinero_numeros_rojos+=Numeros_Rojos.at(j).getsaldo();
        }

    vector<double>Porcentaje;//Porcentaje de dinero que tiene una persona sin que reciba nada de dinero
    vector<double>Diferencia_Porcentaje;//Porcentaje - porcentaje individual
    int TOTAL_PERSONAS=Numeros_Rojos.size();//Sacamos del vector, cantidad de personas
    double DineroRojo=Dinero_numeros_rojos/100;
    double porcentaje_por_persona=100/TOTAL_PERSONAS;
    double dividir=Dinero_en_total/100;
    double reparto=Dinero_en_total/TOTAL_PERSONAS;
    for(int x=0;x<Numeros_Rojos.size();x++)
    {
        Porcentaje.push_back((Numeros_Rojos.at(x).getsaldo()*100)/Dinero_numeros_rojos);//Porcentaje de dinero que tiene una persona sin recibir nada
    }
    for(int x=0;x<Porcentaje.size();x++)
    {
        Diferencia_Porcentaje.push_back((porcentaje_por_persona-Porcentaje.at(x))*DineroRojo);
    }
    for(int x=0;x<Numeros_Rojos.size();x++)
    {
        Persona P2(Numeros_Rojos.at(x).getnombre(),Numeros_Rojos.at(x).getapellido1(),Numeros_Rojos.at(x).getapellido2(),Numeros_Rojos.at(x).getDNI(),Numeros_Rojos.at(x).getciudad(),Numeros_Rojos.at(x).getedad(),Diferencia_Porcentaje.at(x)+reparto);
        roja.push_back(P2);
    }
    return roja;

    }*/
    vector<string> tokenize(const string &str, const char* delim)
{
	 vector<string> result;
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        result.push_back(std::string(token));
        token = strtok(nullptr, delim);
    }
    return result;
}

vector<vector<string> > readData(string file){
   string data;
	fstream infile;
	infile.open (file);
   const char* delim = ";";
   vector<vector<string> > data_result;
   while(getline(infile, data))
   {
     vector<string> row = tokenize(data, delim);
     data_result.push_back(row);
   }
	infile.close();

	return data_result;
}
vector<vector<string> > Leo_Datos(string file){
   string data;
	fstream infile;
	infile.open (file);
   const char* delim = ";";
   vector<vector<string> > data_result;
   while(getline(infile, data))
   {
     vector<string> row = tokenize(data, delim);
     data_result.push_back(row);
   }
	infile.close();

	return data_result;
}
int conversion(string fecha,int &dia,int &mes,int &ano)
{   string DIA;
    string MES;
    string ANO;
    for(int x=0;x<fecha.size();x++)
    {   if(x<2)
        {
            MES+=fecha.at(x);
            mes=stoi(MES);
        }
        if(x>2&&x<5)
        {
            DIA+=fecha.at(x);
            dia=stoi(DIA);
        }
        if(x>5)
        {
            ANO+=fecha.at(x);
            ano=stoi(ANO);
        }

    }
    return dia;

}

int main()
{   Persona P;
    Persona P5;
    string NOMBRE;
    string APELLIDO1;
    string APELLIDO2;
    string DNI;
    string CIUDAD;
    string S_SALDO;
    int EDAD=0;
    vector<Persona>usuarios;
    vector<vector<string> >lectura_Usuarios;
    //Para cargar el ficheor movimientos, reemplazar usuarios por movimientos
   vector<vector<string> > Leo_Datos = readData("usuarios(1).txt");
   for(int i = 0; i < Leo_Datos.size(); i++){
   	for(int j = 0; j < Leo_Datos[i].size(); j++){
   	NOMBRE=Leo_Datos.at(i).at(0);
   	APELLIDO1=Leo_Datos.at(i).at(1);
   	APELLIDO2=Leo_Datos.at(i).at(2);
   	DNI=Leo_Datos.at(i).at(3);
   	CIUDAD=Leo_Datos.at(i).at(4);
    P5.Set(NOMBRE,APELLIDO1,APELLIDO2,DNI,CIUDAD,EDAD);
        }
         usuarios.push_back(P5);
   }
  vector<vector<string> >movimientos;
    //Para cargar el ficheor movimientos, reemplazar usuarios por movimientos
   vector<vector<string> > data = readData("movimientos(1).txt");
   for(int i = 0; i < data.size(); i++){
   vector<string>unafila;
   	for(int j = 0; j < data[i].size(); j++){
        unafila.push_back(data.at(i).at(j));
        }
    movimientos.push_back(unafila);
   }
    string fecha;
    int dia=0;
    int mes=0;
    int ano=0;
    /*Persona P15("Ana","López","Ibáñez",DNI,CIUDAD,EDAD);*/
    for(int i=0;i<usuarios.size();i++)
    {
    vector<Fecha>Fecha_Movimientos;
    vector<double>Registro_Movimientos;
    for(int x=0;x<movimientos.size();x++)
    {   if(usuarios.at(i).getapellido1()== movimientos.at(x).at(1)&&usuarios.at(i).getapellido2()==movimientos.at(x).at(2))
    {
        S_SALDO=movimientos.at(x).at(4);
        double num_float=stod(S_SALDO);//convertir string float;
        Registro_Movimientos.push_back(num_float);
        fecha=(movimientos.at(x).at(3));
        conversion(fecha,dia,mes,ano);
        Fecha F;
        Fecha F1(dia,mes,ano);
        bool correcto=F.Comprobar_fecha(F1);
        if(correcto==1)
            {
            Fecha_Movimientos.push_back(F1);
            }
        else
            {
            cout<<"Fecha incorrecta"<<endl;
            }
    }
    }

    Saldo S5(Fecha_Movimientos,Registro_Movimientos);
    S5.Imprimir();
    usuarios.at(i).SetMOVIMIENTO(S5);
    usuarios.at(i).getMOVIMIENTO().SaldoTotal();

    }
    double sumatoria=0;
    /*usuarios.at(0).getMOVIMIENTO().getFecha_movimiento();
    usuarios.at(15).getMOVIMIENTO().SaldoTotal();
    cout<<usuarios.at(15).getMOVIMIENTO().getSaldo_total();















    /*vector<Persona>datosCompletos_persona;
      for(int x=0;x<usuarios.size();x++)
      {
         Persona P5(usuarios.at(x).getnombre(),usuarios.at(x).getapellido1(),usuarios.at(x).getapellido2(),usuarios.at(x).getDNI(),usuarios.at(x).getciudad(),0,Saldo_total_individuo.at(x));
         datosCompletos_persona.push_back(P5);
      }
    vector<Persona>Resultado_Numeros_Rojos;
    vector<Persona>Resultado_Personas_Mas_Dinero;
    vector<Persona>Resultado_Personas_Menos_Dinero;
    Personas_En_Numeros_Rojos(datosCompletos_persona,Resultado_Numeros_Rojos);
    cout<<"DATOS DE PERSONAS EN NUMEROS ROJOS"<<endl;
    for(int j=0;j<Resultado_Numeros_Rojos.size();j++)
    {
        Resultado_Numeros_Rojos.at(j).Imprimir();
    }
    if(Resultado_Numeros_Rojos.size()==0)
    {
        cout<<"ŃINGUNA PERSONA ESTÁ EN ŃUMEROS ROJOS"<<endl;
    }
    cout<<"PERSONA CON MAS DINERO"<<endl;
    Personas_con_mas_dinero(datosCompletos_persona,Resultado_Personas_Mas_Dinero);
    for(int j=0;j<Resultado_Personas_Mas_Dinero.size();j++)
    {
        Resultado_Personas_Mas_Dinero.at(j).Imprimir();
    }
    cout<<"PERSONA CON MENOS DINERO"<<endl;
    Personas_con_MENOS_dinero(datosCompletos_persona,Resultado_Personas_Menos_Dinero);
    for(int j=0;j<Resultado_Personas_Menos_Dinero.size();j++)
    {
        Resultado_Personas_Menos_Dinero.at(j).Imprimir();
    }
    vector<Persona>Personas_rojas;
    vector<Persona> reparto=Reparto_Riqueza(Resultado_Personas_Mas_Dinero,Resultado_Numeros_Rojos,Personas_rojas);
    cout<<"DINERO EN TOTAL"<<endl;
    cout<<"DATOS DE PERSONAS EN NUMEROS ROJOS"<<endl;
    for(int j=0;j<Personas_rojas.size();j++)
    {
        Personas_rojas.at(j).Imprimir();
    }
*/
}
}
