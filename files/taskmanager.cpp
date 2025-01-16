#include <iostream>
#include <string>

// пишу свой reverse чтобы не использовать std::reverse();
std::string reverse(const std::string& str) {
    std::string reversed;
    for (int i = str.size() - 1; i >= 0; i--) {
        reversed.push_back(str[i]);
    }
    return reversed;
}

// функция умножает число в виде строки на число
std::string multiply(const std::string& num, int multi) {
    std::string result;
    int shift = 0; // для переноса (если произведение больше 10)
    int n = num.size();

    for (int i = n - 1; i >= 0; i--) {
        int res = (num[i] - '0') * multi + shift; // умножаем цифру на множитель и добавляем перенос
        result.push_back((res % 10) + '0'); // запихиваем последнюю цифру произведения в результат
        shift = res / 10;
    }

    // пока (если) перенос есть, добавляем в результат
    while (shift) {
        result.push_back((shift % 10) + '0');
        shift /= 10;
    }

    return reverse(result);
}

// пишу свой pow чтобы не использовать std::pow()
std::string pow(int base, int exp) {
    std::string result = "1";
    for (int i = 0; i < exp; i++) {
        result = multiply(result, base);
    }
    return result;
}

//функция складывает числа, которые в виде строки
std::string add(const std::string& a, const std::string& b) {
    std::string result;
    int shift = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    // пока есть цифры в a, b или перенос
    while (i >= 0 || j >= 0 || shift) { 
        int sum = shift;
        if (i >= 0) {
            sum += a[i--] - '0'; // если есть цифра в a добавляем цифру из a и уменьшаем индекс
        }
        if (j >= 0) {
            sum += b[j--] - '0'; // если есть цифра в b добавляем цифру из b и уменьшаем индекс
        }
        result.push_back((sum % 10) + '0'); // добавляем последнюю цифру суммы в результат
        shift = sum / 10;
    }

    return reverse(result);
}

// сам сумматор
std::string Summator(int n) {
    std::string totalSum = "0";
    for (int i = 1; i <= n; i++) {
        totalSum = add(totalSum, pow(i, n)); // добавляем к общей сумме i^n
    }
    return totalSum;
}
