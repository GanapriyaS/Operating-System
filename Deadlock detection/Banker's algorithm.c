#include<stdio.h>
int main()
{
  int p,r;
  printf("Enter no of processors : ");
  scanf("%d",&p);
  printf("Enter no of resources : ");
  scanf("%d",&r);
  int max[p][r];
  int allocated[p][r];
  int need[p][r];
  int tot[r];
  int avail[r];
  int result[p];
  int temp[r];
  for(int i=0;i<r;i++)
  {
  temp[i]=0;
  }
  for(int i=0;i<p;i++)
  {
    printf("Process %d : \n",i+1);
    printf("Enter max resources and allocated resources:\n");
    for(int j=0;j<r;j++)
    {
        scanf("%d %d",&max[i][j],&allocated[i][j]);
        need[i][j]=max[i][j]-allocated[i][j];
        temp[j]=temp[j]+allocated[i][j];
    }
  }
  printf("Enter total resources :\n");
  for(int i=0;i<r;i++)
  {
    scanf("%d",&tot[i]);
    avail[i]=tot[i]-temp[i];

  }
  int flag[p];
  for(int i=0;i<p;i++)
  {
  flag[i]=0;
}
  int x=0;
  int flag2=1;
printf("Available resources after releasing :\n");
while(flag2)
{
  flag2=0;
  for(int i=0;i<p;i++)
  {
    if(flag[i]==0)
    {
      int flag1=0;

      for(int j=0;j<r;j++)
      {
          if(need[i][j] > avail[j])
          {

            flag1=1;
            break;
          }
      }
      if(!flag1)
      {
        for(int k=0;k<r;k++)
        {
            flag2=1;
            avail[k]=avail[k]+allocated[i][k];

        }
          printf("P%d : ",i);
          for(int h=0;h<r;h++)
          {
            printf("%d ",avail[h]);
          }
          printf("\n");
        flag[i]=1;
        result[x]=i;
        x=x+1;
      }
    }
  }
}
  int b=0;
  for(int i=0;i<p;i++)
  {
    if(flag[i]==0)
    {
      printf("Deadlock occured! System is in safety state.");
      b=1;
    }
  }
  if(b==0)
  {
    printf("No deadlock occured! System is in safety state.\nSafety Sequence : ");
  }
  for(int i=0;i<x-1;i++)
  {
    printf("P%d  ->  ",result[i]);
  }
    printf("P%d",result[x-1]);
  return(0);
}
