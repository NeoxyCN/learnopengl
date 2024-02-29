#include "GL/freeglut.h"

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_FILL); // ��������Ϊ���ģʽ
	glPolygonMode(GL_BACK, GL_LINE); // ���÷���Ϊ����ģʽ
	glFrontFace(GL_CCW); // ������ʱ�뷽��Ϊ����
	glBegin(GL_POLYGON); // ����ʱ�����һ�������Σ������·�
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON); // ��˳ʱ�����һ�������Σ������Ϸ�
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, 0.0f);
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	//��ʼ��glut
	glutInit(&argc, argv);
	//��ʾ��ʽ
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	//��������Ļ��λ��
	glutInitWindowPosition(100, 100);
	//���ڴ�С
	glutInitWindowSize(400, 400);
	//���ñ���
	glutCreateWindow("title");
	//��ͼʱ����
	glutDisplayFunc(&myDisplay);
	//����ѭ��
	glutMainLoop();
	return 0;
}