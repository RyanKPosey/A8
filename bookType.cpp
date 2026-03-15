/**
 * @file bookType.cpp
 * @brief Implementation of the BookType class.
 *
 * This file provides the full implementation of the BookType class declared
 * in bookType.h. Each book record encapsulates metadata (title, ISBN,
 * author, publisher, date added) along with inventory data (quantity on
 * hand, wholesale price, retail price).
 *
 * A static counter (@c bookCount) tracks how many BookType objects exist
 * at any given time; it is incremented in every constructor and decremented
 * in the destructor.
 *
 * @author CS1B Instructor
 * @date 2026-02-23
 * @version 1.0
 *
 * @see bookType.h
 */
#include "bookType.h"

#include <limits>
/*============================================================================
 * Static Member Initialisation
 *===========================================================================*/
/**
 * @var BookType::bookCount
 * @brief Running total of BookType instances currently in memory.
 *
 * @details Initialised to zero at program start. Incremented by every
 * constructor and decremented by the destructor, so at any point
 * in execution the value represents the exact number of live
 * BookType objects.
 */
int BookType::bookCount = 0;
/*============================================================================
 * Constructors & Destructor
 *===========================================================================*/
/**
 * @brief Default constructor — creates an empty book record.
 *
 * @details All string fields are initialised to empty strings, numeric
 * fields to zero. The static book count is incremented to
 * reflect the new instance.
 *
 * @post @c bookCount is incremented by 1.
 * @post All numeric members are set to 0.
 * @post All string members are empty.
 */
BookType::BookType()
    : bookTitle(""), isbn(""), author(""), publisher(""), dateAdded(""),
      qtyOnHand(0), wholesale(0.0f), retail(0.0f) {
    bookCount++;
}
/**
 * @brief Copy constructor — creates a deep copy of an existing BookType.
 *
 * @details Performs a member-wise copy of every field from @p other.
 * Because all members are value types (std::string, int, float),
 * the default member-wise copy is safe and sufficient — no
 * dynamic memory management is required.
 *
 * @param[in] other The source BookType object to duplicate.
 *
 * @post A new BookType exists with identical field values to @p other.
 * @post @c bookCount is incremented by 1.
 */
BookType::BookType(const BookType &other)
    : bookTitle(other.bookTitle), isbn(other.isbn), author(other.author),
      publisher(other.publisher), dateAdded(other.dateAdded),
      qtyOnHand(other.qtyOnHand), wholesale(other.wholesale),
      retail(other.retail) {
    bookCount++;
}
/**
 * @brief Parameterised constructor — creates a fully-populated book record.
 *
 * @details Allows the caller to set every field at construction time,
 * avoiding the need for separate setter calls. This is the
 * preferred way to create a BookType when all data is available
 * up-front.
 *
 * @param[in] title The title of the book.
 * @param[in] isbn The ISBN-13 identifier (e.g. "978-0-13-468599-1").
 * @param[in] author The author's full name.
 * @param[in] publisher The name of the publishing house.
 * @param[in] dateAdded The date this record was created (MM/DD/YYYY).
 * @param[in] qtyOnHand The number of copies currently in stock.
 * @param[in] wholesale The wholesale (cost) price of the book.
 * @param[in] retail The retail (selling) price of the book.
 *
 * @post @c bookCount is incremented by 1.
 * @post All member fields reflect the supplied arguments.
 */
BookType::BookType(const std::string &title, const std::string &isbn,
                   const std::string &author, const std::string &publisher,
                   const std::string &dateAdded, int qtyOnHand, float wholesale,
                   float retail)
    : bookTitle(title), isbn(isbn), author(author), publisher(publisher),
      dateAdded(dateAdded), qtyOnHand(qtyOnHand), wholesale(wholesale),
      retail(retail) {
    bookCount++;
}
/**
 * @brief Destructor — cleans up and adjusts the book count.
 *
 * @details No dynamic memory is owned by this class, so the destructor
 * only needs to decrement the static book counter. The
 * std::string members are automatically destroyed by their
 * own destructors.
 *
 * @post @c bookCount is decremented by 1.
 */
BookType::~BookType() { bookCount--; }
/*============================================================================
 * Mutators (Setters)
 *===========================================================================*/
/**
 * @brief Set the book's title.
 *
 * @param[in] title The new title string.
 *
 * @post @c bookTitle is updated to @p title.
 */
void BookType::setTitle(const std::string &title) { bookTitle = title; }
/**
 * @brief Set the book's ISBN.
 *
 * @param[in] isbn The ISBN-13 identifier string.
 *
 * @note No format validation is performed. The caller is responsible
 * for ensuring the ISBN conforms to the 13-digit standard.
 *
 * @post @c isbn member is updated.
 */
void BookType::setISBN(const std::string &isbn) { this->isbn = isbn; }
/**
 * @brief Set the author's name.
 *
 * @param[in] author The author's full name.
 *
 * @post @c author member is updated.
 */
void BookType::setAuthor(const std::string &author) { this->author = author; }
/**
 * @brief Set the publisher's name.
 *
 * @param[in] publisher The publisher name.
 *
 * @post @c publisher member is updated.
 */
void BookType::setPub(const std::string &publisher) {
    this->publisher = publisher;
}
/**
 * @brief Set the date the book was added to the inventory.
 *
 * @param[in] dateAdded A date string in MM/DD/YYYY format.
 *
 * @note No format validation is performed. The caller should ensure
 * the string conforms to the expected MM/DD/YYYY format.
 *
 * @post @c dateAdded member is updated.
 */
void BookType::setDateAdded(const std::string &dateAdded) {
    this->dateAdded = dateAdded;
}
/**
 * @brief Set the quantity of copies on hand.
 *
 * @param[in] qty The new stock quantity (should be >= 0).
 *
 * @post @c qtyOnHand is updated to @p qty.
 */
void BookType::setQty(int qty) { qtyOnHand = qty; }
/**
 * @brief Set the wholesale (cost) price.
 *
 * @param[in] wholesale The new wholesale price (should be >= 0.0).
 *
 * @post @c wholesale member is updated.
 */
void BookType::setWholesale(float wholesale) { this->wholesale = wholesale; }
/**
 * @brief Set the retail (selling) price.
 *
 * @param[in] retail The new retail price (should be >= 0.0).
 *
 * @post @c retail member is updated.
 */
void BookType::setRetail(float retail) { this->retail = retail; }
/**
 * @brief Increment the global book count by one.
 *
 * @details This static utility is provided for cases where the count
 * needs to be adjusted externally (e.g. bulk import operations).
 * Under normal usage the constructors handle incrementing
 * automatically.
 *
 * @post @c bookCount is incremented by 1.
 */
void BookType::incrementBooks() { bookCount++; }
/**
 * @brief Decrement the global book count by one.
 *
 * @details This static utility is provided for cases where the count
 * needs to be adjusted externally (e.g. bulk delete operations).
 * Under normal usage the destructor handles decrementing
 * automatically.
 *
 * @warning Calling this when @c bookCount is already 0 will result in
 * a negative count — the caller is responsible for bounds
 * checking.
 *
 * @post @c bookCount is decremented by 1.
 */
void BookType::decrementBooks() { bookCount--; }
/*============================================================================
 * Accessors (Getters)
 *===========================================================================*/
/**
 * @brief Retrieve the book's title.
 * @return A copy of the title string.
 */
std::string BookType::getTitle() const { return bookTitle; }
/**
 * @brief Retrieve the book's ISBN.
 * @return A copy of the ISBN-13 string.
 */
std::string BookType::getISBN() const { return isbn; }
/**
 * @brief Retrieve the author's name.
 * @return A copy of the author string.
 */
std::string BookType::getAuthor() const { return author; }
/**
 * @brief Retrieve the publisher's name.
 * @return A copy of the publisher string.
 */
std::string BookType::getPub() const { return publisher; }
/**
 * @brief Retrieve the date the book was added.
 * @return A copy of the date string (MM/DD/YYYY).
 */
std::string BookType::getDateAdded() const { return dateAdded; }
/**
 * @brief Retrieve the quantity on hand.
 * @return The number of copies currently in stock.
 */
int BookType::getQty() const { return qtyOnHand; }
/**
 * @brief Retrieve the wholesale price.
 * @return The cost price of the book.
 */
float BookType::getWholesale() const { return wholesale; }
/**
 * @brief Retrieve the retail price.
 * @return The selling price of the book.
 */
float BookType::getRetail() const { return retail; }
/**
 * @brief Retrieve the total number of BookType instances.
 *
 * @details Because this is a static method it can be called without
 * an object:
 * @code
 * int total = BookType::getBookCount();
 * @endcode
 *
 * @return The current value of @c bookCount.
 */
int BookType::getBookCount() { return bookCount; }
/*============================================================================
 * Utility Methods
 *===========================================================================*/
/**
 * @brief Print the complete book record to standard output.
 *
 * @details Formats and displays every field in a human-readable,
 * labelled layout. Monetary values are displayed with two
 * decimal places using @c std::fixed and @c std::setprecision.
 *
 * @par Example Output:
 * @code
 * Title: The C++ Programming Language
 * ISBN: 978-0-321-56384-2
 * Author: Bjarne Stroustrup
 * Publisher: Addison-Wesley
 * Date Added: 01/15/2026
 * Qty: 12
 * Wholesale: $54.99
 * Retail: $79.99
 * @endcode
 *
 * @note This method does not modify any member state (declared @c const).
 */
void BookType::print() const {
    std::cout << *this;
}
/**
 * @brief Compare this book with another for equality.
 *
 * @details Two books are considered equal if and only if their ISBN
 * values match. The ISBN is the industry-standard unique
 * identifier for published works, making it the most reliable
 * field for comparison. Other fields (title, author, etc.)
 * are intentionally excluded — different editions or printings
 * of the same ISBN should be treated as the same book.
 *
 * @param[in] other The BookType to compare against.
 *
 * @return @c true if both books share the same ISBN.
 * @return @c false if the ISBNs differ.
 *
 * @par Usage Example:
 * @code
 * BookType a("Title A", "978-0-13-468599-1", ...);
 * BookType b("Title B", "978-0-13-468599-1", ...);
 *
 * if (a.equals(b))
 * std::cout << "Same book!" << std::endl;
 * @endcode
 *
 * @note This method does not modify any member state (declared @c const).
 */
bool BookType::equals(const BookType &other) const {
    return (isbn == other.isbn);
}

/*============================================================================
 * Operator Overloads
 *===========================================================================*/
/**
 * @brief Prefix increment operator.
 *
 * @details Increments @c qtyOnHand by one and returns a reference to
 * the updated object.
 *
 * @return Reference to this object after increment.
 */
BookType &BookType::operator++() {
    qtyOnHand++;
    return *this;
}
/**
 * @brief Postfix increment operator.
 *
 * @details Captures the current object state, increments
 * @c qtyOnHand by one, and returns the captured state.
 *
 * @param[in] unused Dummy integer used only to select postfix syntax.
 * @return Copy of object before increment.
 */
BookType BookType::operator++(int unused) {
    (void)unused;
    BookType oldState(*this);
    qtyOnHand++;
    return oldState;
}
/**
 * @brief Prefix decrement operator.
 *
 * @details Decrements @c qtyOnHand by one. If decrementing would make
 * quantity negative, quantity is clamped to zero and a message is printed.
 *
 * @return Reference to this object after decrement.
 */
BookType &BookType::operator--() {
    qtyOnHand--;

    if (qtyOnHand < 0) {
        qtyOnHand = 0;
        std::cout << "Cannot decrement below zero. Quantity set to 0." << '\n';
    }

    return *this;
}
/**
 * @brief Postfix decrement operator.
 *
 * @details Captures the current object state, decrements @c qtyOnHand,
 * then returns the captured state. If decrementing would make quantity
 * negative, quantity is clamped to zero and a message is printed.
 *
 * @param[in] unused Dummy integer used only to select postfix syntax.
 * @return Copy of object before decrement.
 */
BookType BookType::operator--(int unused) {
    (void)unused;
    BookType oldState(*this);
    qtyOnHand--;

    if (qtyOnHand < 0) {
        qtyOnHand = 0;
        std::cout << "Cannot decrement below zero. Quantity set to 0." << '\n';
    }

    return oldState;
}
/**
 * @brief Trade-in subtraction operator.
 *
 * @details Calculates trade-in balance using:
 * @code
 * balance = retail - (other.wholesale * 0.5)
 * @endcode
 * The returned object is a copy of the left operand with retail set
 * to the computed balance. If the balance is negative, an error message
 * is printed and the left operand is returned unchanged.
 *
 * @param[in] other Right-hand trade-in book.
 * @return Resulting BookType from the trade-in operation.
 */
BookType BookType::operator-(const BookType &other) const {
    const float balance = retail - (other.wholesale * 0.5f);

    if (balance < 0.0f) {
        std::cout << "Trade-in error: credit exceeds retail price. Operation "
                     "cancelled."
                  << '\n';
        return *this;
    }

    BookType result(*this);
    result.retail = balance;
    return result;
}
/**
 * @brief Equality operator based on ISBN.
 * @param[in] other Book to compare against.
 * @return @c true if ISBN values are equal.
 */
bool BookType::operator==(const BookType &other) const {
    return isbn == other.isbn;
}
/**
 * @brief Inequality operator based on ISBN.
 * @param[in] other Book to compare against.
 * @return @c true if ISBN values are not equal.
 */
bool BookType::operator!=(const BookType &other) const {
    return !(*this == other);
}
/**
 * @brief Less-than operator based on retail price.
 * @param[in] other Book to compare against.
 * @return @c true if this retail price is lower.
 */
bool BookType::operator<(const BookType &other) const {
    return retail < other.retail;
}
/**
 * @brief Greater-than operator based on retail price.
 * @param[in] other Book to compare against.
 * @return @c true if this retail price is higher.
 */
bool BookType::operator>(const BookType &other) const {
    return retail > other.retail;
}
/**
 * @brief Less-than-or-equal operator based on retail price.
 * @param[in] other Book to compare against.
 * @return @c true if this retail price is lower or equal.
 */
bool BookType::operator<=(const BookType &other) const {
    return retail <= other.retail;
}
/**
 * @brief Greater-than-or-equal operator based on retail price.
 * @param[in] other Book to compare against.
 * @return @c true if this retail price is higher or equal.
 */
bool BookType::operator>=(const BookType &other) const {
    return retail >= other.retail;
}

/**
 * @brief Stream insertion operator for formatted book output.
 * @param[in,out] os Output stream receiving formatted content.
 * @param[in] book Book record to display.
 * @return Reference to @p os for chaining.
 */
std::ostream &operator<<(std::ostream &os, const BookType &book) {
    os << std::fixed << std::setprecision(2);
    os << "\n===== Book Record =====\n"
       << "Title:      " << book.bookTitle << '\n'
       << "ISBN:       " << book.isbn << '\n'
       << "Author:     " << book.author << '\n'
       << "Publisher:  " << book.publisher << '\n'
       << "Date Added: " << book.dateAdded << '\n'
       << "Qty:        " << book.qtyOnHand << '\n'
       << "Wholesale:  $" << book.wholesale << '\n'
       << "Retail:     $" << book.retail << '\n'
       << "========================\n";
    return os;
}

/**
 * @brief Stream extraction operator for interactive book input.
 * @param[in,out] is Input stream used to read book fields.
 * @param[out] book Book record that receives the input.
 * @return Reference to @p is for chaining.
 */
std::istream &operator>>(std::istream &is, BookType &book) {
    std::cout << "Enter book information:\n";

    std::cout << "  Title:       ";
    std::getline(is >> std::ws, book.bookTitle);

    std::cout << "  ISBN:        ";
    std::getline(is, book.isbn);

    std::cout << "  Author:      ";
    std::getline(is, book.author);

    std::cout << "  Publisher:   ";
    std::getline(is, book.publisher);

    std::cout << "  Date Added:  ";
    std::getline(is, book.dateAdded);

    std::cout << "  Qty on Hand: ";
    is >> book.qtyOnHand;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Wholesale:   ";
    is >> book.wholesale;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Retail:      ";
    is >> book.retail;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return is;
}