/*
ID: abhiana1
PROG: dualpal
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int s, n, count, i, j, k, p;
    char ptr[100];
    fin>>n>>s;

    i=1;
    for(k=s+1; i<=n; k++)
    {   p=0;
        for(j=2; j<=10; j++)
        {
            count = convert(ptr, k, j);
            if(checkpalin(ptr, count) == 1)
                p++;
                if(p==2)
                {
                    fout<<k<<endl;
                    i++;
                    break;
                }
        }
    }


    fin.close();
    fout.close();

return 0;
}
