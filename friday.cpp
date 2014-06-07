/*
ID: abhiana1
PROG: friday
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int days[] = {0,0,0,0,0,0,0};

    int i,j,n,leftdays = 1,k;

    fin>>n;

    for(i=1900; i< (1900+n); i++)
    {
        for(j=0; j<12; j++)
        {
            k = (leftdays + 13)%7;
            days[k]++;

            if(j==1)
            {
                if(i%100 == 0)
                {
                    if(i%400 == 0)
                        leftdays = 29 - 13;
                    else
                        leftdays = 28 - 13;
                }
                else if(i%4 == 0)
                {
                    leftdays = 29 - 13;
                }

                else
                    leftdays = 28 - 13;
            }

            else
                leftdays = month[j] - 13;

            leftdays = leftdays + k;
        }
    }
    for(i=0; i<6; i++)
        fout<<days[i]<<" ";
    fout<<days[6]<<endl;
return 0;
}
