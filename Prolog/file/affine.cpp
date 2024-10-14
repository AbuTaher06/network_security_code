#include <bits/stdc++.h>
using namespace std;

// gcd function remains the same
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// modInv function remains the same
int modInv(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  // Return -1 if inverse doesn't exist
}

// Encryption function remains the same
string encrypt(string plaintext, int a, int b) {
    string ciphertext = "";
    for (char &c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (a * (c - base) + b) % 26 + 'A';  // Convert to uppercase letters
            ciphertext += c;
        }
    }
    return ciphertext;
}

// Decryption function - modify to use modInv instead of modInverse
string decrypt(string ciphertext, int a, int b, const string& originalText) {
    string plaintext = "";
    int a_inv = modInv(a, 26);  // Use modInv to get the modular inverse of 'a'
    
    if (a_inv == -1) {  // Check if modular inverse doesn't exist
        cout << "Inverse doesn't exist. 'a' must be coprime with 26!" << endl;
        exit(1);
    }

    int j = 0;
    for (char c : originalText) {
        if (isalpha(c)) {
            char base = 'A';
            char dec = (a_inv * ((ciphertext[j] - base) - b + 26)) % 26 + 'a';  // Convert back to lowercase
            plaintext += dec;
            j++;
        } else {
            plaintext += ' ';
        }
    }
    return plaintext;
}

int main() {
    freopen("input.txt", "r", stdin);

    string plaintext;
    getline(cin, plaintext);

    int a, b;
    cin >> a >> b;

    if (gcd(a, 26) != 1) {
        cout << "'a' must be coprime with 26 for a valid affine cipher!" << endl;
        return 1;
    }

    string cipherText = encrypt(plaintext, a, b);
    cout << "Encrypted Ciphertext: " << cipherText << endl;

    string decryptedText = decrypt(cipherText, a, b, plaintext);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
