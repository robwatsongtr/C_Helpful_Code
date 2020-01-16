// C code to do a basic traversal (for loop).
// of an array by both pointer and array notation.
//
// also shows basic use of getline() function

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char *buffer;
    size_t bufsize = 32;
    size_t c;
    char *p = NULL;
    buffer = NULL;
   
    printf("Type something: ");
    c = getline(&buffer,&bufsize,stdin);
    
    for(p = buffer; p < buffer + c - 1; ++p) {
        printf("%c", *p);
    }
    
    printf("\n");
    
    for(int i = 0; i < c - 1; ++i) {
        printf("char at %d is %c \n", i, buffer[i]);
    }
    
}
