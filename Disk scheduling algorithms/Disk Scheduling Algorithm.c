#include<stdio.h>
#include<stdlib.h>

void display(int working_seq[],int request_no,int tot,int head)
{

  printf("Working sequence : ");
  printf("%d ",head);
  for(int i=0;i<request_no;i++)
    printf("%d ",working_seq[i] );
  printf("\nTotal no of seek operations : %d\n",tot);
  float avg=tot/(float)request_no;
  printf("Average seek time: %.2f\n",avg);
}

void common(int request_no,int head,int request_seq[],int *temp)
{
  int temp1,loc;
  for(int i=0;i<request_no;i++)
    temp[i]=request_seq[i];
  temp[request_no]=head;
  for(int i=0;i<request_no+1;i++)
  {
    for(int j=i;j<request_no+1;j++)
    {
      if(temp[i]>temp[j])
      {
        temp1=temp[i];
        temp[i]=temp[j];
        temp[j]=temp1;
      }
    }
  }
}

void FCFS(int working_seq[],int request_no,int head,int request_seq[])
{
  printf("\n**********FCFS(First Come First Serve)**********\n");
  int tot=abs(request_seq[0]-head);
  int i=0;
  for(i=0;i<request_no-1;i++)
  {
    tot+=(abs(request_seq[i]-request_seq[i+1]));
    working_seq[i]=request_seq[i];
  }
  working_seq[i]=request_seq[i];
  display(working_seq,request_no,tot,head);
}

void SSTF(int working_seq[],int request_no,int head,int request_seq[])
{
  printf("\n**********SSTF(Shortest Seek Time First)**********\n");
  int tot=0,index[request_no],temp=head;
  for(int i=0;i<request_no;i++)
  {
    for(int j=0;j<request_no;j++)
    {
      index[j]=abs(head-request_seq[j]);
    }
    int min=index[0];
    int min_index=0;
    for(int k=1;k<request_no;k++)
    {
      if(min>index[k])
      {
        min = index[k];
        min_index=k;
      }
    }
    working_seq[i]=request_seq[min_index];
    head=request_seq[min_index];
    request_seq[min_index]=1000;
  }
  tot+=abs(temp-working_seq[0]);
  for(int i=1;i<request_no;i++)
    tot+=(abs(working_seq[i]-working_seq[i-1]));

  display(working_seq,request_no,tot,temp);
}

void SCAN(int request_no,int head,int request_seq[])
{

  printf("\n**********SCAN**********\n");
  int disk_size,tot=0,*temp,loc;
  temp=(int*)malloc(request_no * sizeof(int));
  printf("Enter disk size : ");
  scanf("%d",&disk_size);
  disk_size-=1;
  common(request_no,head,request_seq,temp);
  for(int i=0;i<request_no+1;i++)
  {
    if(head==temp[i])
      {
        loc=i;
        break;
      }
  }
  printf("Direction : Left \nWorking sequence : ");
  for (int i = loc; i >=0; i--)
    printf("%d ",temp[i]);
  printf("0 ");
  for (int i = loc+1; i<request_no+1; i++)
    printf("%d ",temp[i]);

  printf("\nDirection : Right \nWorking sequence : ");
  for (int i = loc; i<request_no+1; i++)
    printf("%d ",temp[i]);
  printf("%d ",disk_size);
  for (int i = loc-1; i >=0; i--)
    printf("%d ",temp[i]);

  tot=abs(disk_size-head)+abs(disk_size-temp[0]);
  printf("\nTotal no of seek operations : %d\n",tot);
  float avg=tot/(float)request_no;
  printf("Average seek time: %.2f\n",avg);
}

void CSCAN(int request_no,int head,int request_seq[])
{
  printf("\n**********CSCAN(Circular SCAN)**********\n");
  int disk_size,tot=0,*temp,loc;
  temp=(int*)malloc(request_no * sizeof(int));
  printf("Enter disk size : ");
  scanf("%d",&disk_size);
  disk_size-=1;
  common(request_no,head,request_seq,temp);
  for(int i=0;i<request_no+1;i++)
  {
    if(head==temp[i])
      {
        loc=i;
        break;
      }
  }
  printf("Working sequence : ");
  for (int i = loc; i<request_no+1; i++)
    printf("%d ",temp[i]);
  printf("%d 0 ",disk_size);
  for (int i = 0; i < loc; i++)
    printf("%d ",temp[i]);
  tot=abs(head-disk_size)+disk_size+temp[loc-1];
  printf("\nTotal no of seek operations : %d\n",tot);
  float avg=tot/(float)request_no;
  printf("Average seek time: %.2f\n",avg);
}

void LOOK(int request_no,int head,int request_seq[])
{

  printf("\n**********LOOK**********\n");
  int tot=0,*temp,loc;
  temp=(int*)malloc(request_no * sizeof(int));
  common(request_no,head,request_seq,temp);
  int max=temp[request_no];
  for(int i=0;i<request_no+1;i++)
  {
    if(head==temp[i])
      {
        loc=i;
        break;
      }
  }
  printf("Direction : Right \nWorking sequence : ");
  for (int i = loc; i >=0; i--)
    printf("%d ",temp[i]);
  for (int i = loc+1; i<request_no+1; i++)
    printf("%d ",temp[i]);

  printf("\nDirection : Left \nWorking sequence : ");
  for (int i = loc; i<request_no+1; i++)
    printf("%d ",temp[i]);
  for (int i = loc-1; i >=0; i--)
    printf("%d ",temp[i]);

  tot=abs(max-head)+abs(max-temp[0]);
  printf("\nTotal no of seek operations : %d\n",tot);
  float avg=tot/(float)request_no;
  printf("Average seek time: %.2f\n",avg);
}

void CLOOK(int request_no,int head,int request_seq[])
{
  printf("\n**********CLOOK(Circular LOOK)**********\n");
  int tot=0,*temp,loc;
  temp=(int*)malloc(request_no * sizeof(int));
  common(request_no,head,request_seq,temp);
  int max=temp[request_no];
  for(int i=0;i<request_no+1;i++)
  {
    if(head==temp[i])
      {
        loc=i;
        break;
      }
  }
  printf("Working sequence : ");
  for (int i = loc; i<request_no+1; i++)
    printf("%d ",temp[i]);
  for (int i = 0; i < loc; i++)
    printf("%d ",temp[i]);
  tot=abs(head-max)+abs(max-temp[0])+abs(temp[loc-1]-temp[0]);
  printf("\nTotal no of seek operations : %d\n",tot);
  float avg=tot/(float)request_no;
  printf("Average seek time: %.2f\n",avg);
}

int main()
{
  int head,request_no;
  printf("Enter initial head position and size of request sequence : ");
  scanf("%d %d",&head,&request_no);
  int request_seq[request_no];
  int working_seq[request_no];
  printf("Enter request sequence : ");
  for(int i=0;i<request_no;i++)
    scanf("%d",&request_seq[i]);
  SCAN(request_no,head,request_seq);
  CSCAN(request_no,head,request_seq);
  LOOK(request_no,head,request_seq);
  CLOOK(request_no,head,request_seq);
  FCFS(working_seq,request_no,head,request_seq);
  SSTF(working_seq,request_no,head,request_seq);
  return 0;
}
