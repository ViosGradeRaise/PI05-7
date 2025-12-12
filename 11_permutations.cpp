#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permuteHelper(string& str, int left, int right, vector<string>& result) {
    // При достижении конца добавить перестановку в результат
    if (left == right) {
        result.push_back(str);
        return;
    }
    
    // Проверяем каждый символ кроме выбранного
    for (int i = left; i <= right; i++) {
        // Меняем местами выбранный с одним из остальных
        swap(str[left], str[i]);
        
        // С помощью рекурсии переставляем все остальные
        permuteHelper(str, left + 1, right, result);
        
        // Возвращаемся к изначальной строке
        swap(str[left], str[i]);
    }
}

vector<string> permute(string str) {
    vector<string> result;
    permuteHelper(str, 0, str.length() - 1, result);
    return result;
}

int main() {
    string input;
    
    cout << "Введите строку для перестановки: ";
    cin >> input;
    
    vector<string> permutations = permute(input);
    
    cout << "\nВсе перестановки строки \"" << input << "\":\n";
    cout << "Количество перестановок: " << permutations.size() << "\n\n";
    
    for (int i = 0; i < permutations.size(); i++) {
        cout << i + 1 << ". " << permutations[i] << endl;
    }
    
    return 0;
}
