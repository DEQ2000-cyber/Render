#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

/*
  VERSION: Alpha 1.0.0: Lanzamiento.
  20:16 Argentina Daniel Efrain Quiroga
  06:20 Mexicam Andres Ruiz perez
  06:36 Colombia Jheison Toro Betancourth
  -----------------------
  |16 de octubre de 2021|
  -----------------------
*/



/*
//Codigo de ejemplo

#include "render.h"
#include <stdio.h>
int main(void){
   iniciar( 500,500, "Test" );
   while( loopinit() ){
      if (tecla(27))break;
      printf("%c\n", 1 );
      pintar( 10 );
   }
   salir();
   return (0);
}
*/

#include <stdbool.h>
#include <stdint.h>



struct tagInOut
{
  bool Key[256];
  int xPos, yPos;
  bool ARRASTRE, _bot_izq, _bot_der;
  int comando_salida;

} DEQInOut;

typedef union tagRGBA
{
  uint32_t rgba;
  unsigned char c[4];
} __COLORS__;

#define RGBA(r,g,b,a)((uint32_t)((uint16_t)(b) | ((uint16_t)(g) << 8) | ((uint16_t)(r) << 16)) | ((uint16_t)(a) << 24) )
#undef RGB
#define RGB(r,g,b)((uint32_t)((uint16_t)(b) | ((uint16_t)(g) << 8) | ((uint16_t)(r) << 16)) | ((uint16_t)(255) << 24) )
#define GetAValue(rgb) (LOBYTE((rgb)>>24))


#ifdef __cplusplus
#define FASTCALL __stdcall
#else
#define FASTCALL __fastcall
#endif

/* VERSION HOY EN DIA DEL PROYECTO RENDER.H */
EXPORT void VERSION( void );

/* INICIOS */
EXPORT int      FASTCALL loopinit( void ); /* DETECTA SI LA VENTANA/RENDER ESTA YA ACTIVADA */
EXPORT int      FASTCALL iniciar( int,int,const char* ); /* INICIA LA VENTANA/RENDER */
EXPORT void     FASTCALL pintar( int ); /* LLAMA A PINTAR Y TIRA EL DIBUJO A LA VENTANA/BUFFER */
EXPORT void     FASTCALL salir( void ); /* CANCELA LA VENTANA ELIMINA BUFFER Y SALE DEL RENDER */
EXPORT float    FASTCALL deltatime( void ); /* DA EL VALOR DEL (RETARDO DEL DIBUJADO/DELTA TIME) */
/* DIBUJADOS */
EXPORT void     FASTCALL pixel( int, int, uint32_t ); /* PINTA UN PIXEL EN COORDENADAS Y COLOR ESPECIFICADO USANDO RGB Y RGBA */
EXPORT uint32_t FASTCALL getpixel( int, int ); /* OBTIENE EL COLOR DEL PIXEL EN LAS COORDENADAS ESPECIFICADO */
EXPORT void     FASTCALL borrar( void ); /* BORRA TODO EL DIBUJADO DEJA EN NEGRO/0 */
EXPORT void     FASTCALL fondo( uint32_t ); /* RELLENA EL DIBUJADO CON EL COLOR ESPECIFICO USANDO RGB Y RGBA */
/* INPUTS Y UOTPUTS */
EXPORT bool     FASTCALL tecla( char ); /* OBTIENE LAS TECLAS PRESIONADA */
EXPORT int      FASTCALL mousex( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN X DE TODA LA VENTANA */
EXPORT int      FASTCALL mousey( void ); /* OBTIENE LA COORDENADA DEL PUNTERO MOUSE EN Y DE TODA LA VENTANA */
EXPORT bool     FASTCALL arrastre( void ); /* OBTIENE SI ESTA ARRASTRANDO CON EL PUNTERO MOUSE MANTENIÉNDOSE APRETADO */
EXPORT void     FASTCALL raton_botones( bool *izq, bool *der ); /* OBTIENE EN MEMORIA DE TAL VARIABLE LOS BOTONES IZQUIERDO Y DERECHO DEL MOUSE */
EXPORT bool     FASTCALL izquierdo( void ); /* OBTIENE LA PULSACION IZQUIERDO DEL MOUSE */
EXPORT bool     FASTCALL derecho( void ); /* OBTIENE LA PULSACION DERECHO DEL MOUSE */
EXPORT int      FASTCALL comandomenu( void ); /* OBTIENE EL COMANDO AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */
EXPORT bool     FASTCALL comandomenu2( int ids ); /* OBTIENE UNA UNICA VEZ AL PULSAR LOS BOTONES DEL COMANDO DE LA VENTANA */