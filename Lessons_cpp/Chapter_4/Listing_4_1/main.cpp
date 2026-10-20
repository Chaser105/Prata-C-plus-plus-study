// Стандарт С++11:

#include <iostream>

int main()
{
    using namespace std;
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;
    int yamcosts[3] = {20, 30, 5};
    cout << "Всего батата = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "В упаковке " << yams[1] << " штук батата; стоимость ";
    cout << yamcosts[1] << " центов за батат.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "Общие затраты на батат = " << total << " центов";
    cout << "\nРазмер массива yams = " << sizeof yams;
    cout << " байт.\n";
    cout << "Размер одного элемента массива yams = " << sizeof yams[0];
    cout << " байт.\n";
    return 0;
}