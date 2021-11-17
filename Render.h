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


    VERSION: Alpha 7.9.0.
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
    [SE AGREGO]: RGB : POR DEQ -> Eliminado
    [SE AGREGO]: RGBA : POR DEQ -> Eliminado
    [SE AGREGO]: GetAValue : POR DEQ -> Eliminado

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
    [SE AGREGO]: modotimedelta : POR DEQ PEDIDO POR JTB

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
#define ORB "rb" // OpenReadBynari
#define ORN "r"  // OpenReadNormal
#define OWB "wb" // OpenWriteBynari
#define OWN "w"  // OpenWriteNormal



#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef uint16_t    u16,    U16;
typedef uint32_t    u32,    U32;
typedef int16_t     i16,    I16;
typedef int32_t     i32,    I32;
typedef int8_t      i8,     I8;
typedef uint8_t     u8,     U8;
typedef float       f32,    F32;


enum MODO_DE_CONSOLA{
    OCULTAR     =   2,
    NOOCULTAR   =   4
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
/* Strutura a puntos 2D en floats */
typedef struct tagPUNTOS
{
    float x,y;
} PUNTOS;
#endif





/* VERSION HOY EN DIA DEL PROYECTO RENDER.H */
EXPORT void VERSION( void );



/* EXTRAS */
EXPORT uint32_t*  FASTCALL DATABGRA( void ); /* OBTIENE EL PUNTERO DATA BGRA DEL SCREEN/DIBUJADO */
EXPORT PColorRGBA FASTCALL colorRGB( uint8_t R, uint8_t G, uint8_t B ); /* RETORNA/CREA UN COLOR ESPECFICADO DE 0 A 255 EN CADA CANAL/PIGMENTO RGB */
EXPORT PColorRGBA FASTCALL colorRGBA( uint8_t R, uint8_t G, uint8_t B, uint8_t A ); /* RETORNA/CREA UN COLOR ESPECFICADO DE 0 A 255 EN CADA CANAL/PIGMENTO RGB Y TRANSPARENCIA CON A */
EXPORT void       FASTCALL fondoimagen( const char *nombre ); /* DIBUJA UNA IMAGEN PARA EL FONDO. PASANDOLE POR PARAMETRO EL NOMBRE/RUTA DE LA IMAGEN, ESTE LO LEERA Y DIBUJADA SU LECTURA SERA UNICA VEZ NO SERA UNICA ASTA QUE LA IMAGEN SEA OTRO NOMBRE */


/* INICIOS */
EXPORT int      FASTCALL loopinit( void ); /* DETECTA SI LA VENTANA/RENDER ESTA YA ACTIVADA */
EXPORT int      FASTCALL iniciar( int,int,const char* ); /* INICIA LA VENTANA/RENDER */
EXPORT void     FASTCALL pintar( int ); /* LLAMA A PINTAR Y TIRA EL DIBUJO A LA VENTANA/BUFFER */
EXPORT void     FASTCALL salir( void ); /* CANCELA LA VENTANA ELIMINA BUFFER Y SALE DEL RENDER */
EXPORT float    FASTCALL deltatime( void ); /* DEVUELVE EL VALOR DEL (RETARDO DEL DIBUJADO/DELTA TIME) */

/* CONFIGURACIONES */
EXPORT void     FASTCALL modoventana( int modo ); /* SETEA LA VENTANA EN MODOS DIFERENTES. USANDO DEL ENUM DE MODO_DE_VENTANA. */
EXPORT void     FASTCALL modoconsola( int modo ); /* SETEA EL MODO DE VIZION DE LA CONSOLA CMD/SHEEL USANDO LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_CONSOLA. USE EL FLAG -mwindows SI HAY PROBLEMAS CON LA FUNCIÓN */
EXPORT void     FASTCALL modotimedelta( int modo ); /* SETEA EL MODO DE VIZION DEL TITULO VENTANA LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_CONSOLA. */

/* DIBUJADOS */
EXPORT void     FASTCALL pixel( int x, int y, uint32_t color ); /* PINTA UN PIXEL EN COORDENADAS Y COLOR ESPECIFICADO USANDO RGB O RGBA */
EXPORT uint32_t FASTCALL getpixel( int x, int y ); /* OBTIENE EL COLOR DEL PIXEL EN LAS COORDENADAS ESPECIFICADAS. */
EXPORT void     FASTCALL borrar( void ); /* BORRA TODO EL DIBUJADO DEJA EN NEGRO/0. EL CANAL A/ALPHA ESTARA EN ALTO/255 */
EXPORT void     FASTCALL fondo( uint32_t color ); /* RELLENA EL DIBUJADO CON EL COLOR ESPECIFICO USANDO RGB O RGBA */
EXPORT void     FASTCALL chars( int x, int y, const char ascii, uint32_t color ); /* DIBUJA UA FUENTE DE ASCII DE 8x8 EN SUS COORDENADAS ESPECIFICADAS. Y ASCII STANDAR ESPECIFICADO Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL fontsize( int w, int h ); /* SETEA EL TAMAÑO DE FUENTE EN ANCHO Y ALTO ESTAS NUMERACIONES QUEDAN PARA TODOS LOS DIBUJADOS DE TEXTOS */
EXPORT void     FASTCALL text( int x, int y, uint32_t color, const char *texto ); /* DIBUJA UNA CADENA DE ASCII/TEXTOS CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL texto( int x, int y, uint32_t color, const char *texto, ... ); /* DIBUJA UNA CADENA DE ASCII/TEXTOS CON FORMATOS COMO "PRITF", CON SUS COORDENAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
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
EXPORT void     FASTCALL cuadricula( int itilesx, int itilesy, uint32_t color ); /* DIBUJA UNA CUADRICULA CON TODO EL RENDER/SCREEN CON SEPARAMIENTOS ESPECIFICADOS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL lineanorm( int x1, int y1, int x2, int y2, uint32_t color ); /* DIBUJA UNA LINEA NORMALIZADA POR VECTORES CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT void     FASTCALL linearc( int x, int y, int w, int h, uint32_t color ); /* DIBUJA UNA LINEA MEDIANTE RECORTE CON SUS COORDENADAS ESPECIFICADAS. Y COLOR USANDO RGB O RGBA */
EXPORT uint32_t FASTCALL pixelp( PUNTOS P, void* colore ); /* DIBUJA UN PIXEL EL COORDENADAS STRUCTURA PUNTOS ESPECIFICADAS. Y COLOR USANDO colorRGB O colorRGBA. SI EL COLOR ES NULL RETORNA EL COLOR EN LAS COORDENADAS ESPECIFICADAS. FUNCIONA COMO GETPIXEL */
/* INPUTS Y OUTPUTS */
EXPORT int      FASTCALL anchov( void ); /* OBTIENE EL ANCHO DE LA VENTANA. */
EXPORT int      FASTCALL altov( void ); /* OBTIENE EL ALTO DE LA VENTANA. */
EXPORT int      FASTCALL ancho( void ); /* OBTIENE EL ANCHO DEL SCREEN/DIBUJADO. */
EXPORT int      FASTCALL alto( void ); /* OBTIENE EL ALTO DEL SCREEN/DIBUJADO. */
EXPORT _Bool    FASTCALL tecla( char ); /* OBTIENE LAS TECLAS PRESIONADA */
EXPORT int      FASTCALL mousex( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN X DE TODA LA VENTANA */
EXPORT int      FASTCALL mousey( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN Y DE TODA LA VENTANA */
EXPORT _Bool    FASTCALL arrastre( void ); /* OBTIENE SI ESTA ARRASTRANDO CON EL PUNTERO MOUSE MANTENIÉNDOSE APRETADO */
EXPORT void     FASTCALL raton_botones( _Bool *izq, _Bool *der ); /* OBTIENE EN MEMORIA DE TAL VARIABLE LOS BOTONES IZQUIERDO Y DERECHO DEL MOUSE */
EXPORT _Bool    FASTCALL izquierdo( int mode ); /* OBTIENE LA PULSACION IZQUIERDO DEL MOUSE. SU MODO DE RESPUESTA USANDO LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_MOUSE */
EXPORT _Bool    FASTCALL derecho( int mode ); /* OBTIENE LA PULSACION DERECHO DEL MOUSE. SU MODO DE RESPUESTA USANDO LAS ESPECIFICACIONES DEL ENUM DE MODO_DE_MOUSE */
EXPORT int      FASTCALL comandomenu( void ); /* OBTIENE EL COMANDO AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */
EXPORT _Bool    FASTCALL comandomenu2( int ids ); /* OBTIENE UNA UNICA VEZ AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */
EXPORT char*    FASTCALL abrirfichero( void ); /* OBTIENE UNA APERTURA HACIA LOS FICHEROS PARA ELEJIR Y RETORNA SU RUTA */
#include <stdio.h>
EXPORT FILE*    FASTCALL abrirficherof( const char ModoDeAperturaFile[] ); /* OBTIENE UNA APERTURA HACIA LOS ARCHIVOS PARA ELEJIR Y RETORNA UN PUNTERO FILE. SE PUEDE ELEJIR EL MODO DE APERTURA USANDOLOS DEFINES DE ARCHIVOMODE */
EXPORT uint32_t FASTCALL RGBpicker( void ); /* OBTIENE EL ELEJIDO DE COLORES EN UNA VENTANA SEPARADA. RETORNA EL COLOR ELEJIDO */

#ifdef __cplusplus
    }
#endif
