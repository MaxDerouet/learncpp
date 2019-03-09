#include <iostream>
#include <array>
#include <cassert>

class Stack
{
    std::array<int, 10> m_array;
    int m_length;
public:
    void reset()
    {
        for (auto &element : m_array)
            element=0;
        m_length=0;
    }
    bool push(int element)
    {
        if (m_length>=9)
            return false;
        m_array[m_length]=element;
        ++m_length;
        return true;
    }
    int pop()
    {
        assert((m_length>=0) && "The stack is empty");
        --m_length;
        return m_array[m_length+1];
    }
    void print()
    {
        std::cout << "( ";
        for (int index=0; index<m_length; ++index)
        {
            std::cout << m_array[index] << " ";
        }
        std::cout << ")\n";
    }
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
