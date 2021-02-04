#include "Rectangle.h"
#include <iostream>
#include <GL/glut.h>
#include "Circle.h"
#include <cmath>
#include <string>
void Rect::draw()
{
	if (m_bMarked)
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	else
		glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);
	glRectf(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y);
}

void Rect::drawBbox(Shape *pshape)
{

	float leftBottomx, leftBottomy, rightUpperx, rightUppery;
	if(this->intersects(pshape))
	{
		Rect * temp = static_cast<Rect *>(pshape); 

		leftBottomx = this->m_pos.x > temp->m_pos.x ? temp->m_pos.x : this->m_pos.x;
		leftBottomy = this->m_pos.y > temp->m_pos.y ? temp->m_pos.y : this->m_pos.y;
		rightUpperx= this->m_pos.x + this->m_size.x > temp->m_pos.x + temp->m_size.x ? this->m_pos.x + this->m_size.x : temp->m_pos.x + temp->m_size.x;
		rightUppery = this->m_pos.y + this->m_size.y > temp->m_pos.y + temp->m_size.y ? this->m_pos.y + this->m_size.y : temp->m_pos.y + temp->m_size.y;
	}

	//Do NOT change this part
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(leftBottomx,leftBottomy);
	glVertex2f(rightUpperx,leftBottomy);
	glVertex2f(rightUpperx,rightUppery);
	glVertex2f(leftBottomx,rightUppery);
	glEnd();
}

bool Rect::intersects(Shape *pshape)
{
	if (Rect *temp = dynamic_cast<Rect *>(pshape))
	{
		Point2d leftbottom, rightupper;
		float bounding_w,bounding_h;
		leftbottom.x =  this->m_pos.x > temp->m_pos.x ? temp->m_pos.x : this->m_pos.x;
		leftbottom.y = this->m_pos.y > temp->m_pos.y ? temp->m_pos.y : this->m_pos.y;
		rightupper.x = this->m_pos.x + this->m_size.x > temp->m_pos.x + temp->m_size.x ? this->m_pos.x + this->m_size.x : temp->m_pos.x + temp->m_size.x; 
		rightupper.y = this->m_pos.y + this->m_size.y > temp->m_pos.y + temp->m_size.y ? this->m_pos.y + this->m_size.y : temp->m_pos.y + temp->m_size.y;
		
		bounding_w= rightupper.x - leftbottom.x; 
		bounding_h= rightupper.y - leftbottom.y;
		
		if(this->m_size.x + temp->m_size.x >= bounding_w  && this->m_size.y + temp->m_size.y >= bounding_h)
			return true;
		
	}
	return false;
}
