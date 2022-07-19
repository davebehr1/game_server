#pragma once
#include <queue>

// boost
#include <boost/bind/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>

template <typename T>
class concurrent_queue
{
private:
    std::queue<T> the_queue;
    mutable boost::mutex the_mutex;
    boost::condition_variable the_condition_variable;

public:
    void push(const T &data);

    bool empty() const;

    size_t size() const;

    T &front();

    T const &front() const;

    bool try_pop(T &popped_value);

    void wait_and_pop(T &popped_value);

    void signal_exit();
};