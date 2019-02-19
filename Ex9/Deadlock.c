#include<stdio.h>
int M = 3, N = 2;
int RAG[20][20];
int WFG[10][10];
int stack[20], v[20], top = -1, flag = 0, l = 0, cycle = 0;
void print(int a[][20], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void request()
{
    printf("PID and RID: ");
    int p, r, flag = 0;
    scanf("%d %d", &p, &r);
    RAG[p][r] = 1;
    for(int i = 0; i < M+N; i++)
    {
        if(RAG[r][i] == 1) {
            flag = 1;
        }
    }
    if(flag == 0) {
        RAG[p][r] = 0;
        RAG[r][p] = 1;
    }
}
void release()
{
    printf("PID and RID: ");
    int p, r;
    scanf("%d %d", &p, &r);
    RAG[r][p] = 0;
}

void checkcycle(int a, int o)
{
    v[a] = 1;
    top++;
    stack[top] = a;
    for(int i = 0; i < M+N && cycle == 0; i++)
    {
        if(RAG[a][i] == 1 && i == o && l >= 3) {
            cycle = 1;
            break;
        }
        if(v[i]==0 && RAG[a][i]==1) {
            l++;
            checkcycle(i, o);
        }
    }
}
void detect()
{
    for(int a = 0; a < M+N; a++)
    {
        cycle = 0;
        checkcycle(a, a);
        if(cycle == 1) {
            printf("Deadlock!");
            break;
        }
    }
}
int main()
{
    for(int i = 0; i < 5; i++) request();
    print(RAG, 5, 5); //assumption
    detect();
    return 0;
}
