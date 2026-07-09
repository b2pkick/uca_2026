#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1

int main(int argc, char* argv[]) {

    int fd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char ch;
    int line=1;
    char lineNo;

    if (argc != 3 && argc != 4) {
        printf("./auditlog <filename> --add \"message\"\n");
        printf("./auditlog <filename> --view\n");
        exit(-1);
    }

    if (argc == 4) {
        openFlags = O_CREAT | O_WRONLY | O_APPEND;
        filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        fd = open(argv[1], openFlags, filePerms);

        if (fd == -1) {
            printf("Error opening file\n");
            exit(-1);
        }

        write(fd, argv[3], strlen(argv[3]));
        write(fd, "\n", 1);

        close(fd);
    } else {
        fd = open(argv[1], O_RDONLY);

        if (fd == -1) {
            printf("Error opening file\n");
            exit(-1);
        }

        lineNo = line + '0';

        write(STDOUT_FILENO, &lineNo, 1);
        write(STDOUT_FILENO, ": ", 2);

        while ((numRead = read(fd, &ch, BUF_SIZE)) > 0) {
            write(STDOUT_FILENO, &ch, 1);

            if (ch == '\n')
            {
                if (read(fd, &ch, BUF_SIZE) > 0)
                {
                    line++;

                    lineNo = line + '0';

                    write(STDOUT_FILENO, &lineNo, 1);
                    write(STDOUT_FILENO, ": ", 2);

                    write(STDOUT_FILENO, &ch, 1);
                }
            }
        }

        close(fd);
    }

    return 0;
}