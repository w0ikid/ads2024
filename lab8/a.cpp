#include <iostream>
#include <string>
#include <map>
#include <vector>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const ll PRIME = 11;

string tohash(string s){
    ll hash = 0;
    ll power = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash = (hash + (s[i] - 47) * power) % MOD;
        power = (power * PRIME) % MOD;
    }
    return to_string(hash);
}

int main(){
    int n;
    cin>>n;
    vector <string> hashes;
    map <string, bool> hashCodes;


    string somehashe;
    for (size_t i = 0; i < 2*n; i++)
    {   
        cin >> somehashe;
        hashes.push_back(somehashe);
        hashCodes[somehashe] = true;
    }

    int k = 0;
    for (size_t i = 0; i < 2*n; i++)
    {
        if (n == k) {
            break;
        }
        string hash = tohash(hashes[i]);
        if (hashCodes[hash] == true){
            cout << "Hash of string " << '"' << hashes[i] << '"' <<  " is " << hash << endl;
            k++;
        }
    }
    
    return 0;
}