#pragma once
#include <iostream>

template <typename T>
class Array
{
    private:
        T* _arr;
        unsigned int _size;
    public:
        Array()
        {
            _arr = NULL;
            _size = 0;
        }
        Array(unsigned int n)
        {
            _arr = new T[n];
            _size = n;
        }
        Array(const Array& a)
        {
            _arr = NULL;
            _size = a._size;
            if (_size > 0)
            {
                _arr = new T[_size];
                for (size_t i = 0; i < _size; i++)
                    _arr[i] = a[i];
            }
        }
        Array& operator=(const Array& a)
        {
            if (this != &a)
            {
                delete[] _arr;
                _arr = NULL;
                _size = a._size;
                if (_size > 0)
                {
                    _arr = new T[_size];
                    for (size_t i = 0; i < _size; i++)
                        _arr[i] = a[i];
                }
            }
            return (*this);
        }
        T& operator[](unsigned int i) const 
        {
            if (i >= _size)
                throw std::runtime_error("Index out of bounds");
            return _arr[i];
        }
        ~Array()
        {
            delete[] _arr;
        }
        unsigned int size() const
        {
            return _size;
        }
};