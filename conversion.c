
 #include <stdio.h>
#include <string.h>


int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(const char *hexNumber);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(const char *hexNumber);
void displayMenu();

int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;

            case 0:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Menu Display Function
void displayMenu() {
    printf("\nNumerical Conversion Program\n");
    printf("1. Convert Binary to Decimal\n");
    printf("2. Convert Decimal to Binary\n");
    printf("3. Convert Decimal to Hexadecimal\n");
    printf("4. Convert Hexadecimal to Decimal\n");
    printf("5. Convert Binary to Hexadecimal\n");
    printf("6. Convert Hexadecimal to Binary\n");
    printf("0. Exit\n");
}

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, remainder;

    while (number > 0) {
        remainder = number % 10;
        decimal += remainder * base;
        base *= 2;
        number /= 10;
    }

    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;

    while (number > 0) {
        binary += (number % 2) * base;
        number /= 2;
        base *= 10;
    }

    return binary;
}


void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;

    if (number == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (number > 0) {
        int remainder = number % 16;
        hex[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        number /= 16;
    }
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    printf("\n");
}

void HexadecimalToDecimal(const char *hexNumber) {
    int decimal = 0;
    int base = 1;
    int len = strlen(hexNumber);

    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += (hexNumber[i] - '0') * base;
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimal += (hexNumber[i] - 'A' + 10) * base;
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            decimal += (hexNumber[i] - 'a' + 10) * base;
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        base *= 16;
    }
    printf("Decimal: %d\n", decimal);
}


void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(const char *hexNumber) {
    int decimal = 0;
    int base = 1;
    int len = strlen(hexNumber);

    
    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += (hexNumber[i] - '0') * base;
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimal += (hexNumber[i] - 'A' + 10) * base;
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            decimal += (hexNumber[i] - 'a' + 10) * base;
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        base *= 16;
    }

    // Convert Decimal to Binary
    printf("Binary: %d\n", DecimalToBinary(decimal));
}
