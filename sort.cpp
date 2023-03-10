

#include "sort.h"
#include "Book.h"
#include <vector>

void bubbleSort(std::vector <Book> &a, int size)
{
    int i, j;
    Book x;
    for( i=0; i < size; i++)
    {
  		// i - step number
        for( j = size-1; j > i; j-- )
        {     				// internal loop for each step
            if ( a[j-1] > a[j] )
            {
                x=a[j-1];
                a[j-1]=a[j];
                a[j]=x;
            }
        }
    }
}


void downHeap(std::vector <Book> &a, int k, int n)
{
    //  before sift procedure: a[k+1]...a[n]  - is a pyramid
    //  after:                 a[k]...a[n]  - is a pyramid
    Book new_elem;
    int child;
    new_elem = a[k];

    while(k <= n/2)
    {  // while a[k] has childs
        child = 2*k;
        //  choose bigger son
        if( child < n && a[child] < a[child+1] )
            child++;
        if( new_elem >= a[child] ) break;
        // otherwise
        a[k] = a[child]; 	// move the son up
        k = child;
    }
    a[k] = new_elem;
}

void heapSort(std::vector <Book> &a, int size)
{
    int i;
    Book temp;

    for(i=size/2-1; i >= 0; i--)	 // build pyramid
        downHeap(a, i, size-1);
    // now a[0]...a[size-1] is a pyramid
    for(i=size-1; i > 0; i--)
    {
        std::swap(a[i], a[0]);		// swap first and last
        downHeap(a, 0, i-1); 	// restore the pyramid a[0]...a[i-1]
    }
}


int partition(std::vector<Book> &a, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    Book pivotValue = a[pivotIndex];
    int i = left, j = right;
    Book temp;
    while(i <= j) {
        while(a[i] < pivotValue) {
            i++;
        }
        while(a[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}



void quickSort(std::vector<Book> &a, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(a, left, right);
        quickSort(a, left, pivotIndex - 1);
        quickSort(a, pivotIndex, right);
    }
}



bool operator> (Book b1, Book b2){
    if (b1.name < b1.name) {return false;}
    else if (b1.name > b2.name) {return true;}
    else if (b1.name == b2.name) {
        if (b1.title < b1.title) {return false; }
        else if (b1.title > b1.title) {return true; }
        else if (b1.title == b1.title) {
            if (b1.year < b2.year) {return false;}
            else if (b1.year > b2.year) {return true;}
            else if (b1.year == b2.year) {return false;}
        }
    }
}


bool operator< (Book b1, Book b2){
    if (b1.name > b1.name) {return false;}
    else if (b1.name < b2.name) {return true;}
    else if (b1.name == b2.name) {
        if (b1.title > b1.title) {return false; }
        else if (b1.title < b1.title) {return true; }
        else if (b1.title == b1.title) {
            if (b1.year > b2.year) {return false;}
            else if (b1.year < b2.year) {return true;}
            else if (b1.year == b2.year) {return false;}
        }
    }
}


bool operator>= (Book b1, Book b2){
    if (b1.name < b1.name) {return false;}
    else if (b1.name > b2.name) {return true;}
    else if (b1.name == b2.name) {
        if (b1.title < b1.title) {return false; }
        else if (b1.title > b1.title) {return true; }
        else if (b1.title == b1.title) {
            if (b1.year < b2.year) {return false;}
            else if (b1.year > b2.year) {return true;}
            else if (b1.year == b2.year) {return true;}
        }
    }
}


bool operator<= (Book b1, Book b2){
    if (b1.name > b1.name) {return false;}
    else if (b1.name < b2.name) {return true;}
    else if (b1.name == b2.name) {
        if (b1.title > b1.title) {return false; }
        else if (b1.title < b1.title) {return true; }
        else if (b1.title == b1.title) {
            if (b1.year > b2.year) {return false;}
            else if (b1.year < b2.year) {return true;}
            else if (b1.year == b2.year) {return true;}
        }
    }
}

