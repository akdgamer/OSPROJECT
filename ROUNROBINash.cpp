#include<stdio.h>

int main()
{

  int num,j,n,time,remain,flag=0,tq;
  int wt=0,tt=0,at[10],bt[10],rt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(num=0;num<n;num++)
  {
    printf("Enter Arrival Time for process number %d :",num+1);
    scanf("%d",&at[num]);
	printf("Burst Time for Process Number %d :",num+1);
    scanf("%d",&bt[num]);
    rt[num]=bt[num];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&tq);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,num=0;remain!=0;)
  {
    if(rt[num]<=tq && rt[num]>0)
    {
      time+=rt[num];
      rt[num]=0;
      flag=1;
    }
    else if(rt[num]>0)
    {
      rt[num]-=tq;
      time+=tq;
    }
    if(rt[num]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",num+1,time-at[num],time-at[num]-bt[num]);
      wt+=time-at[num]-bt[num];
      tt+=time-at[num];
      flag=0;
    }
    if(num==n-1)
      num=0;
    else if(at[num+1]<=time)
      num++;
    else
      num=0;
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Avg Turnaround Time = %f",tt*1.0/n);
  
  return 0;
}
