# CPSC 353 - Assignment 00

Long, long ago, the standard algorithm for encrypting data was [the Data Encryption Standard](https://en.wikipedia.org/wiki/Data_Encryption_Standard). The algorithm was first published in 1975, endorsed by the US Federal government as their standard data encryption algorithm, and used through out the world as the de-facto algorithm for securing information. For approximately 25 years, DES was the standard however techniques in cryptanalysis and the computational speed of computers improved so much that today (2021) DES is no longer considered a secure.

The DES algorithm was used to encrypt passwords. Most famously, the DES algorithm was implemented in many [Unix](https://en.wikipedia.org/wiki/Unix) operating systems and in the  [POSIX standard](https://en.wikipedia.org/wiki/POSIX) as the  [`crypt()`](https://en.wikipedia.org/wiki/Crypt_(C)) function. For decades, a Unix user's password was encoded from clear text to a cipher text using the `crypt()` function and [12 bits of salt](https://en.wikipedia.org/wiki/Salt_(cryptography)).

Although use of the `crypt()` function is deprecated, we'll use it as a way to explore topics in computer security. To learn more about `crypt()` or any other aspect of the Linux application programming interface (API), you can use the built-in manual using the [`man`](https://en.wikipedia.org/wiki/Man_page) command. For example, try using the command `man 3 crypt` to access the [`crypt()`](http://manpages.ubuntu.com/manpages/focal/en/man3/crypt.3posix.html) documentation from section 3 of the online-manual.

At the top of the `man` page for `crypt()` is the function's prototype and required header file under Synopsis. This shows us how we can use the function.

```
#include <crypt.h>
char * crypt(const char *phrase, const char *setting);
``` 

Next, the Description provides an explanation of how to use the function.
```
  The crypt, crypt_r, crypt_rn, and crypt_ra functions irreversibly “hash”
  phrase for storage in the system password database (shadow(5)) using a
  cryptographic “hashing method.” The result of this operation is called a
  “hashed passphrase” or just a “hash.” Hashing methods are described in
  crypt(5).

  setting controls which hashing method to use, and also supplies various
  parameters to the chosen method, most importantly a random “salt” which
  ensures that no two stored hashes are the same, even if the phrase
  strings are the same.
```

A little more digging through the `man` pages and other places, you'll learn that to use `crypt()` in the traditional fashion, the parameter `setting` should be given [12 bits of salt](https://en.wikipedia.org/wiki/Salt_(cryptography)).

In cryptography, salt is random bits that are used in conjunction with a one way cryptographic hashing function to guard against attacks.

Since we need only 12 bits of salt and the type for `setting` is `const char *`, the way the salt value is specified is by using a two character array (not a string).

For example, to hash the password `secretpassword` with the salt `Aq`, then the way we would call `crypt()` is as follows:

```
char *cipher_text = crypt("secretpassword", "Aq");
```

See the [Example Output](#example-output) for more examples.

# Requirements

Write a program that takes two arguments from the command line. The first argument is the salt expressed as two ASCII characters and the second argument is the secret password or phrase.

Using the `crypt()` function, hash the password with the given salt value and print the results to the terminal following the examples shown in [Example Output](#example-output).

The program must exit gracefully in case of errors.

The assignment has a [GNUmakefile](https://en.wikipedia.org/wiki/Makefile) which you may use to build and test your progress. The GNUmakefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

To build the program use the `make` command. The GNUmakefile's default target is to build `all`. You must use the GNU version of `make` which is the default on Tuffix.

Every file that you submit must have a header. Please follow the guidelines from the course Canvas page.

Please adhere to the [Google C++ coding style](https://google.github.io/styleguide/cppguide.html).

When writing git log comments, please make them descriptive and meaningful.

# Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; g++ -MM -g -Wall -pipe -std=c++14 hellocrypt.cc \
| sed 's/\(hellocrypt\)\.o[ :]*/\1.o hellocrypt.d : /g' > hellocrypt.d; \
[ -s hellocrypt.d ] || rm -f hellocrypt.d
g++ -g -Wall -pipe -std=c++14 -c hellocrypt.cc
g++ -g -Wall -pipe -std=c++14 -o hellocrypt hellocrypt.o -lcrypt
$ ./hellocrypt 
Please provide two arguments.
The first argument is the salt defined as two ASCII characters.
The second argument is a word you'd like to encrypt.
Exiting.
$ ./hellocrypt Aq secretpassword
The cipher text is "AquiLJNDmJ0sg"
$ ./hellocrypt eR secretpassword
The cipher text is "eRzZSZ3xc5GXM"
```


# Rubric

There is a total of 10 points possible. Your program must compile before it is graded. _Submissions that do not compile shall be assigned a zero grade._

For each problem:

* Functionality (6 points): Your submission shall be assessed for the appropriate constructs and strategies to address the exercise. A program the passes the instructor's tests completely receives full marks. A program that partially passes the instructors tests receives partial-marks. A program that fails the majority or all the tests receives no marks. 
* Format & Readability (4 point): Your submission shall be assessed by checking whether your code passess the style and format check, as well as how well it follows the proper naming conventions, and internal documentation guidelines. Git log messages are an integral part of how readable your project is. Failure to include a header forfeits all marks. Failure to not conform to the [Google C++ coding style](https://google.github.io/styleguide/cppguide.html) forfeits all marks.
