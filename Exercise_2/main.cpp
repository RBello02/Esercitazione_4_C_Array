#include <iostream>
#include <iomanip>
//#include <sstream>
#include <fstream>
#include "Utils.hpp"

using namespace std;

int main()
{
    string file_input = "data.csv";
    string file_output = "result.txt";
    ifstream ifstr(file_input);
    ofstream ofstr(file_output);


    string line;
    unsigned int counter = 0;

    double S = 0;
    unsigned int n = 0;

    double* w = nullptr;
    double* r = nullptr;

    double interesse = 0;
    double V = 0;


    if (ifstr.fail())
    {
        std::cerr<<"Apertura del file fallita"<< endl;
        return 1;
    }
    if (ofstr.fail())
    {
        std::cerr<<"Apertura del file fallita"<< endl;
        return 2;
    }

    while (getline(ifstr,line))
    {
        counter++;
        if (counter == 1)
        {
            S = Utils::modifico_d(line);
        }
        if (counter == 2)
        {
            n = Utils::modifico_i(line);
            w = new double [n];       // costruisco i miei array dinamici
            r = new double [n];
        }
        if (counter >= 4)
        {
            w[counter-4] = Utils::rilascia(line,0);
            r[counter-4] = Utils::rilascia(line,1);

        }
    }
    V = Utils::valore_finale(n,w,r,S);
    interesse = Utils::calcolo_interesse(n,w,r);

    // fase di stampa

    ofstr << "S = "  <<fixed << setprecision(2)<< S <<", n = "<<n<< endl;
    cout << "S = "  <<fixed << setprecision(2)<< S <<", n = "<<n<< endl;

    ofstr << "w = [ ";
    cout << "w = [ ";

    for (unsigned int i = 0; i < n; i++)
    {
        ofstr << *(w+i) <<" ";
        cout << *(w+i) <<" ";
    }
    ofstr << "]"<<endl;
    cout << "]"<<endl;
    ofstr << "r = [ ";
    cout << "r = [ ";
    for (unsigned int i = 0; i < n; i++)
    {
        ofstr << *(r+i) <<" ";
        cout << *(r+i) <<" ";
    }
    ofstr << "]"<<endl;
    cout << "]"<<endl;
    ofstr << "Rate of return of the portfolio: " <<fixed<< setprecision(4) << interesse <<endl;
    cout << "Rate of return of the portfolio: " <<fixed<< setprecision(4) << interesse <<endl;
    ofstr <<"V: "<<fixed << setprecision(2)<<V;
    cout <<"V: "<<fixed << setprecision(2)<<V<<endl;

    // fine programma

    ifstr.close();
    ofstr.close();

    delete [] w;
    delete [] r;

    return 0;
}

