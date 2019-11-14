//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text1, GLuint text2);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void prismaPro(float altura, float largo, float profundidad, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5, GLuint text6);
	void cilindro2(float radio, float altura, int resolucion, GLuint text1, GLuint text2, GLuint text3);
	void cilindro3(float radio, float altura, int resolucion, GLuint text1, GLuint text2, GLuint text3);
	void cilindro4(float radio, float altura, int resolucion, GLuint text1, GLuint text2);
	void prismaPro1(float altura, float largo, float profundidad, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5, GLuint text6);
	void prismaPro2(float altura, float largo, float profundidad, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5, GLuint text6);
	void prismaPro3(float altura, float largo, float profundidad, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5, GLuint text6);
	void prismaPro4(float altura, float largo, float profundidad, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5, GLuint text6);
	void prismaPro5(float altura, float largo, float profundidad, GLuint text1, GLuint text2);
	void prismaPro6(float altura, float largo, float profundidad, GLuint text1, GLuint text2,GLuint text3);
	void prismaPro6x10(float altura, float largo, float profundidad, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5, GLuint text6);
	
};
