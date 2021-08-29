#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int LRU(int pages[],int n_pages,int n_frames)
{
  unordered_set<int>task;
  unordered_map<int,int>map;
  int page_faults=0;
  for(int i=0;i<n_pages;i++)
  {
    if(task.size() < n_frames)
    {
      if(task.find(pages[i])==task.end())
      {
        task.insert(pages[i]);
        page_faults++;
      }
      map[pages[i]]=i;
    }
    else
    {
      if(task.find(pages[i])==task.end())
      {
        int temp,max=2147483647;
        for(auto it=task.begin(); it!=task.end(); it++)
        {
          if(map[*it] < max)
          {
            max=map[*it];
            temp=*it;
          }
        }
        task.erase(temp);
        task.insert(pages[i]);
        page_faults++;
      }
      map[pages[i]]=i;
    }
  }
  return page_faults;
}



int main()
{
  int n_pages,n_frames;
  cout<<"Enter the number of pages of process:";
  cin>>n_pages;
  cout<<"Enter the number of frames in main memory:";
  cin>>n_frames;
  cout<<"Enter the value of reference string:\n";
  int pages[n_pages];
  for(int i=0;i<n_pages;i++)
  {
    cout<<i+1<<" :";
    cin>>pages[i];
  }
  int page_faults=LRU(pages,n_pages,n_frames);
  cout<<"Number of page_faults : "<<page_faults;
  cout<<"\nMiss ratio : "<<(float)page_faults/n_pages;
  cout<<"\nNumber of hits : "<<n_pages-page_faults;
  cout<<"\nHit ratio : "<<1-((float)page_faults/n_pages);
  return 0;
}
