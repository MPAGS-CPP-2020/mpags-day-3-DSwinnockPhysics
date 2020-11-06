#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
    public:
    CaesarCipher(const size_t cipher_key);
    size_t cipher_key_ {0};
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP 