#include <iostream>
using namespace std;
#include "double_hashing.h"
const int size=100 ;
HashMap HashMapTable;
  class sym {
      string identifier, scope, type;
      int lineNo;
  public:
     sym()
     {
       this->identifier = "";
       this->scope = "";
       this->type = "";
       this->lineNo = -1;
     }
     sym(string key, string value, string type, int lineNo)
      {
          this->identifier = key;
          this->scope = value;
          this->type = type;
          this->lineNo = lineNo;
      }
      void print()
      {
          cout<<"------------------------------------------------------------\n";
          cout << "IDENTIFIER       "<< "TYPE      "<< "SCOPE       "<< "LINE NUMBER        "<< endl;
          cout<<"------------------------------------------------------------\n";
          cout<<identifier<<"              "<<type<<"       "<<scope<<"       "<<lineNo<<endl;
      }
      friend class SymbolTable;
};

class SymbolTable {
public:
    sym* head[size];
    SymbolTable()
    {
        for (int i = 0; i < size; i++)
            head[i] = NULL;
   }
    int convert(string id);
    void insert(string id, string scope,
                string Type, int lineno);
    void find(string id);

    void deletion(string id);
    void modify(string id);

};
int SymbolTable::convert(string id)
{
  int asciiSum = 0;

    for (int i = 0; i < id.length(); i++) {
        asciiSum = asciiSum + (char)id[i];
    }
    return asciiSum;
}
// Function to modify an identifier
void SymbolTable::modify(string id)
{
    int index=-1;
    int i=convert(id);
    index= HashMapTable.search(i);
    if(index!=-1)
    {
      sym* start = head[index];
      if (start == NULL)
      {
        cout<<"NO MODIFICATION DONE!!!"<<endl;
      }
      else{
      string type,scope;
      int no;
      cout<<"ENTER THE MODIFIED SYMBOL TABLE DETAILS:"<<endl;
      cout<< "TYPE:";
      cin>>type;
      cout<<"SCOPE:";
      cin>>scope;
      cout <<"LINE NUMBER:";
      cin>>no;
      start->scope = scope;
      start->type = type;
      start->lineNo = no;
      cout<<"MODIFIED SUCCESSFULLY!!!"<<endl;
      }
    }
    else
      cout<<"NO MODIFICATION DONE!!!"<<endl;
}

// Function to delete an identifier
void SymbolTable::deletion(string id)
{   int index=-1;
    int i=convert(id);
    index=HashMapTable.deletion(i);
    if (index==-1)
    {
      cout<<"NO MATCHING!!!!"<<endl;
      return;
    }
    else
    {
      head[index]==NULL;
      cout<<"IDENTIFIER "<<id<<" DELETED"<<endl;
    }
}
// Function to find an identifier
void SymbolTable::find(string id)
{
    int index=-1;
    int i=convert(id);
    index=HashMapTable.search(i);
    if (index==-1)
    {
      cout<<"NO MATCHING!!!!"<<endl;
      return;
    }
    sym* start = head[index];
    if (start == NULL)
    {
      cout<<"NO MATCHING!!!!"<<endl;
      return;
    }
    start->print();
    cout<<"IDENTIFIER FOUND!!!"<<endl;
}
// Function to insert an identifier
void SymbolTable::insert(string id, string scope,string Type, int lineno)
{
    int index=-1;
    int i=convert(id);
    index=HashMapTable.insertion(i);
    if(index==-1)
      cout<<"INSERTION UNSUCCESSFULLY!!"<<endl;
    else
    {
      sym* p = new sym(id, scope, Type, lineno);
      head[index]=p;
      cout<<"INSERTED SUCCESSFULLY!!"<<endl;
    }
}

int main()
{
    SymbolTable st;
    string check;
    cout<<"------------------------------------------------------------\n";
    cout << "**** SYMBOL_TABLE ****\n";
    cout<<"------------------------------------------------------------\n";
     int ch;
     cout<<"1.INSERTION"<<endl;
     cout<<"2.LOOKUP"<<endl;
     cout<<"3.DELETION"<<endl;
     cout<<"4.MODIFY"<<endl;
     cout<<"5.MENU"<<endl;
     cout<<"0.EXIT"<<endl;
     cout<<"-----------------------------------------------------------\n";
     do{
        cout<<"\nENTER YOUR CHOICE:";
        cin>>ch;
        switch(ch) {
           case 1:
           {
              string id,type,scope;
              int no;
              cout<<"ENTER THE SYMBOL TABLE DETAILS:"<<endl;
              cout<< "IDENTIFIER'S NAME:";
              cin>>id;
              cout<< "TYPE:";
              cin>>type;
              cout<<"SCOPE:";
              cin>>scope;
              cout <<"LINE NUMBER:";
              cin>>no;
              st.insert(id,scope,type,no);
              break;
            }
           case 2:
           {
              string id;
              cout<<"ENTER THE IDENTIFIER TO LOOKUP: ";
              cin>>id;
              st.find(id);
              break;
           }
           case 3:
           {
              string id;
              cout<<"ENTER THE IDENTIFIER TO DELETE: ";
              cin>>id;
              st.deletion(id);
              break;
           }
           case 4:
           {
               string id;
               cout<<"ENTER THE IDENTIFIER TO MODIFY: ";
               cin>>id;
               st.modify(id);
               break;
           }
           case 5:
           {
             cout<<"1.INSERTION"<<endl;
             cout<<"2.LOOKUP"<<endl;
             cout<<"3.DELETION"<<endl;
             cout<<"4.MODIFY"<<endl;
             cout<<"5.MENU"<<endl;
             cout<<"0.EXIT"<<endl;
             break;
           }
           case 0:
              cout<<"EXITING................\n\n";
              exit(1);
           default:
              cout<<"ENTER THE VALID OPTION\n";
        }
        cout<<"\n------------------------------------------------------------\n";
      }while(ch);
    return 0;
}
