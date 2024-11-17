#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int d = 26;  // Количество символов в алфавите
const int q = 101;  // Простое число для хеширования

vector<int> rabinKarpSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int p = 0; // Хеш подстроки
    int t = 0; // Хеш окна текста
    int h = 1;
    vector<int> result;

    // Вычисляем значение h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Вычисляем начальные хеши подстроки и первого окна текста
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Сканируем текст, начиная с каждого символа
    for (int i = 0; i <= n - m; i++) {
        // Если хеши совпадают, проверяем каждый символ
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                result.push_back(i);
        }

        // Вычисляем хеш следующего окна текста
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Если хеш отрицательный, преобразуем его в положительный
            if (t < 0)
                t += q;
        }
    }

    return result;
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    vector<int> occurrences = rabinKarpSearch(text, pattern);

    if (occurrences.empty()) {
        cout << "Подстрока не найдена" << endl;
    } else {
        cout << "Подстрока найдена на индексах: ";
        for (int idx : occurrences) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
