/**
 * @file main.cpp
 * @brief Test driver for BookType stream insertion/extraction operators.
 */

#include "bookType.h"

#include <iostream>

int main() {
    using std::cin;
    using std::cout;

    BookType book1;
    // Use input operator from friend function
    cin >> book1;
    // Use output operator from friend function
    cout << book1;

    // Create book with constructor
    BookType book2("The C Plus Plus Programming Language", "923-9210293837",
                   "Super Cool Awesome Guy",
                   "Carnegie Hall", "04/03/2026", 10, 32.50f, 59.99f);

    // Chain ostream friend function calls
    cout << "\nChained Output Demo:\n";
    cout << book1 << "\n" << book2;

    return 0;
}
