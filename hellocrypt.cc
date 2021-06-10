// Tuffy Titan
// CPSC 353-01
// 2021-06-04
// tuffy.titan@csu.fullerton.edu
// @tuffytitan
//
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

  return 0;
}
