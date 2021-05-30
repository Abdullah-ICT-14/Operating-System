#include<stdio.h>



void findWaitingTime(int processes[], int n,int bt[], int wt[])
{

    wt[0] = 0;


    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}


void findTurnAroundTime( int processes[], int n,int bt[], int wt[], int tat[])
{

    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}


void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;


    findWaitingTime(processes, n, bt, wt);

    findTurnAroundTime(processes, n, bt, wt, tat);


    printf("\n\nProcesses   Burst time   Waiting time   Turn around time\n");


    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("  %d           %d            %d               %d\n",(i+1), bt[i],wt[i],tat[i]);

    }
    double s=(float)total_wt / (float)n;
    double t=(float)total_tat / (float)n;

    printf("\nAverage waiting time = %f\n",s);
    printf("\n");
    printf("Average turn around time = %f \n",t);
}


int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d",&n);

    int processes[n],burst_time[n];
int i=0;
while(i<n){
    //for(int i =0; i<n; i++){
       printf("Enter process %d bust time : ",i+1);
       processes[i] = i+1;

       scanf("%d",&burst_time[i]);
i++;
    }

    findavgTime(processes, n,  burst_time);
    return 0;
}
