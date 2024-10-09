#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to create a mapping for encryption using the substitution table
unordered_map<char, char> createEncryptionMap() {
    string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ciphertext = "QWERTYUIOPASDFGHJKLZXCVBNM";
    unordered_map<char, char> encryptionMap;

    for (int i = 0; i < plaintext.length(); i++) {
        encryptionMap[plaintext[i]] = ciphertext[i];
    }

    return encryptionMap;
}

// Function to create a mapping for decryption using the substitution table
unordered_map<char, char> createDecryptionMap() {
    string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ciphertext = "QWERTYUIOPASDFGHJKLZXCVBNM";
    unordered_map<char, char> decryptionMap;

    for (int i = 0; i < ciphertext.length(); i++) {
        decryptionMap[ciphertext[i]] = plaintext[i];
    }

    return decryptionMap;
}

// Function to encrypt the plaintext using the monoalphabetic cipher
string encrypt(string plaintext) {
    unordered_map<char, char> encryptionMap = createEncryptionMap();
    string ciphertext = "";

    for (char c : plaintext) {
        if (isalpha(c)) {
            c = toupper(c); // Convert to uppercase for uniformity
            ciphertext += encryptionMap[c]; // Encrypt the character
        } else {
            ciphertext += c; // Preserve spaces and other non-alphabet characters
        }
    }

    return ciphertext;
}

// Function to decrypt the ciphertext using the monoalphabetic cipher
string decrypt(string ciphertext) {
    unordered_map<char, char> decryptionMap = createDecryptionMap();
    string plaintext = "";

    for (char c : ciphertext) {
        if (isalpha(c)) {
            c = toupper(c); // Convert to uppercase for uniformity
            plaintext += decryptionMap[c]; // Decrypt the character
        } else {
            plaintext += c; // Preserve spaces and other non-alphabet characters
        }
    }

    return plaintext;
}

int main() {
    string plaintext, ciphertext, decryptedText;
    
    // Input plaintext
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    
    // Encryption
    ciphertext = encrypt(plaintext);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;
    
    // Decryption
    decryptedText = decrypt(ciphertext);
    cout << "Decrypted Plaintext: " << decryptedText << endl;
    
    return 0;
}
