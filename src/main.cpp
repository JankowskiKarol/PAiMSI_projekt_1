#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <ctime>
#include "Message.hh"
#include "MessageTransfer.hh"
#include "FileHandling.hh"

using namespace std;


int main()
{
    unsigned int n = 0;
    priority_queue stack_of_messages;
    priority_queue queue_of_messages;

    if(!generating_messages(n, stack_of_messages)) return 1;

    cout << endl << "Wiadomosc zostala podzielona na: " << n << " pakietow" << endl;

    cout << "\n Wysylanie \n" << endl;
/*!!! zakomentowano kod do pomiaru czasu relizacji algorytmu wybranej struktury ADT oraz wywolania funkcji 
   pomocniczy ukazujacych etapy realizacji programu !!!*/
   
    //stack_of_messages.display();
/*
    double r;
    cout.setf(ios::fixed);
    cout.precision(10);
    clock_t start, end;
    start = clock();
*/
    sending_messages(stack_of_messages, queue_of_messages);
/*
    end = clock();
    r = (end - start)/(double)CLOCKS_PER_SEC;
    cout << "Czas wykonania: \t" << r << endl;
*/    
    cout << "\n Odbieranie \n" << endl;
    //queue_of_messages.display();

    savetofile(queue_of_messages);
}