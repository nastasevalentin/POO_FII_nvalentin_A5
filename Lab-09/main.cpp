#include <iostream>
#include "Map.h"
#include "MapElements.h"
#include <map>
#include <vector>
using namespace std;
template <typename Key, typename Value>

int main()

{   
    Map<int, const char *> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    
/*
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }*/
    return 0;
}