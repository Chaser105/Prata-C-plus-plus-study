// Стандарт С++11:

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "pantera";
    cout << "Введите животное из семейства кошачьих: ";
    cin >> charr1;
    cout << "Введите другое животное из семейства кошачьих: ";
    cin >> str1;
    cout << "Здесь несколько животных:\n";
    cout << charr1 << " " << charr2 << " "
        << str1 << " " << str2
        << endl;
    cout << "3 буквой в слове " << charr2 << " является "
         << charr2[2] << endl;
    cout << "3 буквой в слове " << str2 << " является "
         << str2[2] << endl;
    return 0;

}