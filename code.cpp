#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}


bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];
    preKMP(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}
 void  search(string searchword)
{
  string str;
  int line=0;
  for(int i=1;i<=25;i++)
  {
   ifstream fin;
   fin.open("page_"+to_string(i)+".txt",ios::in);
    while(fin)
    {
        getline(fin,str);
        line++;
        if (KMP(searchword,str))
        cout<<"Line No:"<<line<<endl;

      }
  }
      cout<<endl<<endl;

}
int main()
{
   string temp;
   cout<<"                            THE WORD SEARCHED"<<endl;
   cout<<"                           -------------------"<<endl<<endl<<endl;
   ifstream fin;
   fin.open("querie.txt",ios::in);
   while(fin)
   {
     fin>>temp;
     cout<<"WORD:"<<temp<<endl;
     cout<<"----------------"<<endl;
     cout<<"OCCURRENCES:"<<endl;
     search(temp);
   }
   return 0;
}
