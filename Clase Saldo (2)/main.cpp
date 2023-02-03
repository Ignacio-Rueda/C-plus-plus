#include <iostream>
#include <fstream>
#include <string>
#include<cstring> // para poder llamar a la funcion strtok
#include <vector>

using namespace std;
class Fecha
{
    private:
    int dia,mes,ano;
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
    Fecha(int d,int m,int a)
    {
       Set(d,m,a);
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
    double actualizoSALDO=0;
    double Saldo_total=0;
    vector<Fecha>fecha_movimiento;
    vector<double>registro_movimiento;
    public:
    void Set(vector<Fecha>f_m,vector<double>r_m,double sal)
    {
        for(int x=0;x<r_m.size();x++)
        {
            fecha_movimiento.push_back(f_m.at(x));
            registro_movimiento.push_back(r_m.at(x));
            Saldo_total+=r_m.at(x);
        }
        Saldo_total=sal;
    }
    void setter(double sal)
    {
        Saldo_total=sal;    }

    Saldo()
    {
        vector<Fecha>v;
        vector<double>v1;
        Saldo_total=0;

    }
    Saldo(vector<Fecha>f_m,vector<double>r_m,double sal)
    {
       for(int x=0;x<r_m.size();x++)
        {
            fecha_movimiento.push_back(f_m.at(x));
            registro_movimiento.push_back(r_m.at(x));
        }
        Saldo_total=sal;
    }

    vector<Fecha>getfecha_movimiento()
    {
        return fecha_movimiento;
    }
    vector<double>getregistro_movimiento()
    {
       return registro_movimiento;
    }
    double getSaldo_total()
    {
        return Saldo_total;
    }
    bool Numeros_Rojos()
    {
        bool numerosRojos=true;
        if(Saldo_total>500)
        {
            numerosRojos=false;
        }
        return numerosRojos;
    }
     void Resumen_gastos()
    {
        double suma=0;
        double media=0;
        int movimientos=0;
        int ano=0;
        int mes=0;
        if(Saldo_total>500)
        {
        for(int j=0;j<fecha_movimiento.size();j++)
        {
            if(fecha_movimiento.at(j).getano()>ano)
            {
                ano=fecha_movimiento.at(j).getano();
            }

        }
           for(int j=0;j<fecha_movimiento.size();j++)
        {
            if(fecha_movimiento.at(j).getmes()>mes&&fecha_movimiento.at(j).getano()==ano)
            {
                mes=fecha_movimiento.at(j).getmes();
            }

        }

           for(int j=0;j<fecha_movimiento.size();j++)
        {
            if((fecha_movimiento.at(j).getmes()==mes)&&(fecha_movimiento.at(j).getano()==ano)&&fecha_movimiento.at(j).getdia()>=1/*(R_M.at(j)<0)*/)

            {
                if(registro_movimiento.at(j)<0)//Inferior a "0" porque son gastos.
                {
                    cout<<fecha_movimiento.at(j).getdia()<<"/"<<fecha_movimiento.at(j).getmes()<<"/"<<fecha_movimiento.at(j).getano()<<endl;
                    cout<<registro_movimiento.at(j)<<"€"<<endl;
                    suma+=registro_movimiento.at(j);
                }
                movimientos++;
            }

        }

                media=suma/movimientos;

                cout<<"LA MEDIA DE GASTO DURANTE EL ULTIMO MES HA SIDO:"<<endl;
                cout<<media<<"EUROS"<<endl;

    }
    }
    void Imprimir()
    {
        for(int x=0;x<registro_movimiento.size();x++)
        {
            cout<<registro_movimiento.at(x)<<endl;
        }
    }

};
class Persona
{   private:string nombre,primerApellido,segundoApellido,dni,ciudad;
            double saldo;
    Saldo MOVIMIENTOS;
    public:
    void Set(string n, string p,string s,string d,string c,double sal)
    {
        nombre=n;
        primerApellido=p;
        segundoApellido=s;
        dni=d;
        ciudad=c;
        saldo=0;
    }
    Persona()
    {
        nombre="a";
        primerApellido="a";
        segundoApellido="a";
        dni="a";
        ciudad="a";
        saldo=0;
    }
    Persona(string n,string p, string s,string d,string c,double sal)
    {
        Set(n,p,s,d,c,sal);
    }
    void MOV(Saldo M)
    {
        MOVIMIENTOS.Set(M.getfecha_movimiento(),M.getregistro_movimiento(),M.getSaldo_total());
    }

    Saldo getMOVIMIENTOS()
    {
        return MOVIMIENTOS;
    }
    void actualizarSaldo()
    {
        saldo=MOVIMIENTOS.getSaldo_total();
    }
    string getnombre()
    {
        return nombre;
    }
    string getprimerApellido()
    {
        return primerApellido;
    }
    string getsegundoApellido()
    {
        return segundoApellido;
    }
    string getdni()
    {
        return dni;
    }
    string getciudad()
    {
        return ciudad;
    }
    double getsaldo()
    {
        return saldo;
    }
    void Imprimir()
    {
        cout<<nombre<<" "<<primerApellido<<" "<<segundoApellido<<" "<<dni<<" "<<ciudad<<" "<<saldo<<endl;
    }
};
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

vector<vector<string> > LeoUsuarios(string file){
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
vector<vector<string> > LeoMovimientos(string file){
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
void En_Numeros_Rojos(vector<Persona>usuarios)
{   double suma=0;
    for(int i=0;i<usuarios.size();i++)
    {
    if(usuarios.at(i).getMOVIMIENTOS().getSaldo_total()<500)
    {
        usuarios.at(i).Imprimir();
    }
    }


}
  int Personas_con_mas_dinero(vector<Persona>usuarios)
    {   Persona P;
        int pos=0;
        vector<Persona>masDinero;
        double cantidad_dinero=0;
        for(int j=0;j<usuarios.size();j++)
        {
            if(usuarios.at(j).getMOVIMIENTOS().getSaldo_total()>cantidad_dinero)
            {
                cantidad_dinero=usuarios.at(j).getMOVIMIENTOS().getSaldo_total();
            }
        }
        for(int j=0;j<usuarios.size();j++)
        {
            if(usuarios.at(j).getMOVIMIENTOS().getSaldo_total()==cantidad_dinero&&usuarios.at(j).getMOVIMIENTOS().getSaldo_total()>500)
            {

                usuarios.at(j).Imprimir();
                pos=j;
            }
        }


    return pos;
    }

      void Personas_con_MENOS_dinero(vector<Persona>usuarios)
    {   double cantidad_dinero=0;
        Persona P;
        vector<Persona>menosDinero;
            cantidad_dinero=usuarios.at(0).getMOVIMIENTOS().getSaldo_total();

        for(int j=0;j<usuarios.size()-1;j++)
        {
            int siguiente=j+1;
            if(usuarios.at(j).getMOVIMIENTOS().getSaldo_total()<usuarios.at(siguiente).getMOVIMIENTOS().getSaldo_total()&&usuarios.at(j).getMOVIMIENTOS().getSaldo_total()<=cantidad_dinero)
            {
                cantidad_dinero=usuarios.at(j).getMOVIMIENTOS().getSaldo_total();
            }
            else if (usuarios.at(siguiente).getMOVIMIENTOS().getSaldo_total()<usuarios.at(j).getMOVIMIENTOS().getSaldo_total()&&usuarios.at(siguiente).getMOVIMIENTOS().getSaldo_total()<=cantidad_dinero)
            {
                cantidad_dinero=usuarios.at(siguiente).getMOVIMIENTOS().getSaldo_total();
            }
        }
        for(int j=0;j<usuarios.size();j++)
        {
            if(usuarios.at(j).getMOVIMIENTOS().getSaldo_total()==cantidad_dinero)
            {
               usuarios.at(j).Imprimir();
            }
        }

    }
    vector<Persona> Reparto_dinero(vector<Persona>&usuarios,int pos)
    {   double dinero=0;
        double cuantoTiene=0;
        long double Dinero_numeros_rojos=0;
        cuantoTiene=usuarios.at(pos).getMOVIMIENTOS().getSaldo_total();
        cuantoTiene=((cuantoTiene/2)-500);
            Saldo S8;
            S8.setter(cuantoTiene);
            usuarios.at(pos).MOV(S8);
            usuarios.at(pos).actualizarSaldo();
        for(int x=0;x<usuarios.size();x++)

        {
            if(usuarios.at(x).getMOVIMIENTOS().getSaldo_total()<500)
            {

                Dinero_numeros_rojos+=usuarios.at(x).getMOVIMIENTOS().getSaldo_total();

            }
        }
        for(int x=0;x<usuarios.size();x++)
        {
            if(usuarios.at(x).getMOVIMIENTOS().getSaldo_total()<500)
            {

                dinero=cuantoTiene*(usuarios.at(x).getMOVIMIENTOS().getSaldo_total())/Dinero_numeros_rojos;
                dinero=((dinero+usuarios.at(x).getMOVIMIENTOS().getSaldo_total())*0.1);
                Saldo S8;
                S8.setter(dinero);
                usuarios.at(x).MOV(S8);
                usuarios.at(x).actualizarSaldo();

            }


        }

        return usuarios;
    }



int main ()
{   vector<Persona>usuarios;
    string nombre;
    string primerApellido;
    string segundoApellido;
    string dni;
    string ciudad;
    string saldoFormatostring;
    string fecha;
    double saldo=0;
    int pos=0;
    int dia;
    int mes;
    int ano;
    double num_double;
    Persona P;
    vector<vector<string> > datosUsuarios = LeoUsuarios("usuarios(1).txt");
   for(int i = 0; i < datosUsuarios.size(); i++){

   	for(int j = 0; j < datosUsuarios[i].size(); j++)
   	{
        nombre=datosUsuarios.at(i).at(0);
        primerApellido=datosUsuarios.at(i).at(1);
        segundoApellido=datosUsuarios.at(i).at(2);
        dni=datosUsuarios.at(i).at(3);
        ciudad=datosUsuarios.at(i).at(4);
        P.Set(nombre,primerApellido,segundoApellido,dni,ciudad,saldo);
   	}

        usuarios.push_back(P);
   }
    vector<vector<string> > datosMovimientos = LeoMovimientos("movimientos(1).txt");
     for(int i = 0; i < usuarios.size(); i++)
   {
    vector<double>movimientos_de_dinero;
    vector<Fecha>movimientos_de_fechas;
    double sumatoria=0;
   for(int L=0;L<datosMovimientos.size();L++)
   {
   if(usuarios.at(i).getnombre()==datosMovimientos.at(L).at(0)&&usuarios.at(i).getprimerApellido()==datosMovimientos.at(L).at(1))
   {

        saldoFormatostring=datosMovimientos.at(L).at(4);
        fecha=datosMovimientos.at(L).at(3);
        num_double=stod(saldoFormatostring);//pasar de un tipo de variabla a otra se denomina cast o casting.Por ejemplo de un string a un double;
        sumatoria+=num_double;
        movimientos_de_dinero.push_back(num_double);
        conversion(fecha,dia,mes,ano);
        Fecha F(dia,mes,ano);
        bool comprobar=F.Comprobar_fecha(F);
        if(comprobar==1)
        {
            movimientos_de_fechas.push_back(F);
        }
        else
        {
            cout<<"Fecha incorrecta"<<endl;
        }
    }

    }
    Saldo S5(movimientos_de_fechas,movimientos_de_dinero,sumatoria);
    usuarios.at(i).MOV(S5);
    usuarios.at(i).actualizarSaldo();
/*    usuarios.at(i).actualizarSaldo(usuarios.at(i).getMOVIMIENTOS().getSaldo_total());*/
    }
    cout<<"PERSONA X QUE ESTÁ EN NUMEROS ROJOS"<<endl;
    Saldo S6;
    bool numerorojo=S6.Numeros_Rojos();
    if(numerorojo==true)
    {
    cout<<"En numeros rojos: ";usuarios.at(0).Imprimir();

    }
    else
    {
   cout<<"No está en numeros rojos"<<" ";usuarios.at(0).Imprimir();
    }
    cout<<"REGISTRO MOVIMIENTOS ULTIMO MES, PERSONA X"<<endl;
    Saldo S5(usuarios.at(0).getMOVIMIENTOS().getfecha_movimiento(),usuarios.at(0).getMOVIMIENTOS().getregistro_movimiento(),usuarios.at(0).getMOVIMIENTOS().getSaldo_total());
    S5.Resumen_gastos();
    cout<<"PERSONAS QUE ESTÁN EN NÚMEROS ROJOS"<<endl;
    En_Numeros_Rojos(usuarios);
    cout<<"PERSONA O PERSONAS QUE TIENEN MAS DINERO"<<endl;
    pos=Personas_con_mas_dinero(usuarios);
     cout<<"PERSONA O PERSONAS QUE TIENEN MENOS DINERO"<<endl;
    Personas_con_MENOS_dinero(usuarios);
    Reparto_dinero(usuarios,pos);
    cout<<"REPARTO DE DINERO A PERSONAS EN NUMERO ROJOS"<<endl;
    En_Numeros_Rojos(usuarios);
    cout<<"PERSONA O PERSONAS QUE TIENEN MAS DINERO"<<endl;
    Personas_con_mas_dinero(usuarios);
    vector<Fecha>m;
    vector<double>n;

    /*Saldo S8(m,n,9);
    usuarios.at(5).MOV(S8);
    usuarios.at(5).actualizarSaldo();
    usuarios.at(5).Imprimir();*/




}
