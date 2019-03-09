#include <iostream>
#include <cassert>

class IntArray
{
    int m_length=0;
    int *m_array=nullptr;
public:
    IntArray(int length=0):m_length(length)
    {
        m_array = new int[m_length];
    }
    IntArray(const IntArray &array):m_length(array.m_length)
    {
        delete m_array;
        m_array = new int[m_length];
        for (int index=0; index<m_length; ++index)
            m_array[index]=array.m_array[index];
    }
    ~IntArray()
    {
        delete[] m_array;
    }
    int& operator[](const int index);
    friend std::ostream& operator<<(std::ostream &out, const IntArray &array);
    friend bool operator==(const IntArray &a1, const IntArray &a2);
    IntArray& operator=(const IntArray &array);
};

int& IntArray::operator[](const int index)
{
    assert(index>=0 && index<m_length);
    return m_array[index];
}

std::ostream& operator<<(std::ostream &out, const IntArray &array)
{
    for (int index=0; index<array.m_length; ++index)
        out << array.m_array[index] << " ";
    return out;
}

bool operator==(const IntArray &a1, const IntArray &a2)
{
    if (a1.m_length!=a2.m_length)
        return false;
    else
    {
        for (int index=0; index<a1.m_length; ++index)
        {
            if (a1.m_array[index]!=a1.m_array[index])
                return false;
        }
    }
    return true;
}

IntArray& IntArray::operator=(const IntArray &array)
{
    if(*this==array)
        return *this;
    else
    {
        m_length=array.m_length;
        delete m_array;
        m_array = new int[m_length];
        for (int index=0; index<m_length; ++index)
            m_array[index]=array.m_array[index];
    }
    return *this;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}
