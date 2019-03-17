#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc, char* argv[])
{
    if(argc != 3) {
        printf("Usage: ./head -(number) (filename)\n");
        return 1;
    }
    int n = atoi(argv[1]);
    n = -n;
    char r;
    int fd = open(argv[2], O_RDONLY);
    if(fd < 0) {
        printf("No such file!\n");
        return 1;
    }
    int count = 0;
    while(read(fd, &r, 1)) {
        printf("%c", r);
        if(r == '\n') count++;
        if(count == n) break;
    }
    return 0;
}
