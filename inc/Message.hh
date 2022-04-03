#ifndef MESSAGE_HH
#define MESSAGE_HH

using namespace std;


/*!
 * \brief Klasa modeluje pojecie wiadomosci
 *
 * Klasa zawiera pole przechowujace informacje o rzeczywistej kolejnosc, o kolosowo
 * przydzielonej kolejnosci oraz pole przechowujace tresc wiadomosci 
 * 
 * W klasie zostala zdefiniowane konstruktory parametryczne oraz
 * nieparametryczne
 * Klasa zawiera rowniez metody dostepowe do pol prywatnych klasy
 * 
 */
class message
{
private:
    unsigned int current_number;
    unsigned int sequence_number;
    string message_content;
public:
    message(){current_number = 0;sequence_number = 0; message_content = "";};
    message(unsigned int i, unsigned int j){current_number = i; sequence_number = j;};
    void set_message_content(string m_s){message_content = m_s;};
    const unsigned int get_current_number(){return current_number;};
    const unsigned int get_sequence_number(){return sequence_number;};
    string get_message_content(){return message_content;};
};


#endif




