#include<stdio.h>
int main()
{
  int no_of_pages,pageno,offset,pagesize,phyadd,no_of_frames;
  printf("Enter no of pages:");
  scanf("%d",&no_of_pages);
  printf("Enter no of frames:");
  scanf("%d",&no_of_frames);
  printf("Enter page size:");
  scanf("%d",&pagesize);
  int frame[no_of_pages];
  printf("Enter pageno and offset:");
  scanf("%d %d",&pageno,&offset);
  for(int i=0;i<no_of_pages;i++)
  {
    int f;
    printf("Enter the frame of page %d : ",i+1);
    scanf("%d",&f);
    if(f<=no_of_frames)
    {
      frame[i]=f;
    }
    else
    {
      printf("Enter the frame no again(frame out of bound)\n");
      i=i-1;
    }
  }
  if(pageno<=no_of_pages && offset<pagesize)
  {
    phyadd=(frame[pageno-1]*pagesize)+offset;
    printf("Physical address : %d",phyadd);
  }
  else{
    printf("Enter proper pageno and offset!!");
  }
  return 0;
}
