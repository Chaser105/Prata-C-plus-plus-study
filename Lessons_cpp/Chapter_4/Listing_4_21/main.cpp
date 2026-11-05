// Стандарт С++11:

#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    inflatable* ps = new inflatable;
    cout << "Введите имя надувного изделия: ";
    cin.get(ps->name, 20);
    cout << "Введите объем в кубических футах: ";
    cin >> (*ps).volume;
    cout << "Введите цену: ";
    cin >> ps->price;
    cout << "Имя " << (*ps).name << endl;
    cout << "Объем " << ps->volume << " кубических футов\n";
    cout << "Цена $" << ps->price << endl;
    delete ps;
    return 0;
}