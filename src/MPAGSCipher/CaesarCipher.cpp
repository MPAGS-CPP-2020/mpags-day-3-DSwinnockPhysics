// Standard Library includes
#include <iostream>
#include <string>

// Our project headers
#include "CaesarCipher.hpp"


CaesarCipher::CaesarCipher(const size_t& cipher_key)
: cipher_key_{cipher_key}, alphabet_{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}

{}

CaesarCipher::CaesarCipher(const std::string& cipher_key)
: cipher_key_{0}, alphabet_{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}
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
      return;
      }
    }

    cipher_key_ = std::stoul(cipher_key);
  }
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const bool& encrypt) const
{
  // Create the output string
  std::string outputText {};

  // Create the alphabet container
  //const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const size_t alphabetSize = alphabet_.size();

  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { cipher_key_ % alphabetSize };

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize; ++i ) {

      if ( origChar == alphabet_[i] ) {

	// Apply the appropriate shift (depending on whether we're encrypting
	// or decrypting) and determine the new character
	// Can then break out of the loop over the alphabet
	if ( encrypt ) {
	  processedChar = alphabet_[ (i + truncatedKey) % alphabetSize ];
	} else {
	  processedChar = alphabet_[ (i + alphabetSize - truncatedKey) % alphabetSize ];
	}
	break;
      }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}