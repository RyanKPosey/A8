/**
 * @file bookType.h
 * @brief Declaration of the BookType class for book inventory management.
 */
#ifndef BOOKTYPE_H
#define BOOKTYPE_H
#include <iomanip>
#include <iostream>
#include <string>
/**
 * @class BookType
 * @brief Represents a single book record in the inventory system.
 *
 * Stores all relevant metadata for a book including title, ISBN, author,
 * publisher, date added, quantity on hand, and pricing information.
 * Tracks the total number of BookType instances via a static counter.
 */
class BookType {
  public:
    /// @name Constructors & Destructor
    /// @{
    /**
     * @brief Default constructor.
     *
     * Initialises all string members to empty strings, numeric members
     * to zero, and increments the book count.
     */
    BookType();
    /**
     * @brief Copy constructor.
     * @param other The BookType object to copy from.
     */
    BookType(const BookType &other);
    /**
     * @brief Parameterised constructor.
     * @param title Book title.
     * @param isbn ISBN-13 identifier.
     * @param author Author's full name.
     * @param publisher Publisher name.
     * @param dateAdded Date the record was created (MM/DD/YYYY).
     * @param qtyOnHand Quantity currently in stock.
     * @param wholesale Wholesale (cost) price.
     * @param retail Retail (selling) price.
     */
    BookType(const std::string &title, const std::string &isbn,
             const std::string &author, const std::string &publisher,
             const std::string &dateAdded, int qtyOnHand, float wholesale,
             float retail);
    /**
     * @brief Destructor.
     *
     * Decrements the static book count.
     */
    ~BookType();
    /// @}
    /// @name Mutators (Setters)
    /// @{
    /**
     * @brief Set the book title.
     * @param title New title string.
     */
    void setTitle(const std::string &title);
    /**
     * @brief Set the ISBN.
     * @param isbn ISBN-13 string.
     */
    void setISBN(const std::string &isbn);
    /**
     * @brief Set the author name.
     * @param author Author's full name.
     */
    void setAuthor(const std::string &author);
    /**
     * @brief Set the publisher name.
     * @param publisher Publisher name.
     */
    void setPub(const std::string &publisher);
    /**
     * @brief Set the date the book was added to inventory.
     * @param dateAdded Date string in MM/DD/YYYY format.
     */
    void setDateAdded(const std::string &dateAdded);
    /**
     * @brief Set the quantity on hand.
     * @param qty Number of copies in stock.
     */
    void setQty(int qty);
    /**
     * @brief Set the wholesale price.
     * @param wholesale Cost price of the book.
     */
    void setWholesale(float wholesale);
    /**
     * @brief Set the retail price.
     * @param retail Selling price of the book.
     */
    void setRetail(float retail);
    /**
     * @brief Increment the static book count by one.
     */
    static void incrementBooks();
    /**
     * @brief Decrement the static book count by one.
     */
    static void decrementBooks();
    /// @}
    /// @name Accessors (Getters)
    /// @{
    /** @brief Get the book title. @return Title string. */
    std::string getTitle() const;
    /** @brief Get the ISBN. @return ISBN-13 string. */
    std::string getISBN() const;
    /** @brief Get the author name. @return Author string. */
    std::string getAuthor() const;
    /** @brief Get the publisher name. @return Publisher string. */
    std::string getPub() const;
    /** @brief Get the date added. @return Date string (MM/DD/YYYY). */
    std::string getDateAdded() const;
    /** @brief Get the quantity on hand. @return Stock quantity. */
    int getQty() const;
    /** @brief Get the wholesale price. @return Wholesale price. */
    float getWholesale() const;
    /** @brief Get the retail price. @return Retail price. */
    float getRetail() const;
    /**
     * @brief Get the current total book count.
     * @return Number of BookType instances that exist.
     */
    static int getBookCount();
    /// @}
    /// @name Utility
    /// @{
    /**
     * @brief Print the book's details to standard output.
     */
    void print() const;
    /**
     * @brief Compare this book with another for equality.
     * @param other The BookType to compare against.
     * @return @c true if the books are considered equal, @c false otherwise.
     */
    bool equals(const BookType &other) const;
    /**
     * @brief Prefix increment operator.
     *
     * @details Increments @c qtyOnHand by one and returns a reference
     * to the updated object.
     *
     * @return Reference to this object after increment.
     */
    BookType &operator++();
    /**
     * @brief Postfix increment operator.
     *
     * @details Stores the current object state, increments @c qtyOnHand
     * by one, and returns the original state.
     *
     * @param[in] unused Dummy integer used to distinguish postfix form.
     * @return Copy of this object before increment.
     */
    BookType operator++(int unused);
    /**
     * @brief Prefix decrement operator.
     *
     * @details Decrements @c qtyOnHand by one. If decrementing would make
     * the quantity negative, quantity is set to zero and a warning
     * message is printed.
     *
     * @return Reference to this object after decrement.
     */
    BookType &operator--();
    /**
     * @brief Postfix decrement operator.
     *
     * @details Stores the current object state, decrements @c qtyOnHand
     * by one, and returns the original state. If decrementing would
     * make the quantity negative, quantity is set to zero and a warning
     * message is printed.
     *
     * @param[in] unused Dummy integer used to distinguish postfix form.
     * @return Copy of this object before decrement.
     */
    BookType operator--(int unused);
    /**
     * @brief Trade-in subtraction operator.
     *
     * @details Computes the transaction balance using:
     * @code
     * balance = this->retail - (other.wholesale * 0.5)
     * @endcode
     * If the computed balance is negative, an error message is printed
     * and the left-hand object is returned unchanged.
     *
     * @param[in] other Trade-in book on the right-hand side.
     * @return A BookType object representing the result of the trade-in.
     */
    BookType operator-(const BookType &other) const;
    /**
     * @brief Equality operator (by ISBN).
     * @param[in] other Book to compare against.
     * @return @c true if both ISBN values are identical.
     */
    bool operator==(const BookType &other) const;
    /**
     * @brief Inequality operator (by ISBN).
     * @param[in] other Book to compare against.
     * @return @c true if ISBN values differ.
     */
    bool operator!=(const BookType &other) const;
    /**
     * @brief Less-than operator (by retail price).
     * @param[in] other Book to compare against.
     * @return @c true if this retail price is lower.
     */
    bool operator<(const BookType &other) const;
    /**
     * @brief Greater-than operator (by retail price).
     * @param[in] other Book to compare against.
     * @return @c true if this retail price is higher.
     */
    bool operator>(const BookType &other) const;
    /**
     * @brief Less-than-or-equal operator (by retail price).
     * @param[in] other Book to compare against.
     * @return @c true if this retail price is lower or equal.
     */
    bool operator<=(const BookType &other) const;
    /**
     * @brief Greater-than-or-equal operator (by retail price).
     * @param[in] other Book to compare against.
     * @return @c true if this retail price is higher or equal.
     */
    bool operator>=(const BookType &other) const;
    /// @}

    /// @name Friend Functions
    /// @{
    /**
     * @brief Stream insertion operator for formatted book output.
     * @param os Output stream to write to.
     * @param book Book record to display.
     * @return Reference to the same output stream for chaining.
     */
    friend std::ostream &operator<<(std::ostream &os, const BookType &book);
    /**
     * @brief Stream extraction operator for interactive book input.
     * @param is Input stream to read from.
     * @param book Book record to populate.
     * @return Reference to the same input stream for chaining.
     */
    friend std::istream &operator>>(std::istream &is, BookType &book);
    /// @}
    
  protected:
    std::string bookTitle; ///< Book title.
    std::string isbn;      ///< ISBN-13 identifier.
    std::string author;    ///< Author's full name.
    std::string publisher; ///< Publisher name.
    std::string dateAdded; ///< Date added to inventory (MM/DD/YYYY).
    int qtyOnHand;         ///< Copies currently in stock.
    float wholesale;       ///< Wholesale (cost) price.
    float retail;          ///< Retail (selling) price.
    static int bookCount;  ///< Running total of BookType instances.
};

#endif // BOOKTYPE_H
