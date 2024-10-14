#include<bits/stdc++.h>
using namespace std;
string enc(const string& text, int k) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            result += toupper(((ch - base + k) % 26 + base));  // Convert to uppercase after encryption
        }
    }
    return result;
}
string dec(const string& text, int k, const string& originalText) {
    string result = "";
    int j = 0;  // To track ciphertext letters
    for (char ch : originalText) {  // Loop through the original plaintext to preserve spaces
        if (isalpha(ch)) {
            char base = isupper(text[j]) ? 'A' : 'a';
            result += tolower(((text[j] - base - k + 26) % 26 + base));  // Decrypt the character
            j++;  // Move to the next ciphertext letter
        } else {
            result += ' ';  // Add space where it originally appeared
        }
    }
    return result;
}
int main() {
    freopen("input.txt", "r", stdin);  // Open file "input.txt" for reading
    string text;
    getline(cin, text);  
    int k;
    cin >> k;  
    // Encrypt the plaintext
    string cipherText = enc(text, k);
    cout << "The cipherText is: " << cipherText << "\n";
    // Decrypt the ciphertext while preserving spaces
    string decipherText = dec(cipherText, k, text);
    cout << "The decipherText is: " << decipherText << "\n";
    return 0;
}
