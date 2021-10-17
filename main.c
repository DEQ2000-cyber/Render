#include "render.h"
#include <stdlib.h>

int main(void){

   iniciar( 500,500, "Test" );
   int i,o;

   while( loopinit() ){
      if (tecla(27))break;

      for (i=0; i<500; ++i)
      for (o=0; o<500; ++o)
      pixel( o,i, RGBA( rand()%256, rand()%256, rand()%256, rand()%256 ) );

      pintar( 0 );
   }
   salir();
   return (0);
}
