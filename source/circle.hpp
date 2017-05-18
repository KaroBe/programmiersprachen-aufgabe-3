//circle.hpp (programmiersprache-aufgabenblatt-2)

#ifndef CIRCLE_HPP
#define CIRCLE_HPP


class Circle
{
public:
	Circle (float radius);
	Circle ();

	float getRadius() const;
	void setRadius(float r);

	bool operator < (Circle const& c) const;
	bool operator == (Circle const& c) const;
	bool operator > (Circle const& c) const;
	bool operator <= (Circle const& c) const;


private:
	float radius_;
};

#endif
