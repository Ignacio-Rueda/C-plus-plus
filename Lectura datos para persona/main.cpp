#include <iostream>
#include<vector>
#include <fstream>
#include <string>
#include<cstring> // para poder llamar a la funcion strtok
using namespace std;
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

class Persona
{
    private:
    string nombre,apellido1,apellido2,DNI,ciudad;
    public:
    void Set(string n,string a1,string a2,string dni,string ciu)
    {
        nombre=n;
        apellido1=a1;
        apellido2=a2;
        DNI=dni;
        ciudad=ciu;
    }
    void Imprimir()
    {
        cout<<nombre<<apellido1<<apellido2<<DNI<<ciudad<<endl;
    }
};

int main()
{    Persona P;
    string NOMBRE;
    string APELLIDO1;
    string APELLIDO2;
    string DNI;
    string CIUDAD;
    vector<Persona>almacen;

   vector<vector<string> >nombre;
    //Para cargar el ficheor movimientos, reemplazar usuarios por movimientos
   vector<vector<string> > data = readData("usuarios.txt");
   for(int i = 0; i < data.size(); i++){
   vector<string>unafila;
   	for(int j = 0; j < data[i].size(); j++){
        unafila.push_back(data.at(i).at(j));
        }
    nombre.push_back(unafila);
   }

    for(int x=0;x<nombre.size();x++)
    {
        for(int i=0;i<nombre.at(x).size();i++)
        {
            if (i==0)
            {
                 NOMBRE=nombre.at(x).at(0);
                 APELLIDO1=nombre.at(x).at(1);
                 APELLIDO2=nombre.at(x).at(2);
                 DNI=nombre.at(x).at(3);
                 CIUDAD=nombre.at(x).at(4);
                    P.Set(NOMBRE,APELLIDO1,APELLIDO2,DNI,CIUDAD);
                    almacen.push_back(P);

            }
        }
    }

    for(int x=0;x<almacen.size();x++)
    {
        almacen.at(x).Imprimir();
    }


}
