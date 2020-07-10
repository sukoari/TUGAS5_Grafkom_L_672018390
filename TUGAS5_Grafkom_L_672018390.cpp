#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
const double PI = 3.141592653589793;
int i;

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Suko Aribowo - 672018390");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.5, 1.0, 0.0, 0.0);
    //GLfloat light_position0[] = { 100.0,100.0,-350.0,0.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}
void jalan_rumah()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-30, -9.9, 70.0);
    glVertex3f(30, -9.9, 70.0);
    glVertex3f(30, -9.9, 30.1);
    glVertex3f(-30, -9.9, 30.1);
    glEnd();
    glPopMatrix();
}
void rumah()
{
    glPushMatrix();
    //depan
	glBegin(GL_QUADS);
	glColor3f(235, 0, 0);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glEnd();

	//jendela depan
	glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.0, -5.0, 10.001);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, 0.0, 10.001);
	glColor3f(255, 215, 0);
	glVertex3f(-4.0, 0.0, 10.001);
	glColor3f(255, 215, 0);
	glVertex3f(-4.0, -5.0, 10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.0, -5.0, 9.999);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, 0.0, 9.999);
	glColor3f(255, 215, 0);
	glVertex3f(-4.0, 0.0, 9.999);
	glColor3f(255, 215, 0);
	glVertex3f(-4.0, -5.0, 9.999);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(-9.0, -5.0, 0.0f);
	glVertex3f(9.0, -5.0, 10.001);
	glColor3f(1, 1, 1);
	glVertex3f(9.0, 0.0, 10.001);
	glColor3f(255, 215, 0);
	glVertex3f(4.0, 0.0, 10.001);
	glColor3f(255, 215, 0);
	glVertex3f(4.0, -5.0, 10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(9.0, -5.0, 9.999);
	glVertex3f(9.0, 0.0, 9.999);
	glVertex3f(4.0, 0.0, 9.999);
	glVertex3f(4.0, -5.0, 9.999);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-2.0, -5.5, 9.998);
	glVertex3f(-2.0, -5.0, 9.998);
	glVertex3f(-1.8, -5.0, 9.998);
	glVertex3f(-1.8, -5.5, 9.998);
	glEnd();

	//atap depan
	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.5, 0.0);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(0.0, 15.0, 10.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.5, 0);
	glVertex3f(-10.0, 5.0, 9.999);
	glVertex3f(10.0, 5.0, 9.999);
	glVertex3f(0.0, 15.0, 9.999);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glColor3f(0.2, 0.5, 0);
	glVertex3f(-10.0, -10.0, -10.0);
	glVertex3f(-10.0, 5.0, -10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glEnd();

	//jendela belakang
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.0, -5.0, -10.001);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, 0.0, -10.001);
	glColor3f(255, 215, 0);
	glVertex3f(-4.0, 0.0, -10.001);
    glColor3f(255, 215, 0);
	glVertex3f(-4.0, -5.0, -10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, -5.0, -9.999);
	glVertex3f(-9.0, 0.0, -9.999);
	glVertex3f(-4.0, 0.0, -9.999);
	glVertex3f(-4.0, -5.0, -9.999);
	glEnd();

	//atap belakang
	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.3, 0.3);
	glVertex3f(-10.0, 5.0, -10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glVertex3f(0.0, 15.0, -10.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.1, 0);
	glVertex3f(-10.0, 5.0, -9.999);
	glVertex3f(10.0, 5.0, -9.999);
	glVertex3f(0.0, 15.0, -9.999);
	glEnd();

	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.6, 0.3);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.6, 0.3);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(-10.0, -10.0, -10.0);
	glVertex3f(-10.0, 5.0, -10.0);
	glEnd();

	//genteng
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.3, 0.3);
	glVertex3f(0.0, 15.0, 10.0);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glVertex3f(0.0, 15.0, -10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(0.0, 15.0, 10.0);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(-10.0, 5.0, -10.0);
	glVertex3f(0.0, 15.0, -10.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glVertex3f(-10.0, -10.0, -10.0);
	glEnd();


    //lantai
    glBegin(GL_QUADS);
    glColor3ub(211, 211, 211);
    glVertex3f(-10, -9.9, 10.0);
    glVertex3f(10, -9.9, 10.0);
    glVertex3f(10, -9.9, -10.0);
    glVertex3f(-10, -9.9, -10.0);
    glEnd();

    //jalan
    glBegin(GL_QUADS);
    glColor3ub(191, 199, 193);
    glVertex3f(-5, -9.9, 30.0);
    glVertex3f(5, -9.9, 30.0);
    glVertex3f(5, -9.9, -5.0);
    glVertex3f(-5, -9.9, -5.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(81, 214, 28);
    glVertex3f(-30, -10.0, 50.0);
    glVertex3f(30, -10.0, 50.0);
    glVertex3f(30, -10.0, -52.0);
    glVertex3f(-30, -10.0, -52.0);
    glEnd();

    //kursi
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(6.0, -9.0, 3);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(6.0, -9.0, 0);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(9.0, -9.0, 3);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(9.0, -9.0, 0);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.5, 1.0, 0.5);
	glTranslatef(7, -8.0, 1.5);
	glScalef(40, 1, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.5, 1.0, 0.5);
	glTranslatef(9, -6.0, 1.5);
	glScalef(1, 40, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	//lemari
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(6.9, -5.8, -7.9);
	glScalef(60, 80, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0, 0);
	glTranslatef(8, -6, -6);
	glScalef(4, 4, 4);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0, 0);
	glTranslatef(7, -5.8, -5.9);
	glScalef(1, 80, 1);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0, 0);
	glTranslatef(6, -6, -6);
	glScalef(4, 4, 4);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	//kasur
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 1.0, 0.5);
	glTranslatef(-6.9, -9.4, -4.7);
	glScalef(60, 10, 100);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	glTranslatef(-6.6, -8.5, -7.5);
	glScalef(30, 3, 20);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 0);
	glTranslatef(-6.9, -8.85, -3);
	glScalef(58, 2, 60);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	//rak dinding
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0, 0.3, 0);
	glTranslatef(-9.3, 0, 0);
	glScalef(10, 2, 80);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

    glPopMatrix();
}
void pintu()
{
//pintu depan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.1, 0);
	glVertex3f(-2.5, -10.0, 10.001);
	glVertex3f(-2.5, 0.0, 10.001);
	glVertex3f(2.5, 0.0, 10.001);
	glVertex3f(2.5, -10.0, 10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.1, 0);
	glVertex3f(-2.5, -10.0, 9.999);
	glVertex3f(-2.5, 0.0, 9.999);
	glVertex3f(2.5, 0.0, 9.999);
	glVertex3f(2.5, -10.0, 9.999);
	glEnd();

	//pegangan pintu
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-2.0, -5.5, 10.002);
	glVertex3f(-2.0, -5.0, 10.002);
	glVertex3f(-1.8, -5.0, 10.002);
	glVertex3f(-1.8, -5.5, 10.002);
	glEnd();
}
void tampil(void)
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 0, 1, 0);
    glRotatef(yrot, 1, 0, 0);
    rumah();
    pintu();
    jalan_rumah();
    glEnd();
    glPopMatrix();
    glutSwapBuffers();

}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(3.0, 0.0, 0.0);
        break;

	case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
	case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6'://putar kanan
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4'://putar kiri
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();

}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = xrot = x;
        ydiff = yrot = y;
    }
    else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        xrot = x;
        yrot = y;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
