#ifndef MESSAGETRANSFER_HH
#define MESSAGETRANSFER_HH

#include "Queue.hh"

using namespace std;

/*!
 * \brief Deklaracja funkcji realizujacej wysylanie wiadomosci

 */
void sending_messages(priority_queue &, priority_queue &);

/*!
 * \brief Deklaracja funkcji realizujacej generowanie wiadomosci

 */
bool generating_messages(unsigned int &, priority_queue &);


#endif
