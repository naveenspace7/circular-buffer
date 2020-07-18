#pragma once

#include <exception>

class BufferSizeExceeded: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Buffer Size Exceeded";
    }
} BufferSizeExceeded;

class BufferSizeNull: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Buffer Empty";
    }
} BufferSizeNull;

template <typename T, int N>
class CirBuff
{
public:

    CirBuff(): data(new T[N]), _size(0)
    {
        start_index = data;
        end_index   = data;

        start_boundary = data;
        end_boundary = &data[N-1];
    }

    ~CirBuff()
    {
        delete[] data;
    }

    void push_back(const T& new_data)
    {
        if (_size == N) throw BufferSizeExceeded;

        *end_index = new_data;

        if (end_index + 1 > end_boundary)
            end_index = start_boundary;
        else end_index++;

        _size++;
    }

    bool empty()
    {
        return _size == 0;
    }

    T pop_front()
    {
        if (_size == 0)
            throw BufferSizeNull;

        T poped_data = *start_index;

        if (start_index + 1 > end_boundary)
            start_index = start_boundary;
        else
            start_index++;

        --_size;

        return poped_data;
    }

private:
    T * data;
    T * start_index, * end_index;
    T * start_boundary, * end_boundary;

    size_t _size;
};