#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
int NP(int numero,int digito)
{
    int primo=0;
    int resultado=0;
    resultado=numero%digito;
   if(resultado==0&&digito>1)
   {
    primo=digito;    }
    if (resultado==0&&digito==1)
    {
        primo=1;
    }
    else if (resultado>=1&&digito>1)
    {

        primo=NP(numero,digito-1);
        cout<<primo<<endl;
    }
    return primo;
}


int Fibonacci(int numero)
{
    int fibo;
    if(numero<=2)
    {
        fibo=1;    }
    else
    {
        fibo=Fibonacci(numero-1)+Fibonacci(numero-2);
    }
    return fibo;
}

int Factorial(int numero)
{
    int n=0;
    if(numero==0)
    {
        n=1;    }
    else
    {
        n=numero*Factorial(numero-1);    }
    return n;}

int main()
{   int n;
    cout<<"Dime numero para comprobar si es primo: "<<endl;
    cin>>n;
    int devu=NP(n,n-1);
    if(devu==1)
    {
        cout<<"NUMERO PRIMO"<<endl;    }
    else
    {
        cout<<"NUMERO NO PRIMO"<<endl;    }


}
