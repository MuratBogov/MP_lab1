
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Book.h"
#include <vector>
#include "sort.h"


int main()
{
    int data_amnts[10] = {100,200, 500,1000,5000,10000,40000, 60000, 80000,100000};
    std::string line;
    std::string name1, name2, name3, title1, title2;
    std::vector<Book> books(100000);
    int year1, number1, n=0;

    std::ifstream is("data.txt"); // открываем файл для чтения
    if (is.is_open()) {

        while (getline(is, line)) {
            std::istringstream iss(line);  // поток для считывания данных из строки
            iss >> name1 >> name2 >> name3 >> title1 >> title2 >> year1 >> number1;

            std::string fio = name1 + " " + name2 + " " + name3;
            title1 += " " + title2;
            books[n].name = fio;
            books[n].title = title1;
            books[n].year = year1;
            books[n].number = number1;
            n++;
        }
    } else
        std::cout << "File could not be opened\n";

    is.close();     // закрываем файл







    std::vector<Book> bubble,heap,quick;
    int j = 0;
    int amount;
    std::cout << "Введите количество наборов данных для сортировки: ";
    std::cin  >> amount;
    while (bubble.size() != amount)
    {
        bubble.push_back(books[j]);
        j += 1;
    }
    heap = bubble;
    quick = bubble;


    auto start = std::chrono::steady_clock::now();
    bubbleSort(bubble, bubble.size());
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout <<"BubbleSort: "<< std::chrono::duration <double,std::milli> (diff).count() << " ms\n" ;


    std::ofstream fout;
    fout.open("bubble.txt");
    for (int i = 0; i < bubble.size(); i++)
    {

        fout << bubble[i].name << '\t' << bubble[i].title << '\t' << bubble[i].year << '\t' << bubble[i].number << '\n';
    }
    fout.close();

///

    auto starth = std::chrono::steady_clock::now();

    for (int i = heap.size() / 2; i >= 0; i--) {
        downHeap (heap, i, heap.size()-1);
    }
    heapSort(heap, heap.size());

    auto endh = std::chrono::steady_clock::now();
    auto diffh = endh - starth;
    std::cout <<"HeapSort: "<< std::chrono::duration <double,std::milli> (diffh).count() << " ms\n" ;

    std::ofstream fout_heap;
    fout_heap.open("heap.txt");
    for (int i = 0; i < heap.size(); i++)
    {

        fout_heap << heap[i].name << '\t' << heap[i].title << '\t' << heap[i].year << '\t' << heap[i].number << '\n';
    }
    fout_heap.close();

//

    auto startq = std::chrono::steady_clock::now();

    quickSort(quick,0,quick.size() - 1);

    auto endq = std::chrono::steady_clock::now();
    auto diffq = endq - startq;
    std::cout <<"QuickSort: "<< std::chrono::duration <double,std::milli> (diffq).count() << " ms\n" ;

    std::ofstream fout_q;
    fout_q.open("quick.txt");
    for (int i = 0; i < quick.size(); i++)
    {

        fout_q << quick[i].name << '\t' << quick[i].title << '\t' << quick[i].year << '\t' << quick[i].number << '\n';
    }
    fout_q.close();


}
