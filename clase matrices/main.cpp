#include <iostream>
#include<vector>
#include <assert.h>
using namespace std;

class MatrizInt
{
    private:
    vector<int>datos;
    int fil,col;
    public:
    MatrizInt(int f, int c);//Constructor para inicializar la matriz
    int Filas() const {return fil;};//Métodos para consultar el tamaño
    int Columnas() const {return col;};//Métodos para consultar el tamaño
    int Get (int f, int c) const;//Método para obtener un elemento de la matriz
    void Set (int f, int c, int val);//Método para poner un elemento en la matriz



};
 int MatrizInt::Get(int f,int c)const
    {
        assert(f>=0&&f<fil&&c>=0&&c<col);//precondición
        return datos.at(f*col+c);
    }
void MatrizInt::Set(int f, int c,int val)
{
    assert(f>=0&&f<fil&&c>=0&&c<col);//precondición
    datos.at(f*col+c)=val;}
MatrizInt LeeMatriz()
{
    int f,c;
    do{
    cout<<"Dime tamaNo (filas y columnas): ";
    cin>>f>>c;
    }while(f<0||c<0);
}

int main()
{

}
