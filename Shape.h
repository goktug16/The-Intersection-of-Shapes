#ifndef _SHAPES_H
#define _SHAPES_H


struct Point2d
{
	float x, y;

};
struct Point3d
{
	float r, g, b;

};

class Shape
{
protected:
	bool m_bMarked;
	Point3d m_col;
	Point2d m_veldir;
	Point2d m_pos;
	float m_vel;
public:
	Shape(Point2d& pos, Point2d& veldir, float vel, Point3d& col)
		:m_pos(pos),m_veldir(veldir),m_vel(vel),m_col(col)
	{
		m_bMarked = false;
	 }
	virtual ~Shape() {}
	virtual void draw() = 0;
	virtual bool intersects(Shape*) = 0;
	virtual void drawBbox(Shape* pshape) = 0;
	inline void move() { m_pos.x += m_veldir.x*m_vel; m_pos.y += m_veldir.y*m_vel; }
	inline void invert_xdir() { m_veldir.x *= -1; }
	inline void invert_ydir() { m_veldir.y *= -1; }
	inline void MarkShape() { m_bMarked = true; }
	inline void UnMarkShape() { m_bMarked = false; }
	inline bool isMarked() { return m_bMarked; }
	inline void increase_vel() { m_vel += 0.01f; }
	inline void decrease_vel() { m_vel -= 0.01f; }
	
};


#endif
