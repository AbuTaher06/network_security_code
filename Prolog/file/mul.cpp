#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
// Function to find modular inverse of a under modulo m
int modInv(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  
}

string enc(const string& text, int k) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            result += ((ch - base) * k) % 26 + 'A';  
        }
    }
    return result;
}

// Decryption function
string dec(const string& text, int k, const string& originalText) {
    string result = "";
    int mInverse = modInv(k, 26);  

    for (char ch : originalText) {  
        if (isalpha(ch)) {
            char base = 'A';  
            result += tolower(((text[j] - base) * mInverse) % 26 + 'a');  
            j++;  
        } else {
            result += ' ';  
        }
    }
    return result;
}

int main() {
   
    freopen("input.txt", "r", stdin);  

    string text;
    getline(cin, text);  

    int k;
    
    cout << "Enter the key (must be coprime with 26): ";
    cin >> k;

    // Validate the key
    while (gcd(k, 26) != 1) {
        cout << "Invalid key! The key must be coprime with 26. Please enter a new key: ";
        cin >> k;
    }

    // Encrypt the plaintext
    string cipherText = enc(text, k);
    cout << "The cipherText is: " << cipherText << "\n";

    string decipherText = dec(cipherText, k, text);
    cout << "The decipherText is: " << decipherText << "\n";
    return 0;
}
