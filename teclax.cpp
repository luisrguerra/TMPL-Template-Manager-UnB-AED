#include <iostream> // necessario para o cout
#include <conio.h>

int tecla_prescionada(){
///checa primeiro se o teclado est� prescionado para depois pegar tecla. caso n�o. o programa � pausado at� se prescionar uma tecla
int tecla;
if (kbhit() != 0) { //// se a alguma tecla estiver precionada
    tecla=getch(); ///// define a tecla para a tecla atual precionada
    }	
}


