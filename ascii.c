#include <stdio.h>

void ascii();

int main(){
    ascii();
    return 0;
}

void ascii(){
    unsigned char i;
    for (i = 1; i < 256; i++){
        printf("\n%d -> %c", i, i);
    }
}