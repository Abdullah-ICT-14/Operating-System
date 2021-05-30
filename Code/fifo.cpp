#include<stdio.h>
int main()
{
    int i,j,n,pagenumber[50],frame[10],numberofFrames,k,avail,count=0;
    printf("Enter the number of Pages: ");
    scanf("%d",&n);

    printf("Enter the page number : ");

    for(i=1; i<=n; i++){
        scanf("%d",&pagenumber[i]);
    }
    printf("Enter the number of FRAMES : ");

    scanf("%d",&numberofFrames);

    for(i=0; i<numberofFrames; i++){
            frame[i]= -1;
    }
    j=0;
    printf("\n");
    printf("reference string\t page frames\n");
    for(i=1; i<=n; i++)
    {
        printf("%d\t\t",pagenumber[i]);
        avail=0;
        for(k=0; k<numberofFrames; k++)
                   if(frame[k]==pagenumber[i])
                                  avail=1;
        if (avail==0)
        {
            frame[j]=pagenumber[i];
            j=(j+1)%numberofFrames;
            count++;
            for(k=0; k<numberofFrames; k++)
                            printf("%d\t",frame[k]);
        }
        printf("\n");
    }
    printf("Page Fault is: %d",count);
    printf("\n");
    return 0;
}

