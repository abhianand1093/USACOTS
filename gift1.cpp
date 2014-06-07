/*
ID: abhiana1
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<string>

using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int np, i, nt, j;

    fin>>np;

    int total;
    string s[np], giver, accepter;
    map<string, int> smap;

    for(i=0; i<np; i++)
    {
        fin>>s[i];
        smap.insert(std::pair<string,int>(s[i],0));
    }


    for(i=0; i<np; i++)
    {
        fin>>giver;
        fin>>total>>nt;

        if(nt!=0)
        {
            smap[giver] = smap[giver] + total%nt - total;
            //fout<<smap[giver]<<endl;
            for(j=0; j<nt; j++)
            {
                fin>>accepter;
                smap[accepter] = smap[accepter] + total/nt;
                //fout<<smap[accepter]<<endl;
            }
        }

    }

    for(i=0; i<np; i++)
    {
        fout<<s[i]<<" "<<smap[s[i]]<<endl;
    }
return 0;
}
