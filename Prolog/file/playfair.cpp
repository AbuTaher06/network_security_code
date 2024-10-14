#include<bits/stdc++.h>
using namespace std;

char playfairMatrix[5][5];

// Function to create the Playfair cipher matrix using a key
void createMatrix(string key) {
    string matrixKey = "";
    bool letterPresent[26] = {false};
    letterPresent['J' - 'A'] = true;  // Treat 'I' and 'J' as the same letter


    // Remove duplicate letters from the key
    for (char c : key) {
        if (!letterPresent[toupper(c) - 'A']) {
            matrixKey += toupper(c);
            letterPresent[toupper(c) - 'A'] = true;
        }
    }

    // Fill the matrix with the key and remaining letters
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (!letterPresent[c - 'A']) matrixKey += c;
    }

    // Populate the Playfair matrix
    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            playfairMatrix[i][j] = matrixKey[k++];
}

// Function to format the plaintext for the Playfair cipher
string formatPlaintext(string plaintext) {
    string formattedText = "";
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());

    for (size_t i = 0; i < plaintext.length(); i++) {
        formattedText += toupper(plaintext[i]);
        if (i < plaintext.length() - 1 && plaintext[i] == plaintext[i + 1]) 
            formattedText += 'X';  // Insert 'X' between repeated letters
    }

    if (formattedText.length() % 2 != 0) formattedText += 'X';  // Pad if the length is odd

    return formattedText;
}

// Function to find the position of a letter in the Playfair matrix
pair<int, int> findPosition(char c) {
    if (c == 'J') c = 'I';  // Treat 'I' and 'J' as the same letter
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (playfairMatrix[i][j] == c) return {i, j};
    return {-1, -1};
}

// Function to encrypt a pair of letters using the Playfair cipher
string encryptPair(char a, char b) {
    auto [rowA, colA] = findPosition(a);
    auto [rowB, colB] = findPosition(b);

    if (rowA == rowB) 
        return string(1, playfairMatrix[rowA][(colA + 1) % 5]) +
               string(1, playfairMatrix[rowB][(colB + 1) % 5]);
    else if (colA == colB)
        return string(1, playfairMatrix[(rowA + 1) % 5][colA]) +
               string(1, playfairMatrix[(rowB + 1) % 5][colB]);
    else
        return string(1, playfairMatrix[rowA][colB]) +
               string(1, playfairMatrix[rowB][colA]);
}

// Function to encrypt a plaintext using the Playfair cipher
string encrypt(string plaintext, string key) {
    createMatrix(key);
    string formattedText = formatPlaintext(plaintext);
    string ciphertext = "";

    for (size_t i = 0; i < formattedText.length(); i += 2) {
        ciphertext += encryptPair(formattedText[i], formattedText[i + 1]);
    }

    return ciphertext;
}

int main() {
    string plaintext, key;

    // Input plaintext
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Input key
    cout << "Enter the key: ";
    getline(cin, key);

    // Encrypt the plaintext using the Playfair cipher
    string ciphertext = encrypt(plaintext, key);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    return 0;
}
