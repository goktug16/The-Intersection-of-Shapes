#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Shape.h"

class Rect: public Shape
{	
	Point2d m_size;
public:
	Rect(Point2d& pos, Point2d& size, Point2d& vel_dir, float vel, Point3d& col)
		:m_size(size),Shape(pos,vel_dir,vel,col)
	{}
	inline Point2d getPos() { return m_pos; }
	inline Point2d getSize() { return m_size; }

	void draw();	
	bool intersects(Shape* pshape);
	void drawBbox(Shape* pshape);
	
};
#endif

