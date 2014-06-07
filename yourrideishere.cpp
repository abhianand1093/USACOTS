/*
ID: abhiana1
PROG: ride
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int chartoint(string s)
{
    int i, temp = 1;
    for(i=0; i<s.size(); i++)
    {
        temp = temp * (int)(s[i] - 64);
    }
return temp;
}

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string s1, s2;
    fin>>s1>>s2;

    if(chartoint(s1)%47 == chartoint(s2)%47)
        fout<<"GO\n";
    else
        fout<<"STAY\n";

    fout.close();
    fin.close();
return 0;
}
