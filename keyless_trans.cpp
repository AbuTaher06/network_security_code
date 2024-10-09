#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to encrypt the plaintext using Rail Fence Cipher
string encryptRailFence(string text, int numRails) {
    if (numRails <= 1) {
        return text;  // If only one rail, encryption is the original text
    }

    string cipherText = "";
    int len = text.length();

    // Create an array to store characters in each rail
    vector<string> rails(numRails);

    int direction = 1; // 1 means moving down, -1 means moving up
    int row = 0; // Start at the top rail

    // Traverse the plaintext and place characters in the appropriate rail
    for (int i = 0; i < len; i++) {
        rails[row] += text[i];

        // Change direction at the top or bottom rail
        if (row == 0) {
            direction = 1;  // Start moving down
        } else if (row == numRails - 1) {
            direction = -1; // Start moving up
        }

        // Move to the next row
        row += direction;
    }

    // Read the rails row by row to generate the ciphertext
    for (int i = 0; i < numRails; i++) {
        cipherText += rails[i];
    }

    return cipherText;
}

// Function to decrypt the ciphertext using Rail Fence Cipher
string decryptRailFence(string cipherText, int numRails) {
    if (numRails <= 1) {
        return cipherText;  // If only one rail, decryption is the original text
    }

    int len = cipherText.length();
    string plainText(len, ' '); // To store decrypted text

    // Create an array to mark positions for characters
    vector<vector<bool>> railPattern(numRails, vector<bool>(len, false));

    int direction = 1; // 1 means moving down, -1 means moving up
    int row = 0; // Start at the top rail

    // Mark the pattern on the rails where characters will go
    for (int i = 0; i < len; i++) {
        railPattern[row][i] = true;

        if (row == 0) {
            direction = 1;
        } else if (row == numRails - 1) {
            direction = -1;
        }

        row += direction;
    }

    // Now place the ciphertext characters in the correct positions
    int index = 0;
    for (int r = 0; r < numRails; r++) {
        for (int i = 0; i < len; i++) {
            if (railPattern[r][i] && index < len) {
                plainText[i] = cipherText[index++];
            }
        }
    }

    return plainText;
}

int main() {
    string text;
    int numRails;

    // Input plaintext and number of rails
    cout << "Enter the plaintext: ";
    getline(cin, text);
    cout << "Enter the number of rails: ";
    cin >> numRails;

    // Encrypt the text
    string cipherText = encryptRailFence(text, numRails);
    cout << "Encrypted Ciphertext: " << cipherText << endl;

    // Decrypt the text
    string decryptedText = decryptRailFence(cipherText, numRails);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
