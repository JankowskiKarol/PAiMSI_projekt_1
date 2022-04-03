#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include "Queue.hh"

using namespace std;


/*!
 * \brief realizuje wyswietlenie zawartosci elementów kolejki pryjorytetowej
 * 
 */
void priority_queue::display()
{
    receiving_list *help_head = head;
    while(help_head)
    {
        cout << help_head->part_of_message.get_sequence_number() << "\t";
        cout << help_head->part_of_message.get_current_number() << "\t"; 
        cout << help_head->part_of_message.get_message_content() << endl;
        help_head = help_head->next;
    }
    delete help_head;
}


/*!
 * \brief realizuje usuwanie elementu z kolejki pryjorytetowej
 * 
 */
void priority_queue::remove()
{
    if(head)
    {
        receiving_list *new_elem = head;
        head = head->next;
        if(!head) end = NULL;
        delete new_elem;
    }
}


/*!
 * \brief realizuje umieszczanie elementu w kolejce pryjorytetowej wedlug klucza
 * 
 * \param[in] receiving_list - element do umieszczenia w kolejce
 * \param[in] send_receive - rodzaj kolejki
 * 
 */
void priority_queue::insert(message receiving_message, bool send_receive)
{
    receiving_list *help_elem;
    receiving_list *new_elem = new receiving_list;
    new_elem->next = NULL;
    if(send_receive)
    {
        new_elem->key = receiving_message.get_current_number();
    }
    else
    {
        new_elem->key = receiving_message.get_sequence_number();
    }
    new_elem->part_of_message = receiving_message;

    if(!head)
    {
        head = end = new_elem;
    }
    else if (head->key > new_elem->key) 
    {
        new_elem->next = head;
        head = new_elem;
    }
    else
    {
        help_elem = head;
        while ((help_elem->next) && (help_elem->next->key <= new_elem->key)) 
        {
            help_elem = help_elem->next;
        }
        new_elem->next = help_elem->next;
        help_elem->next = new_elem;
        if(!new_elem->next)
        {
            end = new_elem;
        } 
    }
}