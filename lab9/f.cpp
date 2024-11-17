#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_func(string text, string pat) {
    string s = pat + "#" + text;
    vector<int> pref(s.size());

    for (int i = 1; i < s.size(); i++) {
        int k = pref[i - 1];
        while (k > 0 && s[i] != s[k]) {
            k = pref[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        pref[i] = k;
    }

    return pref;
}

pair<vector<int>, int> kmp(vector<int> pref, int pat_size) {
    vector<int> v;
    int count = 0;
    for (int i = 0; i < pref.size(); i++) {
        if (pref[i] == pat_size) {
            v.push_back(i - 2 * pat_size);
            count++;  // Увеличиваем количество совпадений
        }
    }
    return {v, count};
}

int main() {   
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> v = prefix_func(s1, s2);
    auto [found, count] = kmp(v, s2.size());// Используем pair для возврата сразу двух значений
    cout << count << endl;
    for (int i = 0; i < found.size(); i++) {
        cout << found[i] + 1 << " ";  // Выводим индексы
    }
    cout << "\n";
    return 0;
}
