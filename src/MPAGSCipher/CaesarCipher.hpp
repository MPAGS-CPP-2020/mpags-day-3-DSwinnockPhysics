#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
    public:
    explicit CaesarCipher(const size_t cipher_key);
    explicit CaesarCipher(std::string cipher_key);

    size_t cipher_key_ {0};
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP 