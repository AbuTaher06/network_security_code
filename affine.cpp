#include <iostream>
#include <string>
using namespace std;

// Function to calculate GCD and find modular inverse using Extended Euclidean Algorithm
int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to find the modular inverse of 'a' modulo 'mod'
int modInverse(int a, int mod) {
    int x, y;
    int g = gcdExtended(a, mod, x, y);
    if (g != 1) {
        cout << "Inverse doesn't exist. 'a' must be coprime with " << mod << "!" << endl;
        exit(1);  // Exit if no inverse exists
    }
    return (x % mod + mod) % mod;  // Ensure the result is positive
}

// Function to encrypt the plaintext using Affine Cipher
string encrypt(string plaintext, int a, int b) {
    string ciphertext = "";
    for (char &c : plaintext) {
        if (isalpha(c)) {  // Encrypt only alphabetic characters
            char base = islower(c) ? 'a' : 'A';  // Handle lowercase and uppercase separately
            c = (a * (c - base) + b) % 26 + base;  // Affine encryption formula
        }
        ciphertext += c;  // Non-alphabetic characters (spaces, punctuation) remain unchanged
    }
    return ciphertext;
}

// Function to decrypt the ciphertext using Affine Cipher
string decrypt(string ciphertext, int a, int b) {
    string plaintext = "";
    int a_inv = modInverse(a, 26);  // Find the modular inverse of 'a'
    for (char &c : ciphertext) {
        if (isalpha(c)) {  // Decrypt only alphabetic characters
            char base = islower(c) ? 'a' : 'A';  // Handle lowercase and uppercase separately
            c = (a_inv * ((c - base) - b + 26)) % 26 + base;  // Affine decryption formula
        }
        plaintext += c;  // Non-alphabetic characters (spaces, punctuation) remain unchanged
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    int a, b;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);  // Read the whole line including spaces

    // Key input: 'a' must be coprime with 26
    cout << "Enter the multiplicative key 'a' (must be coprime with 26): ";
    cin >> a;
    cout << "Enter the additive key 'b': ";
    cin >> b;

    // Encryption
    ciphertext = encrypt(plaintext, a, b);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    // Decryption
    string decryptedText = decrypt(ciphertext, a, b);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
