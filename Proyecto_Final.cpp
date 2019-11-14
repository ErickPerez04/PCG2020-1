//Semestre 2020 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	      Bernardo Pérez Erick Guillermo	******//
//************************************************************//
//************************************************************//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

float cteBand = -1, cteBand2 = 0;


GLfloat blanco[] = { 1.0, 1.0, 1.0 };
GLfloat azul[] = { 0.0, 0.0, 1.0 };
GLfloat rojo[] = { 1.0, 0.0, 0.0 };
GLfloat verde[] = { 0.0, 1.0, 0.0 };
GLfloat amarillo[] = { 1.0, 1.0, 0.0 };
GLfloat negro[] = { 0.0, 0.0, 0.0 };

GLfloat posicion[] = { -30.0, 20.0, 0.0, 1.0 };

CFiguras Fig_Jose;


int w = 500, h = 500;
int frame = 0, time, timebase = 0;
int deltaTime = 0;
int t1 = 0, t2 = 0, elapsed, caso = 1;
GLfloat angulo = 0;
float cte1 = 0, cte2 = 0, cte3 = 0, cte4 = 0, moveX = -15, moveZ = 9.8, limite = 0.8, velocidad = 0.011,
		velocidadPies = 21, velBand = 0, moveCombi = -18, limManos = 25, bandManos = 0, tempManos = 0, velManos = 1,
		velNave = 0.1, moveNaveX = (8*(-9.3969262078590838405410927732473)), moveNaveY = (8*(-3.4202014332566873304409961468226));


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW)

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture Aluminio;
CTexture Aire;
CTexture Botiquin;
CTexture Botiquin1;
CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture tree;
CTexture Piso;
CTexture Edificio;
CTexture Azotea;
CTexture Techo_interior;
CTexture Piso_Int_Lab;
CTexture Jardinera;
CTexture Cemento;
CTexture Pasto;
CTexture Vidrio;
CTexture Negro;
CTexture Pizarron;
CTexture Monitor;
CTexture Monitor2;
CTexture Gabinte;
CTexture Gabinte2;
CTexture Gabinte3;
CTexture Teclado;
CTexture Mesa;
CTexture Metal;
CTexture Pared;
CTexture Blanco;
CTexture NoComer;
CTexture NoFumar;
CTexture Vidrio2;
CTexture Vidrio3;
CTexture Proyector;
CTexture Proyector2;
CTexture Proyector3;
CTexture Ventana;
CTexture Sh;
CTexture Ventilacion;
CTexture Pared2;
CTexture Respaldo;
CTexture RespaldoFrente;
CTexture Asiento;
CTexture PisoSalon;
CTexture FilaLadrillos;
CTexture PisoSalonGris;
CTexture LetreroSismo;
CTexture EdificioPuerta;
CTexture Carretera;
CTexture Cruce;
CTexture Banqueta;
CTexture LineaBanqueta;
CTexture Cara;
CTexture CaraLD;
CTexture CaraLI;
CTexture CaraAtras;
CTexture CaraArriba;
CTexture CaraAbajo;
CTexture Cuerpo;
CTexture CuerpoL;
CTexture Brazo;
CTexture Pierna;
CTexture CombiFrente;
CTexture CombiAtras;
CTexture CombiLD;
CTexture CombiLI;

CFiguras sky;


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glDisable(GL_LIGHT0);

	glLightfv(GL_LIGHT1, GL_AMBIENT, negro);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blanco);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, blanco);
	glLightfv(GL_LIGHT1, GL_POSITION, posicion);
	//glEnable(GL_LIGHT0);

	//glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	text1.LoadBMP("Imagenes/sky.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	Ventilacion.LoadBMP("Imagenes/Ventilacion.bmp");
	Ventilacion.BuildGLTexture();
	Ventilacion.ReleaseImage();

	Aire.LoadBMP("Imagenes/Aire.bmp");
	Aire.BuildGLTexture();
	Aire.ReleaseImage();

	text2.LoadBMP("Imagenes/logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	Pared.LoadTGA("Imagenes/Pared.tga");
	Pared.BuildGLTexture();
	Pared.ReleaseImage();

	Pared2.LoadTGA("Imagenes/Pared2.tga");
	Pared2.BuildGLTexture();
	Pared2.ReleaseImage();

	Monitor.LoadBMP("Imagenes/Monitor.bmp");
	Monitor.BuildGLTexture();
	Monitor.ReleaseImage();

	Sh.LoadBMP("Imagenes/Sh.bmp");
	Sh.BuildGLTexture();
	Sh.ReleaseImage();

	Botiquin.LoadBMP("Imagenes/Botiquin.bmp");
	Botiquin.BuildGLTexture();
	Botiquin.ReleaseImage();

	Aluminio.LoadBMP("Imagenes/Aluminio.bmp");
	Aluminio.BuildGLTexture();
	Aluminio.ReleaseImage();

	Botiquin1.LoadBMP("Imagenes/Botiquin1.bmp");
	Botiquin1.BuildGLTexture();
	Botiquin1.ReleaseImage();

	Teclado.LoadBMP("Imagenes/Teclado.bmp");
	Teclado.BuildGLTexture();
	Teclado.ReleaseImage();

	Blanco.LoadBMP("Imagenes/Blanco.bmp");
	Blanco.BuildGLTexture();
	Blanco.ReleaseImage();

	NoComer.LoadBMP("Imagenes/NoComer.bmp");
	NoComer.BuildGLTexture();
	NoComer.ReleaseImage();

	NoFumar.LoadBMP("Imagenes/NoFumar.bmp");
    NoFumar.BuildGLTexture();
	NoFumar.ReleaseImage();

	Ventana.LoadBMP("Imagenes/Ventana.bmp");
	Ventana.BuildGLTexture();
	Ventana.ReleaseImage();

	Monitor2.LoadBMP("Imagenes/Monitor2.bmp");
	Monitor2.BuildGLTexture();
	Monitor2.ReleaseImage();

	Vidrio.LoadTGA("Imagenes/Vidrio.tga");
	Vidrio.BuildGLTexture();
	Vidrio.ReleaseImage();

	Vidrio2.LoadTGA("Imagenes/Vidrio2.tga");
	Vidrio2.BuildGLTexture();
	Vidrio2.ReleaseImage();

	Vidrio3.LoadTGA("Imagenes/Vidrio3.tga");
	Vidrio3.BuildGLTexture();
	Vidrio3.ReleaseImage();

	Cemento.LoadBMP("Imagenes/Cemento.bmp");
	Cemento.BuildGLTexture();
	Cemento.ReleaseImage();

	Pizarron.LoadBMP("Imagenes/Pizarron.bmp");
	Pizarron.BuildGLTexture();
	Pizarron.ReleaseImage();

	Gabinte.LoadBMP("Imagenes/Gabinete.bmp");
	Gabinte.BuildGLTexture();
	Gabinte.ReleaseImage();

	Gabinte2.LoadBMP("Imagenes/Gabinete2.bmp");
	Gabinte2.BuildGLTexture();
	Gabinte2.ReleaseImage();

	Gabinte3.LoadBMP("Imagenes/Gabinete3.bmp");
	Gabinte3.BuildGLTexture();
	Gabinte3.ReleaseImage();

	Proyector.LoadBMP("Imagenes/Proyector.bmp");
	Proyector.BuildGLTexture();
	Proyector.ReleaseImage();

	Proyector2.LoadBMP("Imagenes/Proyector2.bmp");
	Proyector2.BuildGLTexture();
	Proyector2.ReleaseImage();

	Proyector3.LoadBMP("Imagenes/Proyector3.bmp");
	Proyector3.BuildGLTexture();
	Proyector3.ReleaseImage();

	Negro.LoadBMP("Imagenes/Negro.bmp");
	Negro.BuildGLTexture();
	Negro.ReleaseImage();

	Piso.LoadBMP("Imagenes/Piso.bmp");
	Piso.BuildGLTexture();
	Piso.ReleaseImage();

	PisoSalon.LoadTGA("Imagenes/PisoSalon.tga");
	PisoSalon.BuildGLTexture();
	PisoSalon.ReleaseImage();

	PisoSalonGris.LoadTGA("Imagenes/PisoSalonGris.tga");
	PisoSalonGris.BuildGLTexture();
	PisoSalonGris.ReleaseImage();

	FilaLadrillos.LoadTGA("Imagenes/FilaLadrillos.tga");
	FilaLadrillos.BuildGLTexture();
	FilaLadrillos.ReleaseImage();

	Mesa.LoadBMP("Imagenes/Mesa.bmp");
	Mesa.BuildGLTexture();
	Mesa.ReleaseImage();

	Metal.LoadBMP("Imagenes/Metal.bmp");
	Metal.BuildGLTexture();
	Metal.ReleaseImage();

	Piso_Int_Lab.LoadBMP("Imagenes/pisoint.bmp");
	Piso_Int_Lab.BuildGLTexture();
	Piso_Int_Lab.ReleaseImage();

	Edificio.LoadBMP("Imagenes/Torre.bmp");
	Edificio.BuildGLTexture();
	Edificio.ReleaseImage();

	EdificioPuerta.LoadTGA("Imagenes/TorrePuerta.tga");
	EdificioPuerta.BuildGLTexture();
	EdificioPuerta.ReleaseImage();

	Azotea.LoadBMP("Imagenes/Techo.bmp");
	Azotea.BuildGLTexture();
	Azotea.ReleaseImage();

	Techo_interior.LoadBMP("Imagenes/interior.bmp");
	Techo_interior.BuildGLTexture();
	Techo_interior.ReleaseImage();

	Jardinera.LoadBMP("Imagenes/Jardinera.bmp");
	Jardinera.BuildGLTexture();
	Jardinera.ReleaseImage();

	Pasto.LoadBMP("Imagenes/Pasto.bmp");
	Pasto.BuildGLTexture();
	Pasto.ReleaseImage();

	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	Respaldo.LoadTGA("Imagenes/TexturaRespaldo.tga");
	Respaldo.BuildGLTexture();
	Respaldo.ReleaseImage();

	RespaldoFrente.LoadTGA("Imagenes/TexturaFrenteRespaldo.tga");
	RespaldoFrente.BuildGLTexture();
	RespaldoFrente.ReleaseImage();

	Asiento.LoadTGA("Imagenes/TexturaAsiento.tga");
	Asiento.BuildGLTexture();
	Asiento.ReleaseImage();

	LetreroSismo.LoadTGA("Imagenes/LetreroSismo.tga");
	LetreroSismo.BuildGLTexture();
	LetreroSismo.ReleaseImage();

	Carretera.LoadTGA("Imagenes/Carretera.tga");
	Carretera.BuildGLTexture();
	Carretera.ReleaseImage();

	Cruce.LoadTGA("Imagenes/Cruce.tga");
	Cruce.BuildGLTexture();
	Cruce.ReleaseImage();

	Banqueta.LoadTGA("Imagenes/BanquetaLinea.tga");
	Banqueta.BuildGLTexture();
	Banqueta.ReleaseImage();

	LineaBanqueta.LoadTGA("Imagenes/LineadelaBanqueta.tga");
	LineaBanqueta.BuildGLTexture();
	LineaBanqueta.ReleaseImage();

	Cara.LoadTGA("Imagenes/Cara.tga");
	Cara.BuildGLTexture();
	Cara.ReleaseImage();

	CaraLD.LoadTGA("Imagenes/CaraLD.tga");
	CaraLD.BuildGLTexture();
	CaraLD.ReleaseImage();

	CaraLI.LoadTGA("Imagenes/CaraLI.tga");
	CaraLI.BuildGLTexture();
	CaraLI.ReleaseImage();

	CaraAtras.LoadTGA("Imagenes/CaraAtras.tga");
	CaraAtras.BuildGLTexture();
	CaraAtras.ReleaseImage();

	CaraArriba.LoadTGA("Imagenes/CaraArriba.tga");
	CaraArriba.BuildGLTexture();
	CaraArriba.ReleaseImage();

	CaraAbajo.LoadTGA("Imagenes/CaraAbajo.tga");
	CaraAbajo.BuildGLTexture();
	CaraAbajo.ReleaseImage();

	Cuerpo.LoadTGA("Imagenes/Cuerpo.tga");
	Cuerpo.BuildGLTexture();
	Cuerpo.ReleaseImage();

	CuerpoL.LoadTGA("Imagenes/CuerpoL.tga");
	CuerpoL.BuildGLTexture();
	CuerpoL.ReleaseImage();

	Brazo.LoadTGA("Imagenes/Brazo.tga");
	Brazo.BuildGLTexture();
	Brazo.ReleaseImage();

	Pierna.LoadTGA("Imagenes/Pierna.tga");
	Pierna.BuildGLTexture();
	Pierna.ReleaseImage();

	CombiFrente.LoadTGA("Imagenes/CombiFrente.tga");
	CombiFrente.BuildGLTexture();
	CombiFrente.ReleaseImage();

	CombiAtras.LoadTGA("Imagenes/CombiAtras.tga");
	CombiAtras.BuildGLTexture();
	CombiAtras.ReleaseImage();

	CombiLD.LoadTGA("Imagenes/CombiLD.tga");
	CombiLD.BuildGLTexture();
	CombiLD.ReleaseImage();

	CombiLI.LoadTGA("Imagenes/CombiLI.tga");
	CombiLI.BuildGLTexture();
	CombiLI.ReleaseImage();


	//END NEW//////////////////////////////

	objCamera.Position_Camera(0, 0.8f, 30, 0, 0.8f, 0, 0, 1, 0);

}


void display(void)   // Creamos la funcion donde se dibuja
{
	GLfloat bandera[4][3][3] = {
		{{5, 5, 0.0},
		{5, 4.5, 0.0},
		{5, 3, 0.0}},

		{{5.66666666, 5, cteBand},
		{5.66666666, 4.5, cteBand},
		{5.66666666, 3, cteBand}},

		{{6.33333333, 5, -cteBand},
		{6.33333333, 4.5, -cteBand},
		{6.33333333, 3, -cteBand}},

		{{7, 5, 0.0},
		{7, 4.5, 0.0},
		{7, 3, 0.0}} //5
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(g_lookupdown, 10.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();

	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	sky.skybox(130.0, 130.0, 130.0, text1.GLindex);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();


	//Jardineras Frontal

	glPushMatrix();
	glTranslatef(2.5, -3.2, -6.5);
	  glPushMatrix();
	    Fig_Jose.cilindro2(7, 2.5, 100, Jardinera.GLindex, Pasto.GLindex, Jardinera.GLindex);
	  glPopMatrix();

	  glTranslatef(-5, 2.5, 0.0);
	   glPushMatrix();
	    glRotatef(180, 0.0, 0.0, 1.0);
		Fig_Jose.cilindro3(7, 2.5, 100, Pasto.GLindex, Jardinera.GLindex, Jardinera.GLindex);
	   glPopMatrix();
	glPopMatrix();



	//Jardineras traseras
	glPushMatrix();
	glTranslatef(-5, -3.29999, -26.5 );
	  glPushMatrix();;
		glRotatef(90, 0.0, 1.0, 0.0);
	    Fig_Jose.cilindro(2.5, 2.5, 100, Pasto.GLindex, Jardinera.GLindex);
	glPopMatrix();

	glTranslatef(10, 0.0, 0.0);
	  glPushMatrix();
	    glRotatef(270, 0.0, 1.0, 0.0);
	    Fig_Jose.cilindro(2.5, 2.5, 100, Pasto.GLindex, Jardinera.GLindex);
	  glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.9, -2.09999, -26.5);
	  glPushMatrix();
	    Fig_Jose.prismaPro2(2.5, 6.0, 5, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Pasto.GLindex);
	  glPopMatrix();

	  glTranslatef(15.8, 0.0, 0.0);
	  glPushMatrix();
		Fig_Jose.prismaPro3(2.5, 6, 5, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Pasto.GLindex);
	  glPopMatrix();
	glPopMatrix();

	//Jardineras Laterales
	glPushMatrix();
	glTranslatef(13.0, -2.09999, -13);
	  glPushMatrix();
	    Fig_Jose.prismaPro4(2.5, 3.0, 7, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Pasto.GLindex);
	    glPopMatrix();

	  glTranslatef(-26.5, 0.0, 0.0);
	  glPushMatrix();
		 glRotatef(180, 0, 0, 1);
	     Fig_Jose.prismaPro4(2.5, 3, 7, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Jardinera.GLindex, Pasto.GLindex, Jardinera.GLindex);

	glPopMatrix();
	glPopMatrix();


	//Nave espacial
	glPushMatrix();
	glPushMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(moveNaveX, 25.0, moveNaveY);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glRotatef(20.0, 1.0, 0.0, 0.0);
	Fig_Jose.cilindro(0.7, 2.0, 30.0, 0.0, 0.0);//Parte inferior delantera
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	Fig_Jose.cilindro(0.7, 2.0, 30.0, 0.0, 0.0); //Parte inferior trasera
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 2.0, 0.0);
	Fig_Jose.cilindro(0.7, 1.0, 30.0, 0.0, 0.0);//Parte superior delantera
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	Fig_Jose.cilindro(0.7, 1.0, 30.0, 0.0, 0.0);//Parte superior trasera
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.5, 0.3);
	Fig_Jose.esfera(0.6, 20.0, 20.0, 0.0);//Ventana
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, 3.0, 0.0);
	Fig_Jose.cono(1.0, 0.7, 30.0, 0.0);//Punta de la nave
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.6, 0.0, 0.0);
	Fig_Jose.cono(1.0, 0.35, 30.0, 0.0);//alerones derecho
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, 0.0, 0.0);
	Fig_Jose.cono(1.0, 0.35, 30.0, 0.0);//alerones izq
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.6);
	Fig_Jose.cono(1.0, 0.35, 30.0, 0.0);//alerones adelante
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.6);
	Fig_Jose.cono(1.0, 0.35, 30.0, 0.0);//alerones atras
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.49, 0.15);
	glTranslatef(0.0, -0.2, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	Fig_Jose.cono(1.5, 0.4, 30.0, 0.0); //Flama
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//////////////////////////////////////////////////////////////////////////////////////////
	//MUÑECO DE NIEVE
	float tempMN[2][2] = { { -8.0, 25 }, {8,-25} };
	for (int i = 0; i < 2; i++) {
		glPushMatrix();
		glPushMatrix(); //muñeco de nieve
		glColor3f(1, 1, 1);
		glTranslatef(tempMN[i][0], 21.41, -8.0);
		glRotatef(tempMN[i][1],0,1,0);
		glRotatef(35, 1, 0, 0);

		Fig_Jose.esfera(2.0, 20.0, 20.0, 0.0);//Estomago
		glPushMatrix();// botones
		glColor3f(0, 0, 0);
		glTranslatef(0.0, 0.0, 2.0);
		Fig_Jose.esfera(0.2, 20.0, 20.0, 0.0); //boton enmedio
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(0.0, 1.2, -0.3);
		Fig_Jose.esfera(0.2, 20.0, 20.0, 0.0); //boton Superior
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(0.0, -1.2, -0.3); //bonton inferior
		Fig_Jose.esfera(0.2, 20.0, 20.0, 0.0);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();// Manos izquierda
		glRotatef(-10.0, 0.0, 0.0, 1.0);
		glRotatef(tempManos, 1,0,0);
		glPushMatrix();
		glColor3f(0.72, 0.47, 0.34);
		glTranslatef(2.0, 0.0, 0.0);
		Fig_Jose.cilindro(0.1, 4.0, 30.0, 0.0, 0.0);
		glPushMatrix();
		glColor3f(0.72, 0.47, 0.34);
		glTranslatef(-0.1, 3.0, 0.0);
		glRotatef(35.0, 0.0, 0.0, 1.0);
		Fig_Jose.cilindro(0.1, 0.5, 30.0, 0.0, 0.0);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.72, 0.47, 0.34);
		glTranslatef(0.1, 3.0, 0.0);
		glRotatef(-35.0, 0.0, 0.0, 1.0);
		Fig_Jose.cilindro(0.1, 0.5, 30.0, 0.0, 0.0);
		glColor3f(0.72, 0.47, 0.34);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();// Manos derecha
		glRotatef(10.0, 0.0, 0.0, 1.0);
		glRotatef(-tempManos, 1, 0, 0);
		glPushMatrix();
		glColor3f(0.72, 0.47, 0.34);
		glTranslatef(-2.0, 0.0, 0.0);
		Fig_Jose.cilindro(0.1, 4.0, 30.0, 0.0, 0.0);//
		glPushMatrix();
		glColor3f(0.72, 0.47, 0.34);
		glTranslatef(-0.1, 3.0, 0.0);
		glRotatef(35.0, 0.0, 0.0, 1.0);
		Fig_Jose.cilindro(0.1, 0.5, 30.0, 0.0, 0.0);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.72, 0.47, 0.34);
		glTranslatef(0.1, 3.0, 0.0);
		glRotatef(-35.0, 0.0, 0.0, 1.0);
		Fig_Jose.cilindro(0.1, 0.5, 30.0, 0.0, 0.0);

		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(0.0, 3.10, 0.0);
		Fig_Jose.esfera(1.5, 20.0, 20.0, 0.0);//cara
		glPushMatrix();
		glColor3f(1, 0.498, 0.1529);
		glTranslatef(0.0, 0.0, 1.5);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		Fig_Jose.cono(0.5, 0.2, 30.0, 0.0);//Nariz
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(0.5, 0.5, 1.3);
		Fig_Jose.esfera(0.1, 20.0, 20.0, 0.0);//ojo izquierdo
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(-0.5, 0.5, 1.3);
		Fig_Jose.esfera(0.1, 20.0, 20.0, 0.0);//ojo derecho
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(0.0, -0.5, 1.4);
		Fig_Jose.prisma(0.1, 0.6, 0.1, 0.0);//boca
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(0.0, 1.3, 0.0);
		Fig_Jose.cono(0.001, 1.4, 30.0, 0.0);//sombrero
		glPushMatrix();
		glColor3f(0, 0, 0);
		Fig_Jose.cilindro(1.0, 3.0, 30.0, 0.0, 0.0);//sombrero
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		Fig_Jose.cilindro(1.0, 3.0, 30.0, 0.0, 0.0);//sombrero
		glColor3f(1, 1, 1);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}


	//Carretera
	float initCarretera[2] = {-19.5,19.5};
	for (i = 0; i < 2; i++) {
		glPushMatrix();

		glTranslatef(initCarretera[i], -3, -14);
		glPushMatrix();

		Fig_Jose.prismaPro1(0.2, 5, 35, Negro.GLindex, Negro.GLindex, Negro.GLindex, Negro.GLindex, Negro.GLindex, Carretera.GLindex);

		glPopMatrix();

		glTranslatef(-3.75, 0.25, 0);
		glPushMatrix();

		Fig_Jose.prismaPro1(0.7, 2.5, 35, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, Negro.GLindex, Banqueta.GLindex);

		glPopMatrix();

		glTranslatef(7.5, 0, 0);
		glPushMatrix();

		Fig_Jose.prismaPro1(0.7, 2.5, 35, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, Cemento.GLindex, Banqueta.GLindex);

		glPopMatrix();

		glPopMatrix();
	}

	glPushMatrix();
	glRotatef(90, 0, 1, 0);

	float initCarretera2[2] = {-6,34};
	for (i = 0; i < 2; i++) {
		glPushMatrix();

		glTranslatef(initCarretera2[i], -3, 0);
		glPushMatrix();

		Fig_Jose.prismaPro1(0.2, 5, 34, Negro.GLindex, Negro.GLindex, Negro.GLindex, Negro.GLindex, Negro.GLindex, Carretera.GLindex);

		glPopMatrix();

		glTranslatef(-3.75, 0.25, 0);
		glPushMatrix();

		Fig_Jose.prismaPro1(0.701, 2.5, 34, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, Cemento.GLindex, Banqueta.GLindex);

		glPopMatrix();

		glTranslatef(7.5, 0, 0);
		glPushMatrix();

		Fig_Jose.prismaPro1(0.701, 2.5, 34, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, LineaBanqueta.GLindex, Cemento.GLindex, Banqueta.GLindex);

		glPopMatrix();

		glPopMatrix();
	}
	glPopMatrix();

	float initCruce[4][2] = { {19.5,-34},{19.5,6},{-19.5,6},{-19.5,-34} };
	for (i = 0; i < 4; i++) {
		glPushMatrix();

		glTranslatef(initCruce[i][0], -3, initCruce[i][1]);
		glPushMatrix();

		Fig_Jose.prismaPro1(0.2, 5, 5, Negro.GLindex, Negro.GLindex, Negro.GLindex, Negro.GLindex, Negro.GLindex, Cruce.GLindex);

		glPopMatrix();

		glPopMatrix();
	}

	//Combi
	glPushMatrix();

	glTranslatef(moveCombi, -0.8999, 4.8);
	glPushMatrix();

	Fig_Jose.prismaPro(4, 6, 1.7, CombiLD.GLindex, CombiFrente.GLindex, CombiLI.GLindex, CombiAtras.GLindex, Vidrio3.GLindex, Blanco.GLindex);

	glPopMatrix();

	glPopMatrix();


	//Persona
	//Cara
	glPushMatrix();

	glTranslatef(moveX, 0.2, moveZ);
	glRotatef(angulo, 0, 1, 0);

	glPushMatrix();
	Fig_Jose.prismaPro(.5, .5, .5, CaraLD.GLindex, Cara.GLindex, CaraLI.GLindex, CaraAtras.GLindex, CaraAbajo.GLindex, CaraArriba.GLindex);
	glPopMatrix();

	//Cuello

	glTranslatef(0.0, -0.4, 0.0);

	glPushMatrix();
	Fig_Jose.prismaPro(.3, .1, .1, CaraAbajo.GLindex, CaraAbajo.GLindex, CaraAbajo.GLindex, CaraAbajo.GLindex, CaraAbajo.GLindex, CaraAbajo.GLindex);
	glPopMatrix();

	//Cuerpo
	glTranslatef(0.0, -0.65, 0.0);

	glPushMatrix();
	Fig_Jose.prismaPro(1.2, .5, 1, CuerpoL.GLindex, Cuerpo.GLindex, CuerpoL.GLindex, CuerpoL.GLindex, CuerpoL.GLindex, CuerpoL.GLindex);
	glPopMatrix();

	//Brazos

	glPushMatrix();
	glRotatef(5,1,0,0);
	glRotatef(10, 0, 0, 1);
	glTranslatef(0.0, 0, -.64);

	glPushMatrix();
	Fig_Jose.prismaPro(1, .26, .26, Brazo.GLindex, Brazo.GLindex, Brazo.GLindex, Brazo.GLindex, Negro.GLindex, Blanco.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-5, 1, 0, 0);
	glRotatef(10, 0, 0, 1);
	glTranslatef(0.0, 0, 0.6);

	glPushMatrix();
	Fig_Jose.prismaPro(1, .26, .26, Brazo.GLindex, Brazo.GLindex, Brazo.GLindex, Brazo.GLindex, Negro.GLindex, Blanco.GLindex);
	glPopMatrix();
	glPopMatrix();


	//Piernas
	//Pierna 1

	glRotatef(cte1, 0, 0, 1);

	glTranslatef(cte2, -1, -.2);

	glPushMatrix();
	Fig_Jose.prismaPro(1, .26, .26, Pierna.GLindex, Pierna.GLindex, Pierna.GLindex, Pierna.GLindex, Negro.GLindex, Blanco.GLindex);
	glPopMatrix();


	//Pierna 2

	glRotatef(cte3, 0, 0, 1);
	glTranslatef(cte4, 0.0, .4);

	glPushMatrix();
	Fig_Jose.prismaPro(1, .26, .26, Pierna.GLindex, Pierna.GLindex, Pierna.GLindex, Pierna.GLindex, Negro.GLindex, Blanco.GLindex);
	glPopMatrix();


	glPopMatrix();

	//Bandera

	glPushMatrix();

	glTranslatef(-5, 3, 4);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 9/*intermedio x final*/, 4/*inicial*/, 0, 1, 3, 3/*intermedio*/, &bandera[0][0][0]);
	//printf("cteBandera = %f\n", cteBand);
	glEnable(GL_MAP2_VERTEX_3);
	glRotatef(45, 0, 1, 0);
	glEnable(GL_AUTO_NORMAL);
	glMapGrid2f(40, 0.0, 1.0, 40, 0.0, 1.0);
	glPushMatrix();
	glColor3f(1, 0, 0);
	glEvalMesh2(GL_FILL, 0, 40, 0, 40);
	glDisable(GL_AUTO_NORMAL);
	glDisable(GL_MAP2_VERTEX_3);
	glPopMatrix();
	glColor3f(1, 1, 1);
	glPopMatrix();

	//Mastil
	glPushMatrix();

	glTranslatef(-0.05, 5.8, -0.95);

	glPushMatrix();
	Fig_Jose.prisma(4.6, 0.07, .07, Metal.GLindex);
	glPopMatrix();

	glPopMatrix();


	//Piso
	glPushMatrix();
	  glBindTexture(GL_TEXTURE_2D, Pasto.GLindex);
	  
	  glEnable(GL_LIGHTING);
	  glBegin(GL_QUADS);
	    glColor3f(1.0, 1.0, 1.0);
	    glNormal3f(0.0f, 0.0f, 1.0f);
	    glTexCoord2f(0.0f, 0.0f); glVertex3f(65.0, -3.3, 75.0);
	    glTexCoord2f(20.0f, 0.0f); glVertex3f(65.0, -3.3, -75.0);
	    glTexCoord2f(20.0f, 20.0f); glVertex3f(-65.0, -3.3, -75.0);
	    glTexCoord2f(0.0f, 20.0f); glVertex3f(-65.0, -3.3, 75.0);
		glDisable(GL_LIGHTING);
	  glEnd();
	  
	glPopMatrix();


	////////////////////////////////////////////////////////////////////Arbol////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-5, -0.8, -2);
	glScalef(0.3, 0.3, 0.3);
	glPushMatrix();
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();

	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(5, -0.8, -2);
	glScalef(0.3, 0.3, 0.3);
	glPushMatrix();
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////Arbol/////////////////////////////////////////////////


	glPopMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	t1=t1+1;

	if (cteBand < limite && cteBand2 == 0) {
		cteBand = cteBand + velBand;
	}
	else if (cteBand == limite, cteBand2 == 0)
	{
		cteBand = cteBand + velBand;
		cteBand2 = 1;
	}
	else if (cteBand > -limite && cteBand2 == 1){
		cteBand = cteBand - velBand;
	}
	else if (cteBand == -limite, cteBand2 == 1)
	{
		cteBand = cteBand - velBand;
		cteBand2 = 0;
	}



	//printf("moveX = %.3f", moveX);

	glutSwapBuffers();

}

void animacion()
{
	if (caso == 1) {
		if (t1 >= 0 && t1 < velocidadPies) {
			cte1 = -5; cte2 = 0.05; cte3 = 10; cte4 = 0.1;
			moveX = moveX + velocidad;
			int cteban = rand() % 32;
			velBand = ((float)cteban / 1000);
		}
		if (t1 >= velocidadPies && t1 < velocidadPies*2) {
			cte1 = cte2 = cte3 = cte4 = 0.0;
			moveX = moveX + velocidad;
		}
		if (t1 >= velocidadPies*2 && t1 < velocidadPies*3) {
			cte1 = 5, cte2 = -0.05, cte3 = -10, cte4 = -0.1;
			moveX = moveX + velocidad;
		}
		if (t1 >= velocidadPies*3 && t1 < velocidadPies*4) {
			cte1 = cte2 = cte3 = cte4 = 0.0;
			moveX = moveX + velocidad;
		}
		if (t1 == velocidadPies*4) {
			t1 = 0;
			moveX = moveX + velocidad;
		}
		if (moveX >= 15.8 && moveX < 15.815) {
			moveX = 15.8;
			cte1 = cte2 = cte3 = cte4 = 0.0;
			t2 = t2 + 1;
			angulo = angulo + 0.18;
			if (t2 == 500) {
				moveX = 15.815;
				caso = 2;
				t2 = 0;
			}
		}
	}

	if (caso == 2) {
		//printf("moveZ = %f", moveZ);
		if (t1 >= 0 && t1 < 30) {
			cte1 = -5; cte2 = 0.05; cte3 = 10; cte4 = 0.1;
			moveZ = moveZ - velocidad;
			int cteban = rand() % 32;
			velBand = ((float)cteban / 1000);
		}
		if (t1 >= 30 && t1 < 60) {
			cte1 = cte2 = cte3 = cte4 = 0.0;
			moveZ = moveZ - velocidad;
		}
		if (t1 >= 60 && t1 < 90) {
			cte1 = 5, cte2 = -0.05, cte3 = -10, cte4 = -0.1;
			moveZ = moveZ - velocidad;
		}
		if (t1 >= 90 && t1 < 120) {
			cte1 = cte2 = cte3 = cte4 = 0.0;
			moveZ = moveZ - velocidad;
		}
		if (t1 == 120) {
			t1 = 0;
			moveZ = moveZ - velocidad;
		}
		if (moveZ > -30.285 && moveZ <= -30.27) {
			//printf("angulo = %f",0.09);
			moveZ = -30.271273;
			cte1 = cte2 = cte3 = cte4 = 0.0;
			t2 = t2 + 1;
			angulo = angulo + 0.18;
			if (t2 == 500) {
				moveZ = -30.28;
				caso = 3;
				t2 = 0;
			}
		}//-30.271273
	}

	if (caso == 3) {
		//printf("moveX = %f", moveX);
		if (t1 >= 0 && t1 < 30) {
			cte1 = -5; cte2 = 0.05; cte3 = 10; cte4 = 0.1;
			moveX = moveX - velocidad;
			int cteban = rand() % 32;
			velBand = ((float)cteban / 1000);
		}
		if (t1 >= 30 && t1 < 60) {
			cte1 = cte2 = cte3 = cte4 = 0.0;
			moveX = moveX - velocidad;
		}
		if (t1 >= 60 && t1 < 90) {
			cte1 = 5, cte2 = -0.05, cte3 = -10, cte4 = -0.1;
			moveX = moveX - velocidad;
		}
		if (t1 >= 90 && t1 < 120) {
			cte1 = cte2 = cte3 = cte4 = 0.0;
			moveX = moveX - velocidad;
		}
		if (t1 == 120) {
			t1 = 0;
			moveX = moveX - velocidad;
		}
		if (moveX >= -15.815 && moveX < -15.8) {
			moveX = -15.8;
			cte1 = cte2 = cte3 = cte4 = 0.0;
			t2 = t2 + 1;
			angulo = angulo - 0.18;
			if (t2 == 500) {
				moveX = -15.8;
				caso = 2;
				t2 = 0;
			}
		}//-15.801580
	}
	moveCombi = moveCombi + 0.02;

	if (tempManos < limManos && bandManos == 0) {
		tempManos = tempManos + velManos;
	}
	if (tempManos == limManos) {
		bandManos = 1;
	}
	if (tempManos > -limManos && bandManos == 1) {
		tempManos = tempManos - velManos;
	}
	if (tempManos == -limManos) {
		bandManos = 0;
	}

	moveNaveX = moveNaveX + (0.1*0.93969262078590838405410927732473);
	moveNaveY = moveNaveY + (0.1*0.34202014332566873304409961468226);
	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 220.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	//Vista Isom�trica

	case 'f':
	case 'F':

		objCamera.Position_Camera(0, 0, 64, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();

		break;

	//Vista Frontal
	case 'i':
	case 'I':

		objCamera.Position_Camera(45, 45.0f, 20, 0, 0.0f, -50.0, 0, 1, 0);
		glutPostRedisplay();

		break;

	//Vista Laboratorio
	case 'l':
	case 'L':

		objCamera.Position_Camera(-6.25, 17.0f, -6.5, -6.25, 17.0f, -10, 0, 1, 0);
		glutPostRedisplay();

		break;

	//Vista Salon
	case 'c':
	case 'C':

		objCamera.Position_Camera(6.5, 5.0f, -6.5, 6.5, 5.0f, -20, 0, 1, 0);
		glutPostRedisplay();

		break;

	//Vista Aerea
	case 'u':
	case 'U':

		objCamera.Position_Camera(0, 40.0f, -10, 0, -0.0f, -11, 0, 1, 0);
		glutPostRedisplay();

		break;

	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.05);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.05));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED+0.05));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED+0.05);
		break;

	case 'q':
	case 'Q':
		objCamera.UpDown_Camera(-CAMERASPEED-0.02f);
		break;

	case 'e':
	case 'E':
		objCamera.UpDown_Camera(CAMERASPEED+0.02f);
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void mouseMove(/*int r,int l,*/int x, int y) {

	//printf("x=%d\n",x);
	//printf("y=%d\n", y);
	if (x > 500)
	{
		objCamera.Rotate_View(CAMERASPEED+.01f);
		glutWarpPointer(500, 500);
	}
	if (x < 500)
	{
		objCamera.Rotate_View(-CAMERASPEED-0.01f);
		glutWarpPointer(500, 500);
	}
	if (y < 500)
	{
		g_lookupdown -= 0.7f;
		glutWarpPointer(500, 500);
	}
	if (y > 500)
	{
		g_lookupdown += 0.7f;
		glutWarpPointer(500, 500);
	}
}

int main(int argc, char** argv)   // Main Function
{
	PlaySound(TEXT("Musica.wav"), NULL, SND_LOOP | SND_ASYNC);//Musica
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(2000, 2000);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto Final"); // Nombre de la Ventana
	//glutFullScreen( );         // Full Screen
	glutIdleFunc(animacion);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutPassiveMotionFunc(mouseMove); //Indicamos a GLUT la funci�n de manejo de la camara con el mouse
	glutSetCursor(GLUT_CURSOR_NONE);


	glutMainLoop();          //

	return 0;
}
