// Стандарт С++11:
/*
#include <iostream>

int main()
{
    using namespace std;
    int symbol;
    symbol = 25;
    cout << "Слово состоит из ";
    cout <<  symbol;
    cout << " символов";
    cout <<endl;
    symbol = symbol - 4;
    cout << "Другое слово состоит из " << symbol << " символа." << endl;
    return 0;
}
*/


// Стандарт С++11:
#include <iostream>

int main()
{
    int symbol = 25;
    std::cout << "Слово состоит из ";
    std::cout << symbol;
    std::cout << " символов.\n";
    symbol = symbol - 4;
    std::cout << "Другое слово состоит из " << symbol << " символа.\n";
}
