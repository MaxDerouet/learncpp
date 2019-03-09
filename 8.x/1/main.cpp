#include <iostream>
#include <cmath>

class Point2d
{
private:
    double m_x;
    double m_y;
public:
    Point2d(double x=0.0, double y=0.0):m_x{x}, m_y{y}
    {
    }
    void print() const;
    double distanceTo(Point2d &point) const;
    friend double distanceFrom(Point2d &firstpoint,Point2d &secondpoint);
};

void Point2d::print() const
{
    std::cout << "Point2d(" << m_x << ", " << m_y << ");\n";
}
double Point2d::distanceTo(Point2d &point) const
{
    return sqrt((m_x - point.m_x)*(m_x - point.m_x) + (m_y - point.m_y)*(m_y - point.m_y));
}

double distanceFrom(Point2d &firstpoint,Point2d &secondpoint)
{
    return sqrt((firstpoint.m_x - secondpoint.m_x)*(firstpoint.m_x - secondpoint.m_x) + (firstpoint.m_y - secondpoint.m_y)*(firstpoint.m_y - secondpoint.m_y));
}

int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}
