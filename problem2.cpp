#include <iostream>

int getLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int getShiftValue(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 1);
    } else if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 1);
    }
    return 0;
}

char shiftChar(char c, int shift) {
    if (c >= 'A' && c <= 'Z') {
        return (char)('A' + (c - 'A' + shift) % 26);
    } else if (c >= 'a' && c <= 'z') {
        return (char)('a' + (c - 'a' + shift) % 26);
    }
    return c;
}

int main() {
    char input[1000];
    char output[1000];

    std::cin.getline(input, 1000);

    int len = getLength(input);

    if (len > 0) {
        output[0] = input[0];

        for (int i = 1; i < len; i++) {
            char prevChar = input[i - 1];
            int shift = getShiftValue(prevChar);
            output[i] = shiftChar(input[i], shift);
        }

        output[len] = '\0'; 
    }

    std::cout << output << std::endl;

    return 0;
}
