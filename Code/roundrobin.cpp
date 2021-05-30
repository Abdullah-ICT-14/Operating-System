#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int b[n],a[n],w[n],p[n],tq,flag=0,i,k,temp[100],total=0;
    for(i=0; i<n; i++)
    {
        printf("enter burst time of process%d:",i+1);
        scanf("%d",&b[i]);
        w[i]=0;
        p[i]=0;
    }
    printf("Enter the time quantum:");
    scanf("%d",&tq);
    i=0;
    k=0;
    while(1)
    {
        if(i==n)
                    i=0;
        if(flag==n)
                   break;
        if(b[i]<=tq && b[i]>0)
        {
            w[i]+=total-p[i];
            flag++;
            total+=b[i];
            b[i]=0;
            temp[k]=i;
            k++;
        }
        if(b[i]>tq)
        {
            w[i]+=total-p[i];
            b[i]=b[i]-tq;
            total+=tq;
            temp[k]=i;
            k++;
        }
        p[i]=total;
        i++;
    }
    printf("\nOrder of execution:\n");
    for(i=0; i<k; i++)
    {
        printf("P%d ",temp[i]+1);
    }
    int a_w_time=0;
    for(i=0; i<n; i++)
    {
        printf("\nP%d Waiting time %d\n",i+1,w[i]);
        a_w_time = a_w_time + w[i];
    }
    printf("\nAverage Waiting time %.4f\n",((float)a_w_time/(float)n));
}

