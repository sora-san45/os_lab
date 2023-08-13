#include <stdio.h>
void main()
{
    int n, m;
    printf("\nEnter number of processes :");
    scanf("%d", &n);
    printf("\nEnter number of resources :");
    scanf("%d", &m);
    int allocation[n][m], max[n][m], need[n][m], available[m];
    for (int i = 0; i < n; i++)
    {
        printf("Enter for process %d \n", i + 1);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("\nEnter available :");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    int index = 0;
    int ans[n];
    int finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!finish[j])
            {
                int flag = 0;
                for (int d = 0; d < m; d++)
                {
                    if (need[j][d] > available[d])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    ans[index++] = j;
                    finish[j] = 1;
                    for (int w = 0; w < m; w++)
                    {
                        available[w] += allocation[j][w];
                    }
                }
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            printf("Not in safe state");
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        for (int i = 0; i < n; i++)
        {
            printf("P%d -> ", ans[i]);
        }
    }
}