#pragma once
#include <boost/thread/thread.hpp>

class test
{
private:
    mutable boost::mutex the_mutex;

public:
    test();
    int add(int num1, int num2);
};