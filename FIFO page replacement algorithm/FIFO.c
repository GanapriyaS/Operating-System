#include<stdio.h>


int FIFO(int pages[],int n_pages,int n_frames)
{
    int frames[n_frames],i,j,page_faults=0;
    for(i=0;i<n_frames;i++)
      frames[i]=-1;
    for(int i=0;i<n_pages;i++)
    {
      int flag=0;
      for(int j=0;j<n_frames;j++)
      {
        if(pages[i]==frames[j])
        {
          flag=1;
          page_faults--;
        }
      }
      page_faults++;
      if((page_faults <= n_frames) && flag==0)
        frames[i]= pages[i];
      else if(flag==0)
        frames[(page_faults-1)%n_frames]= pages[i];
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
  int page_faults=FIFO(pages,n_pages,n_frames);
  printf("\nNumber of page_faults : %d",page_faults);
  float missratio=(float)page_faults/n_pages;
  printf("\nMiss ratio : %f",missratio);
  printf("\nNumber of hits : %d",n_pages-page_faults);
  printf("\nHit ratio : %f\n",1-missratio);
  return 0;
}
