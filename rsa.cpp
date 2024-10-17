#include <iostream>
#include <cmath>

using namespace std;

// Function to compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to find the modular inverse
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1;
}

// Function to compute modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to encrypt a message
long long encrypt(int message, int e, int n) {
    return modExp(message, e, n);
}

// Function to decrypt a message
long long decrypt(long long encryptedMessage, int d, int n) {
    return modExp(encryptedMessage, d, n);
}

int main() {
    // Step 1: User inputs prime numbers p, q and e
    int p, q, e;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;

    // Step 2: Compute n and Euler's Totient Function (phi)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Step 3: Input and validate e (public key exponent)
    cout << "Enter public key exponent e (should be coprime with phi): ";
    cin >> e;
    while (gcd(e, phi) != 1) {
        cout << "e is not coprime with phi. Enter a valid e: ";
        cin >> e;
    }

    // Step 4: Compute d (private key exponent)
    int d = modInverse(e, phi);

    // Output the values of n, phi, d, public key, and private key
    cout << "\nCalculated Values:" << endl;
    cout << "n (p * q) = " << n << endl;
    cout << "phi (Euler's Totient) = " << phi << endl;
    cout << "d (private key exponent) = " << d << endl;
    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;

    // Step 5: Encryption
    int message;
    cout << "\nEnter a message to encrypt (as an integer): ";
    cin >> message;
    long long encryptedMessage = encrypt(message, e, n);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    // Step 6: Decryption
    long long decryptedMessage = decrypt(encryptedMessage, d, n);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
