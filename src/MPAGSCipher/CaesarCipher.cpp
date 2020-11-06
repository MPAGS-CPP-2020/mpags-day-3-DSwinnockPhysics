// Standard Library includes
#include <iostream>
#include <string>

// Our project headers
#include "CaesarCipher.hpp"


CaesarCipher::CaesarCipher(size_t cipher_key)
: cipher_key_{cipher_key}
{};

CaesarCipher::CaesarCipher(std::string cipher_key)
: cipher_key_{0}
  // We have the key as a string, but the Caesar cipher needs an unsigned long, so we first need to convert it
  // We default to having a key of 0, i.e. no encryption, if no key was provided on the command line
{
    if ( ! cipher_key.empty() ) {
    // Before doing the conversion we should check that the string contains a
    // valid positive integer.
    // Here we do that by looping through each character and checking that it
    // is a digit. What is rather hard to check is whether the number is too
    // large to be represented by an unsigned long, so we've omitted that for
    // the time being.
    // (Since the conversion function std::stoul will throw an exception if the
    // string does not represent a valid unsigned long, we could check for and
    // handled that instead but we only cover exceptions very briefly on the
    // final day of this course - they are a very complex area of C++ that
    // could take an entire course on their own!)
    for ( const auto& elem : cipher_key ) {
      if ( ! std::isdigit(elem) ) {
	  std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
	            << "        the supplied key (" << cipher_key << ") could not be successfully converted" << std::endl;
	  }
    }
    cipher_key_ = std::stoul(cipher_key);
  }
};