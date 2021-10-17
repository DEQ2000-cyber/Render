#include "render.h"
#include <stdlib.h>

int main(void){

    iniciar( 500,500, "Test" );
    int i,o;
    modoconsola( OCULTAR );
    fontsize( 80,80 );

    while( loopinit() ){
        if (tecla(27))break;

        for (i=0; i<500; ++i)
        for (o=0; o<500; ++o)
        pixel( o,i, RGBA( rand()%256, rand()%256, rand()%256, rand()%256 ) );

        texto( 0,0, RGB(255,0,0), "X:%i\nY:%i", mousex(), mousey() );

        pintar( 10 );
    }

    modoconsola( NOOCULTAR );
    salir();
    return (0);
}
