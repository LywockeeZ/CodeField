#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
GLfloat d = 0.1;
GLfloat translateX = 0, translateY = 0;
int halfLength = 20;
GLfloat ratio;
class Point{
public:
    GLfloat x, y, z;
    Point(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
typedef Point Color;
int renderMode = 1;
GLfloat light_position[]={1.0,1.0,1.0,0.0};
GLfloat blackColor[]={0.0,0.0,0.0,1.0};
GLfloat greyColor[] = {0.5, 0.5, 0.5, 1.0};
GLfloat whiteColor[]={1.0,1.0,1.0,1.0};
GLfloat redColor[]={1.0,0.0,0.0,1.0};
 
GLfloat no_mat[] ={0.0,0.0,0.0,1.0};
GLfloat mat_ambient[] = {0.7,0.7,0.7,1.0};
GLfloat mat_diffuse[] = {0.1,0.5,0.8,1.0};
GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
GLfloat no_shininess[] = {0.0};
GLfloat low_shininess[] = {5.0};
GLfloat high_shininess[] = {100.0};
void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //远光源照射
 
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
 
    //启用光照
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    //局部光源照射
//    GLfloat light_position1[] = {2.0,0.0,3.0,1.0};
//    glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT1);
 
    glEnable(GL_DEPTH_TEST);
}
void drawCoord(){
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(-halfLength, 0.0);
    glVertex2f(halfLength, 0.0);
    glVertex2f(0.0, -halfLength);
    glVertex2f(0.0, halfLength);
    glEnd();
}
void changeSize(GLsizei w, GLsizei h){
    glViewport(0.0, 0.0, w, h);
    if(h == 0)
        h = 1;
    ratio = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w < h)
        glOrtho(-halfLength, halfLength, -halfLength / ratio, halfLength /ratio, -halfLength, halfLength);
//        glFrustum(-halfLength, halfLength, -halfLength / ratio, halfLength /ratio, -10 * halfLength, 0.0);
    else
        glOrtho(-halfLength * ratio, halfLength * ratio, -halfLength, halfLength, -halfLength, halfLength);
//        glFrustum(-halfLength * ratio, halfLength * ratio, -halfLength, halfLength, -10 * halfLength, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    switch (renderMode){
        case 1:
        case 2:
            glDisable(GL_LIGHTING);
            break;
        case 3:
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, no_mat);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, no_mat);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, no_shininess);
//            glLightfv(GL_LIGHT0,GL_DIFFUSE,whiteColor);
            break;
        case 4:
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, no_mat);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, no_shininess);
//            glLightfv(GL_LIGHT0,GL_SPECULAR,whiteColor);;
        case 5:
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_shininess);
            break;
        case 6:
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);
        default:;
 
 
 
    }
    glColor3f(1.0, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0.0, -5.0);
    //glRotatef(15.0, 1.0, 1.0, 1.0);
    printf("renderMode = %d\n", renderMode);
    if(renderMode == 1)
        glutWireTeapot(7.0);
    else
        glutSolidTeapot(7.0);
    glFlush();
}
void keyboardFunc(unsigned char key, int x, int y){
    switch(key){
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            renderMode = key - '0';
            break;
        case 'q':
            exit(0);
        default:;
    }
    glutPostRedisplay();
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("template");
 
    init();
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
 
    return 0;
}
