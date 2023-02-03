#include <iostream>
#include<vector>
using namespace std;

int main()
{   int tamaNo=3;
    vector<vector<double> >matrizA;
    for(int x=0;x<tamaNo;x++)
    {
        vector<double>unafila;
        for(int i=0;i<tamaNo;i++)
        {
            cout<<"Dime número"<<endl;
            double numero=0;
            cin>>numero;
            unafila.push_back(numero);
        }
        matrizA.push_back(unafila);
    }
    cout<<"Siguiente matriz"<<endl;
     vector<vector<double> >matrizB;
    for(int x=0;x<tamaNo;x++)
    {
        vector<double>unafila;
        for(int i=0;i<tamaNo;i++)
        {
            cout<<"Dime número"<<endl;
            double numero=0;
            cin>>numero;
            unafila.push_back(numero);
        }
        matrizB.push_back(unafila);
    }
        vector<vector<double> >matrizR;
    for(int x=0;x<tamaNo;x++)
    {
        vector<double>unafila;
        double Resultado=0;
        double suma=0;
        for(int i=0;i<tamaNo;i++)
        {
            for(int z=0;z<tamaNo;z++)
            {Resultado+=(matrizA.at(x).at(z)*matrizB.at(z).at(i));

            }
            unafila.push_back(Resultado);
            Resultado=0;
            suma=0;
        }


        matrizR.push_back(unafila);
    }

    for(int x=0;x<tamaNo;x++)
    {
        for(int i=0;i<tamaNo;i++)
        {
            cout<<matrizR.at(x).at(i);
            if(i==2)
            {
                cout<<""<<endl;
            }
        }
    }
}
