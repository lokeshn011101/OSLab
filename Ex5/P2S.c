#include<sys/ipc.h>
#define NULL 0
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio_ext.h>
int main()
{
	char *a;
	FILE *fd;
	int id = shmget(112, 50, IPC_CREAT);
	a = shmat(id, NULL, 0);
	while(a[0] == '\0');
	fd = fopen(a, "r");
	a[0] = 'O';
	fscanf(fd, "%s", a);
	shmdt(a);
}
