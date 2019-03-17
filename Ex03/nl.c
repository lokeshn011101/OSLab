#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc, char* argv[])
{
    if(argc != 2) {
        printf("Usage: ./nl (filename)\n");
        return 1;
    }
    char r;
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        printf("No such file!\n");
        return 1;
    }
    // Output shows the line number and line
    int lines = 1, begin = 1;
    while(read(fd, &r, 1)) {
        if(begin == 1) {
            printf("%d:\t",lines);
            begin = 0;
        }
        printf("%c", r);
        if(r == '\n') {
            lines++;
            begin = 1;
        }
    }
    return 0;
}
