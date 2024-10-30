 #include <stdio.h>
#include <string.h>

#define max 128

void Character(char *slo) {
    int freq[max] = {0};
    
    for (int i = 0; slo[i] != '\0'; i++) {
        char ch = slo[i];
        freq[(int)ch]++;
    }

    printf("For \"%s\": {", slo);
    int first = 1;
    for (int i = 0; i < max; i++) {
        if (freq[i] > 0) {
            if (!first) {
                printf(", ");
            }
            printf("'%c': %d", (char)i, freq[i]);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
     char *slo[] = {"buy now", "save big", "limited offer"};
    int Slogans = sizeof(slo) / sizeof(slo[0]);

    // Process each slogan
    for (int i = 0; i < Slogans; i++) {
        Character(slo[i]);
    }
    return 0;
}