#include "hash.h"

#define MASK_20 (((uint32_t)1 << 20) - 1)
#define FNV1_32_INIT ((uint32_t)2166136261)

hash::hash()
{
    /*for (int i = 0; i < 1098000; i++)
    {
        item* HashTableTmp;
        HashTableTmp = new item;
        HashTableTmp->name = 0;
        HashTableTmp->value = 0;
        HashTableTmp->next = NULL;
        HashTable.push_back(HashTableTmp);
        delete HashTableTmp;
    }*/
    m_tableSize = 1000000;
}

int hash::Hash(double key)
{
    uint32_t hash;
    hash = FNV::fnv1a(key, FNV1_32_INIT);
    hash = (hash >> 20)^(hash & MASK_20);
    int index;
    index = static_cast<int>(hash);
    return index;
}

void hash::AddItem(double name)
{
    int index = Hash(name);
    m_HashTable[index].push_back(name);
    
    /*if (HashTable.at(index)->name == 0)
    {
        HashTable.at(index)->name = name;
        HashTable.at(index)->value = value;
    }
    else
    {
        item* Ptr = HashTable.at(index);
        item* n = new item;
        n->name = name;
        n->value = value;
        n->next = NULL;
        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }*/
}

int hash::NumberOfItemsInIndex(int index)
{
    int count  = 0 ;
    std::map <int, std::vector<double> >::iterator it;
    it = m_HashTable.find(index);
    if (it == m_HashTable.end())
    {
        return count;
    }
    else
    {
        count = (it->second).size();
    }
    /*if (HashTable.at(index)->name == 0)
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable.at(index);
        while (Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
    }*/
    return count;
}

void hash::PrintTable()
{
    int number, Max = 0;
    int collisions[1000] = {0};
    for (int i = 0; i < 1048576 ; i++)
    {
        number = NumberOfItemsInIndex(i);
        if (Max < number)
            Max = number;
        /*cout << "-----------------------" << endl;
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->value << endl;
        cout << "# of items = " << number << endl;*/
        collisions[number]++;
    }
    for (int i = 0; i <= Max; i++)
        cout << "# of items = " << i << ", collisions = " << collisions[i] << endl;
}

void hash::PrintItemsInIndex(int index)
{
    std::map <int, std::vector<double> >::iterator it;
    it = m_HashTable.find(index);
    if (it == m_HashTable.end())
    {
        cout << "Index = " << index << " is empty." << endl;
    }
    else
    {
        std::vector <double>::iterator it2;
        cout << "Index = " << index << " contains the following items" << endl;
        for(it2 = (it->second).begin(); it2 != (it->second).end(); ++it2)
        {
            cout << *it2 << endl;
        }
        cout << "---------------------------------------" << endl;
    }
    /*item* Ptr = HashTable.at(index);
    if (Ptr->name == 0)
    {
        cout << "Index = " << index <<" is empty" << endl;
    }
    else
    {
        cout << "Index = " << index << " contains the following items" << endl;
        while (Ptr != NULL)
        {
            cout << "-------------------" << endl;
            cout << Ptr->name << endl;
            cout << Ptr->value << endl;
            Ptr = Ptr->next;
        }
    }*/
}

void hash::PrintCollisions()
{
    int collisions[1000] = {0};
    int Max = 0, number;
    for (int i = 0; i < m_tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        if (Max < number)
            Max = number;
        collisions[number]++;
    }
    for (int i = 0; i <= Max; i++)
    {
        cout << "# of items = " << i << ", collisions = " << collisions[i] << endl;
    }
}

