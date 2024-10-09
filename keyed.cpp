#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to sort the key and keep track of the column positions
vector<int> getKeyOrder(string key) {
    int keyLength = key.length();
    vector<pair<char, int>> keyPos(keyLength);

    // Store each character of the key with its original position
    for (int i = 0; i < keyLength; i++) {
        keyPos[i] = make_pair(key[i], i);
    }

    // Sort the key characters alphabetically while keeping track of original positions
    sort(keyPos.begin(), keyPos.end());

    // Extract the original positions in sorted order
    vector<int> order(keyLength);
    for (int i = 0; i < keyLength; i++) {
        order[i] = keyPos[i].second;
    }

    return order;
}

// Function to encrypt the plaintext using the Keyed Transposition Cipher
string encrypt(string plaintext, string key) {
    int keyLength = key.length();
    int textLength = plaintext.length();

    // Remove spaces from plaintext (optional based on cipher rules)
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());

    // Calculate the number of rows needed for the matrix
    int numRows = (textLength + keyLength - 1) / keyLength;

    // Fill the matrix row by row
    vector<vector<char>> grid(numRows, vector<char>(keyLength, 'X')); // Initialize grid with 'X' for padding

    int index = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < keyLength; col++) {
            if (index < textLength) {
                grid[row][col] = plaintext[index++];
            }
        }
    }

    // Get the column order based on the key
    vector<int> keyOrder = getKeyOrder(key);

    // Read the columns in the new order to create the ciphertext
    string ciphertext = "";
    for (int col : keyOrder) {
        for (int row = 0; row < numRows; row++) {
            ciphertext += grid[row][col];
        }
    }

    return ciphertext;
}

// Function to decrypt the ciphertext using the Keyed Transposition Cipher
string decrypt(string ciphertext, string key) {
    int keyLength = key.length();
    int textLength = ciphertext.length();

    // Calculate the number of rows needed for the matrix
    int numRows = (textLength + keyLength - 1) / keyLength;

    // Fill the matrix column by column based on the key order
    vector<vector<char>> grid(numRows, vector<char>(keyLength, 'X')); // Initialize grid with 'X' for padding

    vector<int> keyOrder = getKeyOrder(key);

    int index = 0;
    for (int colIndex = 0; colIndex < keyLength; colIndex++) {
        int col = keyOrder[colIndex];
        for (int row = 0; row < numRows; row++) {
            if (index < textLength) {
                grid[row][col] = ciphertext[index++];
            }
        }
    }

    // Read the matrix row by row to retrieve the plaintext
    string plaintext = "";
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < keyLength; col++) {
            plaintext += grid[row][col];
        }
    }

    // Remove any trailing 'X' padding
    while (!plaintext.empty() && plaintext.back() == 'X') {
        plaintext.pop_back();
    }

    return plaintext;
}

int main() {
    string plaintext, key;

    // Input plaintext and key
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    cout << "Enter the key: ";
    cin >> key;

    // Encryption
    string ciphertext = encrypt(plaintext, key);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    // Decryption
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
