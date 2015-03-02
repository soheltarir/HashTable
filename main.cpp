#include "hash.h"
#include <stdlib.h>
using namespace std;

int main()
{
    double dblOID, dblVal;;
    hash Dummy;
    for (int i = 9000000; i < 10000000; i++)
    {
        dblOID = (double)(2014082500000000 + i);
        Dummy.AddItem(dblOID);
    }
    Dummy.PrintTable();
    return 1;
}
