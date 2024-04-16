#ifndef __UTILS_H
#define __UTILS_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace Utils
{

double modifico_d(string line);                      // definisco le mie funzioni
unsigned int modifico_i(string line);
double rilascia(string line, unsigned int number);
double valore_finale(unsigned int dimensione, double* array1, double* array2, double Valore_iniziale);
double calcolo_interesse (unsigned int dimensione, double* array1, double* array2);

}
#endif
