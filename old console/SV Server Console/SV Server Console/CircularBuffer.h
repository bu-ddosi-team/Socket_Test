#include <cstddef>
#include <iostream>

template <typename T, int N>
class CircularBuffer
{
public:
    CircularBuffer();
    CircularBuffer(T initial_value);
    std::size_t count();
    bool push(T item);
    void pop();
    T front();
    bool is_full();
    bool is_empty();
private:
    T storage[N+1];
    std::size_t head, tail;
};

template <typename T, int N>
CircularBuffer<T, N>::CircularBuffer() :
    head(0),
    tail(0)
{
}

template <typename T, int N>
CircularBuffer<T, N>::CircularBuffer(T initial_value) :
    head(0),
    tail(0)
{
    for (int i = 0; i < N; ++i) {
        storage[i] = initial_value;
    }
}

template <typename T, int N>
std::size_t CircularBuffer<T, N>::count()
{
    if (this->is_full()) {
        return N;
    } else {
        return tail - head;
    }
}

template <typename T, int N>
bool CircularBuffer<T, N>::push(T item)
{
    if (this->is_full()) {
        return false;
    }
    storage[tail++] = item;
    return true;
}

template <typename T, int N>
void CircularBuffer<T, N>::pop()
{
    if (!this->is_empty()) {
        ++head;
    }
}

template <typename T, int N>
T CircularBuffer<T, N>::front()
{
    return storage[head];
}

template <typename T, int N>
bool CircularBuffer<T, N>::is_full()
{
    return (tail == N);
}

template <typename T, int N>
bool CircularBuffer<T, N>::is_empty()
{
    return (head == tail);
}