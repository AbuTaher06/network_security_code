#include <bits/stdc++.h>
using namespace std;

string autoKeyCipherEncrypt(const string &plaintext, const string &key) {
    string ciphertext;
    string extendedKey = key + plaintext; // Extend the key with the plaintext

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char p = plaintext[i];
        char k = extendedKey[i];

        // Only encrypt alphabetic characters
        if (isalpha(p)) {
            char base = isupper(p) ? 'A' : 'a';
            char c = (p - base + (isupper(k) ? k - 'A' : k - 'a')) % 26 + 'A';
            ciphertext += toupper(c);
        }
    }

    return ciphertext;
}

string autoKeyCipherDecrypt(const string &ciphertext, const string &key) {
    string plaintext;
    string extendedKey = key; // Start with the key

    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];
        char k = extendedKey[i];

        // Only decrypt alphabetic characters
        if (isupper(c)) {
            char p = (c - 'A' - (isupper(k) ? k - 'A' : k - 'a') + 26) % 26 + 'A';
            plaintext += p;

            // Update the extended key with the decrypted character
            extendedKey += p;
        }
    }

    return plaintext;
}

int main() {
    string plaintext, key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    getline(cin, key);

    // Remove spaces from plaintext for encryption
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());

    string ciphertext = autoKeyCipherEncrypt(plaintext, key);

    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypting
    string decryptedText = autoKeyCipherDecrypt(ciphertext, key);

    // Add spaces back for the output (for demo purpose, assuming original words)
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
