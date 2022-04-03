#include <iostream>
#include <cstdlib>
#include <cstring>
#include "FileHandling.hh"


using namespace std;


/*!
 * \brief przygotowuje plik do odczytu oraz sprawdza ilosc pakietow 
 * do podzialu
 * 
 * \param[in] Inputfile - rekurencja do uchwytu do pliku
 * \param[in] nameofmessage - wskaznik na nazwe pliku
 * \param[in] number_of_packets - liczba pakietow
 * 
 * \return true jezeli plik zostal otworzony poprawnie
 * \return false jezeli plik nie zostal otworzony poprawnie
 */
bool preparefile(ifstream &Inputfile, const char *nameofmessage, unsigned int &number_of_packets)
{
  if (!strcmp(nameofmessage,"messagetoAnia"))
  {
    Inputfile.open("messagetoAnia.dat");
    if (!Inputfile.is_open())
    {
      cerr << "Plik z wiadomoscia do Ani nie zostal otwarty" << endl;
      return false;
    }
  }

  string packet;

  while (!Inputfile.eof())
  {
    getline(Inputfile, packet);
    number_of_packets++;
  }
  number_of_packets-=1;
  Inputfile.close();
  Inputfile.open("messagetoAnia.dat");

  return true;
}


/*!
 * \brief realizuje odczyt z pliku
 * 
 * \param[in] Inputfile - rekurencja do uchwytu do pliku
 * 
 * \return przeczytana wiadomosc wchodzaca w sklad pojedynczego pakietu 
 */
string readfromfile(ifstream &Inputfile)
{
  string part_of_message_content;

  if (Inputfile.eof())
  {
    cerr << "Blad podzialu na pakiety" << endl;
  }
  else
  {
    
    getline(Inputfile, part_of_message_content);
  }
  
  return part_of_message_content;
}


/*!
 * \brief realizuje zapis do pliku
 * 
 * \param[in] queue_of_message - rekurencja do kolejki pryjorytetowej
 *
 */
void savetofile(priority_queue &queue_of_messages)
{
  ofstream save("wynik.txt");

    while (!queue_of_messages.empty())
    {
       save << queue_of_messages.get_string() << "\n";
       queue_of_messages.remove();
    }
    save.close();
}
