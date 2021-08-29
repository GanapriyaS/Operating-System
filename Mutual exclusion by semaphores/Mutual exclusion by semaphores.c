#include<stdio.h>
int semaphore[4]={1,0,0,0};
// 0 - mutex(key)
// 1 - count read
// 2 - waiting processor
// 3 - write count
void addRead()
{
  if(semaphore[0]==0 && semaphore[1]==0)
  {
    printf("\nFile open in write mode\nReader added to queue\n");
    semaphore[2]++;
  }
  else {
    printf("\nReader process added\n");
    semaphore[1]++;
    semaphore[0]--;
  }
}
void removeRead()
{
  if(semaphore[1]==0)
  {
    printf("\nNo readers to remove\n");
  }
  else {
    printf("\nReader removed\n");
    semaphore[1]--;
    semaphore[0]++;
  }
}
void addWrite()
{
  if(semaphore[0]>0)
  {
    printf("\nWriter process added\n");
    semaphore[3]=1;
    semaphore[0]--;
  }
  else if(semaphore[3]) {
      printf("\nWriter already operational\n");
  }
  else{
    printf("\nFile open in read mode\n");
  }
}
void removeWrite()
{
  if(semaphore[3]==0)
  {
    printf("\nNo writer to remove\n");
  }
  else
  {
    printf("\nWriter removed\n");
    semaphore[0]++;
    semaphore[3]=0;
  }
  if(semaphore[2]>0)
  {
    semaphore[0]-=semaphore[2];
    semaphore[1]=semaphore[2];
    semaphore[2]=0;
    printf("Waiting Readers added : %d\n",semaphore[1]);
  }

}
int main()
{
  printf("1.Add Reader\n2.Add Writer\n3.Remove Reader\n4.Remove Writer\n5.Exit\n");
  do{
    int choice;
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice) {
      case 1: addRead(); break;
      case 2: addWrite(); break;
      case 3: removeRead(); break;
      case 4: removeWrite(); break;
      case 5: printf("Exiting....."); exit(1);
      default: printf("Invalid Option!");
    }
  }while(1);

  return(0);
}
