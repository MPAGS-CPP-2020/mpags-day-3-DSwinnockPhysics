#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
    public:
     explicit CaesarCipher(const size_t& cipher_key);
     explicit CaesarCipher(const std::string& cipher_key);

     size_t cipher_key_;
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP 