// Стандарт С++20:

#include <iostream>
#include <format>                                                           // Подключение современной библиотеки форматирования текста (стандарт C++20);
#include <cstdint>                                                          // Подключение типов данных с гарантированным фиксированным размером в битах;

int main()
{
    int64_t country_population{0};
    int64_t total_population{0};
    std::cout << "Введите численность населения в мире: ";
    std::cin >> total_population;
    std::cout << "Введите численность населени какой-нибудь страны: ";
    std::cin >> country_population;
    double percentage_ratio = static_cast<double>(country_population) * 100.0 / static_cast<double>(total_population);
    std::cout << std::format("Численность страны составляет {:.5f}% от мирового населения.\n", percentage_ratio);
}


// Стандарт С++23/С++26:
/*
#include <iostream>
#include <print>                                                    // Подключение библиотеки для форматированной быстрой печати текста (std::print/println);
#include <cstdint>                                                  // Подключение типов данных с гарантированным фиксированным размером в битах;

int main()
{
    int64_t country_population{0};
    int64_t total_population{0};
    std::print("Введите численность населения в мире: ");
    std::cin >> total_population;
    std::print("Введите численность населени какой-нибудь страны: ");
    std::cin >> country_population;
    double percentage_ratio = static_cast<double>(country_population) * 100.0 / static_cast<double>(total_population);
    std::println("Численность страны составляет {:.5f}% от мирового населения.", percentage_ratio);
}
*/
