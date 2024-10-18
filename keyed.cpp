#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Function to encrypt using the transposition key
string encrypt(const string& plaintext, const vector<int>& key) {
    string ciphertext = "";
    int blockSize = key.size();

    // Process text in blocks of the size of the key
    for (size_t i = 0; i < plaintext.length(); i += blockSize) {
        string block = plaintext.substr(i, blockSize);

        // Pad block if it is smaller than block size
        while (block.length() < blockSize) {
            block += 'X';  // Add padding character (e.g., 'X')
        }

        // Reorder block using the permutation key
        for (int k : key) {
            ciphertext += block[k - 1];  // Subtract 1 for zero-indexing
        }
    }

    return ciphertext;
}

// Function to decrypt using the transposition key
string decrypt(const string& ciphertext, const vector<int>& key) {
    string plaintext = "";
    int blockSize = key.size();

    // Process ciphertext in blocks of the size of the key
    for (size_t i = 0; i < ciphertext.length(); i += blockSize) {
        string block = ciphertext.substr(i, blockSize);
        string decryptedBlock(blockSize, ' ');

        // Reverse the permutation for decryption
        for (size_t j = 0; j < key.size(); ++j) {
            decryptedBlock[key[j] - 1] = block[j];  // Subtract 1 for zero-indexing
        }

        plaintext += decryptedBlock;
    }

    return plaintext;
}

// Helper function to parse key input as space-separated integers
vector<int> parseKey(const string& keyStr) {
    vector<int> key;
    stringstream ss(keyStr);
    int num;

    while (ss >> num) {
        key.push_back(num);
    }

    return key;
}

int main() {
    string plaintext, keyStr;

    // Get plaintext input from the user
    cout << "Enter the plaintext (spaces allowed): ";
    getline(cin, plaintext);  // Use getline to allow spaces in plaintext

    // Get key input from the user
    cout << "Enter the key (as space-separated numbers): ";
    getline(cin, keyStr);

    // Parse the key
    vector<int> key = parseKey(keyStr);

    // Encryption
    string ciphertext = encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    // Decryption
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
