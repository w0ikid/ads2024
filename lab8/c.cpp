#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const ll PRIME = 31;

ll getHash(const string& s) {
    ll hash = 0, power = 1;
    for (char ch : s) {
        hash = (hash + (ch - 'a' + 1) * power) % MOD;
        power = (power * PRIME) % MOD;
    }
    return hash;
}

vector<ll> getPrefixHashes(const string& text, const vector<ll>& powers) {
    int n = text.size();
    vector<ll> hashCodes(n);
    ll hash = 0;
    for (int i = 0; i < n; i++) {
        hash = (hash + (text[i] - 'a' + 1) * powers[i]) % MOD;
        hashCodes[i] = hash;
    }
    return hashCodes;
}

void rabinKarp(const string& text, const string& pattern, vector<size_t>& vec, const vector<ll>& prefixHashes, const vector<ll>& powers) {
    int m = pattern.size();
    ll patternHash = getHash(pattern);
    for (int i = 0; i <= text.size() - m; i++) {
        ll currentHash = prefixHashes[i + m - 1];
        if (i > 0) {
            currentHash = (currentHash - prefixHashes[i - 1] + MOD) % MOD;
        }
        if (patternHash * powers[i] % MOD == currentHash) {
            for (int j = i; j < i + m; j++) {
                vec[j]++;
            }
        }
    }
}

int main() {
    string text; cin >> text;
    int n; cin >> n;
    vector<size_t> vec(text.size(), 0);

    // Предварительное вычисление степеней PRIME
    vector<ll> powers(text.size(), 1);
    for (int i = 1; i < text.size(); i++) {
        powers[i] = (powers[i - 1] * PRIME) % MOD;
    }

    // Вычисление префиксных хешей один раз
    vector<ll> prefixHashes = getPrefixHashes(text, powers);

    // Запуск алгоритма для каждого шаблона
    for (int i = 0; i < n; i++) {
        string pattern; cin >> pattern;
        rabinKarp(text, pattern, vec, prefixHashes, powers);
    }

    // Проверка покрытия
    for (size_t covered : vec) {
        if (covered == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
