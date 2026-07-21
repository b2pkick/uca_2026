#include <stdio.h> 
#include <string.h>

void url_encode(char *str, int true_length) {
    int reqLength = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') reqLength += 2;
        reqLength++;   
    }

    printf("%d\n", true_length);
    printf("%d\n", reqLength);

    str[reqLength] = '\0';

    int j = reqLength - 1;
    int i = true_length - 1;

    while(i >= 0) {
        if(str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }else {
            str[j--]=str[i];
        }
        i--;
    }

}

int main() {

    char str[100];

    fgets(str, sizeof(str), stdin);

    url_encode(str, strlen(str));

    printf("%s", str);

    return 0;
}