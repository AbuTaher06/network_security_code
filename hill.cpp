#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// Function to convert a character to its corresponding integer value
int charToInt(char c) {
    return toupper(c) - 'A';
}

// Function to convert an integer to its corresponding character
char intToChar(int num) {
    return (char)(num + 'A');
}

// Function to find the modular inverse of a number modulo 26
int modInverse(int a, int m) {
    int t = 0, newT = 1;
    int r = m, newR = a;
    
    while (newR != 0) {
        int quotient = r / newR;
        int tempT = t;
        t = newT;
        newT = tempT - quotient * newT;
        
        int tempR = r;
        r = newR;
        newR = tempR - quotient * newR;
    }
    
    if (r > 1) {
        throw invalid_argument("The matrix is not invertible");
    }
    
    if (t < 0) {
        t = t + m;
    }
    
    return t;
}

// Function to calculate the determinant of a 2x2 matrix
int determinant(vector<vector<int>>& matrix, int mod) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % mod;
}

// Function to find the inverse of a 2x2 matrix modulo 26
vector<vector<int>> inverseMatrix(vector<vector<int>>& matrix, int mod) {
    int det = determinant(matrix, mod);
    int invDet = modInverse(det, mod);
    
    // Inverse of a 2x2 matrix:
    // [a b]     1/det * [ d -b ]
    // [c d]   =          [-c  a]
    
    vector<vector<int>> inverseMatrix(2, vector<int>(2));
    
    inverseMatrix[0][0] = (matrix[1][1] * invDet) % mod;
    inverseMatrix[0][1] = (-matrix[0][1] * invDet + mod) % mod;
    inverseMatrix[1][0] = (-matrix[1][0] * invDet + mod) % mod;
    inverseMatrix[1][1] = (matrix[0][0] * invDet) % mod;
    
    return inverseMatrix;
}

// Function to multiply two matrices modulo 26
vector<vector<int>> multiplyMatrices(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int mod) {
    vector<vector<int>> result(2, vector<int>(2));
    
    result[0][0] = (matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0]) % mod;
    result[0][1] = (matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1]) % mod;
    result[1][0] = (matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0]) % mod;
    result[1][1] = (matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1]) % mod;
    
    return result;
}

// Function to encrypt plaintext using Hill Cipher with 2x2 matrix
string encrypt(string plaintext, vector<vector<int>>& keyMatrix) {
    string ciphertext = "";
    int mod = 26;
    
    // Ensure the plaintext is even in length, padding if necessary
    if (plaintext.length() % 2 != 0) {
        plaintext += 'X';  // Padding with 'X'
    }
    
    for (size_t i = 0; i < plaintext.length(); i += 2) {
        vector<vector<int>> ptMatrix(2, vector<int>(1));
        ptMatrix[0][0] = charToInt(plaintext[i]);
        ptMatrix[1][0] = charToInt(plaintext[i + 1]);
        
        // Encrypt by multiplying the key matrix with the plaintext matrix
        vector<vector<int>> encryptedMatrix = multiplyMatrices(keyMatrix, ptMatrix, mod);
        
        // Convert encrypted matrix back to ciphertext
        ciphertext += intToChar(encryptedMatrix[0][0]);
        ciphertext += intToChar(encryptedMatrix[1][0]);
    }
    
    return ciphertext;
}

// Function to decrypt ciphertext using Hill Cipher with 2x2 matrix
string decrypt(string ciphertext, vector<vector<int>>& keyMatrix) {
    string plaintext = "";
    int mod = 26;
    
    // Find the inverse of the key matrix
    vector<vector<int>> invKeyMatrix = inverseMatrix(keyMatrix, mod);
    
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        vector<vector<int>> ctMatrix(2, vector<int>(1));
        ctMatrix[0][0] = charToInt(ciphertext[i]);
        ctMatrix[1][0] = charToInt(ciphertext[i + 1]);
        
        // Decrypt by multiplying the inverse key matrix with the ciphertext matrix
        vector<vector<int>> decryptedMatrix = multiplyMatrices(invKeyMatrix, ctMatrix, mod);
        
        // Convert decrypted matrix back to plaintext
        plaintext += intToChar(decryptedMatrix[0][0]);
        plaintext += intToChar(decryptedMatrix[1][0]);
    }
    
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    
    // Input key matrix (2x2 matrix)
    vector<vector<int>> keyMatrix(2, vector<int>(2));
    cout << "Enter the 2x2 key matrix (4 numbers from 0-25): " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> keyMatrix[i][j];
        }
    }
    
    // Input plaintext
    cout << "Enter the plaintext: ";
    cin.ignore();  // To ignore the newline character after entering the key matrix
    getline(cin, plaintext);
    
    // Encryption
    ciphertext = encrypt(plaintext, keyMatrix);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;
    
    // Decryption
    string decryptedText = decrypt(ciphertext, keyMatrix);
    cout << "Decrypted Plaintext: " << decryptedText << endl;
    
    return 0;
}
