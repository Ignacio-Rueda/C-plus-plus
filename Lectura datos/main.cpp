#include <iostream>
#include <fstream>
#include <string>
#include<cstring> // para poder llamar a la funcion strtok
#include <vector>
#include <cmath>

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

int main ()
{  double n=0;
   //Para cargar el ficheor movimientos, reemplazar usuarios por movimientos
   vector<vector<string> > data = readData("movimientos.txt");
   for(int i = 0; i < data.size(); i++){
   	for(int j = 0; j < data[i].size(); j++)
   		cout << data.at(i).at(j)<< " ";
   	cout << endl;
   }

   n=5/2;
   cout<<n;
}
