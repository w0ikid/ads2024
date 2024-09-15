#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> reverseProcess(int n) {
    deque<int> dq;

    // Начинаем с последней карты и выполняем шаги в обратном порядке
    for (int i = n; i >= 1; --i) {
        // Кладём карту с номером i в начало
        dq.push_front(i);

        // Перемещаем последние i-1 карт в конец колоды
        for (int j = 0; j < i - 1; ++j) {
            dq.push_front(dq.back());  // Перемещаем последнюю карту в начало
            dq.pop_back();             // Удаляем её с конца
        }
    }

    // Преобразуем deque в вектор для вывода
    vector<int> result(dq.begin(), dq.end());
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> result = reverseProcess(n);

    // Выводим результат
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
