#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    int bt[n],p[n],wt[n],i,j,total=0,pos,temp;

    for(i=0; i<n; i++)
    {
        printf("\nEnter Burst Time of processs %d : ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    sort(bt,bt+n);
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]=0;
        for(j=0; j<i; j++)
        wt[i]=wt[i]+bt[j];
        total=total+wt[i];
    }
    avg_wt=(float)total/(float)n;

    printf("\nProcess\t    Burst Time    \tWaiting Time");

    for(i=0; i<n; i++)
    {
        printf("\np%d\t\t  %d\t\t    %d",p[i],bt[i],wt[i]);
    }
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    return 0;
}

