# Render
Render.h es una librería básica de dibujados de ventanas win32.

De esta manera iniciamos al motor grafico.
<br>
![Screenshot](IMG/screenshot1.bmp)
<br>
sus palabras claves son faciles de entender y ejecutar.
<br><br><br>


# Funciones:
<br>
loopinit( void );
<br>
DETECTA SI LA VENTANA/RENDER ESTA YA ACTIVADA
<br><br>

iniciar( int ancho, int alto, const char* titulo );
<br>
INICIA LA VENTANA/RENDER
<br><br>

pintar( int espera );
<br>
LLAMA A PINTAR Y TIRA EL DIBUJO A LA VENTANA/BUFFER
<br><br>

salir( void );
<br>
CANCELA LA VENTANA ELIMINA BUFFER Y SALE DEL RENDER
<br><br>

deltatime( void );
<br>
DEVUELVE EL VALOR DEL (RETARDO DEL DIBUJADO/DELTA TIME)
<br><br>

pintarblur( int espera );
<br>
LLAMA A PINTAR Y TIRA EL DIBUJO A LA VENTANA/BUFFER CON EFECTO BLUR/DIFUMINAR
<br><br>



@Andres Ruiz perez
@Jheison Toro Betancourth
@Daniel Efrain Quiroga
