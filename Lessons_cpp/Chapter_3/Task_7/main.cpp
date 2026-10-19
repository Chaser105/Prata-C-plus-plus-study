// Стандарт С++20:

#include <iostream>
#include <format>                                           // Подключение современной библиотеки форматирования текста (стандарт C++20);

constexpr double Miles_In_100Km{62.14};
constexpr double Litres_Per_Gallon{3.875};

int main()
{
    double gasoline_in100km{0.0};
    std::cout << "Введите расход бензина на 100 км: ";
    std::cin >> gasoline_in100km;
    std::cout << std::format("Расход бензина в единицах измерения США {:.2f} миль на галлон.\n",
        (Miles_In_100Km * Litres_Per_Gallon) / gasoline_in100km);
}


// Стандарт С++23/С++26:
/*
#include <iostream>
#include <print>                                // Подключение библиотеки для форматированной быстрой печати текста (std::print/println);

constexpr double Miles_In_100Km{62.14};
constexpr double Litres_Per_Gallon{3.875};

int main()
{
    double gasoline_in100km{0.0};
    std::print("Введите расход бензина на 100 км: ");
    std::cin >> gasoline_in100km;
    std::println("Расход бензина в единицах измерения США {:.2f} миль на галлон.",
        (Miles_In_100Km * Litres_Per_Gallon) / gasoline_in100km);
}
*/