// Стандарт С++11:

#include <iostream>

int main()
{
    using namespace std;
    cout << "Удивительный Счетчик вычислит для вас сумму и среднее значение ";
    cout << "5 чисел.\n";
    cout << "Пожалуста, введите 5 значений:\n";
    double number;
    double sum = 0.0;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Число " << i << ": ";
        cin >> number;
        sum += number;
    }
    cout << "Превосходный выбор! ";
    cout << " Их сумма составляет " << sum << endl;
    cout << ", а среднее значение " << sum / 5 << ".\n";
    cout << "Удивительный Счетчик прощается с вами!\n";
    return 0;
}