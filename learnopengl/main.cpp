#include "GL/freeglut.h"

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_FILL); // 设置正面为填充模式
	glPolygonMode(GL_BACK, GL_LINE); // 设置反面为线形模式
	glFrontFace(GL_CCW); // 设置逆时针方向为正面
	glBegin(GL_POLYGON); // 按逆时针绘制一个正方形，在左下方
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON); // 按顺时针绘制一个正方形，在右上方
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, 0.0f);
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	//初始化glut
	glutInit(&argc, argv);
	//显示方式
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	//窗口在屏幕中位置
	glutInitWindowPosition(100, 100);
	//窗口大小
	glutInitWindowSize(400, 400);
	//设置标题
	glutCreateWindow("title");
	//绘图时调用
	glutDisplayFunc(&myDisplay);
	//窗口循环
	glutMainLoop();
	return 0;
}