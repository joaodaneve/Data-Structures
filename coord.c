#include <stdio.h>

/*
Implemente uma função que indique se um ponto (x,y) está localizado dentro ou fora de um retângulo.
O retângulo é definido por seus vértices inferior esquerdo (x0,y0) e superior direito (x1,y1)
A função deve retornar 1 se o ponto estiver dentro do retângulo e 0 se estiver fora
*/

int dentro_ret(int, int, int, int, int, int);

int main(){

    printf("%d\n", dentro_ret(2,1,4,6,3,3));
    return 0;

}

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
    if (x>=x0 && x<=x1 && y>=y0 && y<=y1)
        return 1;
    else
        return 0;
}