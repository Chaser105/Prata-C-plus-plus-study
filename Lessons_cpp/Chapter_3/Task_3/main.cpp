// Стандарт С++20:

#include <iostream>
#include <format>                                                              // Подключение библиотеки для современного и безопасного форматирования текста (std::format);

constexpr double Arcseconds_In_Minute{60.0};                                   // Константа времени компиляции: количество угловых секунд в одной минуте дуги;
constexpr double Arcseconds_In_Degree{3600.0};                                 // Константа времени компиляции: общее количество секунд в одном географическом градусе;

int main()
{
    double lat_degree{0.0}, lat_minute{0.0}, lat_second{0.0};                  // Безопасная инициализация вещественных переменных двойной точности для хранения координат;
    std::cout << "Введите широту в градусах, минутах и секундах:\n";
    std::cout << "Сначала введите в градусах: ";
    std::cin >> lat_degree;
    std::cout << "Затем введите в минутах: ";
    std::cin >> lat_minute;
    std::cout << "И введите в секундах: ";                                     
    std::cin >> lat_second;
    double total_degree = lat_degree + (lat_minute / Arcseconds_In_Minute) + (lat_second / Arcseconds_In_Degree); // Расчет итоговой десятичной широты силами точной вещественной арифметики;
    std::cout << std::format("{:g} градусов, {:g} минут, {:g} секунд = {:.4f} градусов\n", // Генерируем форматированную строку, где исходные данные компактны, а итог округлен;
                            lat_degree, lat_minute, lat_second, total_degree);
}



// Стандарт С++23/С++26:
/*
#include <iostream>
#include <print>                                                               // Подключение библиотеки для форматированной быстрой печати текста (std::print/println);

constexpr double Arcseconds_In_Minute{60.0};                                   // Константа времени компиляции: количество угловых секунд в одной минуте дуги;
constexpr double Arcseconds_In_Degree{3600.0};                                 // Константа времени компиляции: общее количество секунд в одном географическом градусе;

int main()
{
    double lat_degree{0.0}, lat_minute{0.0}, lat_second{0.0};                  // Безопасная инициализация вещественных переменных двойной точности для хранения координат;
    std::println("Введите широту в градусах, минутах и секундах:");
    std::print("Сначала введите в градусах: ");
    std::cin >> lat_degree;
    std::print("Затем введите в минутах: ");
    std::cin >> lat_minute;
    std::print("И введите в секундах: ");
    std::cin >> lat_second;
    double total_degree = lat_degree + (lat_minute / Arcseconds_In_Minute) + (lat_second / Arcseconds_In_Degree); // Расчет итоговой десятичной широты силами точной вещественной арифметики;
    std::println("{:g} градусов, {:g} минут, {:g} секунд = {:.4f} градусов.",   // Вывод результатов: исходные данные форматируются компактно, а итог округляется до 4 знаков;
            lat_degree, lat_minute, lat_second, total_degree);
}
*/