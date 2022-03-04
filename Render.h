#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif



/*
    MOTOR probado en winer GNU/LINUX


    VERSION: Alpha 9.14.0.
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
    [SE AGREGO]: SE AGREGO UNA INTEGRACION NUEVA SOBRE AL ESTIRAR LA VENTANA EL RENDER/PINTADO/DIBUJO TAMBIEN VA A LA PAR DEL TAMAÑO DE LA VENTANA

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

    VERSION: Alpha 3.2.0:
    [SE AGREGO]: SOLUCION DE FALLA DE GETPIXEL AL OBTENER EL COLOR/PIXEL CORRECTO : POR DEQ PEDIDO POR JTB

    VERSION: Alpha 3.3.0:
    [SE AGREGO]: SE AGREGO UNA INTEGRACION NUEVA SOBRE AL ESTIRAR LA VENTANA EL RENDER/PINTADO/DIBUJO TAMBIEN EL MOUSE DEBE MODIFICARSE PARA OBTENER EL MISMO DIAMETRO : POR DEQ
    [SE AGREGO]: SOLUCION DE FALLA DE FONDO AL PINTAR : POR DEQ PEDIDO POR JTB

    VERSION: Alpha 4.3.0:
    [SE AGREGO]: modotimedelta : POR DEQ PEDIDO POR JTB : ELIMINADO DE LA LISTA.

    VERSION: Alpha 4.4.0:
    [SE AGREGO]: poligon : POR DEQ
    [SE AGREGO]: moveto : POR DEQ
    [SE AGREGO]: lineato : POR DEQ

    VERSION: Alpha 4.5.0:
    [SE AGREGO]: cuadricula : POR JTB

    VERSION: Alpha 4.6.0:
    [SE AGREGO]: lineanorm : POR JTB

    VERSION: Alpha 4.7.0.
    [SE AGREGO]: linearc : POR DEQ
    [SE AGREGO]: SOLUCION DE FALLA DE lineato : POR JTB 
    [SE AGREGO]: SOLUCION DE FALLA DE cuadricula : POR JTB

    VERSION: Alpha 4.8.0.
    [SE AGREGO]: linearc : SOLUCION DE MAL PUNTOS DE A HACIA B. : POR DEQ

    VERSION: Alpha 5.8.0.
    [SE AGREGO]: linearc : SOLUCION DE MAL NINGUN Y MAL GRADIENTE PARA EL CANAL A/ALPHA DE COLOR : POR DEQ
    [SE AGREGO]: SE CAMBIO LA FORMA DE OBTENER LOS CLICKS DEL MOUSE/RATON, AHORA TIENEN PARAMETROS DEL MODO DE RETORNO. (SOSTENIDO) Y (UNAVEZ)

    VERSION: Alpha 6.8.0.
    [SE AGREGO]: abrirfichero : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: abrirficherof : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: RGBpicker : POR DEQ
    [SE AGREGO]: modoventana : POR DEQ PEDIDO POR JTB

    VERSION Alpha 6.9.0
    [SE AGREGO]: ancho : POR DEQ
    [SE AGREGO]: alto : POR DEQ
    [SE AGREGO]: DATABGRA : POR DEQ
    [SE AGREGO]: colorRGB : POR DEQ
    [SE AGREGO]: colorRGBA : POR DEQ
    [SE AGREGO]: pixelp : POR DEQ

    VERSION Alpha 7.9.0
    [SE AGREGO]: fondoimagen : POR DEQ
    [SE AGREGO]: triangulofillgr : POR DEQ

    VERSION: Alpha 8.9.0
    [SE AGREGO]: cargarimagen : POR DEQ
    [SE AGREGO]: pintarimagen : POR DEQ
    [SE AGREGO]: pintarimagenr : POR DEQ
    [SE AGREGO]: borrarimagen : POR DEQ

    VERSION: Alpha 8.10.0
    [SE AGREGO]: triangulofillgrp : POR DEQ
    [SE AGREGO]: SE AGREGO UNA NUEVA IMPLEMENTACION PARA EL BORRADO DE MEMORIA DE LAS IMAGENES AUTOMATICAMENTE, LO MISMO CON EL FONDO.
    [SE AGREGO]: borrarimagenes : POR DEQ
    [SE AGREGO]: efectoimagen : POR DEQ
    [SE AGREGO]: SE ISO UN CAMBIO CON. chars, texto, text : SE AGREGO COLOR DEL FONDO DE LA FUENTE : POR DEQ
    [SE AGRAGO]: lineawgr : POR JTB
    [SE AGRAGO]: lineahgr : POR JTB
    [SE AGREGO]: rectangulofillgr : POR JTB
    [SE AGREGO]: copiarbufferimagen : POR DEQ
    
    VERSION Alpha 8.11.0
    [SE AGREGO]: pixelimagen : POR DEQ PEIDO POR JTB
    [SE AGREGO]: getpixelimagen : POR DEQ PEIDO POR JTB
    [SE AGREGO]: rectangulogr : POR DEQ

    VERSION Alpha 8.12.0
    [SE AGREGO]: pintarblur : POR DEQ
    [SE AGREGO]: configimagen : POR DEQ
    [SE AGREGO]: crearbufferimagen : POR DEQ
    [SE AGREGO]: pmousexy : POR DEQ

    VERSION Alpha 9.12.0
    [SE AGREGO]: rectangulocopiarbufferimagen : POR DEQ
    [SE AGREGO]: guardarimagen : POR DEQ
    [SE AGREGO]: lineap : POR DEQ
    [SE AGREGO]: circulop : POR DEQ
    [SE AGREGO]: circulofillp : POR DEQ
    [SE AGREGO]: movetop : POR DEQ
    [SE AGREGO]: lineatop : POR DEQ
    [SE AGREGO]: triangulop : POR DEQ
    [SE AGREGO]: triangulofillp : POR DEQ
    [SE AGREGO]: lineagrp : POR DEQ
    [SE AGREGO]: triangulogrp : POR DEQ
    [SE AGREGO]: cuadriculap : POR DEQ
    [SE AGREGO]: lineanormp : POR DEQ
    [SE AGREGO]: linearcp : POR DEQ
    [SE AGREGO]: mouse : POR DEQ
    [SE AGREGO]: fps : POR DEQ
    [SE CAMBIO]: modotimedelta : a modotitulo : POR DEQ

    VERSION Alpha 9.13.0
    [SE AGREGO]: asciitecla : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: tecla2 : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: mouserueda : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: triangulotextura : POR DEQ
    [SE AGREGO]: triangulotexturap : POR DEQ

    VERSION Alpha 9.14.0
    [SE AGREGO]: menu : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: menuagregar : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: menuid : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: submenu : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: submenupop : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: submenusub : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: menuseparador : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: menumostrar : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: desvanecerse : POR DEQ
    [SE AGREGO]: desvanecimiento : POR DEQ
    [SE AGREGO]: tinte : POR DEQ
    [SE AGREGO]: lineaaliasing : POR DEQ
    [SE AGREGO]: lineaaliasingp : POR DEQ
    [SE AGREGO]: dropfichero : POR DEQ
    [SE AGREGO]: ClearDepthBuffer : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: pixeldepth : POR DEQ PEDIDO POR JTB
    [SE AGREGO]: getpixeldepth : POR DEQ PEDIDO POR JTB
*/







/* Codigo de ejemplo */

/*

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




#ifdef __cplusplus
#ifdef FASTCALL
#undef FASTCALL
#define FASTCALL __stdcall
#else
#undef FASTCALL
#define FASTCALL __fastcall
#endif
#endif


/* ARCHIVOMODE */
#define ORB "rb" // OpenReadBinary
#define ORN "r"  // OpenReadNormal
#define OWB "wb" // OpenWriteBinary
#define OWN "w"  // OpenWriteNormal



#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#ifndef __TYPOS__
#define __TYPOS__
typedef uint16_t    u16,    U16;
typedef uint32_t    u32,    U32;
typedef int16_t     i16,    I16;
typedef int32_t     i32,    I32;
typedef int8_t      i8,      I8;
typedef uint8_t     u8,      U8;
typedef float       f32,    F32;
#endif


enum MODO_DE_TITULO{
    TITULO      =   2,
    FPS         =   4
};


enum MODO_DE_CONSOLA{
    OCULTAR     =   2,
    NOOCULTAR   =   4,
    MOSTRAR     =   4
};

enum MODO_DE_VENTANA{
    MINIMIZADO  =   2,
    MAXIMIZADO  =   4,
    FULLSCREEN  =   8,
    OCULTO      =   16
};

enum MODO_DE_MOUSE{
    SOSTENIDO   =   2,
    UNAVEZ      =   4
};

enum MODO_FONDOIMG
{
    NORMAL      =   0,
    ESTRECHAR   =   2,
    MOSAICO     =   4
};




#define RGBA(r,g,b,a)((uint32_t)((uint16_t)(b) | ((uint16_t)(g) << 8) | ((uint16_t)(r) << 16)) | ((uint16_t)(a) << 24) )
#undef RGB
#define RGB(r,g,b)((uint32_t)((uint16_t)(b) | ((uint16_t)(g) << 8) | ((uint16_t)(r) << 16)) | ((uint16_t)(255) << 24) )
#define GetAValue(rgb) (LOBYTE((rgb)>>24))



/* Strutura a color rgba separando los colores/canales en bytes */
typedef union tagRGBA{
    uint32_t rgba;
    struct{ uint8_t B,G,R,A; };
} __COLORS__;


/* Structura a color rgba separando los colores/canales en bytes, y activado de transparencia */
typedef struct tagColorRGBA
{
    uint8_t B,G,R,A;
    _Bool alpha;
} ColorRGBA, *PColorRGBA;


#ifndef __POINT2D__
#define __POINT2D__
/* Strutura a puntos 2D en float's */
typedef struct tagPUNTOS
{
    float x,y;
} PUNTOS;
#endif



#ifndef __POINTF2D__
#define __POINTF2D__
/* Strutura a puntos 2D en float's */
typedef struct tagPUNTOSF
{
    float x,y;
} PUNTOSF;
#endif



#ifndef __POINTI2D__
#define __POINTI2D__
/* Strutura a puntos 2D en int's */
typedef struct tagPUNTOSI
{
    int x,y;
} PUNTOSI;
#endif



#ifndef __POINTD2D__
#define __POINTD2D__
/* Strutura a puntos 2D en double's */
typedef struct tagPUNTOSD
{
    double x,y;
} PUNTOSD;
#endif





enum __EFECTOS_IMAGEN__
{
    SCALA_ROJO      = 0,    SCALE_RED      = 0,
    SCALA_VERDE     = 1,    SCALE_GREEN    = 1,
    SCALA_AZUL      = 2,    SCALE_BLUE     = 2,
    SCALA_ALPHA     = 4,    SCALE_ALFA     = 4,
    SCALA_GRIS      = 8,    SCALE_GRAY     = 8,
    INVERTIR        = 16,   INVERT         = 16,
    VOLTEAR_V       = 32,   FLIP_V         = 32,
    VOLTEAR_H       = 64,   FLIP_H         = 64,
    DIFUMINAR       = 128,  BLUR           = 128

};

enum __CONFIGURACION_IMAGEN__
{
    NOCENTRO    = 0,    NOCENTER   = 0,
    CENTRO      = 1,    CENTER     = 1

};




/* Structura a IMAGEN */

typedef struct tagIMAGEN{
    _Bool CENTER; /* Activado o Desactivado del centro al dibujar la imagen. */
    uint32_t ID, /* ID de la imagen para usos del render y configuraciones aptas. */
        W,WS, /* Ancho iamgen, y ancho dividido en 2 para centro. */
        H,HS, /*  Alto iamgen, y alto  dividido en 2 para centro. */
        BPP;  /* El byte por separaciones del pixel de la imagen siempre 4, para usos del render y configuraciones aptas. */
    uint32_t *DATA; /* Datos del color de la imagen/pixeles */
}IMAGEN,*PIMAGEN; /* Typos: 1) structura normal, 2) structura puntero */




/* VERSION HOY EN DIA DEL PROYECTO RENDER.H */
EXPORT void VERSION( void );



/* FONDO */
EXPORT void       FASTCALL fondoimagen( const char *nombre, int modo ); /* DIBUJA UNA IMAGEN PARA EL FONDO. PASANDOLE POR PARAMETRO EL NOMBRE/RUTA DE LA IMAGEN, ESTE LO LEERA Y DIBUJADA SU LECTURA SERA UNICA VEZ, NO SERA UNICA ASTA QUE LA IMAGEN SEA OTRO NOMBRE O OTRO MODO. USE LOS MODOS DE DIBUJADOS CON MODO_FONDOIMG */

/* IMAGEN */
EXPORT uint32_t*  FASTCALL DATABGRA( void ); /* OBTIENE EL PUNTERO DATA BGRA DEL SCREEN/DIBUJADO */
EXPORT PColorRGBA FASTCALL colorRGB( uint8_t R, uint8_t G, uint8_t B ); /* RETORNA/CREA UN COLOR ESPECFICADO DE 0 A 255 EN CADA CANAL/PIGMENTO RGB */
EXPORT PColorRGBA FASTCALL colorRGBA( uint8_t R, uint8_t G, uint8_t B, uint8_t A ); /* RETORNA/CREA UN COLOR ESPECFICADO DE 0 A 255 EN CADA CANAL/PIGMENTO RGB Y TRANSPARENCIA CON A */
EXPORT void       FASTCALL cargarimagen( const char *nombre, IMAGEN *SPR ); /* CARGA UNA IMAGEN. PARAMETRO DE NOMBRE, Y EL TYPO STRUCTURA PUNTERO IMAGEN */
EXPORT void       FASTCALL guardarimagen( const char *nombre, IMAGEN *SPR ); /* GUARDA UNA IMAGEN. PARAMETRO DE NOMBRE, Y EL TYPO DE STRUCTURA PUNTERO IMAGEN */
EXPORT void       FASTCALL pintarimagen( int x, int y, IMAGEN *SPR ); /* DIBUJA LA IMAGEN CENTRADA CON SUS COORDENASA ESPECIFICADAS Y EL TYPO STRUCTURA PUNTERO IMAGEN */
EXPORT void       FASTCALL pintarimagenr( int x, int y, int w, int h, IMAGEN *SPR ); /* DIBUJA LA IMAGEN CENTRADA CON SUS COORDENASA ESPECIFICADAS,TAMAÑO ESPECIFICADOS Y EL TYPO STRUCTURA PUNTERO IMAGEN */
EXPORT void       FASTCALL borrarimagen( IMAGEN *SPR ); /* LIBERA LA IMAGEN DE LA MEMORIA. PASANDOLE EL TYPO STRUCTURA PUNTERO IMAGEN. ES OPCIONAL LLAMARLA SE LIEBRAN SOLAS AL CERRAR EJECUTABLE */
EXPORT void       FASTCALL borrarimagenes( void ); /* LIBERA LAS IMAGENES DE LA MEMORIA, A TODAS', ES OPCIONAL LLAMARLA SE LIEBRAN SOLAS AL CERRAR EJECUTABLE, LLAMELA POR PROTECCIÓN */
EXPORT void       FASTCALL efectoimagen( unsigned int modo, IMAGEN *SPR ); /* INSERTA EFECTO A LA IMAGEN ESPECIFICANDOLE EL EFECTO, CON LA STRUCTURA __EFECTOS_IMAGEN__ */
EXPORT IMAGEN     FASTCALL copiarbufferimagen( IMAGEN *SPR ); /* RETORNA LA COPIA DEL BUFFER PASADO POR EL ARGUMENTO */
EXPORT IMAGEN     FASTCALL rectangulocopiarbufferimagen( unsigned int x, unsigned int y, unsigned int w, unsigned int h, IMAGEN *SPR ); /* RETORNA LA COPIA RECTANGULAR DE LA IAMGEN SELECCIONADA DE LA IMAGEN ORIGINAL */
EXPORT void       FASTCALL pixelimagen( int x, int y, uint32_t color, IMAGEN *SPR ); /* PINTA UN PIXEL EN COORDENADAS Y COLOR ESPECIFICADO USANDO RGB O RGBA DE LA IMAGEN */
EXPORT uint32_t   FASTCALL getpixelimagen( int x, int y, IMAGEN *SPR ); /* OBTIENE EL COLOR DEL PIXEL EN LAS COORDENADAS ESPECIFICADAS. DE LA IMAGEN */
EXPORT void       FASTCALL configimagen( int modo, IMAGEN *SPR ); /* CONFIGURaCIONES DE LA IMAGEN. USE EL ENUM __CONFIGURACION_IMAGEN__, CON LA IMAGEN ESPECIFICADA. */
EXPORT void       FASTCALL crearbufferimagen( unsigned int w, unsigned int h, IMAGEN *SPR ); /* CREAR UNA IMAGEN MEDIANTE SU ANCHO Y ALTO ESPECIFICADOS. CON LA IMAGEN ESPECIFICADA. */
EXPORT void       FASTCALL triangulotextura( int x0, int y0, int x1, int y1, int x2, int y2, int xt0, int yt0, int xt1, int yt1, int xt2, int yt2, IMAGEN *spr ); /* DIBUJA UN TRIANGULO TEXTURA USANDO LAS COORDENADAS ESPECIFICADAS Y LA IMAGEN A MAPEAR. */
EXPORT void       FASTCALL triangulotexturap( PUNTOS P[3], PUNTOS TEX[3], IMAGEN *spr ); /* DIBUJA UN TRIANGULO TEXTURA USANDO LAS COORDENADAS ESPECIFICADAS CON PUNTOS Y LA IMAGEN A MAPEAR. */


/* INICIOS */
EXPORT int      FASTCALL loopinit( void ); /* DETECTA SI LA VENTANA/RENDER ESTA YA ACTIVADA */
EXPORT int      FASTCALL iniciar( int,int,const char* ); /* INICIA LA VENTANA/RENDER */
EXPORT void     FASTCALL pintar( int ); /* LLAMA A PINTAR Y TIRA EL DIBUJO A LA VENTANA/BUFFER */
EXPORT void     FASTCALL salir( void ); /* CANCELA LA VENTANA ELIMINA BUFFER Y SALE DEL RENDER */
EXPORT int      FASTCALL anchov( void ); /* OBTIENE EL ANCHO DE LA VENTANA. */
EXPORT int      FASTCALL altov( void ); /* OBTIENE EL ALTO DE LA VENTANA. */
EXPORT int      FASTCALL ancho( void ); /* OBTIENE EL ANCHO DEL SCREEN/DIBUJADO. */
EXPORT int      FASTCALL alto( void ); /* OBTIENE EL ALTO DEL SCREEN/DIBUJADO. */
EXPORT int      FASTCALL fps( void ); /* OBTIENE LOS FRAMES POR SEGUNDOS LIBRES */
EXPORT float    FASTCALL deltatime( void ); /* DEVUELVE EL VALOR DEL (RETARDO DEL DIBUJADO/DELTA TIME) */
EXPORT void     FASTCALL pintarblur( int espera ); /* LLAMA A PINTAR Y TIRA EL DIBUJO A LA VENTANA/BUFFER CON EFECTO BLUR/DIFUMINAR */

/* CONFIGURACIONES */
EXPORT void     FASTCALL modoventana( int modo ); /* SETEA LA VENTANA EN MODOS DIFERENTES. USANDO DEL ENUM DE MODO_DE_VENTANA. */
EXPORT void     FASTCALL modoconsola( int modo ); /* SETEA EL MODO DE VIZION DE LA CONSOLA CMD/SHEEL USANDO LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_CONSOLA. USE EL FLAG -mwindows SI HAY PROBLEMAS CON LA FUNCIÓN */
EXPORT void     FASTCALL modotitulo( int modo ); /* SETEA EL MODO DE VIZION DEL TITULO ED LA VENTANA. USANDO DEL ENUM DE MODO_DE_TITULO. */

/* DIBUJADOS */
EXPORT void     FASTCALL pixel( int x, int y, uint32_t color ); /* PINTA UN PIXEL EN COORDENADAS Y COLOR ESPECIFICADO USANDO RGB O RGBA */
EXPORT uint32_t FASTCALL getpixel( int x, int y ); /* OBTIENE EL COLOR DEL PIXEL EN LAS COORDENADAS ESPECIFICADAS. */
EXPORT void     FASTCALL borrar( void ); /* BORRA TODO EL DIBUJADO DEJA EN NEGRO/0. EL CANAL A/ALPHA ESTARA EN ALTO/255 */
EXPORT void     FASTCALL fondo( uint32_t color ); /* RELLENA EL DIBUJADO CON EL COLOR ESPECIFICO USANDO RGB O RGBA */
EXPORT void     FASTCALL chars( int x, int y, const char ascii, uint32_t colorB, uint32_t colorF ); /* DIBUJA UA FUENTE DE ASCII DE 8x8 EN SUS COORDENADAS ESPECIFICADAS. Y ASCII STANDAR ESPECIFICADO Y COLOR DE FONDO Y LETRA USANDO RGB O RGBA */
EXPORT void     FASTCALL fontsize( int w, int h ); /* SETEA EL TAMAÑO DE FUENTE EN ANCHO Y ALTO ESTAS NUMERACIONES QUEDAN PARA TODOS LOS DIBUJADOS DE TEXTOS */
EXPORT void     FASTCALL text( int x, int y, uint32_t colorB, uint32_t colorF, const char *texto ); /* DIBUJA UNA CADENA DE ASCII/TEXTOS CON SUS COORDENADAS ESPECIFICADAS. Y COLOR DE FONDO Y LETRA USANDO RGB O RGBA */
EXPORT void     FASTCALL texto( int x, int y, uint32_t colorB, uint32_t colorF, const char *texto, ... ); /* DIBUJA UNA CADENA DE ASCII/TEXTOS CON FORMATOS COMO "PRINTF", CON SUS COORDENAS ESPECIFICADAS. Y COLOR DE FONDO Y LETRA USANDO RGB O RGBA */
EXPORT void     FASTCALL rectangulo( int x, int y, int w, int h, uint32_t color ); /* DIBUJA UN RECTANGULO HUECO DE CUATRO PUNTOS ESPEFICICADOS Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL rectangulofill( int x, int y, int w, int h, uint32_t color ); /* DIBUJA UN RECTANGULO RELLENO DE CUATRO PUNTOS ESPEFICICADOS Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL moveto( int x, int y ); /* SETEA LAS COORDENADAS PRMARIAS USADAS PARA LINEATO */
EXPORT void     FASTCALL lineato( int x, int y, uint32_t color ); /* DIBUJA UNA LINEA SEGUIDA POR COORDENADAS MOVETO, SETEADOS POR COORDENADAS ESPECIFICADAS Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL linea( int x0, int y0, int x1, int y1, uint32_t color ); /* DIBUJA UNA LINEA CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineaw( int x, int w, int y, uint32_t color ); /* DIBUJA UNA LINEA EN HORIZONTAL CON COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineah( int y, int h, int x, uint32_t color ); /* DIBUJA UNA LIENA EN VERTICAL CON SUS COORDENADA ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL circulo( int ox, int oy, int radio, uint32_t color ); /* DIBUJA UN CIRCULO HUECO CON SUS COORDENADAS Y RADIO ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL circulofill( int ox, int oy, int radio, uint32_t color ); /* DIBUJA UN CIRCULO RELLENO CON SUS COORDENADAS Y RADIO ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL triangulo( int x, int y, int x1, int y1, int x2, int y2, uint32_t color ); /* DIBUJA UN TRIANGULO HUECO CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL triangulofill( int X1, int Y1, int X2, int Y2, int X3, int Y3, uint32_t color ); /* DIBUJA UN TRIANGULO RELLENO CON SUS COORDENADAS ESPECIFICAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL polygon( uint32_t cantidad, PUNTOS p[], uint32_t color ); /* DIBUJA POLIGONOS HUECO CON SUS COORDENADAS ESPECIFICADAS. USANDO LA STRUCTURA PUNTOS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL polygonfill( uint32_t cantidad, PUNTOS p[], uint32_t color ); /* DIBUJA POLIGONOS RELLENOS CON SUS COORDENADAS ESPECIFICADAS. USANDO LA STRUCTURA PUNTOS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineagr( int x0, int y0, int x1, int y1, uint32_t colorA, uint32_t colorB ); /* DIBUJA UNA LINEA GRADIENTE CON SUS COORDENADAS ESPECIFICADAS. Y EL COLOR VA DESDE EL COLOR A, ASTA YEGAR AL COLOR B. SE LO LLAMA GRADIENTE DE COLOR */
EXPORT void     FASTCALL triangulogr( int x, int y, int x1, int y1, int x2, int y2, uint32_t colorA, uint32_t colorB, uint32_t colorC ); /* DIBUJA UN TRIANGULO GRADIENTE CON SUS COORDENADAS ESPECIFICADAS. Y EL COLOR VA DESDE EL COLOR A, LUEGO YEGAR AL COLOR B, LUEGO YEGAR AL COLOR C Y VOLVER AL COLOR DE A, SE LO LLAMA GRADIENTE DE COLOR */
EXPORT void     FASTCALL triangulofillgr( int x1, int y1, int x2, int y2, int x3, int y3, uint32_t colorA, uint32_t colorB, uint32_t colorC ); /* DIBUJA UN TRIANGULO RELLENO GRADIENTE CON SUS COORDENADAS ESPECIFICADAS. Y EL COLOR VA DESDE EL COLOR A, LUEGO YEGAR AL COLOR B, LUEGO YEGAR AL COLOR C Y VOLVER AL COLOR DE A, SE LO LLAMA GRADIENTE DE COLOR */
EXPORT void     FASTCALL cuadricula( int itilesx, int itilesy, uint32_t color ); /* DIBUJA UNA CUADRICULA CON TODO EL RENDER/SCREEN CON SEPARAMIENTOS ESPECIFICADOS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineanorm(  int x0, int y0, int x1, int y1, uint32_t color  ); /* DIBUJA UNA LINEA NORMALIZADA POR VECTORES CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL linearc( int x, int y, int w, int h, uint32_t color ); /* DIBUJA UNA LINEA MEDIANTE RECORTE CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineawgr( int x, int w, int y, uint32_t color1, uint32_t color2); /* DIBUJA UNA LÍNEA HORIZONTAL GRADIANTE DE 2 COLORES */
EXPORT void     FASTCALL lineahgr( int x, int w, int y, uint32_t color1, uint32_t color2); /* DIBUJA UNA LÍNEA VERTICAL GRADIANTE DE 2 COLORES */
EXPORT void     FASTCALL desvanecerse( uint8_t alpha ); /* EFECTO DESVANECERSE EN TODO SCREEN. ESPECIFICANDO EN 0 - 255 */
EXPORT void     FASTCALL desvanecimiento( uint8_t alpha ); /* EFECTO DESVANECIMIENTO EN TODO SCREEN. ESPECIFICANDO EN 0 - 255 */
EXPORT void     FASTCALL tinte( uint32_t color ); /* EFECTO DE TINTERO AMBIENTAL EN TODO EL SCREEN. USANDO RGB O RGBA */
EXPORT void     FASTCALL lineaaliasing( int x0, int y0, int x1, int y1, uint32_t color ); /* DIBUJA UNA LINEA CON ALIASING. ESPECIFICANDO LAS CORDENADAS Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL vaciardepthbuffer( void ); /* VACIA EL DEPTHBUFFER, LO EJA EN CEROS. */
EXPORT void     FASTCALL pixeldepth( int x, int y, float depth, uint32_t color ); /* DIBUJA UN PIXEL SI EN SU POSICION EN EL DEPTHBUFFER HAY UN VALOR DE PROFUNDIDAD MAYOR AL SUYO, O IGUAL A CERO. */
EXPORT double   FASTCALL getpixeldepth( int x, int y ); /* OBTIENE EL VALOR EN LA POSICION DEL DEPTHBUFFER. */

/* EXTRAS */
EXPORT uint32_t FASTCALL pixelp( PUNTOS P, void* colore ); /* DIBUJA UN PIXEL EL COORDENADAS STRUCTURA PUNTOS ESPECIFICADAS. Y COLOR USANDO colorRGB O colorRGBA. SI EL COLOR ES NULL RETORNA EL COLOR EN LAS COORDENADAS ESPECIFICADAS. FUNCIONA COMO GETPIXEL */
EXPORT void     FASTCALL triangulofillgrp( PUNTOS a[3], uint32_t colorA, uint32_t colorB, uint32_t colorC ); /* DIBUJA UN TRIANGULO RELLENO GRADIENTE CON SUS COORDENADAS ESPECIFICADAS CON LA STRUCTURA PUNTOS. Y EL COLOR VA DESDE EL COLOR A, LUEGO YEGAR AL COLOR B, LUEGO YEGAR AL COLOR C Y VOLVER AL COLOR DE A, SE LO LLAMA GRADIENTE DE COLOR */
EXPORT void     FASTCALL rectangulogr( int x, int y, int w, int h, uint32_t color1, uint32_t color2, uint32_t color3, uint32_t color4 ); /* DIBUJA UN RECTÁNGULO HUECO GRADIANTE CON 4 COLORES EN CADA ESQUINA */
EXPORT void     FASTCALL rectangulofillgr( int x, int y, int w, int h, uint32_t color1, uint32_t color2, uint32_t color3, uint32_t color4  ); /* DIBUJA UN RECTÁNGULO RELLENO GRADIANTE CON 4 COLORES EN CADA ESQUINA */
EXPORT void     FASTCALL lineap( PUNTOS a[2], uint32_t color ); /* DIBUJA UNA LINEA CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL circulop( PUNTOS a, uint32_t r, uint32_t color ); /* DIBUJA UN CIRCULO HUECO CON SUS COORDENADAS Y RADIO ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL circulofillp( PUNTOS a, uint32_t r, uint32_t color ); /* DIBUJA UN CIRCULO RELLENO HUECO CON SUS COORDENADAS Y RADIO ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL movetop( PUNTOS a ); /* SETEA LAS COORDENADAS PRMARIAS USADAS PARA LINEATO */
EXPORT void     FASTCALL lineatop( PUNTOS a, uint32_t color ); /* DIBUJA UNA LINEA SEGUIDA POR COORDENADAS MOVETO, SETEADOS POR COORDENADAS ESPECIFICADAS Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL triangulop( PUNTOS a[3], uint32_t color ); /* DIBUJA UN TRIANGULO CON SUS COORDENADAS ESPECIFICAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL triangulofillp( PUNTOS a[3], uint32_t color ); /* DIBUJA UN TRIANGULO RELLENO CON SUS COORDENADAS ESPECIFICAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineagrp( PUNTOS a[2], uint32_t colorA, uint32_t colorB ); /* DIBUJA UNA LINEA GRADIENTE CON SUS COORDENADAS ESPECIFICADAS. Y EL COLOR VA DESDE EL COLOR A, ASTA YEGAR AL COLOR B. SE LO LLAMA GRADIENTE DE COLOR */
EXPORT void     FASTCALL triangulogrp( PUNTOS a[3], uint32_t colorA, uint32_t colorB, uint32_t colorC ); /* DIBUJA UN TRIANGULO GRADIENTE CON SUS COORDENADAS ESPECIFICADAS. Y EL COLOR VA DESDE EL COLOR A, LUEGO YEGAR AL COLOR B, LUEGO YEGAR AL COLOR C Y VOLVER AL COLOR DE A, SE LO LLAMA GRADIENTE DE COLOR */
EXPORT void     FASTCALL cuadriculap( PUNTOS a, uint32_t color ); /* DIBUJA UNA CUADRICULA CON TODO EL RENDER/SCREEN CON SEPARAMIENTOS ESPECIFICADOS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineanormp( PUNTOS a[2], uint32_t color ); /* DIBUJA UNA LINEA NORMALIZADA POR VECTORES CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL linearcp( PUNTOS a[2], uint32_t color ); /* DIBUJA UNA LINEA MEDIANTE RECORTE CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineaaliasingp( PUNTOS a[2], uint32_t color ); /* DIBUJA UNA LINEA CON ALIASING. ESPECIFICANDO LAS CORDENADAS USANDO LA STRUCTURA PUNTOS Y COLOR USANDO RGB O RGBA */

/* INPUTS Y OUTPUTS */
EXPORT _Bool    FASTCALL tecla( char ); /* OBTIENE LAS TECLAS PRESIONADA */
EXPORT _Bool    FASTCALL tecla2( char ); /* OBTIENE LA TECLA PRESIONADA NUEVA DE TECLA */
EXPORT char     FASTCALL asciitecla( void ); /* OBTIENE EL CODIGO ASCII DE LAS TECLA PRESIONADA */
EXPORT _Bool    FASTCALL mouse( void ); /* OBTIENE SI EL MOUSE ESTA DENTRO DE LA VENTANA */
EXPORT int      FASTCALL mouserueda( void ); /* OBTIENE EL VALOR DEL GIRO DE lA RUEDA */
EXPORT int      FASTCALL mousex( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN X DE TODA LA VENTANA */
EXPORT int      FASTCALL mousey( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN Y DE TODA LA VENTANA */
EXPORT _Bool    FASTCALL arrastre( void ); /* OBTIENE SI ESTA ARRASTRANDO CON EL PUNTERO MOUSE MANTENIÉNDOSE APRETADO */
EXPORT void     FASTCALL raton_botones( _Bool *izq, _Bool *der ); /* OBTIENE EN MEMORIA DE TAL VARIABLE LOS BOTONES IZQUIERDO Y DERECHO DEL MOUSE */
EXPORT _Bool    FASTCALL izquierdo( int mode ); /* OBTIENE LA PULSACION IZQUIERDO DEL MOUSE. SU MODO DE RESPUESTA USANDO LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_MOUSE */
EXPORT _Bool    FASTCALL derecho( int mode ); /* OBTIENE LA PULSACION DERECHO DEL MOUSE. SU MODO DE RESPUESTA USANDO LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_MOUSE */
EXPORT int      FASTCALL comandomenu( void ); /* OBTIENE EL COMANDO AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */
EXPORT _Bool    FASTCALL comandomenu2( int ids ); /* OBTIENE UNA UNICA VEZ AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */
EXPORT char*    FASTCALL abrirfichero( void ); /* OBTIENE UNA APERTURA HACIA LOS FICHEROS PARA ELEJIR Y RETORNA SU RUTA */
EXPORT PUNTOS   FASTCALL pmousexy( void ); /* OBTIENE LAS COORDENADAS DEL MOUSE Y LO RETORNA EN UNA STRUCTURA PUNTOS. */
EXPORT PUNTOSF   FASTCALL pfmousexy( void ); /* OBTIENE LAS COORDENADAS DEL MOUSE Y LO RETORNA EN UNA STRUCTURA PUNTOSF. */
EXPORT PUNTOSI   FASTCALL pimousexy( void ); /* OBTIENE LAS COORDENADAS DEL MOUSE Y LO RETORNA EN UNA STRUCTURA PUNTOSI. */
EXPORT PUNTOSD   FASTCALL pdmousexy( void ); /* OBTIENE LAS COORDENADAS DEL MOUSE Y LO RETORNA EN UNA STRUCTURA PUNTOSD. */
#include <stdio.h>
EXPORT FILE*    FASTCALL abrirficherof( const char ModoDeAperturaFile[] ); /* OBTIENE UNA APERTURA HACIA LOS ARCHIVOS PARA ELEJIR Y RETORNA UN PUNTERO FILE. SE PUEDE ELEJIR EL MODO DE APERTURA USANDOLOS DEFINES DE ARCHIVOMODE */
EXPORT uint32_t FASTCALL RGBpicker( void ); /* OBTIENE EL ELEJIDO DE COLORES EN UNA VENTANA SEPARADA. RETORNA EL COLOR ELEJIDO */
EXPORT void     FASTCALL menu( const char *nombre, DWORD id ); /* INICIA UN MENU CON IDENTIDAD. USE COMANDO O COMANDO2 PARA SABER SU SALIDA. */
EXPORT void     FASTCALL menuagregar( const char *nombre ); /* INICIA UN MENU SIN IDENTIDAD. USE COMANDO O COMANDO2 PARA SABER SU SALIDA. */
EXPORT void     FASTCALL menuid( const char *nombre, DWORD id ); /* CREA UN MENU CON IDENTIDAD. USE COMANDO O COMANDO2 PARA SABER SU SALIDA. */
EXPORT void     FASTCALL submenu( const char *nombre, DWORD id ); /* CREA UN SUBMENU CON IDENTIDAD LUEGO DE LLAMAR A MENUAGREGAR, NO SE PUEDE CON: MENU, MENUID, MENUSEPARADOR. USE COMANDO O COMANDO2 PARA SABER SU SALIDA.  */
EXPORT void     FASTCALL submenupop( const char *nombre ); /* CREA UN SUBMENU-POP SIN IDENTIDAD LUEGO DE LLAMAR A MENUAGREGAR, NO SE PUEDE CON: MENU, MENUID, MENUSEPARADOR */
EXPORT void     FASTCALL submenusub( const char *nombre, DWORD id ); /* CREA UN SUBMENU-SUB CON IDENTIDAD LUEGO DE LAMAR. NO SE PUEDE CON: MENU, MENUID, MENUAGREGAR, MENUSEPARADOR A SUBMENU-POP. USE COMANDO O COMANDO2 PARA SABER SU SALIDA. */
EXPORT void     FASTCALL menuseparador( void ); /* CREA UN SEPARADOR DE MENU'S. NO SE PUEDE CON: SUBMENU, SUBMENUSUB */
EXPORT void     FASTCALL menumostrar( void ); /* MUESTRA EL MENU */
EXPORT char *   FASTCALL dropfichero( void ); /* OBTIENE EL NOMBRE DEL ARCHIVO VOLCADO A LA VENTANA */

#ifdef __cplusplus
    }
#endif
