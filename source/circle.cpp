//circle.cpp (programmiersprache-aufgabenblatt-2)

#include "circle.hpp"

//Constructor
Circle::Circle (float radius):
	radius_{radius}
	{}
Circle::Circle ():
	radius_{1}
	{}

float Circle::getRadius() const
{
	return radius_;
}

void Circle::setRadius(float r)
{
	radius_ = r;
}

bool Circle::operator < (Circle const& c)
{
	return radius_ < c.getRadius();
}

bool Circle::operator == (Circle const& c)
{
	return radius_ == c.getRadius();
}

bool Circle::operator > (Circle const& c)
{
	return radius_ > c.getRadius();
}

/*
bool operator < (Circle const& c1,Circle const& c2)
{
	return c1.getRadius() < c2.getRadius();
}

bool operator == (Circle const& c1,Circle const& c2)
{
	return c1.getRadius() == c2.getRadius();
}

bool operator > (Circle const& c1,Circle const& c2)
{
	return c1.getRadius() > c2.getRadius();
}
*/