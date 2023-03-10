
#ifndef METPROG_BOOK_H
#define METPROG_BOOK_H

/**
 * @brief A class containing fields with book data
 *
*/
#include <string>

class Book {
public:
    std::string name; ///< Full name of the author of the book
    std::string title; ///< Title of the book
    int year; ///< Year of publication
    int number;///< Number of pages
};



#endif //METPROG_BOOK_H
