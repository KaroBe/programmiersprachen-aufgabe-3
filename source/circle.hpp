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

	bool operator < (Circle const& c);
	bool operator == (Circle const& c);
	bool operator > (Circle const& c);


private:
	float radius_;
};
/*
//Operatoren
bool operator < (Circle const& c1,Circle const& c2);
bool operator == (Circle const& c1,Circle const& c2);
bool operator > (Circle const& c1,Circle const& c2);
*/

#endif