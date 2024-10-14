#include <bits/stdc++.h>
using namespace std;

string encrypt(const string& plaintext, const string& keyword) {
    string key = keyword;
    string ciphertext = "";
    for (size_t i = 0, j = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            key += tolower(plaintext[i]);
            char encChar = (tolower(plaintext[i]) - 'a' + tolower(key[j]) - 'a') % 26 + 'A';
            ciphertext += encChar;
            j++;
        }
    }
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& keyword) {
    string plaintext = "";
    string key = keyword;
    for (size_t i = 0, j = 0; i < ciphertext.length(); i++) {
        char decChar = (toupper(ciphertext[i]) - 'A' - (tolower(key[j]) - 'a') + 26) % 26 + 'a';
        plaintext += decChar;
        key += decChar;
        j++;
    }
    return plaintext;
}

int main() {
    freopen("input.txt", "r", stdin);
    string plaintext;
    getline(cin, plaintext);
    string keyword;
    getline(cin, keyword);
    string ciphertext = encrypt(plaintext, keyword);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;
    string decryptedText = decrypt(ciphertext, keyword);
    cout << "Decrypted Plaintext: " << decryptedText << endl;
    return 0;
}
