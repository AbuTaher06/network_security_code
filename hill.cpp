#include <bits/stdc++.h>
using namespace std;

// Convert char to integer value (A=0, B=1, ..., Z=25)
int charToInt(char c) {
    return toupper(c) - 'A';
}

// Convert integer value to char (0=A, 1=B, ..., 25=Z)
char intToChar(int num) {
    return char(num % 26 + 'A');
}

// Find the modular inverse of a number modulo 26
int modInverse(int a, int mod) {
    int t = 0, newT = 1, r = mod, newR = a;
    while (newR != 0) {
        int quotient = r / newR;
        tie(t, newT) = make_pair(newT, t - quotient * newT);
        tie(r, newR) = make_pair(newR, r - quotient * newR);
    }
    if (r > 1) throw invalid_argument("Matrix is not invertible");
    return (t < 0) ? t + mod : t;
}

// Calculate the determinant of a 2x2 matrix mod 26
int determinant(const vector<vector<int>>& matrix, int mod) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % mod;
}

// Find the inverse of a 2x2 matrix mod 26
vector<vector<int>> inverseMatrix(const vector<vector<int>>& matrix, int mod) {
    int det = determinant(matrix, mod), invDet = modInverse(det, mod);
    return {
        {(matrix[1][1] * invDet) % mod, (-matrix[0][1] * invDet + mod) % mod},
        {(-matrix[1][0] * invDet + mod) % mod, (matrix[0][0] * invDet) % mod}
    };
}

// Multiply 2x2 and 2x1 matrices mod 26
vector<int> multiplyMatrix(const vector<vector<int>>& matrix, const vector<int>& vec, int mod) {
    return {
        (matrix[0][0] * vec[0] + matrix[0][1] * vec[1]) % mod,
        (matrix[1][0] * vec[0] + matrix[1][1] * vec[1]) % mod
    };
}

// Hill Cipher encryption for 2x2 matrix
string encrypt(string plaintext, const vector<vector<int>>& keyMatrix) {
    string ciphertext = "";
    int mod = 26;
    if (plaintext.length() % 2 != 0) plaintext += 'X'; // Pad if odd length

    for (size_t i = 0; i < plaintext.length(); i += 2) {
        vector<int> ptMatrix = { charToInt(plaintext[i]), charToInt(plaintext[i + 1]) };
        vector<int> encryptedMatrix = multiplyMatrix(keyMatrix, ptMatrix, mod);
        ciphertext += intToChar(encryptedMatrix[0]);
        ciphertext += intToChar(encryptedMatrix[1]);
    }
    return ciphertext;
}

// Hill Cipher decryption for 2x2 matrix
string decrypt(string ciphertext, const vector<vector<int>>& keyMatrix) {
    string plaintext = "";
    vector<vector<int>> invKeyMatrix = inverseMatrix(keyMatrix, 26);

    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        vector<int> ctMatrix = { charToInt(ciphertext[i]), charToInt(ciphertext[i + 1]) };
        vector<int> decryptedMatrix = multiplyMatrix(invKeyMatrix, ctMatrix, 26);
        plaintext += intToChar(decryptedMatrix[0]);
        plaintext += intToChar(decryptedMatrix[1]);
    }
    return plaintext;
}

int main() {
    vector<vector<int>> keyMatrix(2, vector<int>(2));
    string plaintext;

    // Input key matrix
    cout << "Enter the 2x2 key matrix (4 numbers from 0-25): \n";
    for (auto& row : keyMatrix)
        for (auto& elem : row)
            cin >> elem;

    // Input plaintext
    cout << "Enter the plaintext: ";
    cin.ignore();
    getline(cin, plaintext);

    // Encryption
    string ciphertext = encrypt(plaintext, keyMatrix);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    // Decryption
    string decryptedText = decrypt(ciphertext, keyMatrix);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
