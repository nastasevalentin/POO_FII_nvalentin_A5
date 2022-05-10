#pragma once
#include "MapElements.h"

template <typename Key, typename Value>
class Map
{
    int count;
    MapElements<Key, Value> *elements;
    MapElements<Key, Value> *begin() { return elements; };
    MapElements<Key, Value> *end() { return elements + count; }
};