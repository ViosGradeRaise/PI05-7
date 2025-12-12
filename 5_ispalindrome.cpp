#include <iostream>
#include <string>

bool isPalindrome(const std::string& s, int start, int end) {
    // Если start >= end, все элементы проверены (длина <= 1)
    if (start >= end) {
        return true;
    }
    // Сверяем первый и последний символы
    if (s[start] != s[end]) {
        return false;
    }
    // рекурсия без первого и последнего символов
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    std::string test1 = "racecar";
    std::string test2 = "hello";

    std::cout << test1 << " палиндром? " << (isPalindrome(test1, 0, test1.length() - 1) ? "Да" : "Нет") << std::endl;
    std::cout << test2 << " палиндром? " << (isPalindrome(test2, 0, test2.length() - 1) ? "Да" : "Нет") << std::endl;

    return 0;
}
