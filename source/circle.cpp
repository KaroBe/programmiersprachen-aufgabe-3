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

bool Circle::operator < (Circle const& c) const
{
	return radius_ < c.getRadius();
}

bool Circle::operator == (Circle const& c) const
{
	return radius_ == c.getRadius();
}

bool Circle::operator > (Circle const& c) const
{
	return radius_ > c.getRadius();
}

bool Circle::operator <= (Circle const& c) const
{
	return radius_ <= c.getRadius();
}
