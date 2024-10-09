#include <iostream>
#include <cmath>

using namespace std;

// Function to compute gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular inverse of e mod phi (extended Euclidean algorithm)
int modInverse(int e, int phi) {
    int t = 0, newT = 1;
    int r = phi, newR = e;

    while (newR != 0) {
        int quotient = r / newR;
        int tempT = t;
        t = newT;
        newT = tempT - quotient * newT;

        int tempR = r;
        r = newR;
        newR = tempR - quotient * newR;
    }

    if (t < 0) {
        t += phi;
    }

    return t;
}

// Function to compute (base^exp) % mod
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide by 2
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    // Given values
    int p = 17;
    int q = 11;
    int plaintext = 88;

    // Step 1: Compute n = p * q
    int n = p * q;

    // Step 2: Compute phi(n) = (p-1) * (q-1)
    int phi = (p - 1) * (q - 1);

    // Step 3: Choose e such that 1 < e < phi and gcd(e, phi) = 1
    int e = 7; // Commonly used public exponent

    // Step 4: Compute d, the modular inverse of e mod phi
    int d = modInverse(e, phi);

    // Step 5: Encrypt the plaintext: C = (M^e) mod n
    int ciphertext = modExp(plaintext, e, n);

    // Step 6: Decrypt the ciphertext: M = (C^d) mod n
    int decryptedText = modExp(ciphertext, d, n);

    // Output the results
    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;
    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

