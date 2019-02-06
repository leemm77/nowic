/****************************************************************************
 * Nowic Library 1.0 - C++ Library for Data Structures and Algorithms
 *
 * Youngsup Kim <idebtor@gmail.com>
 * Compilation:
 * > g++ -c nowic.cpp -o nowic.o -I../include
 * > ar rcs libnowic.a nowic.o
 *
 * 2019/02/05 Created
 *
 * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 ***************************************************************************/
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cstring>

/*
 * Reads a line of text from standard input and returns it as an int in
 * the range of [-2^31 + 1, 2^31 - 2], if possible; if text does not
 * represent such an int, user is prompted to retry. Leading and trailing
 * whitespace is ignored.  For simplicity, overflow is not detected.
 * It provides a default parameter, but it can be overwritten.
 */
int GetInt(std::string prompt = "Enter an integer: ") {
   int keyin;
   std::string line;
   std::cout << prompt;                   // display a prompt
   while (true) {
     if (std::getline(std::cin, line)) {  // get an input
       std::stringstream sstr(line);      // make sstream obj
       if (sstr >> keyin) break;          // scan for int
     }
     std::cout << "Retry: ";              // not an int, retry
   }
   return keyin;
 }

/*
 * Reads a line of text from standard input and returns the first char.
 * If text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.
 * It provides a default parameter, but it can be overwritten.
 */
char GetChar(std::string prompt = "Enter a character: ") {
  char keyin;
  std::string line;
  std::cout << prompt;                  // diplay prompt
  while (true) {
    if (getline(std::cin, line)) {      // get a line
      std::stringstream sstr(line);     // create a sstream obj
      if (sstr >> keyin) break;         // get the first char
    }
    std::cout << "Retry: ";             // not a char, retry
  }
  return keyin;
}

/*
 * Reads a line of text from standard input and returns it as a
 * c string (char *), without trailing newline character.
 * If user inputs only "\n", he/she will be asked to retry.
 * Leading and trailing whitespace is not ignored.  Stores c string
 * on heap via malloc and returns the pointer.  The memory must be
 * freed by caller to avoid leak. Use free(), or delete [] to free it.
 */

 char* GetString(std::string prompt = "Enter a string: ") {
   std::string line, str;
   std::cout << prompt;                 // display prompt
   while (true) {
     if (getline(std::cin, line)) {     // get a line
       std::stringstream ssobj(line);   // make string stream obj
       if (ssobj >> str) break;         // scan for a string
     }
     std::cout << "Retry: ";            // if not, retry
   }
   char *cstr = new char [str.length()+1]; // malloc for c char array
   strcpy (cstr, str.c_str());          // copy the contents
   return cstr;
 }

// For the sake of a simple testing
#if 0
int main() {
  int i = GetInt();
  std::cout << "i=" << i << "===" << std::endl;

  char ch = GetChar();
  std::cout << "ch=" << ch << "===" << std::endl;

  char *str = GetString();
  std::cout << "keyin=" << str << "===" << std::endl;
  delete[] str;

  std::cout << "Happy Coding~~\n";
}
#endif
