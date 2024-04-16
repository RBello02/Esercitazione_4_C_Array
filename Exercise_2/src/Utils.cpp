#include "Utils.hpp"
#include <sstream>
using namespace std;

namespace Utils{

double modifico_d(string line)
{
    double valore;
    line[0]='0';
    line[1]='0';
    istringstream convert(line);        // definisco la classe convert su line che ha il compito di convertire da stringa a 'quello che mi serve'
    convert >> valore;
    return valore;
}
unsigned int modifico_i(string line)
{
    int valore;
    line[0]='0';
    line[1]='0';
    istringstream convert(line);        // definisco la classe convert su line che ha il compito di convertire da stringa a 'quello che mi serve'
    convert >> valore;
    return valore;
}
double rilascia(string line, unsigned int tipo)     // data la riga del mio file questo metodo mi restituisce il primo o il secondo valore
{                                                   // la variabile tipo è 0 se mi riferisco al primo elemento e 1 se mi riferisco al secondo
    double* vettore = new double [2];
    unsigned int counter = 0;
    istringstream iss(line);        // permette di trattare la stringa come un flusso di input
    string token;
    getline(iss,token,';');         // estrae i caratteri fino a ; e salva in token
    vettore[0] = stod(token);       // converte token in double
    getline(iss,token,';');
    vettore[1] = stod(token);

    return *(vettore + tipo);

}
double valore_finale(unsigned int dimensione, double* array1, double* array2, double Valore_iniziale)
{
    double valore = 0;
    for (unsigned int i = 0; i < dimensione; i++)
    {
        valore += (1+ *(array2+i)) * Valore_iniziale * (*(array1+i));
    }
    return valore;
}
double calcolo_interesse(unsigned int dimensione, double* array1, double* array2)
{
    double somma = 0;
    for (unsigned int i = 0; i < dimensione; i++)
    {
        somma = somma + *(array1+i) * *(array2+i);
    }
    return somma;
}
}
