 #include <stdio.h>
#include <string.h>

#define length 100
#define max 100

// Function to compress a single word
void Word(char *word, char *compressed, int *Count) {
    int j = 0;
    *Count = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressed[j++] = word[i];
        } else {
            (*Count)++;
        }
    }
    compressed[j] = '\0';
}

// Function to compress a list of words
void compressWords(char words[][max], int size) {
    for (int i = 0; i < size; i++) {
        char compressed[length];
        int Count = 0;
        
        Word(words[i], compressed, &Count);
        
        printf("Original: %s, Compressed: %s, Characters Removed: %d\n", words[i], compressed, Count);
    }
}

int main() {
    char words[max][length];
    int size;

    printf("Enter the number of words: ");
    scanf("%d", &size);

    if (size > max) {
        printf("Error: Exceeds maximum number of words (%d)\n", max);
        return 1;
    }

    printf("Enter each word:\n");
    for (int i = 0; i < size; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    printf("\nCompressed words:\n");
    compressWords(words, size);

    return 0;
}
