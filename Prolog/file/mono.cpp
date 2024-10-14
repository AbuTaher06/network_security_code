#include <iostream>
#include <map>
using namespace std;

map<char, char> encMap, decMap;

string encryption_monosub(const string& plainText);
string decryption_monosub(const string& cipherText);

int main() {
    string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ciphertext = "QWERTYUIOPASDFGHJKLZXCVBNM";

    for (size_t i = 0; i < plaintext.size(); i++) {
        encMap[plaintext[i]] = ciphertext[i];
        decMap[ciphertext[i]] = plaintext[i];
    }

    string plainText = "HELLO WORLD";

    string cipherText = encryption_monosub(plainText);
    cout << "The cipherText is: " << cipherText << "\n";

    string decipherText = decryption_monosub(cipherText);
    cout << "The decipherText is: " << decipherText << "\n";

    return 0;
}

string encryption_monosub(const string& plainText) {
    string cipherText = "";

    for (char c : plainText) {
        if (encMap.find(c) != encMap.end())
            cipherText += encMap[c];
        else
            cipherText += c;
    }

    return cipherText;
}

string decryption_monosub(const string& cipherText) {
    string decipherText = "";

    for (char c : cipherText) {
        if (decMap.find(c) != decMap.end())
            decipherText += decMap[c];
        else
            decipherText += c;
    }
    return decipherText;
}
