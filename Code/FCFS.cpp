#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;
int main()
{
    printf("please enter the number of process  : ");
    int i,n,a;
    scanf("%d",&n);
    vector<string>v,v1;
    map<string,int>mp,mp1;
    int  ar[100];
    for(i=0; i<n; i++)
    {
        printf("please enter the process and value : ");
        string s1;
        cin>>s1>>ar[i];
        v.push_back(s1);
        mp.insert(make_pair(v[i],ar[i]));
    }
sohag:
    for(i=0; i<n; i++)
    {
        printf("please enter the arrived process   : ");
        string s1;
        cin>>s1;
        v1.push_back(s1);
    }
    int sum=0;
    mp1.insert(make_pair(v1[0],sum));
    if(n>1)
    {
        for(i=1; i<n; i++)
        {
            sum+=mp[v1[i-1]];
            mp1.insert(make_pair(v1[i],sum));

        }
    }
    map<string,int>::iterator it;
    float sum1=0;
    //for(i=0; i<v1.size(); i++)
        sum1+=float(ar[i]);
    printf("\n           ***********            \n");
    for(it=mp1.begin(); it!=mp1.end(); it++)
    {
        cout<<"waiting time for :";
        cout<<it->first<<" = "<<it->second<<endl;
        sum1+=float(it->second);
    }
    printf("\n           ***********            \n");

    printf("average waiting time : %.3lf\n\n",(sum1/float(n)));
    printf("if you want to select new arrived process please press (1) : ");
    scanf("%d",&a);
    v1.clear();
    mp1.clear();
    if(a==1)
        goto sohag;
    return 0;
}
