#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> createMap(const string& from, const string& to) {
    unordered_map<char, char> m;
    for (size_t i = 0; i < from.size(); i++) {
        m[from[i]] = to[i];
    }
    return m;
}

string processText(const string& text, const unordered_map<char, char>& mapping) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            result += mapping.at(c);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string plaintext, ciphertext;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    auto encryptionMap = createMap(alphabet, cipher);
    ciphertext = processText(plaintext, encryptionMap);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    auto decryptionMap = createMap(cipher, alphabet);
    string decryptedText = processText(ciphertext, decryptionMap);
    transform(decryptedText.begin(),decryptedText.end(),decryptedText.begin(),::tolower);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
