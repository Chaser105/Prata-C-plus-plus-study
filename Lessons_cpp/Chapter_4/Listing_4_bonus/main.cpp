// Стандарт С++23/С++26

#include <print>
#include <string>
#include <variant>   // Замена опасного union;
#include <bitset>    // Безопасная альтернатива битовым полям;
#include <bit>       // Для std::bit_cast;
#include <cstdint>

// 1. Safe Enum: Безопасное (ограниченное) перечисление. Защищает от путаницы типов.
// Явно задаем тип uint8_t (1 байт), чтобы экономить память.
namespace                                               // namespace - пространство имен, которое сообщает компилятору, что данная структура будет использоваться только в файле main.cpp, тем самым защищая от конфликтов имен, в случае расширении программы;
{
    enum class TransactionStatus : std::uint8_t         // enum class - класс для создание безопасного перечисления. TransactionStatus - перечисляемый тип данных. : std::uint8_t - указывает компилятору, что перечислимый тип занимает 8 бит;
    {
        Pending,                                        // Константе по молчанию присвоится 0;
        Approved,                                       // Константе по молчанию присвоится 1;
        Rejected                                        // Константе по молчанию присвоится 2;
    };
}

// 2. Safe Bit Fields: Используем std::bitset для флагов безопасности.
// 4 бита под настройки доступа (например: [0]-чтение, [1]-запись, [2]-VIP, [3]-крипто).
using AccountFlags = std::bitset<4>;                    // using - создает псевдоним AccountFlags для сложного типа std::bitset<4>.
                                                        // std::bitset<4> - безопасный контейнер C++, который выделяет из памяти ровно 4 бита для независимого управления флагами доступа (например: [0]-чтение, [1]-запись, [2]-VIP, [3]-крипто). То что AccountFlags может использовать;


namespace                                               // namespace - пространство имен, которое сообщает компилятору, что данная структура будет использоваться только в файле main.cpp, тем самым защищая от конфликтов имен, в случае расширении программы;
{
    // Современная структура банковского платежа
    struct Payment                                      // Объявление структуры типа Payment;
    {
        std::string target_account{};                   // Поле структуры: инициализированный объект строки под именем target_account, который не имеет ни одного символа;
        double amount{0.0};                             // Поле структуры: инициализированная переменная типа double значением 0.0;

        // 3. Safe Union: std::variant. Может хранить ЛИБО строку с ошибкой, ЛИБО флаги аккаунта.
        // В отличие от union, variant помнит, что в нем лежит, и не позволит прочитать мусор.
        std::variant<std::string, AccountFlags> security_info{}; // Поле структуры security_info, которое может хранить в памяти объект строки std::string или флаг пользователя объекта AccountFlags;

        TransactionStatus status{TransactionStatus::Pending};    // Имя status переменной типа перечислений TransactionStatus, которая инициализируется по умолчанию константой Pending из этого перечисления;
    };
}

int main()
{
    // Задаем флаги: выставляем биты 0 и 2 в true (например, чтение и VIP-статус)
    AccountFlags flags;
    flags.set(0);
    flags.set(2);

    // Создаем транзакцию с помощью безопасного variant и enum class
    const Payment tx
    {
        .target_account = "NL99BANK0123456789",
        .amount = 1500.50,
        .security_info = flags, // variant автоматически переключился на тип AccountFlags
        .status = TransactionStatus::Approved
    };

    // 4. Безопасный вывод enum class. Неявное приведение к числу запрещено, приводим явно.
    std::println("Статус транзакции (числовой код): {}", static_cast<std::uint8_t>(tx.status));

    // Проверяем, что лежит внутри variant, с помощью функции std::holds_alternative
    if (std::holds_alternative<AccountFlags>(tx.security_info))
    {
        // std::get безопасно извлекает данные. Если бы там была строка, программа бы не прочитала мусор, а выдала ошибку.
        auto current_flags = std::get<AccountFlags>(tx.security_info);
        std::println("Битовая маска безопасности платежа: {}", current_flags.to_string());
    }

    // 5. БОНУС: std::bit_cast (C++20). Самый безопасный способ интерпретировать байты как другой тип.
    // Пересылаем сумму double в виде сырых байт uint64_t по сети без нарушения правил языка (Strict Aliasing).
    double money = 99.99;
    std::uint64_t raw_bytes = std::bit_cast<std::uint64_t>(money);
    std::println("Байты числа double 99.99, представленные как целое число: {}", raw_bytes);
}
