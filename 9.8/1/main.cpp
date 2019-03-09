#include <iostream>
#include <string>
#include <vector>


struct StudentGrade
{
    std::string name;
    char grade;
};

class GradeMap
{
    std::vector<StudentGrade> m_map;
public:
    GradeMap()
    {
    }
    char& operator[](const std::string name);
};

char& GradeMap::operator[](const std::string name)
{
    for (auto &ref : m_map)
        if (name == ref.name)
            return ref.grade;
    StudentGrade sg {name, ' '};
    m_map.push_back(sg);
    return (m_map.back()).grade;

}

#include <iostream>

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
