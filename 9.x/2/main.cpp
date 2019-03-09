#include <iostream>
#include <cassert>

class Average
{
    int32_t m_sum;
    int8_t m_count;
public:
    Average(int32_t sum=0, int8_t count=0):m_sum(sum), m_count(count)
    {
    }
    Average& operator=(Average &average);
    friend std::ostream& operator<<(std::ostream &out, const Average &average);
    Average& operator+=(int number);
    friend bool operator==(const Average &a1, const Average &a2);
};

Average& Average::operator=(Average &average)
{
    if(*this==average)
        return *this;
    else
    {
        m_sum=average.m_sum;
        m_count=average.m_count;
    }
}

std::ostream& operator<<(std::ostream &out, const Average &average)
{
    assert(average.m_count!=0 && "m_count is 0; you can't divide by 0");
    out << static_cast<double>(average.m_sum)/average.m_count;
    return out;
}

Average& Average::operator+=(int number)
{
    m_sum+=number;
    ++m_count;
    return *this;
}

bool operator==(const Average &a1, const Average &a2)
{
    return ((a1.m_sum == a2.m_sum) && (a1.m_count == a2.m_count));
}

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}
