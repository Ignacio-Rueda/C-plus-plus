#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;
void lectura()
{
ifstream archivo;//para escribir sería off stream, para la lectura, es ifstream
string texto;
archivo.open("lectura/nombre del archivo",ios::in);//Abrimos el archivo en modo lectura
if(archivo.fail())//Comprobamos si quremos abrir un archivo que no existe
{
cout<<"No se pudo abrir el archivo"<<endl;
exit(1);}
while(!archivo.eof())//Mientras no sea el final del archivo
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();//cerramos el archivo}
void escribir()
{
    ofstream archivo;
    archivo.open("prueba escritura",ios::out);//Abrimos el archivo
    if(archivo.fail())
    {
        cout<<"No se pudo abrir el archivo";
        exit(1);//gracias a la libreria stdlib
    }
    archivo<<"Hola que tal mi nombre es Nacho"<<endl;
    archivo.close();//cerrar el archivo}
int main()
{
  /*lectura();*/
  escribir();
}
