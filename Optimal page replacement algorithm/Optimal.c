#include<stdio.h>


int Optimal(int pages[],int n_pages,int n_frames)
{
    int frames[n_frames],i,j,page_faults=0,count[n_frames],counter=0,temp[n_frames];
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
        int flag3=0,pos,max;
        for(j = 0; j < n_frames; ++j){
             temp[j] = -1;

             for(int k = i + 1; k < n_pages; k++){
              if(frames[j] == pages[k]){
                temp[j] = k;
                break;
              }
             }
        }
            
        for(j = 0; j < n_frames; j++){
            if(temp[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
        }
            
        if(flag3 ==0){
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < n_frames; j++){
             if(temp[j] > max){
             max = temp[j];
             pos = j;
             }
             }            
        }

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
  int page_faults=Optimal(pages,n_pages,n_frames);
  printf("\nNumber of page_faults : %d",page_faults);
  float missratio=(float)page_faults/n_pages;
  printf("\nMiss ratio : %f",missratio);
  printf("\nNumber of hits : %d",n_pages-page_faults);
  printf("\nHit ratio : %f\n",1-missratio);
  return 0;
}
