#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

class Circ : public Shape
{
	
	float m_rad;
public:
	Circ(Point2d& pos, float r, Point2d& veldir, float vel, Point3d& col)
		:m_rad(r), Shape(pos, veldir, vel, col)
	{}
	inline Point2d getPos() { return m_pos; }
	inline float getRad() { return m_rad; }
	void draw();
	void drawBbox(Shape* pshape);
	bool intersects(Shape* pshape);
};

#endif
