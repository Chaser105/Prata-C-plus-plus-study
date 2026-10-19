// Стандарт С++20:

#include <iostream>
#include <format>                                                           // Подключение современной библиотеки форматирования текста (стандарт C++20);
#include <cstdint>                                                          // Подключение типов данных с гарантированным фиксированным размером в битах;

constexpr int64_t Seconds_Per_Minute{60};
constexpr int64_t Seconds_Per_Hour{60 * Seconds_Per_Minute};
constexpr int64_t Seconds_Per_Day{24 * Seconds_Per_Hour};

int main()
{
    int64_t seconds{0};
    std::cout << "Введите количество секунд: ";
    std::cin >> seconds;
    int64_t days = seconds / Seconds_Per_Day;
    int64_t hours = (seconds % Seconds_Per_Day) / Seconds_Per_Hour;
    int64_t minutes = ((seconds % Seconds_Per_Day) % Seconds_Per_Hour) / Seconds_Per_Minute;
    int64_t per_seconds = ((seconds % Seconds_Per_Day) % Seconds_Per_Hour) % Seconds_Per_Minute;
    std::cout << std::format("{} секунд = {} дней, {} часов, {} минут, {} секунд.\n",
                        seconds, days, hours, minutes, per_seconds);
}


// Стандарт С++23/С++26:
/*
#include <iostream>
#include <print>                                                    // Подключение библиотеки для форматированной быстрой печати текста (std::print/println);
#include <cstdint>                                                  // Подключение типов данных с гарантированным фиксированным размером в битах;

constexpr int64_t Seconds_Per_Minute{60};
constexpr int64_t Seconds_Per_Hour{60 * Seconds_Per_Minute};
constexpr int64_t Seconds_Per_Day{24 * Seconds_Per_Hour};

int main()
{
    int64_t seconds{0};
    std::print("Введите количество секунд: ");
    std::cin >> seconds;
    int64_t days = seconds / Seconds_Per_Day;
    int64_t hours = (seconds % Seconds_Per_Day) / Seconds_Per_Hour;
    int64_t minutes = ((seconds % Seconds_Per_Day) % Seconds_Per_Hour) / Seconds_Per_Minute;
    int64_t per_seconds = ((seconds % Seconds_Per_Day) % Seconds_Per_Hour) % Seconds_Per_Minute;
    std::println("{} секунд = {} дней, {} часов, {} минут, {} секунд.",
                        seconds, days, hours, minutes, per_seconds);
}
*/


// Более усовершенствованный метод расчета времени (не по 3 главе учебника С. Прата):
/*
#include <print>
#include <chrono>

int main()
{
    std::chrono::seconds total_seconds{31'600'000};   //  Задаем исходную продолжительность в секундах;
    auto days = std::chrono::duration_cast<std::chrono::days>(total_seconds); // Достаем чистые ДНИ (как мы уже умеем);
    auto time_left = total_seconds - days; // Вычитаем целые дни из общего времени, чтобы остался "хвостик" для часов и минут. Система сама знает, сколько секунд было в 365 днях, и вычтет их;
    std::chrono::hh_mm_ss time_split{time_left};  // Передаем оставшийся хвостик в специальный разделитель времени hh_mm_ss. Он сам мгновенно разложит остаток секунд на чистые часы, минуты и секунды;
    std::println("{} seconds = {} days, {} hours, {} minutes, {} seconds", // Печатаем идеальный результат через .count();
                 total_seconds.count(),
                 days.count(),
                 time_split.hours().count(),
                 time_split.minutes().count(),
                 time_split.seconds().count());
}
*/

