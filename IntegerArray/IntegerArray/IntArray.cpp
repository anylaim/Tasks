#include <iostream>
#include "IntArray.h"

IntArray::IntArray() = default;

IntArray::IntArray(int length) :
    m_length{ length }
{
    if (length <= 0)
        throw bad_length();

    if (length > 0)
        m_data = new int[length] {};
}

IntArray::~IntArray() noexcept
{
    delete[] m_data;
}

IntArray::IntArray(const IntArray& a)
{
    reallocate(a.getLength());
    std::copy_n(a.m_data, m_length, m_data);
}

IntArray& IntArray::operator=(const IntArray& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());
    std::copy_n(a.m_data, m_length, m_data);

    return *this;
}

void IntArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](int index) 
{
    if (index < 0 || index >= m_length) 
    {
        std::cout << "Index out of range" << std::endl;
        throw bad_range();
    }

    return m_data[index];
}


void IntArray::reallocate(int newLength)
{
    erase();

    if (newLength <= 0)
        return;

    m_data = new int[newLength];
    m_length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }
     
    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        std::copy_n(m_data, elementsToCopy, data);
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)
    {
        std::cout << "insertBefore ERROR" << std::endl;
        throw bad_range();
    }

    int* data{ new int[m_length + 1] };

    std::copy_n(m_data, index, data);

    data[index] = value;

    std::copy_n(m_data + index, m_length - index, data + index + 1);

    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index)
{
    if (index < 0 || index >= m_length)
    {
        std::cout << "remove ERROR" << std::endl;
        throw bad_length();
    }

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };

    std::copy_n(m_data, index, data);

    std::copy_n(m_data + index + 1, m_length - index - 1, data + index);

    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntArray::insertAtBeginning(int value) { insertBefore(value, 0); }
void IntArray::insertAtEnd(int value) { insertBefore(value, m_length); }

int IntArray::getLength() const { return m_length; }