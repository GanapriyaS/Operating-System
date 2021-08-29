#include<stdio.h>
int main()
{
  int no_of_segment,segment,offset,pagesize,phyadd,no_of_frames;
  printf("Enter no of segment:");
  scanf("%d",&no_of_segment);
  int segment_table[no_of_segment][2];
  printf("Enter segment and offset:");
  scanf("%d %d",&segment,&offset);
  for(int i=0;i<no_of_segment;i++)
  {
    printf("Enter base address for segment %d: ",i+1);
    scanf("%d",&segment_table[i][0]);
    printf("Enter length for segment %d: ",i+1);
    scanf("%d",&segment_table[i][1]);
  }
  if(offset<segment_table[segment-1][1])
  {
    phyadd=segment_table[segment-1][0]+offset;
    printf("Physical address : %d",phyadd);
  }
  else{
    printf("Enter proper segment and offset!!");
  }
  return 0;
}
