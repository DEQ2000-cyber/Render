#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500
#include <windows.h>
#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif



/*
    MOTOR probado en winer GNU/LINUX


    VERSION: Alpha 3.1.0: Lanzamiento.
    20:16 Argentina Daniel Efrain Quiroga
    06:20 Mexicam Andres Ruiz perez
    06:36 Colombia Jheison Toro Betancourth
    -----------------------
    |16 de octubre de 2021|
    -----------------------

    VERSION: Alpha 1.0.0: Lanzamiento.
    [SE AGREGO]: version : POR DEQ
    [SE AGREGO]: iniciar : POR DEQ
    [SE AGREGO]: loopinit : POR DEQ
    [SE AGREGO]: pintar : POR DEQ
    [SE AGREGO]: salir : POR DEQ
    [SE AGREGO]: deltatime : POR DEQ
    [SE AGREGO]: mousex : POR DEQ
    [SE AGREGO]: mousey : POR DEQ
    [SE AGREGO]: izquierdo : POR DEQ
    [SE AGREGO]: derecho : POR DEQ
    [SE AGREGO]: tecla : POR DEQ
    [SE AGREGO]: pixel : POR DEQ
    [SE AGREGO]: getpixel : POR DEQ
    [SE AGREGO]: fondo : POR DEQ
    [SE AGREGO]: arrastre : POR DEQ
    [SE AGREGO]: raton_botones : POR DEQ
    [SE AGREGO]: comandomenu : POR DEQ
    [SE AGREGO]: comandomenu2 : POR DEQ
    [SE AGREGO]: RGB : POR DEQ
    [SE AGREGO]: RGBA : POR DEQ
    [SE AGREGO]: GetAValue : POR DEQ

    VERSION: Alpha 2.0.0:
    [SE AGREGO]: chars : POR DEQ
    [SE AGREGO]: fontsize : POR DEQ
    [SE AGREGO]: text : POR DEQ
    [SE AGREGO]: texto : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: modoconsola : POR DEQ PEDIDO POR JTB

    VERSION: Alpha 2.1.0:
    [SE AGREGO]: SOLUCION DE FALLA DE COMPILACION EN C++ : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: SE AGREGO UNA INTEGRACION NUEVA SOBRE AL ESTIRAR LA VENTANAEL RENDER/PINTADO/DIBUJO TAMBIEN VA A LA PAR DEL TAMAÑO DE LA VENTANA
    VERSION: Alpha 3.1.0:
    [SE AGREGO]: rectangulo : POR DEQ
    [SE AGREGO]: rectangulofill : POR DEQ
    [SE AGREGO]: linea : POR DEQ
    [SE AGREGO]: lineaw : POR DEQ
    [SE AGREGO]: lineah : POR DEQ
    [SE AGREGO]: circulo : POR DEQ
    [SE AGREGO]: circulofill : POR DEQ
    [SE AGREGO]: triangulo : POR DEQ
    [SE AGREGO]: triangulofill : POR DEQ
    [SE AGREGO]: polygonfill : POR DEQ
    [SE AGREGO]: lineagr : POR DEQ
    [SE AGREGO]: triangulogr : POR DEQ
*/



/*
//Codigo de ejemplo

#include "render.h"
#include <stdlib.h>
int main(void){
   iniciar( 500,500, "Test" );
   while( loopinit() ){
      if (tecla(27))break;
      pixel( rand()%500,rand()%500, RGBA( rand()%256, rand()%256, rand()%256, rand()%256 ) );
      pintar( 10 );
   }
   salir();
   return (0);
}
*/

#include <stdbool.h>
#include <stdint.h>


enum MODO_DE_CONSOLA{
    OCULTAR = 2,
    NOOCULTAR = 4
};

#define RGBA(r,g,b,a)((uint32_t)((uint16_t)(b) | ((uint16_t)(g) << 8) | ((uint16_t)(r) << 16)) | ((uint16_t)(a) << 24) )
#undef RGB
#define RGB(r,g,b)((uint32_t)((uint16_t)(b) | ((uint16_t)(g) << 8) | ((uint16_t)(r) << 16)) | ((uint16_t)(255) << 24) )
#define GetAValue(rgb) (LOBYTE((rgb)>>24))



#ifdef __cplusplus
#ifdef FASTCALL
#undef FASTCALL
#define FASTCALL __stdcall
#else
#undef FASTCALL
#define FASTCALL __fastcall
#endif
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __POINT2D__
#define __POINT2D__
typedef struct tagPUNTOS
{
    float x,y;
} PUNTOS;
#endif

/* VERSION HOY EN DIA DEL PROYECTO RENDER.H */
EXPORT void VERSION( void );

/* INICIOS */
EXPORT int      FASTCALL loopinit( void ); /* DETECTA SI LA VENTANA/RENDER ESTA YA ACTIVADA */
EXPORT int      FASTCALL iniciar( int,int,const char* ); /* INICIA LA VENTANA/RENDER */
EXPORT void     FASTCALL pintar( int ); /* LLAMA A PINTAR Y TIRA EL DIBUJO A LA VENTANA/BUFFER */
EXPORT void     FASTCALL salir( void ); /* CANCELA LA VENTANA ELIMINA BUFFER Y SALE DEL RENDER */
EXPORT float    FASTCALL deltatime( void ); /* DEVUELVE EL VALOR DEL (RETARDO DEL DIBUJADO/DELTA TIME) */
/* CONFIGURACIONES */
EXPORT void     FASTCALL modoconsola( int modo ); /* SETEA EL MODO DE VIZION DE LA CONSOLA CMD/SHEEL USANDO LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_CONSOLA. USE EL FLAG -mwindows SI HAY PROBLEMAS CON LA FUNCIÓN */
/* DIBUJADOS */
EXPORT void     FASTCALL pixel( int, int, uint32_t ); /* PINTA UN PIXEL EN COORDENADAS Y COLOR ESPECIFICADO USANDO RGB O RGBA */
EXPORT uint32_t FASTCALL getpixel( int, int ); /* OBTIENE EL COLOR DEL PIXEL EN LAS COORDENADAS ESPECIFICADAS. */
EXPORT void     FASTCALL borrar( void ); /* BORRA TODO EL DIBUJADO DEJA EN NEGRO/0. EL CANAL A/ALPHA ESTARA EN ALTO/255 */
EXPORT void     FASTCALL fondo( uint32_t ); /* RELLENA EL DIBUJADO CON EL COLOR ESPECIFICO USANDO RGB O RGBA */
EXPORT void     FASTCALL chars( int x, int y, const char ascii, uint32_t color ); /* DIBUJA UA FUENTE DE ASCII DE 8x8 EN SUS COORDENADAS ESPECIFICADAS. Y ASCII STANDAR ESPECIFICADO Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL fontsize( int w, int h ); /* SETEA EL TAMAÑO DE FUENTE EN ANCHO Y ALTO ESTAS NUMERACIONES QUEDAN PARA TODOS LOS DIBUJADOS DE TEXTOS */
EXPORT void     FASTCALL text( int x, int y, uint32_t color, const char *texto ); /* DIBUJA UNA CADENA DE ASCII/TEXTOS CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL texto( int x, int y, uint32_t color, const char *texto, ... ); /* DIBUJA UNA CADENA DE ASCII/TEXTOS CON FORMATOS COMO "PRITF", CON SUS COORDENAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL rectangulo( int x, int y, int w, int h, uint32_t color ); /* DIBUJA UN RECTANGULO HUECO DE CUATRO PUNTOS ESPEFICICADOS Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL rectangulofill( int x, int y, int w, int h, uint32_t color ); /* DIBUJA UN RECTANGULO RELLENO DE CUATRO PUNTOS ESPEFICICADOS Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL linea( int x0, int y0, int x1, int y1, uint32_t color ); /* DIBUJA UNA LINEA CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineaw( int x, int w, int y, uint32_t color ); /* DIBUJA UNA LINEA EN HORIZONTAL CON COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineah( int y, int h, int x, uint32_t color ); /* DIBUJA UNA LIENA EN VERTICAL CON SUS COORDENADA ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL circulo( int ox, int oy, int radio, uint32_t color ); /* DIBUJA UN CIRCULO HUECO CON SUS COORDENADAS Y RADIO ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL circulofill( int ox, int oy, int radio, uint32_t color ); /* DIBUJA UN CIRCULO RELLENO CON SUS COORDENADAS Y RADIO ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL triangulo( int x, int y, int x1, int y1, int x2, int y2, uint32_t color ); /* DIBUJA UN TRIANGULO HUECO CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL triangulofill( int X1, int Y1, int X2, int Y2, int X3, int Y3, uint32_t color ); /* DIBUJA UN TRIANGULO RELLENO CON SUS COORDENADAS ESPECIFICAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL polygonfill( uint32_t cantidad, PUNTOS p[], uint32_t color ); /* DIBUJA POLIGONOS RELLENOS CON SUS COORDENADAS ESPECIFICADAS. USANDO LA STRUCTURA PUNTOS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineagr( int x0, int y0, int x1, int y1, uint32_t colorA, uint32_t colorB ); /* DIBUJA UNA LINEA GRADIENTE CON SUS COORDENADAS ESPECIFICADAS. Y EL COLOR VA DESDE EL COLOR A, ASTA YEGAR AL COLOR B. SE LO LLAMA GRADIENTE DE COLOR */
EXPORT void     FASTCALL triangulogr( int x, int y, int x1, int y1, int x2, int y2, uint32_t colorA, uint32_t colorB, uint32_t colorC ); /* DIBUJA UN TRIANGULO GRADIENTE CON SUS COORDENADAS ESPECIFICADAS. Y EL COLOR VA DESDE EL COLOR A, LUEGO YEGAR AL COLOR B, LUEGO YEGAR AL COLOR C Y VOLVER AL COLOR DE A, SE LO LLAMA GRADIENTE DE COLOR */

/* INPUTS Y OUTPUTS */
EXPORT bool     FASTCALL tecla( char ); /* OBTIENE LAS TECLAS PRESIONADA */
EXPORT int      FASTCALL mousex( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN X DE TODA LA VENTANA */
EXPORT int      FASTCALL mousey( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN Y DE TODA LA VENTANA */
EXPORT bool     FASTCALL arrastre( void ); /* OBTIENE SI ESTA ARRASTRANDO CON EL PUNTERO MOUSE MANTENIÉNDOSE APRETADO */
EXPORT void     FASTCALL raton_botones( bool *izq, bool *der ); /* OBTIENE EN MEMORIA DE TAL VARIABLE LOS BOTONES IZQUIERDO Y DERECHO DEL MOUSE */
EXPORT bool     FASTCALL izquierdo( void ); /* OBTIENE LA PULSACION IZQUIERDO DEL MOUSE */
EXPORT bool     FASTCALL derecho( void ); /* OBTIENE LA PULSACION DERECHO DEL MOUSE */
EXPORT int      FASTCALL comandomenu( void ); /* OBTIENE EL COMANDO AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */
EXPORT bool     FASTCALL comandomenu2( int ids ); /* OBTIENE UNA UNICA VEZ AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */

#ifdef __cplusplus
    }
#endif