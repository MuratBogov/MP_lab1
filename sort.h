/** @file
 * @brief A file with the implementation of sorting algorithms and operator overloads
 */

#ifndef METPROG_SORT_H
#define METPROG_SORT_H

#include <string>
#include "Book.h"

/** @brief Bubble sorting function
*  @param a Vector of Book elements
*  @param size Size of the vector to sort
*/
void bubbleSort(std::vector <Book> &a, int size);

/** @brief Function of building a pyramid
*  @param a Vector of Book elements
*  @param k,n Pyramid boundaries
*/
void downHeap(std::vector <Book> &a, int k, int n);

/** @brief Function of sorting a pyramid
*  @param a Vector of Book elements
*  @param size Size of the vector to sort
*/
void heapSort(std::vector <Book> &a, int size);


/** @brief Function of dividing a vector into 2 parts.
 *
 * Function of dividing a vector into 2 parts: all the elements of the left are less than
 * middle element, all the elements of the right are greater than middle element
 *
*  @param a Vector of Book elements
*  @param left,right Vector boundaries
*/
int partition(std::vector<Book> &a, int left, int right);

/** @brief Function of quick sorting
 *
*  @param a Vector of Book elements
*  @param left,right Vector boundaries
*/
void quickSort(std::vector<Book> &a, int left, int right);


/** @brief Operator > overloading
 *
*  @param b1,b2 compared elements
*/
bool operator> (Book b1, Book b2);

/** @brief Operator < overloading
 *
*  @param b1,b2 compared elements
*/
bool operator< (Book b1, Book b2);

/** @brief Operator >= overloading
 *
*  @param b1,b2 compared elements
*/
bool operator>= (Book b1, Book b2);

/** @brief Operator <= overloading
 *
*  @param b1,b2 compared elements
*/
bool operator<= (Book b1, Book b2);

#endif //METPROG_SORT_H
