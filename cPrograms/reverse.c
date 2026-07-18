#include <stdio.h>
#include <string.h>

void reverse(char* p) {
    int i = 0;
    int j = strlen(p)-1;
    while(i < j) {
        char temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[100];

    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    reverse(str);

    for(int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }

    return 0;
}