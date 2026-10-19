// Стандарт С++20:

#include <iostream>
#include <format>                                    // Подключение современной библиотеки форматирования текста (стандарт C++20);

int main()
{
    double distance{0.0};
    double volume_of_gasoline{0.0};
    std::cout << "Введите пройденное расстояние в километрах: ";
    std::cin >> distance;
    std::cout << "Введите количество израсходованного бензина в литрах: ";
    std::cin >> volume_of_gasoline;
    std::cout << std::format("Израсходовано бензина {:.2f} на 100 км.\n", (volume_of_gasoline * 100.0) / distance);
}


// Стандарт С++23/С++26:
/*
#include <iostream>
#include <print>

int main()
{
    double distance{0.0};
    double volume_of_gasoline{0.0};
    std::print("Введите пройденное расстояние в километрах: ");
    std::cin >> distance;
    std::print("Введите количество израсходованного бензина в литрах: ");
    std::cin >> volume_of_gasoline;
    std::println("Израсходовано бензина {:.2f} на 100 км.", (volume_of_gasoline * 100.0) / distance);
}
*/
