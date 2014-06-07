/*
ID: abhiana1
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

char array[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int checkpalin(char * ptr, int n)
{
    int i;

    for(i=0; i<(n-1-i); i++)
    {
        if(ptr[i]!= ptr[n-1-i])
            return 0;
    }
return 1;
}

int convert(char *ptr, int n, int b)
{
    int i;

    for(i=0; n>0; i++)
    {
        ptr[i] = array[n%b];
        n = n/b;
    }
return i;
}

int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int b, n, count1, i, j, count2;

    fin>>b;

    char ptr1[100], ptr2[100];
    for(i=1; i<=300; i++)
    {
        count1 = convert(ptr1, i*i, b);
        if(checkpalin(ptr1, count1) == 1)
        {
            count2 = convert(ptr2, i, b);
            for(j=count2-1;j>=0;j--)
                fout<<ptr2[j];
            fout<<" ";
            for(j=count1-1;j>=0;j--)
                fout<<ptr1[j];
            fout<<endl;
        }
    }

    fin.close();
    fout.close();

return 0;
}
