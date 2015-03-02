/**
 * @file hash.h
 * @brief Hash Table Coding
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-08-13
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "fnv.h"

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash
{
    public:
        hash();
        int Hash (double key);
        void AddItem(double name);
        int NumberOfItemsInIndex(int index);
        void PrintTable();
        void PrintItemsInIndex(int index);
        void PrintCollisions();
        void FindValue(double name);
    private:
        //static const long tableSize = 2098000;
        /*struct item{
            double name;
            double value;
            item* next;
        };*/
        std::map <int, std::vector<double> > m_HashTable;
        int m_tableSize;
        //item* HashTable = new item[2098000];
};
#endif
