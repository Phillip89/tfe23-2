#include <fmt/chrono.h>
#include <fmt/format.h>
#include "config.h" /* Make sure this file exists and defines PROJECT_NAME, PROJECT_VER, PROJECT_BUILD_DATE */
#include "myVector.hpp"

MyVector::MyVector() : data(nullptr), m_size(0)
{
}

MyVector::MyVector(unsigned int size) : m_size(size)
{
    data = new int[size]; // Reserve memory for `data`
}

MyVector::~MyVector()
{
    delete[] data; // Release allocated memory
}

unsigned int MyVector::size() 
{
    return m_size;
}

unsigned int MyVector::get_current_size()
{
    return current_size;
}

void MyVector::resize(int new_elements)
{
    int* new_data = new int[m_size + new_elements];
    for (int i=0; i<m_size; i++)
    {
        new_data[i] = data[i];
    }
    
    m_size += new_elements;
    data = new_data;
}

void MyVector::push_back(int element)
{
    if (current_size < m_size)
    {
        data[current_size] = element;
    }
    else
    {
        resize(m_size);
        data[current_size] = element;
    }
    current_size++;
}

/*void MyVector::push_back(int &element)
{
    if (current_size < m_size)
    {
        data[current_size] = element;
    }
    else
    {
        resize(1);
        data[current_size] = element;
    }
    current_size++;
}

void MyVector::push_back(int* element)
{
    if (current_size < m_size)
    {
        data[current_size] = *element;
    }
    else
    {
        resize(1);
        data[current_size] = *element;
    }
    current_size++;
}*/

int MyVector::at(unsigned int index)
{
    if (index >= 0 && index < current_size)
    {
        return data[index];
    }
    return -1;
}