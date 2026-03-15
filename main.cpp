/**
 * @file main.cpp
 * @brief Lab A8 driver for InventorySystem<T> with BookType and string.
 */

#include "InventorySystem.h"
#include "bookType.h"

#include <iostream>
#include <string>

BookType makeIsbnKey(const std::string &isbn) {
    return BookType("", isbn, "", "", "", 0, 0.0f, 0.0f);
}

int main() {
    using std::cout;
    using std::string;

    cout << "======================================\n";
    cout << "  Serendipity Book Store - Inventory\n";
    cout << "======================================\n\n";

    InventorySystem<BookType> inventory;

    BookType b1("The C++ Programming Language", "978-0-321-56384-2",
                "Bjarne Stroustrup", "Addison-Wesley", "03/10/2026", 8,
                52.50f, 79.99f);
    BookType b2("Clean Code", "978-0-132-35088-4", "Robert C. Martin",
                "Prentice Hall", "03/10/2026", 12, 24.00f, 39.99f);
    BookType b3("Design Patterns", "978-0-201-63361-0",
                "Gamma/Helm/Johnson/Vlissides", "Addison-Wesley",
                "03/10/2026", 5, 33.25f, 54.99f);
    BookType b4("Effective C++", "978-0-321-33487-9", "Scott Meyers",
                "O'Reilly", "03/11/2026", 9, 26.00f, 44.95f);

    cout << "--- 1) Adding books to inventory ---\n";
    inventory.add(b1);
    cout << "Added: \"" << b1.getTitle() << "\" (ISBN: " << b1.getISBN() << ")\n";
    inventory.add(b2);
    cout << "Added: \"" << b2.getTitle() << "\" (ISBN: " << b2.getISBN() << ")\n";
    inventory.add(b3);
    cout << "Added: \"" << b3.getTitle() << "\" (ISBN: " << b3.getISBN() << ")\n";
    inventory.add(b4);
    cout << "Added: \"" << b4.getTitle() << "\" (ISBN: " << b4.getISBN() << ")\n\n";

    cout << "--- 2) Full inventory print ---\n";
    inventory.print();
    cout << '\n';

    cout << "--- 3) Search (found) by ISBN ---\n";
    BookType foundKey = makeIsbnKey("978-0-132-35088-4");
    int foundIndex = inventory.search(foundKey);
    cout << "Searching for " << foundKey.getISBN() << "... ";
    if (foundIndex != -1) {
        cout << "Found at index " << foundIndex << "\n\n";
    } else {
        cout << "Not found\n\n";
    }

    cout << "--- 4) Search (not found) ---\n";
    BookType missingKey = makeIsbnKey("000-0-000-00000-0");
    int missingIndex = inventory.search(missingKey);
    cout << "Searching for " << missingKey.getISBN() << "... ";
    if (missingIndex != -1) {
        cout << "Found at index " << missingIndex << "\n\n";
    } else {
        cout << "Not found\n\n";
    }

    cout << "--- 5) Sort by retail price (before/after) ---\n";
    cout << "Before sort:\n";
    inventory.print();
    cout << "\nAfter sort:\n";
    inventory.sort();
    inventory.print();
    cout << '\n';

    cout << "--- 6) Remove a book ---\n";
    BookType removeKey = makeIsbnKey("978-0-132-35088-4");
    cout << "Removing ISBN " << removeKey.getISBN() << "... ";
    if (inventory.remove(removeKey)) {
        cout << "Removed successfully\n";
    } else {
        cout << "Not found\n";
    }
    inventory.print();
    cout << '\n';

    cout << "--- 7) Remove (not found) ---\n";
    cout << "Removing ISBN " << missingKey.getISBN() << "... ";
    if (inventory.remove(missingKey)) {
        cout << "Removed successfully\n\n";
    } else {
        cout << "Not found\n\n";
    }

    cout << "--- 8) Access with operator[] ---\n";
    cout << "Book at index 0: " << inventory[0].getTitle() << "\n\n";

    cout << "--- 9) Bounds check ---\n";
    try {
        cout << "Accessing index 99...\n";
        cout << inventory[99];
    } catch (const std::out_of_range &e) {
        cout << "Exception caught: " << e.what() << "\n\n";
    }

    cout << "--- 10) isEmpty / isFull checks ---\n";
    cout << "isEmpty(): " << (inventory.isEmpty() ? "true" : "false") << '\n';
    cout << "isFull(): " << (inventory.isFull() ? "true" : "false") << "\n\n";

    cout << "--- 11) Add when full ---\n";
    while (!inventory.isFull()) {
        int n = inventory.getCount() + 1;
        string isbn = "978-0-000-000" + std::to_string(n);
        BookType filler("Filler Book " + std::to_string(n), isbn, "Staff",
                        "Serendipity Press", "03/15/2026", n, 1.0f * n,
                        2.0f * n);
        inventory.add(filler);
    }
    cout << "Inventory now full? " << (inventory.isFull() ? "true" : "false")
         << '\n';
    BookType overflow("Overflow Book", "999-9-999-99999-9", "Overflow Author",
                      "Overflow Pub", "03/15/2026", 1, 5.0f, 9.99f);
    inventory.add(overflow);
    cout << "Count after overflow add attempt: " << inventory.getCount() << "\n\n";

    cout << "======================================\n";
    cout << "  Customer Name List (string test)\n";
    cout << "======================================\n\n";

    InventorySystem<string> customers;

    cout << "--- Adding customers ---\n";
    customers.add("Alice Johnson");
    cout << "Added: Alice Johnson\n";
    customers.add("Charlie Brown");
    cout << "Added: Charlie Brown\n";
    customers.add("Bob Smith");
    cout << "Added: Bob Smith\n\n";

    cout << "--- Sorted alphabetically ---\n";
    customers.sort();
    customers.print();
    cout << '\n';

    cout << "--- Search ---\n";
    int customerIndex = customers.search("Bob Smith");
    cout << "Searching for \"Bob Smith\"... ";
    if (customerIndex != -1) {
        cout << "Found at index " << customerIndex << '\n';
    } else {
        cout << "Not found\n";
    }

    return 0;
}
