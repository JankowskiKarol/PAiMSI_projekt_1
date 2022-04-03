#ifndef QUEUE_HH
#define QUEUE_HH

#include "Message.hh"


/*!
 * \brief Struktura modeluje pojecie listy jednokierunkowej

 * Struktura zawiera wskaznik na nastepny element tego samego typu,
 * zawiera również pole przechowujące wiadomosc oraz pole z wartoscia klucza
 *          
 */
struct receiving_list
{
    receiving_list *next;
    message part_of_message;
    int key;
};

/*!
 * \brief Klasa modeluje pojecie kolejki pryjorytetowej
 *
 * Klasa zawiera wskaznik na strukturę listy jednokierunkowej, na jej poczatek 
 * oraz na jej koniec
 * 
 * W klasie zostal zdefiniowany konstruktor nieparametryczny i destruktor
 * Klasa zawiera metody obslugujace dzialanie kolejki pryjorytetowej:
 * - metoda dodajac nowy elemet do kolejki wstawijac go wedlug odpowiedniej kolejnosci
 * klucza
 * - metoda usuwajaca element z kolejki o najniższej watości klucza
 * - metoda pomocnicza wyswietlajaca zawartosc kolejki pryjorytetowej
 * - metoda sprawdzajaca, czy kolejka jest pusta
 * - metody dostepowe do wartosci klucza oraz zawartosci przechowywanej wiadomosci
 * - metoda zwacajaca wskaznik na poczatek kolejki
 * 
 */
class priority_queue
{
private:
    receiving_list *head;
    receiving_list *end;
public:
    priority_queue(){head = NULL; end = NULL;};
    ~priority_queue(){while(head)remove();}
    void insert(message,bool);
    void remove();
    void display();
    bool empty(){return !head;};
    int getpriority(){return head->key;};
    string get_string(){return head->part_of_message.get_message_content();};
    receiving_list* top(){return head;};
};



#endif
