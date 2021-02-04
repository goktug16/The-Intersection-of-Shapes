#include "Circle.h"
#include <cmath>
#include <iostream>
#include<GL/glut.h>
#include "Rectangle.h"

void Circ::draw()
{
	// Do NOT modify this function
	if (m_bMarked)
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	else
		glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);


	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < 50; i++)
	{
		float theta = i * (2.0f * (float)3.14159 / 50);
		float x = m_rad * cos(theta);
		float y = m_rad * sin(theta);
		glVertex2f(x + m_pos.x, y + m_pos.y);
	}
	glEnd();

}
void Circ::drawBbox(Shape* pshape)
{	
	float leftBottomx, leftBottomy, rightUpperx, rightUppery;

	if(this->intersects(pshape))
	{
		Circ * temp = static_cast<Circ *>(pshape);

		leftBottomx = this->m_pos.x-this->m_rad <= temp->m_pos.x - temp->m_rad ? this->m_pos.x - this->m_rad : temp->m_pos.x - temp->m_rad;
		leftBottomy = this->m_pos.y-this->m_rad <= temp->m_pos.y-temp->m_rad ? this->m_pos.y - this->m_rad : temp->m_pos.y - temp->m_rad;
		rightUpperx = this->m_pos.x+this->m_rad  >= temp->m_pos.x+temp->m_rad ? this->m_pos.x + this->m_rad : temp->m_pos.x + temp->m_rad;
		rightUppery = this->m_pos.y+this->m_rad >= temp->m_pos.y+temp->m_rad  ? this->m_pos.y + this->m_rad : temp->m_pos.y + temp->m_rad;
	}	

	//Do NOT change this part
	glColor3f(0.0,0.0,1.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(leftBottomx,leftBottomy);
	glVertex2f(rightUpperx,leftBottomy);
	glVertex2f(rightUpperx,rightUppery);
	glVertex2f(leftBottomx,rightUppery);
	glEnd();			
}
bool Circ::intersects(Shape* pshape)
{
	Circ*temp=static_cast<Circ*>(pshape); 
	Point2d c= temp->getPos();
	Point2d s = this->getPos(); 
	double a= pow(s.x-c.x,2)+pow(s.y-c.y,2);
	double dist= sqrt(a);
	if(dist< temp->m_rad + m_rad)
	{
		return true;
	}
	return false;
}
