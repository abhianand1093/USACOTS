/*
ID: abhiana1
PROG: namenum
LANG: C++
*/


#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
ifstream fin1("dict.txt");

char keymap[8][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};
int recur = 0, count =0;
char dict[4620][13];

void load()
{
    int i=0;
    do
    {
        fin1>>dict[i];
        i++;
    }while(fin1);
}

int check(char *str)
{
    int i=0;

    do
    {
        fout<<dict[i]<<endl;
        if(strcmp(dict[i], str)==0)
            return 1;
        i++;
    }while(dict[i][0] <= str[0] && i<4620);
return 0;
}

void genname(char *name, string number, int i)
{
    int j;

    if(strlen(name) == number.size())
    {
        if(check(name)== 1)
        {
            fout<<name<<endl;
            count++;
        }
    }
    else
    {
        for(j=0; j<3; j++)
        {
            name[i] = keymap[(int)(number[i] - 48 -2)][j];
            name[i+1] = '\0';
            genname(name, number, i+1);
        }
    }
}

int main()
{

    char name[15];
    string number;
    load();
    fin>>number;
    cout<<number;
    name[0] = '\0';
    genname(name, number, 0);

    if(count == 0)
        fout<<"NONE\n";

    fin.close();
    fout.close();

return 0;
}
