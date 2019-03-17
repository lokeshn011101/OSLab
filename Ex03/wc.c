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
        printf("Usage: ./wc (filename)\n");
        return 1;
    }
    char r, prev;
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        printf("No such file!\n");
        return 1;
    }
    // Output shows the number of lines, number of words and number of characters in file
    int lines = 0, words = 0, chars = 0;
    while(read(fd, &r, 1)) {
        chars++;
        if(r == '\n') lines++;
        if(isspace(r)) words++;
        prev = r;
    }
    if(isspace(prev)) words--; // If last character is space, then not an extra word
    if(prev != '\n') lines++; // If last character is not \n even then it is a line
    words++; // Spaces plus 1 is words
    printf("%d %d %d %s\n", lines, words, chars, argv[1]);
    return 0;
}
