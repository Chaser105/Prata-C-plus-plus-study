// Стандарт С++11:
/*
#include <iostream>

int main()
{
    using namespace std;
    const int Lbs_per_stn = 14;
    int lbs;
    cout << "Введите свой вес в фунтах: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;                  // При делении целых чисел, дробная часть отсечется, т.к. перменные имеют тип int;
    int pounds = lbs % Lbs_per_stn;                 // Для нахождения остатка значения имеют только целочисленный тип;
    cout << lbs << " фунтов = " << stone
    << " стоуна(ов), " << pounds << " и фунтов.\n";
    return 0;
}
*/


// Стандарт С++20:

#include <iostream>
#include <format>
#include <cstdint>                                           // Подключение типов данных с гарантированным фиксированным размером в битах;

constexpr int32_t Lbs_per_stn = 14;

int main()
{
    std::int32_t lbs{0};
    std::cout << "Введите свой вес в фунтах: ";              // Если в строке не используется форматирование {}, вывод текста используется без форматирования (std::format);
    std::cin >> lbs;
    std::int32_t stone = lbs / Lbs_per_stn;                  // При делении целых чисел, дробная часть отсечется, т.к. перменные имеют тип int;
    std::int32_t pounds = lbs % Lbs_per_stn;                 // Для нахождения остатка значения имеют только целочисленный тип;
    std::cout << std::format("{} фунтов = {} стоуна(ов) и {} фунтов.\n", lbs, stone, pounds);
}


// Стандарт С++23/С++26:
/*
//import std;
#include <iostream>
#include <print>
#include <cstdint>               // Подключение типов данных с гарантированным фиксированным размером в битах;

constexpr int32_t Lbs_per_stn = 14;

int main()
{
    std::int32_t lbs{0};
    std::print("Введите свой вес в фунтах: ");               // Если в строке не используется форматирование {}, вывод текста используется без форматирования (std::format);
    std::cin >> lbs;
    std::int32_t stone = lbs / Lbs_per_stn;                  // При делении целых чисел, дробная часть отсечется, т.к. перменные имеют тип int;
    std::int32_t pounds = lbs % Lbs_per_stn;                 // Для нахождения остатка значения имеют только целочисленный тип;
    std::println("{} фунтов = {} стоуна(ов) и {} фунтов.", lbs, stone, pounds);
}
*/
