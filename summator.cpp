#include <iostream>
#include <limits> // для добавления защиты от дурака
#include "files/taskmanager.h"
int main()
{
    int n, userChoice;

    std::cout << "==================================================================" << std::endl;
    std::cout << "Добро пожаловать в СУММАТОР.\nЭта программа считает сумму ряда вида 1^n + 2^n + 3^n + ... + n^n." << std::endl;
    std::cout << "==================================================================" << std::endl;

    std::cout << "Введите n: ";
    std::cin >> n;

    // защита от дурака если пользователь ввел не число
    while (std::cin.fail())
    {
        std::cout << "!! Некорректное значение n. Попробуй еще раз !! " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введи n (нормально): ";
        std::cin >> n;
    }
    // вторая защита от дурака если n < 10
    while (n <= 9)
    {
        std::cout << "!! По условию задачи, n должно быть больше или равно 10 !!" << std::endl;
        std::cout << "Введи n (нормально): ";
        std::cin >> n;
    }

    // предупреждение, если пользователь ввел число больше 200
    if (n > 200)
    {
        std::cout << "!! ВНИМАНИЕ: из-за большого числа n время вычисления может затянуться и процесс может нагрузить систему. Программа конечно высчитает, если подождете. Продолжить? (0 - нет, 1 - да) !!" << std::endl;
        std::cin >> userChoice;
        while (std::cin.fail() || userChoice < 0 || userChoice > 1) // защита от дурака
        {
            std::cout << "!! Неверный вариант ответа. Введи еще раз !! " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введи ответ (0 или 1): ";
            std::cin >> userChoice;
        }
        switch (userChoice) { // если пользователь не хочет продолжать, выходим
            case 0: return 0;
        }
    }

    std::string result = Summator(n);
    std::cout << "Сумма ряда 1^" << n << " + 2^" << n << " + 3^" << n << " + ... + " << n << "^" << n << " = " << result << std::endl;
    return 0;
}