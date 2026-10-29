// Стандарт С++11:

#include <iostream>

struct inflatable                  // Объявление структуры (шаблона нового типа данных) inflatable;
{
    char name[20];                 // Поле структуры: массив из 20 символов char;
    float volume;                  // Поле структуры: переменная типа float;
    double price;                  // Поле структуры: переменная типа double;
};

int main()
{
    using namespace std;

    inflatable bouquet =
    {
        "sunflowers",
        0.20,
        12.49
    };
    inflatable choice;
    cout << "Букет: " << bouquet.name << " за $";
    cout << bouquet.price << endl;
    choice = bouquet;
    cout << "Букет: " << choice.name << " за $";
    cout << choice.price << endl;
    return 0;
}