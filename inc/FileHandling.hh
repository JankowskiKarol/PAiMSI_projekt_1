#ifndef FILEHANDLING_HH
#define FILEHANDLING_HH

#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include "Queue.hh"

using namespace std;

/*!
 * \brief Deklaracja funkcji otwierajacej plik i sprawdzajacej ilosc pakietow

 */
bool preparefile(ifstream &, const char *, unsigned int &);

/*!
 * \brief Deklaracja funkcji odczytu z pliku

 */
string readfromfile(ifstream &);

/*!
 * \brief Deklaracja funkcji zapisu do pliku

 */
void savetofile(priority_queue &);


#endif
