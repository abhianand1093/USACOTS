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
char dict[5000][13];

void load()
{
    int i=0;
    do
    {
        fin1>>dict[i];
        i++;
    }while(fin1);
}

int check(char *name, string number)
{
    int i, j, flag = 0;

    for(i=0; i<number.size(); i++)
    {

        for(j=0; j<3; j++)
        {
            if(name[i] == keymap[(int)(number[i] - 48 -2)][j])
            {
                flag = 1;
                break;
            }

        }
        if(flag == 1)
            flag =  0;
        else
            return 0;
    }
return 1;
}


void fun(string number)
{
    int i=0;

    while(i<5000)
    {

        if(strlen(dict[i]) == number.size())
        {   if(check(dict[i], number)==1)
            {
                count++;
                fout<<dict[i]<<endl;
            }

        }
        i++;
    }
}


int main()
{
    string number;
    load();
    fin>>number;

    fun(number);

    if(count == 0)
        fout<<"NONE\n";

    fin.close();
    fout.close();


return 0;
}
