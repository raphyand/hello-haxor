// Raphael S. Andaya
// CPSC 353-01
// 2021-06-04
// raphyand@csu.fullerton.edu
// @raphyand
// Copyright 2021 raphyand?
// Assignment 00
//
// Demonstrate the traditional use of crypt.
//

#include <cstdlib>
#include <iostream>
#include <string>

#if defined(__linux__)
#include <crypt.h>
#elif defined(__FreeBSD__)
#include <unistd.h>
#elif defined(__APPLE__) && defined(__MACH__)
#include <unistd.h>
#else
#pragma message("Missing header for crypt().")
#endif

#if defined(_WIN32) || defined(_WIN64)
#pragma message("Windoze is not supported.")
#endif

/// Demonstrate the traditional use of
/// [crypt](https://en.wikipedia.org/wiki/Crypt_(C))
/// which implements
/// [DES](https://en.wikipedia.org/wiki/Data_Encryption_Standard).
/// Given a user provided salt and clear text, use crypt and print
/// the cipher text.
int main(int argc, char const* argv[]) {
  if (argc < 3) {
    std::cout << "Two arguments are needed. \n";
  }

  std::string salt = std::string(argv[1]);
  std::string clear_text = std::string(argv[2]);
  char *cipher_text = crypt(clear_text.c_str(), salt.c_str());
  std::cout << "Cipher: " << cipher_text << "\n";

  return 0;
}
