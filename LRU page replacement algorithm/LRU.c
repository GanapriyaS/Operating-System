#include<stdio.h>

int minLRU(int count[],int n_frames)
{
  int i,min=count[0],pos=0;
  for(i=1;i<n_frames;i++)
  {
    if(count[i]<min)
    {
      min=count[i];
      pos=i;
    }
  }
  return pos;
}

int LRU(int pages[],int n_pages,int n_frames)
{
    int frames[n_frames],i,j,page_faults=0,count[n_frames],counter=0;
    for(i=0;i<n_frames;i++)
      frames[i]=-1;
    for(int i=0;i<n_pages;i++)
    {
      int flag1=0,flag2=0;
      for(int j=0;j<n_frames;j++)
      {
        if(pages[i]==frames[j])
        {
          count[j]=++counter;
          flag1=flag2=1;
          break;
        }
      }
      if(flag1==0)
      {
        for(int j=0;j<n_frames;j++)
        {
          if(frames[j]==-1)
          {
            count[j]=++counter;
            frames[j]= pages[i];
            page_faults++;
            flag2=1;
            break;
          }
        }
      }
      if(flag2==0)
      {
        int pos= minLRU(count,n_frames);
        count[pos]=++counter;
        frames[pos]= pages[i];
        page_faults++;
      }
      for(j=0;j<n_frames;j++)
        printf("%d\t",frames[j]);
      printf("\n");
    }
    return page_faults;
}

int main()
{
  int n_pages,n_frames,i;
  printf("Enter the number of pages of process:");
  scanf("%d",&n_pages);
  printf("Enter the number of frames in main memory:");
  scanf("%d",&n_frames);
  printf("Enter the value of reference string:\n");
  int pages[n_pages];
  for(i=0;i<n_pages;i++)
  {
    printf("%d :",i+1);
    scanf("%d",&pages[i]);
  }
  printf("Pages in the frames of main memory:\n");
  int page_faults=LRU(pages,n_pages,n_frames);
  printf("\nNumber of page_faults : %d",page_faults);
  float missratio=(float)page_faults/n_pages;
  printf("\nMiss ratio : %f",missratio);
  printf("\nNumber of hits : %d",n_pages-page_faults);
  printf("\nHit ratio : %f\n",1-missratio);
  return 0;
}
