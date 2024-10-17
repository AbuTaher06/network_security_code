#include <bits/stdc++.h>
using namespace std;

// Function to extend the keyword to match the length of the plaintext/ciphertext
string generateKey(string str, string key) {
    int strLen = str.length();
    int keyLen = key.length();
    string extendedKey = "";
    int j = 0;  // Index for the key

    // Extend the key to match only the alphabetic characters of the plaintext
    for (int i = 0; i < strLen; i++) {
        if (isalpha(str[i])) {
            extendedKey += key[j % keyLen];  // Add key character
            j++;  // Move to the next character in the key
        }
    }

    return extendedKey;
}

// Function to encrypt the plaintext using Vigenère Cipher
string encrypt(string plaintext, string key) {
    string ciphertext = "";
    string extendedKey = generateKey(plaintext, key);

    // Encrypt the plaintext
    for (int i = 0, k = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            char keyChar = islower(plaintext[i]) ? tolower(extendedKey[k]) : toupper(extendedKey[k]);
            ciphertext += toupper((plaintext[i] - base + (keyChar - base)) % 26 + base);  // Vigenère encryption formula
            k++;  // Move to the next character in the extended key
        }
    }
    return ciphertext;
}

// Function to decrypt the ciphertext using Vigenère Cipher
string decrypt(string ciphertext, string key) {
    string plaintext = "";
    string extendedKey = generateKey(ciphertext, key);

    // Decrypt the ciphertext
    for (int i = 0, k = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            char keyChar = islower(ciphertext[i]) ? tolower(extendedKey[k]) : toupper(extendedKey[k]);
            plaintext += (ciphertext[i] - 'A' - (keyChar - 'A') + 26) % 26 + 'A';  // Vigenère decryption formula
            k++;  // Move to the next character in the extended key
        } else {
            plaintext += ciphertext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext, key;

    // Input plaintext and key
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);  // Read the whole line including spaces

    cout << "Enter the key: ";
    getline(cin, key);

    // Encryption
    ciphertext = encrypt(plaintext, key);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    // Decryption
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
