#include <iostream>
#include "MessageTransfer.hh"
#include "FileHandling.hh"

using namespace std;


/*!
 * \brief wysyla wiadomosc poprzez zdejmowanie elementu klasy message
 * z kolejki pryjorytetowaj zawierajacej losowa kolejnosc pakietow i wrzuca 
 * je na kolejke pryjorytetowa według poprawnej kolejnosci pakietow
 * 
 * \param[in] stack_of_messages - rekurencja do kolejki pryjorytetowej z wiadomosciami w losewej kolejnosci
 * \param[in] queue_of_messages - rekurencja do kolejki pryjorytetowej z wiadomosciami w losewej poprawnej
 * 
 */
void sending_messages(priority_queue &stack_of_messages, priority_queue &queue_of_messages)
{
    while (!stack_of_messages.empty())
    {
        message sending_message = stack_of_messages.top()->part_of_message;
        queue_of_messages.insert(sending_message,false);
        stack_of_messages.remove();
    }
}


/*!
 * \brief tworzy kolejke pryjorytetowa z wiadomosciami do wyslania 
 * w losowej kolejnosci
 * 
 * \param[in] n - rekurencja do ilosci pakietow
 * \param[in] stack_of_messages - rekurencja do kolejki pryjorytetowej z wiadomosciami w losewej kolejnosci
 * 
 * \return true jezeli proces sie powiodl
 * \return false jezeli proces sie nie powiodl
 */
bool generating_messages(unsigned int &n, priority_queue &stack_of_messages)
{
    unsigned int help_number = 0;
    bool another;
    unsigned int drawn_number = 0;
    ifstream Inputfile;
    if(!preparefile(Inputfile, "messagetoAnia", n))
    {
        return false;
    }
    unsigned int tab[n];

    srand(time(NULL));
    while (help_number < n)
    {   
        drawn_number = 1+rand()%n;
        another = true;
        for(unsigned int i=0; i<help_number; i++)
        {
            if(tab[i] == drawn_number) 
            {
                another = false;
            }
        }
        if (another == false)
        {
            help_number--;
        }
        else
        {
            tab[help_number] = drawn_number;
            message new_message(drawn_number,help_number+1);
            new_message.set_message_content(readfromfile(Inputfile));
            stack_of_messages.insert(new_message,true);
        }
        help_number++;
    }
    return true;
}




