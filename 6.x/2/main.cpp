#include <iostream>
#include <string>
#include <utility>

struct Student
{
    std::string name;
    int grade;
};

int getNumberOfStudents()
{
    while(true)
    {
        std::cout << "How many students do you want to enter? ";
        int numberOfStudents;
        std::cin >> numberOfStudents;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(3333,'\n');
        }
        else
        {
            std::cin.ignore(3333,'\n');
            return numberOfStudents;
        }
    }
}

Student enterStudent()
{
    Student student;
    std::string name;
    int grade;
    while (true)
    {
        std::cout << "Enter the student's name: ";
        std::cin >> name;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(3333,'\n');
        }
        else
        {
            std::cin.ignore(3333,'\n');
            break;
        }
    }
    while(true)
    {
        std::cout << "Enter the student's grade (0-100): ";
        std::cin >> grade;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(3333,'\n');
        }
        else
        {
            std::cin.ignore(3333,'\n');
            if (0<=grade && grade<=100)
                break;
        }
    }
    student.name=name;
    student.grade=grade;
    return student;
}

void printStudents(Student *students, int numberOfStudents)
{
    for (int noCurrentStudent=0; noCurrentStudent < numberOfStudents; ++noCurrentStudent)
        std::cout << students[noCurrentStudent].name << " got a grade of " << students[noCurrentStudent].grade << ".\n";
}

void sortStudents(Student *students, int numberOfStudents) //bubblesort
{
    bool arraySorted(false);
    while (!arraySorted)
    {
        arraySorted=true;
        for (int index=0; index<numberOfStudents-1; ++index)
        {
            if ((students[index]).grade<(students[index+1]).grade)
                {
                    std::swap(students[index],students[index+1]);
                    arraySorted=false;
                }
        }
        --numberOfStudents; // the biggest element of the current subarray is the last element after one iteration
    }
}


int main()
{
    int numberOfStudents(getNumberOfStudents());
    Student *students=new Student[numberOfStudents];
    for (int noCurrentStudent=0; noCurrentStudent<numberOfStudents; ++noCurrentStudent)
    {
        students[noCurrentStudent]=enterStudent();
    }
    sortStudents(students, numberOfStudents);
    printStudents(students, numberOfStudents);
    delete[] students;
    return 0;
}
