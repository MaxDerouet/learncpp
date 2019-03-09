#include <iostream>

class IntPair
{
public:
    int m_v1;
    int m_v2;

    void set(int firstValue, int secondValue)
    {
        m_v1=firstValue;
        m_v2=secondValue;
    }
    void print()
    {
        std::cout << "Pair(" << m_v1 << "," << m_v2 << ")\n";
    }
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}
