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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaGreen1[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaGreen2[] = {0.0, 0.8, 0.0, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaLowAmbient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaFullAmbient[] = {1.0, 1.0, 1.0, 1.0};

	for (int iIndex = 0; iIndex < 2; ++iIndex) {
		if (iIndex == 0) {
			glShadeModel(GL_FLAT);
		} else {
			glShadeModel(GL_SMOOTH);
		}

		//Set, ambient, diffuse and specular lighting. Set ambient to 20%.
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f);
    glRotatef(glrotate, 1.0f, 1.0f, 2.0f);

    glClearColor(0.2,0.2,0.2,0.2);//dark blue

    int i, loop_i;
    double pi = 3.1415926535;

    float temp_sudut1, temp_sudut2;

    int j, loop_j;
    float temp_sudut_lengkung1, temp_sudut_lengkung2;
    float temp_Botol_LL_X, temp_Botol_LL_Y, temp_Botol_LL_Z;

    int k, loop_k;
    float temp_sudut_LA1, temp_sudut_LA2;
    float temp_Botol_LA_X, temp_Botol_LA_Y, temp_Botol_LA_Z;

    temp_sudut1 = 0.0f;
    temp_sudut2 = d_sudut;
    loop_i = (int)(360.0 / d_sudut);

    loop_j = (int)(sudut_LL_botol / d_sudut_LL_botol);
    temp_sudut_lengkung1 = 0.0f;
    temp_sudut_lengkung2 = d_sudut_LL_botol;

    loop_k = (int)(sudut_LA_botol / d_sudut_LA_botol);
    temp_sudut_LA1 = 0.0f;
    temp_sudut_LA2 = d_sudut_LA_botol;

    TK_BT_atas[0].X = 0.0f;
    TK_BT_atas[1].X = 0.0f;

    TK_BT_atas[2].X = d_TK_x;
    TK_BT_atas[3].X = d_TK_x;

    TK_BT_siku[0].X = 0.0f;
    TK_BT_siku[1].X = 0.0f;

    TK_BT_siku[2].X = d_TK_x;
    TK_BT_siku[3].X = d_TK_x;

    TK_BT_samping[0].X = 0.0f;
    TK_BT_samping[1].X = 0.0f;
    TK_BT_samping[2].X = d_TK_x;
    TK_BT_samping[3].X = d_TK_x;

    TK_BT_bawah[0].X = 0.0f;
    TK_BT_bawah[1].X = 0.0f;
    TK_BT_bawah[2].X = d_TK_x;
    TK_BT_bawah[3].X = d_TK_x;

    TK_leher[0].X = 0.0f;
    TK_leher[1].X = 0.0f;

    TK_leher[2].X = d_TK_x;
    TK_leher[3].X = d_TK_x;

    TK_LL[0].X = 0.0f;
    TK_LL[0].Y = awal_TK_LL_y;

    TK_LL[1].X = 0.0f;
    TK_LL[1].Y = awal_TK_LL_y + d_TK_LL_y;

    TK_LL[2].X = d_TK_x;
    TK_LL[2].Y = awal_TK_LL_y + d_TK_LL_y;

    TK_LL[3].X = d_TK_x;
    TK_LL[3].Y = awal_TK_LL_y;

    TK_BS[0].X = 0.0f;
    TK_BS[1].X = 0.0f;

    TK_BS[2].X = d_TK_x;
    TK_BS[3].X = d_TK_x;

    TK_LA[0].X = 0.0f;
    TK_LA[0].Y = awal_TK_LA_y;

    TK_LA[1].X = 0.0f;
    TK_LA[1].Y = awal_TK_LA_y + d_TK_LA_y;

    TK_LA[2].X = d_TK_x;
    TK_LA[2].Y = awal_TK_LA_y + d_TK_LA_y;

    TK_LA[3].X = d_TK_x;
    TK_LA[3].Y = awal_TK_LA_y;

    TK_BA[0].X = 0.0f;
    TK_BA[1].X = 0.0f;
    TK_BA[2].X = d_TK_x;
    TK_BA[3].X = d_TK_x;

    glPushMatrix();
    for (i = 1; i <= loop_i; i++)
    {

        Botol_Tutup[0].VX = awal_tutup_botol[0].VX;
        Botol_Tutup[0].VY = awal_tutup_botol[0].VY;
        Botol_Tutup[0].VZ = awal_tutup_botol[0].VZ;

        Botol_Tutup[1].VX = (awal_tutup_botol[1].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[1].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_Tutup[1].VY = awal_tutup_botol[1].VY;
        Botol_Tutup[1].VZ = (-awal_tutup_botol[1].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[1].VZ  * (float)cos(temp_sudut1 / 180 * pi));

        Botol_Tutup[8].VX = (awal_tutup_botol[1].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[1].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_Tutup[8].VY = awal_tutup_botol[1].VY;
        Botol_Tutup[8].VZ = (-awal_tutup_botol[1].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[1].VZ  * (float)cos(temp_sudut2 / 180 * pi));

        Botol_Tutup[2].VX = (awal_tutup_botol[2].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[2].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_Tutup[2].VY = awal_tutup_botol[2].VY;
        Botol_Tutup[2].VZ = (-awal_tutup_botol[2].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[2].VZ  * (float)cos(temp_sudut1 / 180 * pi));

        Botol_Tutup[7].VX = (awal_tutup_botol[2].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[2].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_Tutup[7].VY = awal_tutup_botol[2].VY;
        Botol_Tutup[7].VZ = (-awal_tutup_botol[2].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[2].VZ  * (float)cos(temp_sudut2 / 180 * pi));
        ///

        Botol_Tutup[3].VX = (awal_tutup_botol[3].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[3].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_Tutup[3].VY = awal_tutup_botol[3].VY;
        Botol_Tutup[3].VZ = (-awal_tutup_botol[3].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[3].VZ  * (float)cos(temp_sudut1 / 180 * pi));

        Botol_Tutup[6].VX = (awal_tutup_botol[3].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[3].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_Tutup[6].VY = awal_tutup_botol[3].VY;
        Botol_Tutup[6].VZ = (-awal_tutup_botol[3].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[3].VZ  * (float)cos(temp_sudut2 / 180 * pi));
        //

        Botol_Tutup[4].VX = (awal_tutup_botol[4].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[4].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_Tutup[4].VY = awal_tutup_botol[4].VY;
        Botol_Tutup[4].VZ = (-awal_tutup_botol[4].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_tutup_botol[4].VZ  * (float)cos(temp_sudut1 / 180 * pi));

        Botol_Tutup[5].VX = (awal_tutup_botol[4].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[4].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_Tutup[5].VY = awal_tutup_botol[4].VY;
        Botol_Tutup[5].VZ = (-awal_tutup_botol[4].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_tutup_botol[4].VZ  * (float)cos(temp_sudut2 / 180 * pi));

        glBegin(GL_POLYGON);
        glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
        glTexCoord2f(TK_BT_atas[0].X, TK_BT_atas[0].Y);
        glVertex3f(Botol_Tutup[0].VX, Botol_Tutup[0].VY, Botol_Tutup[0].VZ);

        glTexCoord2f(TK_BT_atas[1].X, TK_BT_atas[1].Y);
        glVertex3f(Botol_Tutup[1].VX, Botol_Tutup[1].VY, Botol_Tutup[1].VZ);

        glTexCoord2f(TK_BT_atas[2].X, TK_BT_atas[2].Y);
        glVertex3f(Botol_Tutup[8].VX, Botol_Tutup[8].VY, Botol_Tutup[8].VZ);

        glTexCoord2f(TK_BT_atas[3].X, TK_BT_atas[3].Y);
        glVertex3f(Botol_Tutup[0].VX, Botol_Tutup[0].VY, Botol_Tutup[0].VZ);
        glEnd();

        glBegin(GL_POLYGON);
        glTexCoord2f(TK_BT_siku[0].X, TK_BT_siku[0].Y);
        glVertex3f(Botol_Tutup[1].VX, Botol_Tutup[1].VY, Botol_Tutup[1].VZ);

        glTexCoord2f(TK_BT_siku[1].X, TK_BT_siku[1].Y);
        glVertex3f(Botol_Tutup[2].VX, Botol_Tutup[2].VY, Botol_Tutup[2].VZ);

        glTexCoord2f(TK_BT_siku[2].X, TK_BT_siku[2].Y);
        glVertex3f(Botol_Tutup[7].VX, Botol_Tutup[7].VY, Botol_Tutup[7].VZ);

        glTexCoord2f(TK_BT_siku[3].X, TK_BT_siku[3].Y);
        glVertex3f(Botol_Tutup[8].VX, Botol_Tutup[8].VY, Botol_Tutup[8].VZ);
        glEnd();

        glBegin(GL_POLYGON);
        glTexCoord2f(TK_BT_samping[0].X, TK_BT_samping[0].Y);
        glVertex3f(Botol_Tutup[2].VX, Botol_Tutup[2].VY, Botol_Tutup[2].VZ);

        glTexCoord2f(TK_BT_samping[1].X, TK_BT_samping[1].Y);
        glVertex3f(Botol_Tutup[3].VX, Botol_Tutup[3].VY, Botol_Tutup[3].VZ);

        glTexCoord2f(TK_BT_samping[2].X, TK_BT_samping[2].Y);
        glVertex3f(Botol_Tutup[6].VX, Botol_Tutup[6].VY, Botol_Tutup[6].VZ);

        glTexCoord2f(TK_BT_samping[3].X, TK_BT_samping[3].Y);
        glVertex3f(Botol_Tutup[7].VX, Botol_Tutup[7].VY, Botol_Tutup[7].VZ);
        glEnd();

        glBegin(GL_POLYGON);
        glTexCoord2f(TK_BT_bawah[0].X, TK_BT_bawah[0].Y);
        glVertex3f(Botol_Tutup[3].VX, Botol_Tutup[3].VY, Botol_Tutup[3].VZ);

        glTexCoord2f(TK_BT_bawah[1].X, TK_BT_bawah[1].Y);
        glVertex3f(Botol_Tutup[4].VX, Botol_Tutup[4].VY, Botol_Tutup[4].VZ);

        glTexCoord2f(TK_BT_bawah[2].X, TK_BT_bawah[2].Y);
        glVertex3f(Botol_Tutup[5].VX, Botol_Tutup[5].VY, Botol_Tutup[5].VZ);

        glTexCoord2f(TK_BT_bawah[3].X, TK_BT_bawah[3].Y);
        glVertex3f(Botol_Tutup[6].VX, Botol_Tutup[6].VY, Botol_Tutup[6].VZ);
        glEnd();


        Botol_Leher[0].VX = (awal_leher_botol[0].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_leher_botol[0].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_Leher[0].VY = awal_leher_botol[0].VY;
        Botol_Leher[0].VZ = (-awal_leher_botol[0].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_leher_botol[0].VZ * (float)cos(temp_sudut1 / 180 * pi));

        Botol_Leher[1].VX = (awal_leher_botol[1].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_leher_botol[1].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_Leher[1].VY = awal_leher_botol[1].VY;
        Botol_Leher[1].VZ = (-awal_leher_botol[1].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_leher_botol[1].VZ  * (float)cos(temp_sudut1 / 180 * pi));

        Botol_Leher[2].VX = (awal_leher_botol[1].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_leher_botol[1].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_Leher[2].VY = awal_leher_botol[1].VY;
        Botol_Leher[2].VZ = (-awal_leher_botol[1].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_leher_botol[1].VZ  * (float)cos(temp_sudut2 / 180 * pi));

        Botol_Leher[3].VX = (awal_leher_botol[0].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_leher_botol[0].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_Leher[3].VY = awal_leher_botol[0].VY;
        Botol_Leher[3].VZ = (-awal_leher_botol[0].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_leher_botol[0].VZ * (float)cos(temp_sudut2 / 180 * pi));

        glBegin(GL_POLYGON);
        glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
        glTexCoord2f(TK_leher[0].X, TK_leher[0].Y);
        glVertex3f(Botol_Leher[0].VX, Botol_Leher[0].VY, Botol_Leher[0].VZ);

        glTexCoord2f(TK_leher[1].X, TK_leher[1].Y);
        glVertex3f(Botol_Leher[1].VX, Botol_Leher[1].VY, Botol_Leher[1].VZ);

        glTexCoord2f(TK_leher[2].X, TK_leher[2].Y);
        glVertex3f(Botol_Leher[2].VX, Botol_Leher[2].VY, Botol_Leher[2].VZ);

        glTexCoord2f(TK_leher[3].X, TK_leher[3].Y);
        glVertex3f(Botol_Leher[3].VX, Botol_Leher[3].VY, Botol_Leher[3].VZ);
        glEnd();

        for (j = 1; j <= loop_j; j++)
        {

            Botol_LL[0].VX = (awal_LL_botol.VX * (float)cos(temp_sudut_lengkung1 / 180 * pi)) + (-awal_LL_botol.VY * (float)sin(temp_sudut_lengkung1 / 180 * pi));
            Botol_LL[0].VY = (awal_LL_botol.VX * (float)sin(temp_sudut_lengkung1 / 180 * pi)) + (awal_LL_botol.VY * (float)cos(temp_sudut_lengkung1 / 180 * pi));
            Botol_LL[0].VZ = awal_LL_botol.VZ;

            Botol_LL[1].VX = (awal_LL_botol.VX * (float)cos(temp_sudut_lengkung2 / 180 * pi)) + (-awal_LL_botol.VY * (float)sin(temp_sudut_lengkung2 / 180 * pi));
            Botol_LL[1].VY = (awal_LL_botol.VX * (float)sin(temp_sudut_lengkung2 / 180 * pi)) + (awal_LL_botol.VY * (float)cos(temp_sudut_lengkung2 / 180 * pi));
            Botol_LL[1].VZ = awal_LL_botol.VZ;

            temp_Botol_LL_X = Botol_LL[0].VX;
            temp_Botol_LL_Y = Botol_LL[0].VY;
            temp_Botol_LL_Z = Botol_LL[0].VZ;

            Botol_LL[0].VX = (temp_Botol_LL_X * (float)cos(temp_sudut1 / 180 * pi)) + (temp_Botol_LL_Z * (float)sin(temp_sudut1 / 180 * pi));
            Botol_LL[0].VY = temp_Botol_LL_Y;
            Botol_LL[0].VZ = (-temp_Botol_LL_X * (float)sin(temp_sudut1 / 180 * pi)) + (temp_Botol_LL_Z * (float)cos(temp_sudut1 / 180 * pi));

            Botol_LL[3].VX = (temp_Botol_LL_X * (float)cos(temp_sudut2 / 180 * pi)) + (temp_Botol_LL_Z * (float)sin(temp_sudut2 / 180 * pi));
            Botol_LL[3].VY = temp_Botol_LL_Y;
            Botol_LL[3].VZ = (-temp_Botol_LL_X * (float)sin(temp_sudut2 / 180 * pi)) + (temp_Botol_LL_Z * (float)cos(temp_sudut2 / 180 * pi));

            temp_Botol_LL_X = Botol_LL[1].VX;
            temp_Botol_LL_Y = Botol_LL[1].VY;
            temp_Botol_LL_Z = Botol_LL[1].VZ;

            Botol_LL[1].VX = (temp_Botol_LL_X * (float)cos(temp_sudut1 / 180 * pi)) + (temp_Botol_LL_Z * (float)sin(temp_sudut1 / 180 * pi));
            Botol_LL[1].VY = temp_Botol_LL_Y;
            Botol_LL[1].VZ = (-temp_Botol_LL_X * (float)sin(temp_sudut1 / 180 * pi)) + (temp_Botol_LL_Z * (float)cos(temp_sudut1 / 180 * pi));

            Botol_LL[2].VX = (temp_Botol_LL_X * (float)cos(temp_sudut2 / 180 * pi)) + (temp_Botol_LL_Z * (float)sin(temp_sudut2 / 180 * pi));
            Botol_LL[2].VY = temp_Botol_LL_Y;
            Botol_LL[2].VZ = (-temp_Botol_LL_X * (float)sin(temp_sudut2 / 180 * pi)) + (temp_Botol_LL_Z * (float)cos(temp_sudut2 / 180 * pi));

            glBegin(GL_POLYGON);
            glTexCoord2f(TK_LL[0].X, TK_LL[0].Y);
            glVertex3f(Botol_LL[0].VX, Botol_LL[0].VY, Botol_LL[0].VZ);

            glTexCoord2f(TK_LL[1].X, TK_LL[1].Y);
            glVertex3f(Botol_LL[1].VX, Botol_LL[1].VY, Botol_LL[1].VZ);

            glTexCoord2f(TK_LL[2].X, TK_LL[2].Y);
            glVertex3f(Botol_LL[2].VX, Botol_LL[2].VY, Botol_LL[2].VZ);

            glTexCoord2f(TK_LL[3].X, TK_LL[3].Y);
            glVertex3f(Botol_LL[3].VX, Botol_LL[3].VY, Botol_LL[3].VZ);
            glEnd();

            temp_sudut_lengkung1 = temp_sudut_lengkung1 + d_sudut_LL_botol;
            temp_sudut_lengkung2 = temp_sudut_lengkung2 + d_sudut_LL_botol;

            TK_LL[0].Y = TK_LL[0].Y + d_TK_LL_y;
            TK_LL[1].Y = TK_LL[1].Y + d_TK_LL_y;
            TK_LL[2].Y = TK_LL[2].Y + d_TK_LL_y;
            TK_LL[3].Y = TK_LL[3].Y + d_TK_LL_y;
        }

        temp_sudut_lengkung1 = 0.0f;
        temp_sudut_lengkung2 = d_sudut_LL_botol;

        Botol_BS[0].VX = (awal_body_botol[0].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_body_botol[0].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_BS[0].VY = awal_body_botol[0].VY;
        Botol_BS[0].VZ = (-awal_body_botol[0].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_body_botol[0].VZ * (float)cos(temp_sudut1 / 180 * pi));

        Botol_BS[1].VX = (awal_body_botol[1].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_body_botol[1].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_BS[1].VY = awal_body_botol[1].VY;
        Botol_BS[1].VZ = (-awal_body_botol[1].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_body_botol[1].VZ  * (float)cos(temp_sudut1 / 180 * pi));

        Botol_BS[2].VX = (awal_body_botol[1].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_body_botol[1].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_BS[2].VY = awal_body_botol[1].VY;
        Botol_BS[2].VZ = (-awal_body_botol[1].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_body_botol[1].VZ  * (float)cos(temp_sudut2 / 180 * pi));

        Botol_BS[3].VX = (awal_body_botol[0].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_body_botol[0].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_BS[3].VY = awal_body_botol[0].VY;
        Botol_BS[3].VZ = (-awal_body_botol[0].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_body_botol[0].VZ * (float)cos(temp_sudut2 / 180 * pi));

        glBegin(GL_POLYGON);
        glTexCoord2f(TK_BS[0].X, TK_BS[0].Y);
        glVertex3f(Botol_BS[0].VX, Botol_BS[0].VY, Botol_BS[0].VZ);

        glTexCoord2f(TK_BS[1].X, TK_BS[1].Y);
        glVertex3f(Botol_BS[1].VX, Botol_BS[1].VY, Botol_BS[1].VZ);

        glTexCoord2f(TK_BS[2].X, TK_BS[2].Y);
        glVertex3f(Botol_BS[2].VX, Botol_BS[2].VY, Botol_BS[2].VZ);

        glTexCoord2f(TK_BS[3].X, TK_BS[3].Y);
        glVertex3f(Botol_BS[3].VX, Botol_BS[3].VY, Botol_BS[3].VZ);
        glEnd();

        for (k = 1; k <= loop_k; k++)
        {
            Botol_LA[0].VX = (awal_LA_botol.VX * (float)cos(temp_sudut_LA1 / 180 * pi)) + (-awal_LA_botol.VY * (float)sin(temp_sudut_LA1 / 180 * pi));
            Botol_LA[0].VY = (awal_LA_botol.VX * (float)sin(temp_sudut_LA1 / 180 * pi)) + (awal_LA_botol.VY * (float)cos(temp_sudut_LA1 / 180 * pi));
            Botol_LA[0].VZ = awal_LA_botol.VZ;

            Botol_LA[1].VX = (awal_LA_botol.VX * (float)cos(temp_sudut_LA2 / 180 * pi)) + (-awal_LA_botol.VY * (float)sin(temp_sudut_LA2 / 180 * pi));
            Botol_LA[1].VY = (awal_LA_botol.VX * (float)sin(temp_sudut_LA2 / 180 * pi)) + (awal_LA_botol.VY * (float)cos(temp_sudut_LA2 / 180 * pi));
            Botol_LA[1].VZ = awal_LA_botol.VZ;

            Botol_LA[0].VX = Botol_LA[0].VX + dxR2;
            Botol_LA[0].VY = Botol_LA[0].VY + dyR2;

            Botol_LA[1].VX = Botol_LA[1].VX + dxR2;
            Botol_LA[1].VY = Botol_LA[1].VY + dyR2;

            temp_Botol_LA_X = Botol_LA[0].VX;
            temp_Botol_LA_Y = Botol_LA[0].VY;
            temp_Botol_LA_Z = Botol_LA[0].VZ;

            Botol_LA[0].VX = (temp_Botol_LA_X * (float)cos(temp_sudut1 / 180 * pi)) + (temp_Botol_LA_Z * (float)sin(temp_sudut1 / 180 * pi));
            Botol_LA[0].VY = temp_Botol_LA_Y;
            Botol_LA[0].VZ = (-temp_Botol_LA_X * (float)sin(temp_sudut1 / 180 * pi)) + (temp_Botol_LA_Z * (float)cos(temp_sudut1 / 180 * pi));

            Botol_LA[3].VX = (temp_Botol_LA_X * (float)cos(temp_sudut2 / 180 * pi)) + (temp_Botol_LA_Z * (float)sin(temp_sudut2 / 180 * pi));
            Botol_LA[3].VY = temp_Botol_LA_Y;
            Botol_LA[3].VZ = (-temp_Botol_LA_X * (float)sin(temp_sudut2 / 180 * pi)) + (temp_Botol_LA_Z * (float)cos(temp_sudut2 / 180 * pi));

            temp_Botol_LA_X = Botol_LA[1].VX;
            temp_Botol_LA_Y = Botol_LA[1].VY;
            temp_Botol_LA_Z = Botol_LA[1].VZ;

            Botol_LA[1].VX = (temp_Botol_LA_X * (float)cos(temp_sudut1 / 180 * pi)) + (temp_Botol_LA_Z * (float)sin(temp_sudut1 / 180 * pi));
            Botol_LA[1].VY = temp_Botol_LA_Y;
            Botol_LA[1].VZ = (-temp_Botol_LA_X * (float)sin(temp_sudut1 / 180 * pi)) + (temp_Botol_LA_Z * (float)cos(temp_sudut1 / 180 * pi));

            Botol_LA[2].VX = (temp_Botol_LA_X * (float)cos(temp_sudut2 / 180 * pi)) + (temp_Botol_LA_Z * (float)sin(temp_sudut2 / 180 * pi));
            Botol_LA[2].VY = temp_Botol_LA_Y;
            Botol_LA[2].VZ = (-temp_Botol_LA_X * (float)sin(temp_sudut2 / 180 * pi)) + (temp_Botol_LA_Z * (float)cos(temp_sudut2 / 180 * pi));

            glBegin(GL_POLYGON);
            glTexCoord2f(TK_LA[0].X, TK_LA[0].Y);
            glVertex3f(Botol_LA[0].VX, Botol_LA[0].VY, Botol_LA[0].VZ);

            glTexCoord2f(TK_LA[1].X, TK_LA[1].Y);
            glVertex3f(Botol_LA[1].VX, Botol_LA[1].VY, Botol_LA[1].VZ);

            glTexCoord2f(TK_LA[2].X, TK_LA[2].Y);
            glVertex3f(Botol_LA[2].VX, Botol_LA[2].VY, Botol_LA[2].VZ);

            glTexCoord2f(TK_LA[3].X, TK_LA[3].Y);
            glVertex3f(Botol_LA[3].VX, Botol_LA[3].VY, Botol_LA[3].VZ);
            glEnd();

            temp_sudut_LA1 = temp_sudut_LA1 + d_sudut_LA_botol;
            temp_sudut_LA2 = temp_sudut_LA2 + d_sudut_LA_botol;

            TK_LA[0].Y = TK_LA[0].Y + d_TK_LA_y;
            TK_LA[1].Y = TK_LA[1].Y + d_TK_LA_y;
            TK_LA[2].Y = TK_LA[2].Y + d_TK_LA_y;
            TK_LA[3].Y = TK_LA[3].Y + d_TK_LA_y;
        }

        temp_sudut_LA1 = 0.0f;
        temp_sudut_LA2 = d_sudut_LA_botol;

        Botol_Alas[0].VX = awal_alas_botol[0].VX;
        Botol_Alas[0].VY = awal_alas_botol[0].VY;
        Botol_Alas[0].VZ = awal_alas_botol[0].VZ;

        Botol_Alas[1].VX = (awal_alas_botol[1].VX * (float)cos(temp_sudut1 / 180 * pi)) + (awal_alas_botol[1].VZ  * (float)sin(temp_sudut1 / 180 * pi));
        Botol_Alas[1].VY = awal_alas_botol[1].VY;
        Botol_Alas[1].VZ = (-awal_alas_botol[1].VX * (float)sin(temp_sudut1 / 180 * pi)) + (awal_alas_botol[1].VZ  * (float)cos(temp_sudut1 / 180 * pi));

        Botol_Alas[2].VX = (awal_alas_botol[1].VX * (float)cos(temp_sudut2 / 180 * pi)) + (awal_alas_botol[1].VZ  * (float)sin(temp_sudut2 / 180 * pi));
        Botol_Alas[2].VY = awal_alas_botol[1].VY;
        Botol_Alas[2].VZ = (-awal_alas_botol[1].VX * (float)sin(temp_sudut2 / 180 * pi)) + (awal_alas_botol[1].VZ  * (float)cos(temp_sudut2 / 180 * pi));

        glBegin(GL_POLYGON);
        glTexCoord2f(TK_BA[0].X, TK_BA[0].Y);
        glVertex3f(Botol_Alas[0].VX, Botol_Alas[0].VY, Botol_Alas[0].VZ);

        glTexCoord2f(TK_BA[1].X, TK_BA[1].Y);
        glVertex3f(Botol_Alas[1].VX, Botol_Alas[1].VY, Botol_Alas[1].VZ);

        glTexCoord2f(TK_BA[2].X, TK_BA[2].Y);
        glVertex3f(Botol_Alas[2].VX, Botol_Alas[2].VY, Botol_Alas[2].VZ);

        glTexCoord2f(TK_BA[3].X, TK_BA[3].Y);
        glVertex3f(Botol_Alas[0].VX, Botol_Alas[0].VY, Botol_Alas[0].VZ);
        glEnd();

        temp_sudut1 = temp_sudut1 + d_sudut;
        temp_sudut2 = temp_sudut2 + d_sudut;

        TK_BT_atas[0].X = TK_BT_atas[0].X + d_TK_x;
        TK_BT_atas[1].X = TK_BT_atas[1].X + d_TK_x;

        TK_BT_atas[2].X = TK_BT_atas[2].X + d_TK_x;
        TK_BT_atas[3].X = TK_BT_atas[3].X + d_TK_x;

        TK_BT_siku[0].X = TK_BT_siku[0].X + d_TK_x;
        TK_BT_siku[1].X = TK_BT_siku[1].X + d_TK_x;

        TK_BT_siku[2].X = TK_BT_siku[2].X + d_TK_x;
        TK_BT_siku[3].X = TK_BT_siku[3].X + d_TK_x;

        TK_BT_samping[0].X = TK_BT_samping[0].X + d_TK_x;
        TK_BT_samping[1].X = TK_BT_samping[1].X + d_TK_x;
        TK_BT_samping[2].X = TK_BT_samping[2].X + d_TK_x;
        TK_BT_samping[3].X = TK_BT_samping[3].X + d_TK_x;

        TK_BT_bawah[0].X = TK_BT_bawah[0].X + d_TK_x;
        TK_BT_bawah[1].X = TK_BT_bawah[1].X + d_TK_x;
        TK_BT_bawah[2].X = TK_BT_bawah[2].X + d_TK_x;
        TK_BT_bawah[3].X = TK_BT_bawah[3].X + d_TK_x;

        TK_leher[0].X = TK_leher[0].X + d_TK_x;
        TK_leher[1].X = TK_leher[1].X + d_TK_x;

        TK_leher[2].X = TK_leher[2].X + d_TK_x;
        TK_leher[3].X = TK_leher[3].X + d_TK_x;

        TK_LL[0].X = TK_LL[0].X + d_TK_x;
        TK_LL[0].Y = awal_TK_LL_y;

        TK_LL[1].X = TK_LL[1].X + d_TK_x;
        TK_LL[1].Y = awal_TK_LL_y + d_TK_LL_y;

        TK_LL[2].X = TK_LL[2].X + d_TK_x;
        TK_LL[2].Y = awal_TK_LL_y + d_TK_LL_y;

        TK_LL[3].X = TK_LL[3].X + d_TK_x;
        TK_LL[3].Y = awal_TK_LL_y;

        TK_BS[0].X = TK_BS[0].X + d_TK_x;
        TK_BS[1].X = TK_BS[1].X + d_TK_x;

        TK_BS[2].X = TK_BS[2].X + d_TK_x;
        TK_BS[3].X = TK_BS[3].X + d_TK_x;

        TK_LA[0].X = TK_LA[0].X + d_TK_x;
        TK_LA[0].Y = awal_TK_LA_y;

        TK_LA[1].X = TK_LA[1].X + d_TK_x;
        TK_LA[1].Y = awal_TK_LA_y + d_TK_LA_y;

        TK_LA[2].X = TK_LA[2].X + d_TK_x;
        TK_LA[2].Y = awal_TK_LA_y + d_TK_LA_y;

        TK_LA[3].X = TK_LA[3].X + d_TK_x;
        TK_LA[3].Y = awal_TK_LA_y;

        TK_BA[0].X = TK_BA[0].X + d_TK_x;
        TK_BA[1].X = TK_BA[1].X + d_TK_x;
        TK_BA[2].X = TK_BA[2].X + d_TK_x;
        TK_BA[3].X = TK_BA[3].X + d_TK_x;
    }

    glPopMatrix();

    glrotate -= 0.15f;
    glutSwapBuffers();
}
}

void Initialize() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.4, 0.4, 0.4, 1};
	GLfloat qaDiffuseLight[]	= {0.6, 0.6, 0.6, 1};
	GLfloat qaSpecularLight[]	= {0.8, 0.8, 0.8, 1};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[]	= {0.0, 1.0, -.5, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
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
    Initialize();
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
