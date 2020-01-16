// Robert's "replace foo with bar in in input" state machine program 

#include <stdio.h>

enum States {
    SCANNING,
    FOUND_F,
    FOUND_FIRST_O
};

void output_char(enum States state, int c) {
    if (state != SCANNING) {
        printf("f");
    }
    if (state == FOUND_FIRST_O) {
        printf("o");
    }
    if (c != EOF) {
        printf("%c",c);
    }
}

int main() {
    int c, state;
    
    state = SCANNING;
    while ((c = getchar()) != EOF) {
        if (state == FOUND_FIRST_O && c == 'o') {
            printf("bar");
            state = SCANNING;
        } else if (state == FOUND_F && c == 'o') {
            state = FOUND_FIRST_O;
        } else if (state == SCANNING && c == 'f') {
            state = FOUND_F;
        } else {
            output_char(state, c);
            state = SCANNING;
        }
    }
    output_char(state, c);
}
