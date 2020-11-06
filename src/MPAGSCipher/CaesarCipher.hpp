#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>

#include "CipherMode.hpp"

class CaesarCipher {
    public:
     explicit CaesarCipher(const size_t& cipher_key);
     explicit CaesarCipher(const std::string& cipher_key);
     std::string applyCipher(const std::string& inputText, const CipherMode& encrypt) const;

    private:
     size_t cipher_key_;
     std::vector<char> alphabet_;
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP 