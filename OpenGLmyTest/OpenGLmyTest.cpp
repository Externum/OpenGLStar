#include "stdafx.h"
#include <stdlib.h>
#include <glut.h>


/* начальная ширина и высота окна */
GLint Width = 512, Height = 512;

float angleX = 0;
float angleY = 0;

void Display(void);
void Reshape(GLint w, GLint h);
void Keyboard(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void rotate(float x, float y);

/* Главный цикл приложения */
void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Star");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(Display);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
}

/* эта функция управляет всем выводом на экран */
void Display(void)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	int mid = 0;
	int top = 384;
	int rear = 64;
	int z = 60;
	int topSmall = 240;

	glPushMatrix();

	rotate(angleX, angleY);
			
	//малая лицевая сторона

	glColor3ub(185, 190, 200); //серый

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(-topSmall, topSmall, mid); //вершина
	glVertex3d(-rear, mid, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(topSmall, topSmall, mid); //вершина
	glVertex3d(mid, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний левый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(-topSmall, -topSmall, mid); //вершина
	glVertex3d(mid, -rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(topSmall, -topSmall, mid); //вершина
	glVertex3d(mid, rear, mid); //бок
	glEnd();

		
	glColor3ub(255, 255, 255); //белый

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(-topSmall, topSmall, mid); //вершина
	glVertex3d(mid, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(topSmall, topSmall, mid); //вершина
	glVertex3d(rear, mid, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний левый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(-topSmall, -topSmall, mid); //вершина
	glVertex3d(-rear, mid, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(topSmall, -topSmall, mid); //вершина
	glVertex3d(mid, -rear, mid); //бок
	glEnd();


	//малая задняя сторона

	glColor3ub(140, 190, 200);

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(-topSmall, topSmall, mid); //вершина
	glVertex3d(-rear, mid, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний правый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(topSmall, topSmall, mid); //вершина
	glVertex3d(mid, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(-topSmall, -topSmall, mid); //вершина
	glVertex3d(mid, -rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний правый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(topSmall, -topSmall, mid); //вершина
	glVertex3d(mid, rear, mid); //бок
	glEnd();

	glColor3ub(0, 100, 100);

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(-topSmall, topSmall, mid); //вершина
	glVertex3d(mid, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний правый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(topSmall, topSmall, mid); //вершина
	glVertex3d(rear, mid, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(-topSmall, -topSmall, mid); //вершина
	glVertex3d(-rear, mid, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(topSmall, -topSmall, mid); //вершина
	glVertex3d(mid, -rear, mid); //бок
	glEnd();

	//лицевая сторона

	glColor3ub(185, 190, 200);

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(mid, top, mid); //вершина
	glVertex3d(-rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); // средний левый нижний
	glVertex3d(mid, mid, z); //начало
	glVertex3d(-top, mid, mid); //вершина
	glVertex3d(-rear, -rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //средний верхний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(top, mid, mid); //вершина
	glVertex3d(rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(mid, -top, mid); //вершина
	glVertex3d(rear, -rear, mid); //бок
	glEnd();

	glColor3ub(255, 255, 255);

	glBegin(GL_TRIANGLES); //верхний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(mid, top, mid); //вершина
	glVertex3d(rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //средний левый верхний
	glVertex3d(mid, mid, z); //начало
	glVertex3d(-top, mid, mid); //вершина
	glVertex3d(-rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //средний нижний правый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(top, mid, mid); //вершина
	glVertex3d(rear, -rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний левый
	glVertex3d(mid, mid, z); //начало
	glVertex3d(mid, -top, mid); //вершина
	glVertex3d(-rear, -rear, mid); //бок
	glEnd();

	//задняя сторона

	glColor3ub(140, 190, 200);

	glBegin(GL_TRIANGLES); //верхний левый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(mid, top, mid); //вершина
	glVertex3d(-rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); // средний левый нижний
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(-top, mid, mid); //вершина
	glVertex3d(-rear, -rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //средний верхний правый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(top, mid, mid); //вершина
	glVertex3d(rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний правый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(mid, -top, mid); //вершина
	glVertex3d(rear, -rear, mid); //бок
	glEnd();

	glColor3ub(0, 100, 100);

	glBegin(GL_TRIANGLES); //верхний правый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(mid, top, mid); //вершина
	glVertex3d(rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //средний левый верхний
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(-top, mid, mid); //вершина
	glVertex3d(-rear, rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //средний нижний правый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(top, mid, mid); //вершина
	glVertex3d(rear, -rear, mid); //бок
	glEnd();

	glBegin(GL_TRIANGLES); //нижний левый
	glVertex3d(mid, mid, -z); //начало
	glVertex3d(mid, -top, mid); //вершина
	glVertex3d(-rear, -rear, mid); //бок
	glEnd();

	glutSwapBuffers();
	glPopMatrix();
	
	glFinish();
}
/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;
	/* устанавливаем размеры области отображения */
	glViewport(0, 0, w, h);
	/* ортографическая проекция */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w, w, -h, h, -400, 400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	

}
/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'
	if (key == ESCAPE)
		exit(0);
}


void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		angleY -= 1;
		break;

	case GLUT_KEY_UP:
		angleX -= 1;
		break;

	case GLUT_KEY_RIGHT:
		angleY += 1;
		break;

	case GLUT_KEY_DOWN:
		angleX += 1;
		break;
	}
}

void rotate(float x, float y)
{
	glRotated(y, 0.0, 1.0, 0.0);
	glRotated(x, 1.0, 0.0, 0.0);
}