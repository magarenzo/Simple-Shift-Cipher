#include <iostream>
#include <sstream>

using namespace std;

// Determine the ordinal value of c
unsigned int ordinal(const char c) {
    return c - 97;
}

// Determine character representation of c
char character(const unsigned int c) {
    return (char) (c + 97);
}

// for all chars in the cipher, one char at a time,
// get its ordinal value, add the shift to it modulus 26,
// turn it back into a char, and append it to plaintext
string decrypt(const string ciphertext, const unsigned int shift) {
	stringstream plaintext;
	unsigned int ord;
	char ch;
    for (unsigned int i = 0; i < ciphertext.length(); i++) {
        ord = ordinal(ciphertext[i]);
        ord = (ord + shift) % 26;
        ch = character(ord);
        plaintext << ch;
    }    
	return plaintext.str();
}

// pass cipher and shift into decrypt(),
// print returned string
int main() {    
    string plain;
    string cipher = "ycvejqwvhqtdtwvwu";
    for (unsigned int i = 1; i <= 25; i++) {
        plain = decrypt(cipher, i);
        cout << plain + "\n";
    }	
	return 0;
}