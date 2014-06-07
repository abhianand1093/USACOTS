/*
ID: abhiana1
PROG: beads
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int dividencount(string s, int n, int size)
{
    int i,count = 2;
    char c;

    string :: iterator it = s.begin()+size;

    i=0;
    while(*(it+n+i)=='w')
        i++;
    c = *(it+n+i);

    i = size+n+1;
    //fout<<"Right Side "<<c<<"=> "<<*(it+i);
    while(c == *(it+i) || *(it+i)=='w')
    {
        count++;
        i++;
        //fout<<" "<<*(it+i);
    }

    i=0;
    while(*(it+n-1+i)=='w')
        i--;
    c = *(it+n-1+i);
    i = size+n-2;
    //fout<<endl<<"Left Side "<<c<<"=> "<<*(it+i);
    while(c == *(it+i)|| *(it+i)=='w')
    {
        count++;
        i--;
        //fout<<" "<<*(it+i);
    }
    //fout<<"\n"<<count;
return count;
}


int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n, i, temp, max=0;
    string s,stemp;

    fin>>n;
    fin>>s;
    stemp = s+s+s+s+s;
    //fout<<stemp<<endl;

    for(i=0; i<n; i++)
    {
        //fout<<"\n\n\n\nIter "<<i+1<<endl;
        temp = dividencount(stemp, i, s.size());
        if(temp>max)
            max = temp;
    }
    if(max>=s.size())
        max = s.size();
    fout<<max<<endl;

    fin.close();
    fout.close();
return 0;
}
