#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
struct process{
  int id;
  int at;
  int bt;
  int st;
  int ct;
  int tat;
  int wt;
  int rt;
};
bool cmp1(process a, process b)
{
	return a.at < b.at;
}
bool cmp2(process a, process b)
{
	return a.id < b.id;
}

int main()
{
  cout<<"------------------------------------------------------------------------------"<<endl;
  cout<<"AT - Arrival Time \nBT - Burst Time \nWT - Waiting Time \nTAT - TurnAround Time \nCT - Completing Time \nRT - Response Time \nST - Starting Time \n";
  cout<<"-------------------------------------------------------------------------------"<<endl;
  int n,tot_tat=0,tot_wt=0,tot_rt=0,time_quantum,time,remain;
  cout<<"Enter the number of process:";
  cin>>n;
  struct process p[n];
  remain=n;
  vector<int>rem_bt(n);
  queue<int>q;
  cout<<"\nEnter the value of time quantum:";
  cin>>time_quantum;
  for(int i=0;i<n;i++)
  {
      p[i].id=i;
      cout<<"\nEnter the Burst time and arrival time for process:"<<i+1; cout<<endl;
      cout<<"Burst time:";
      cin>>p[i].bt;
      cout<<"Arrival time:";
      cin>>p[i].at;
  }
  sort(p, p+n, cmp1);
  for(int i=0;i<n;i++)
  {
      rem_bt[i]=p[i].bt;
  }
  time=p[0].at;
  q.push(p[0].id);
  int x;
  int i=0;
  while(remain!=0)
 {

   if(q.empty())
   {
      i++;
      q.push(i);
      continue;
   }
   x=q.front();
   q.pop();
   if(rem_bt[x]==p[x].bt )
   {
     p[x].st=max(time,p[x].at);
     time=p[x].st;
   }
   if(rem_bt[x]<=time_quantum && rem_bt[x]>0)
   {
     time+=rem_bt[x];
     remain--;
     rem_bt[x]=0;
     p[x].ct=time;
     p[x].rt=p[x].st-p[x].at;
     p[x].tat=time - p[x].at;
     p[x].wt=p[x].tat-p[x].bt;
     tot_wt+=p[x].wt;
     tot_tat+=p[x].tat;
     tot_rt+=p[x].rt;
     int k=i+1;
     for(;k!=n;k++)
     {
       if(p[k].at<=time)
       {
         q.push(k);
         i++;
       }
     }
   }
   else if(rem_bt[x]-time_quantum>0)
   {
     rem_bt[x]=rem_bt[x]-time_quantum;
     time+=time_quantum;
     int k=i+1;
     for(;k!=n;k++)
     {
       if(p[k].at<=time)
       {
         q.push(k);
         i++;
       }
     }
     q.push(x);
   }
 }
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"PROCESS \tBT \tAT \tST \tCT \tWT \tTAT \tRT"<<endl;
    sort(p,p+n,cmp2);
    for(int i=0;i<n;i++)
    {
    cout<<"P["<<i+1<<"]\t\t"<<p[i].bt<<"\t"<<p[i].at<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<"\t"<<p[i].rt;
    cout<<endl;
    }
    cout<<endl;
    cout<<"Average Waiting time:"<<(float)tot_wt/n<<"\n"; cout<<"Average Turnaround time:"<<(float)tot_tat/n<<"\n"; cout<<"Average Response time:"<<(float)tot_rt/n<<"\n";
    return 0;
    }
