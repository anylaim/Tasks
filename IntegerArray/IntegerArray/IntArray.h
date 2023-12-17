#pragma once
#include <cassert>
#include <algorithm> 

class bad_range : public std::exception // выход за пределы массива
{
public:
    virtual const char* what() const noexcept override
    {
        return "Out of array";
    }
};

class bad_length : public std::exception // предоставление неправильной длины массиву
{
public:
    virtual const char* what() const noexcept override
    {
        return "Incorrect array length";
    }
};

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray();

    IntArray(int length);

    ~IntArray();

    IntArray(const IntArray& a);

    IntArray& operator=(const IntArray& a);

    void erase();

    int& operator[](int index);

    void reallocate(int newLength);

    void resize(int newLength);

    void insertBefore(int value, int index);

    void remove(int index);

    void insertAtBeginning(int value);
    void insertAtEnd(int value);

    int getLength() const;
};