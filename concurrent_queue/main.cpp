#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include "test.h"
#include "concurrent_queue.h"
#include "concurrent_queue.cpp"
int main()
{
    boost::mutex the_mutex;

    int value;

    test newTest;
    newTest.add(1, 2);
    newTest.add(1, 2);

    concurrent_queue<int> queue;

    queue.push(2);
    queue.push(2);
    queue.wait_and_pop(value);
    queue.try_pop(value);

    return 0;
}