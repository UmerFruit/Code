#include <iostream>
#include <string>

std::string decrypt(const std::string& ciphertext, int key) {
    std::string decrypted_text = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            decrypted_text += static_cast<char>((c - base - key + 26) % 26 + base);
        } else {
            decrypted_text += c;
        }
    }
    return decrypted_text;
}

void bruteForceSubstitution(const std::string& ciphertext) {
    for (int key = 1; key <= 26; ++key) {
        std::string decrypted_text = decrypt(ciphertext, key);
        std::cout << "Key " << key << ": " << decrypted_text << std::endl;
    }
}

int main() {
    std::string ciphertext = "YOUR_ENCRYPTED_TEXT_HERE";
    bruteForceSubstitution(ciphertext);
    return 0;
}
