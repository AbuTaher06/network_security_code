#include <bits/stdc++.h>
using namespace std;

// Function to extend the keyword to match the length of the plaintext/ciphertext
string generateKey(string str, string key) {
    int strLen = str.length();
    int keyLen = key.length();
    
    string extendedKey = key;
    
    // Repeat the key until it matches the length of the plaintext
    for (int i = 0; extendedKey.length() < strLen; i++) {
        extendedKey += key[i % keyLen];
    }
    
    return extendedKey;
}

// Function to encrypt the plaintext using Vigenère Cipher
string encrypt(string plaintext, string key) {
    string ciphertext = "";
    
    // Extend the key to match the length of the plaintext
    string extendedKey = generateKey(plaintext, key);
    
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {  // Encrypt only alphabetic characters
            char base = islower(plaintext[i]) ? 'a' : 'A';
            char keyChar = islower(plaintext[i]) ? tolower(extendedKey[i]) : toupper(extendedKey[i]);
            ciphertext += (plaintext[i] - base + (keyChar - base)) % 26 + base;  // Vigenère encryption formula
        } else {
            ciphertext += plaintext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    return ciphertext;
}

// Function to decrypt the ciphertext using Vigenère Cipher
string decrypt(string ciphertext, string key) {
    string plaintext = "";
    
    // Extend the key to match the length of the ciphertext
    string extendedKey = generateKey(ciphertext, key);
    
    for (int i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {  // Decrypt only alphabetic characters
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            char keyChar = islower(ciphertext[i]) ? tolower(extendedKey[i]) : toupper(extendedKey[i]);
            plaintext += (ciphertext[i] - base - (keyChar - base) + 26) % 26 + base;  // Vigenère decryption formula
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
