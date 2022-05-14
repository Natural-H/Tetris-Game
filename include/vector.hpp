#pragma once
#include "Arduino.h"
#include <string.h>


template <typename T>
struct vector
{
public:
    vector() : capacity_(0), count_(0), data_(nullptr) {}

    vector(const vector &rhs) : capacity_(0), count_(0), data_(nullptr)
    {
        data_ = new T[rhs.capacity_];
        capacity_ = rhs.capacity_;
        count_ = rhs.count_;
        memcpy(data_, rhs.data_, sizeof(T) * count_);
    }

    vector &operator=(const vector &rhs)
    {
        if (this == &rhs)
            return *this;

        data_ = new T[rhs.capacity_];
        capacity_ = rhs.capacity_;
        count_ = rhs.count_;
        memcpy(data_, rhs.data_, sizeof(T) * count_);
        return *this;
    }

    ~vector()
    {
        clear();
    }

    T const &operator[](unsigned int idx) const
    {
        return data_[idx];
    }

    T &operator[](unsigned int idx)
    {
        return data_[idx];
    }

    void resize_to_fit()
    {
        resize(count_);
    }

    T &pop_back()
    {
        return data_[--count_];
    }

    void push_back(T obj)
    {
        if (capacity_ == count_)
        {
            resize(capacity_ + 1);
        }

        data_[count_++] = obj;
    }

    bool isEmpty()
    {
        return count_ == 0;
    }

    void clear()
    {
        delete[] data_;
        data_ = nullptr;
        count_ = capacity_ = 0;
    }

    T *data()
    {
        return data_;
    }

    int size()
    {
        return count_;
    }

    int capacity()
    {
        return capacity_;
    }

private:
    void resize(int capacity)
    {
        if (data_ == nullptr)
        {
            data_ = new T[capacity];
            count_ = 0;
            capacity_ = capacity;
        }
        else if (capacity > capacity_)
        {
            T *data = new T[capacity];
            count_ = min(count_, capacity);
            capacity_ = capacity;
            memcpy(data, data_, sizeof(T) * count_);
            delete[] data_;
            data_ = data;
        }
    }

protected:
    int capacity_;
    int count_;
    T *data_;
};