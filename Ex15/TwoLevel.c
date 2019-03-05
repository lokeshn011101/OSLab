#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct files {
    char fname[10];
}File;
typedef struct directory {
    char fname[10];
    int c;
    File* l[5];
}Directory;
typedef struct unit {
    int d;
    void *p;
} Unit;
Unit root[50];
int count = 0;
File* new_file(char s[])
{
    File* n = (File*)malloc(sizeof(File));
    strcpy(n->fname, s);
    return n;
}
Directory* new_dir(char s[])
{
    Directory* n = (Directory*)malloc(sizeof(Directory));
    strcpy(n->fname, s);
    c = 0;
    return n;
}
int search_file(char s[])
{
    int flag = 0;
    for(int i = 0; i < count; i++)
    {
        if(root[i] != NULL) {
            if(strcmp(root[i].p->fname,s) == 0 && root[i].d == 0) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
int search_dir(char s[])
{
    int flag = 0;
    for(int i = 0; i < count; i++)
    {
        if(root[i] != NULL) {
            if(strcmp(root[i].p->fname,s) == 0 && root[i].d == 1) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
void insert_file(char s[])
{
    if(search_file(s) == 1) {
        printf("File %s already exists!\n", s);
        return;
    }
    root[count].p = new_file(s);
    root[count].d = 0;
    count++;
    printf("Created!\n");
}
void insert_dir(char s[])
{
    if(search_dir(s) == 1) {
        printf("Directory %s already exists!\n", s);
        return;
    }
    root[count].p = new_dir(s);
    root[count].d = 1;
    count++;
    printf("Created!\n");
}
void display(Unit* d[])
{
    printf("Contents of root:\n");
    if(count == 0) {
        printf("Empty!\n");
        return;
    }
    printf("Files:\n");
    for(int i = 0; i < count; i++) {
        if(root[i] != NULL) {
            if(root[i].d == 0)
                printf("%s\t",root[i].p->fname);
        }
    }
    printf("\nDirectories:\n");
    for(int i = 0; i < count; i++) {
        if(root[i] != NULL) {
            if(root[i].d == 1) {
                printf("%s\n",root[i].p->fname);
                printf("Contents:\n");
                for(int j = 0; j < 5)
            }
        }
    }
    printf("\n");
}
int main()
{
    int c;
    while(1)
    {
        printf("1. New File\n");
        printf("2. Display all files\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&c);
        if(c==1)
        {
            char s[50];
            printf("Enter file name: ");
            scanf("%s",s);
            insert_file(s);
        }
        else if(c==2)
        {
            display(root);
        }
        else {
            break;
        }
    }
}


