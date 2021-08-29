#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{	
	int process=fork();
	char id[4]="";
	
	if(process>0)
	{	
		printf("\nPARENT PROCESS\n");
	}
	else if(process==0)
	{	
		printf("\n=======================\nPARENT PROCESS AND CHILD PROCESS-ID\n======================\n");
		printf("Parent process-id: %d\n",getppid());
		printf("Child process-id: %d\n",getpid());
		printf("\nCHILD PROCESS\n");
		int temp=getpid();
		sprintf(id,"%d",temp);
			printf("\n=======================\nPROCESSES\n======================\n");
		system("ps -al");
		char c1[20]="";
		char c[20]="";
		strcpy(c,"cd /proc/");
		strcat(c,id);
		strcpy(c1,c);
		strcat(c," && ls");
		strcat(c1," && cat status");
		printf("\n=======================\nPROCESS CONTROL BLOCK\n======================\n");
		system(c);
		printf("\n=======================\nPROCESS STATUS\n======================\n");
		system(c1);
	}
	sleep(5);
	return 0;
}
