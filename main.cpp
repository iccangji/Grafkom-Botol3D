#define WIN32_LEAN_AND_MEAN


#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include <gl\freeglut.h>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<mmsystem.h>


/* Global variables */
char title[] = "Objek Botol 3D";
GLfloat anglePyramid = 0.0f;
GLfloat glrotate = 0.0f;
int refreshMills = 15;

float d_sudut, sudut_LL_botol, d_sudut_LL_botol, sudut_LA_botol, d_sudut_LA_botol, dxR2, dyR2, d_TK_x, d_TK_LL_y, awal_TK_LL_y, awal_TK_LA_y, d_TK_LA_y;

typedef struct
{
	float VX,VY,VZ;
}Vertex;

typedef struct
{
	float X,Y;
}TexCoord;

Vertex Botol_Tutup[9],awal_tutup_botol[5], awal_LL_botol , awal_leher_botol[2], awal_body_botol[2], awal_LA_botol, awal_alas_botol[2], Botol_Leher[4], Botol_LL[4], Botol_BS[4], Botol_LA[4], Botol_Alas[3];

TexCoord TK_BT_atas[4], TK_BT_siku[4], TK_BT_samping[4], TK_BT_bawah[4], TK_leher[4], TK_BS[4], TK_BA[4], TK_LL[4], TK_LA[4];

void initGL()
{

	glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Load_Vertex_Botol()
{
    double pi = 3.1415926535;

    d_sudut = 10.0f;

    float lebar_tutup = 0.3f;
    float tinggi_tutup = 0.35f;
    float d_siku_siku = 0.05f;

    float lebar_leher = 0.25f;
    float tinggi_leher = 1.2f;
    float R1 = 0.8f;

    sudut_LL_botol = 55.0f;
    d_sudut_LL_botol = 5.0f;

    float tinggi_body = 1.8f;

    float R2 = 0.3f;
    sudut_LA_botol = 90.0f;
    d_sudut_LA_botol = 10.0f;
    dxR2 = R1 - R2;
    dyR2 = -tinggi_body;

    float JT_tutup_botol;

    float JT, JT_leher, JT_LL, JT_tinggi_body, JT_LA, JT_alas;

    awal_tutup_botol[0].VX = 0.0f;
    awal_tutup_botol[0].VY = tinggi_tutup + tinggi_leher + (R1 * (float)(float)sin(sudut_LL_botol / 180 * pi));
    awal_tutup_botol[0].VZ = 0.0f;

    awal_tutup_botol[1].VX = lebar_tutup - d_siku_siku;
    awal_tutup_botol[1].VY = tinggi_tutup + tinggi_leher + (R1 * (float)sin(sudut_LL_botol / 180 * pi));
    awal_tutup_botol[1].VZ = 0.0f;

    awal_tutup_botol[2].VX = lebar_tutup;
    awal_tutup_botol[2].VY = tinggi_tutup + tinggi_leher + (R1 * (float)sin(sudut_LL_botol / 180 * pi)) - d_siku_siku;
    awal_tutup_botol[2].VZ = 0.0f;

    awal_tutup_botol[3].VX = lebar_tutup;
    awal_tutup_botol[3].VY = tinggi_leher + (R1 * (float)sin(sudut_LL_botol / 180 * pi));
    awal_tutup_botol[3].VZ = 0.0f;

    awal_tutup_botol[4].VX = lebar_leher;
    awal_tutup_botol[4].VY = tinggi_leher + (R1 * (float)sin(sudut_LL_botol / 180 * pi));
    awal_tutup_botol[4].VZ = 0.0f;

    awal_leher_botol[0].VX = lebar_leher;
    awal_leher_botol[0].VY = tinggi_leher + (R1 * (float)sin(sudut_LL_botol / 180 * pi));
    awal_leher_botol[0].VZ = 0.0f;

    awal_leher_botol[1].VX = R1 * (float)cos(sudut_LL_botol / 180 * pi);
    awal_leher_botol[1].VY = R1 * (float)sin(sudut_LL_botol / 180 * pi);
    awal_leher_botol[1].VZ = 0.0f;

    awal_LL_botol.VX = R1;
    awal_LL_botol.VY = 0.0f;
    awal_LL_botol.VZ = 0.0f;

    awal_body_botol[0].VX = R1;
    awal_body_botol[0].VY = 0.0f;
    awal_body_botol[0].VZ = 0.0f;

    awal_body_botol[1].VX = R1;
    awal_body_botol[1].VY = -tinggi_body;
    awal_body_botol[1].VZ = 0.0f;

    awal_LA_botol.VX = 0.0f;
    awal_LA_botol.VY = -R2;
    awal_LA_botol.VZ = 0.0f;

    awal_alas_botol[0].VX = 0.0f;
    awal_alas_botol[0].VY = -(tinggi_body + R2);
    awal_alas_botol[0].VZ = 0.0f;

    awal_alas_botol[1].VX = R1 - R2;
    awal_alas_botol[1].VY = -(tinggi_body + R2);
    awal_alas_botol[1].VZ = 0.0f;

    JT_tutup_botol = (lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f)) + tinggi_tutup + (lebar_tutup - lebar_leher);

    TK_BT_atas[0].Y = 1.0f;

    TK_BT_atas[1].Y = 1.0f - ((lebar_tutup - d_siku_siku) / JT_tutup_botol);

    TK_BT_atas[2].Y = 1.0f - ((lebar_tutup - d_siku_siku) / JT_tutup_botol);

    TK_BT_atas[3].Y = 1.0f;

    TK_BT_siku[0].Y = 1.0f - ((lebar_tutup - d_siku_siku) / JT_tutup_botol);

    TK_BT_siku[1].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f))) / JT_tutup_botol);

    TK_BT_siku[2].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f))) / JT_tutup_botol);

    TK_BT_siku[3].Y = 1.0f - ((lebar_tutup - d_siku_siku) / JT_tutup_botol);

    TK_BT_samping[0].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f))) / JT_tutup_botol);
    TK_BT_samping[1].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f)) + tinggi_tutup) / JT_tutup_botol);
    TK_BT_samping[2].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f)) + tinggi_tutup) / JT_tutup_botol);
    TK_BT_samping[3].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f))) / JT_tutup_botol);

    TK_BT_bawah[0].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f)) + tinggi_tutup) / JT_tutup_botol);
    TK_BT_bawah[1].Y = 0.0f;
    TK_BT_bawah[2].Y = 0.0f;
    TK_BT_bawah[3].Y = 1.0f - (((lebar_tutup - d_siku_siku) + sqrt(2 * pow(d_siku_siku, 2.0f)) + tinggi_tutup) / JT_tutup_botol);

    JT_leher = sqrt(pow((awal_leher_botol[1].VX - awal_leher_botol[0].VX), 2.0f) + pow(tinggi_leher, 2.0f));

    JT_LL = (sudut_LL_botol / d_sudut_LL_botol) * (2.0f * R1 * (float)sin(0.5f * d_sudut_LL_botol / 180.0f * pi));

    JT_tinggi_body = tinggi_body;

    JT_LA = (sudut_LA_botol / d_sudut_LA_botol) * (2.0f * R2 * (float)sin(0.5f * d_sudut_LA_botol / 180.0f * pi));

    JT_alas = R1 - R2;

    JT = JT_leher + JT_LL + JT_tinggi_body + JT_LA + JT_alas;

    d_TK_x = 1.0f / (360.0f / d_sudut);

    TK_leher[0].Y = 1.0f;

    TK_leher[1].Y = 1.0f - (JT_leher / JT);

    TK_leher[2].Y = 1.0f - (JT_leher / JT);

    TK_leher[3].Y = 1.0f;

    d_TK_LL_y = (JT_LL / JT) / (sudut_LL_botol / d_sudut_LL_botol);

    awal_TK_LL_y = 1.0f - ((JT_leher + JT_LL) / JT);

    TK_BS[0].Y = 1.0f - ((JT_leher + JT_LL) / JT);

    TK_BS[1].Y = 1.0f - ((JT_leher + JT_LL + JT_tinggi_body) / JT);

    TK_BS[2].Y = 1.0f - ((JT_leher + JT_LL + JT_tinggi_body) / JT);

    TK_BS[3].Y = 1.0f - ((JT_leher + JT_LL) / JT);

    d_TK_LA_y = (JT_LA / JT) / (sudut_LA_botol / d_sudut_LA_botol);

    float awal_TK_LA_y = 1.0f - ((JT_leher + JT_LL + JT_tinggi_body + JT_LA) / JT);

    TK_BA[0].Y = 0.0f;
    TK_BA[1].Y = 1.0f - ((JT_leher + JT_LL + JT_tinggi_body + JT_LA) / JT);
    TK_BA[2].Y = 1.0f - ((JT_leher + JT_LL + JT_tinggi_body + JT_LA) / JT);
    TK_BA[3].Y = 0.0f;

}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(300, 100); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    Load_Vertex_Botol();
    initGL();                       // Our own OpenGL initialization
    glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
