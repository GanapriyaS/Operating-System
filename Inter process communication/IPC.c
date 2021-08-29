#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
  int pipefd[2]; //passed to pipe system call
  char buffer[50];  //buffer to keeo data
  pipe(pipefd);  //pipe formed, have 2 return values ,onr for read and another for write
  int result=fork(); //throws 2 values, ==0 child, >0 parent
  if(result>0)
  {
    fflush(stdin); //clean standard input file
    printf("Parent process id : %d\n",getppid());
    write(pipefd[1],"moon",50); //write  in  write end of the pipe
  }
  if(result==0)
  {
    sleep(1);
    fflush(stdin);
    printf("\nChild process id : %d\n",getpid());
    read(pipefd[0],buffer,sizeof(buffer)); //data read from already written
    int n=strlen(buffer);
    int c=0;
    int j;
    for(int i=0;i<n/2;i++)
    {
      j=i;
      if(buffer[i]==buffer[n-i-1])
      c++;
    }
    if(c==j)
      printf("%s : PALINDROME\n",buffer);
    else
      printf("%s : NOT PALINDROME\n",buffer);
  }
  return 0;
}
