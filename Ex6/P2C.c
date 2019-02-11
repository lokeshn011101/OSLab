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
	int pid, id;
	char *a;
	id = shmget(112, 50, IPC_CREAT | 00666);
	a = shmat(id, NULL, 0);
	a[0] = '\0';
	scanf("%s", a);
	sleep(2);
	while(a[0] == 'O');
	printf("%s", a);
	shmdt(a);
	shmctl(id, IPC_RMID, NULL);
}
