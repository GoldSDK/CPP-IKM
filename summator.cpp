#include <iostream>
#include "files/taskmanager.h"
int main() {
    int n;

    std::cout << "==================================================================" << std::endl;
    std::cout << "Добро пожаловать в СУММАТОР.\nЭта программа считает сумму ряда вида 1^n + 2^n + 3^n + ... + n^n." << std::endl;
    std::cout << "==================================================================" << std::endl;

    std::cout << "Введите n: ";
    std::cin >> n;

    std::string result = Summator(n);
    std::cout << "Сумма ряда 1^" << n << " + 2^" << n << " + 3^" << n << " + ... + " << n << "^" << n << " = " << result << std::endl;
    return 0;
}