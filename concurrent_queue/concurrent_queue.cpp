#include "concurrent_queue.h"

template <class T>
void concurrent_queue<T>::push(const T &data)
{
    boost::mutex::scoped_lock lock(the_mutex);
    the_queue.push(data);
    lock.unlock();
    the_condition_variable.notify_one();
}

template <class T>
bool concurrent_queue<T>::empty() const
{
    boost::mutex::scoped_lock lock(the_mutex);
    return the_queue.empty();
}

template <class T>
size_t concurrent_queue<T>::size() const
{
    boost::mutex::scoped_lock lock(the_mutex);
    return the_queue.size();
}

template <class T>
bool concurrent_queue<T>::try_pop(T &popped_value)
{
    boost::mutex::scoped_lock lock(the_mutex);
    if (the_queue.empty())
    {
        return false;
    }

    popped_value = the_queue.front();
    the_queue.pop();

    return true;
}

template <class T>
void concurrent_queue<T>::wait_and_pop(T &popped_value)
{
    boost::mutex::scoped_lock lock(the_mutex);
    while (the_queue.empty())
    {
        the_condition_variable.wait(lock);
    }
    popped_value = the_queue.front();
    the_queue.pop();
};

template <class T>
void concurrent_queue<T>::signal_exit()
{
    T t;
    push(t);
}
