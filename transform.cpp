/*
ID: abhiana1
PROG: transform
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stdlib.h>

using namespace std;

//void print(char **result, int n)
//{
//    int i, j;
//
//    cout<<"\n";
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n ;j++)
//        {
//            cout<<result[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//}

int compare(char **input, char **output, int n)
{
    int i, j;
    //cout<<"Compare  \n";
//    print(input, n);
//    print(output, n);
    //cout<<"Compare  \n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            //cout<<"output[i][j] "<<output[i][j]<<"input[i][j] "<<input[i][j]<<endl;
            if(output[i][j] != input[i][j])
                return 0;
        }
    }
return 1;
}

void trans270(char **input, char **result, int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            result[n-1-j][i] = input[i][j];
        }
    }

}

void trans180(char **input, char **result, int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            result[n-1-i][n-1-j] = input[i][j];
        }
    }

}

void trans90(char **input, char **result, int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            result[i][j] = input[n-1-j][i];
        }
    }

}


void mirrorver(char **input, char **result, int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            result[i][j] = input[i][n-1-j];
        }
    }

}

//void mirrorhori(char **input, char **result, int n)
//{
//    int i, j;
//
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n ;j++)
//        {
//            result[i][j] = input[n-1-i][j];
//        }
//    }
//
//}

int combi(char **input, char **result, int n, char **output)
{
    int i, value;

    char **temp = (char **)malloc(sizeof(char *) * n);
    for(i=0; i<n; i++)
    {
        *(temp + i) = (char *)malloc(sizeof(char) * n);
    }

    mirrorver(input, temp, n);
    trans90(temp, result, n);
    value = compare(result, output, n);
    if(value == 1)
        return 1;

    trans180(temp, result, n);
    value = compare(result, output, n);
    if(value == 1)
        return 1;

    trans270(temp, result, n);
    value = compare(result, output, n);
    if(value == 1)
        return 1;
return 0;
}

int check(char **input, char **output, int n)
{
    int i, j, value;

    char **result = (char **)malloc(sizeof(char *) * n);
    for(i=0; i<n; i++)
    {
        *(result + i) = (char *)malloc(sizeof(char) * n);
    }

    //print(result, n);

    trans90(input, result, n);
    value = compare(result, output, n);
//    print(result, n);
//    cout<<"value = "<<value<<endl;
    if(value == 1)
        return 1;

    trans180(input, result, n);
    value = compare(result, output, n);
    //print(result, n);
    if(value == 1)
        return 2;

    trans270(input, result, n);
    value = compare(result, output, n);
    //print(result, n);
    if(value == 1)
        return 3;

    mirrorver(input, result, n);
    value = compare(result, output, n);
    //print(result, n);
    if(value == 1)
        return 4;

    value = combi(input, result, n, output);
    //print(result, n);
    if(value == 1)
        return 5;

    value = compare(input, output, n);
    if(value == 1)
        return 6;

return 7;
}


int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int n, i, j, result;

    fin>>n;

    char **input = (char **)malloc(sizeof(char *) * n);
    for(i=0; i<n; i++)
    {
        *(input + i) = (char *)malloc(sizeof(char) * n);
    }

    char **output = (char **)malloc(sizeof(char *) * n);
    for(i=0; i<n; i++)
    {
        *(output + i) = (char *)malloc(sizeof(char) * n);
    }


    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            fin>>input[i][j];
        }
    }


    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            fin>>output[i][j];
        }
    }

    result = check(input, output, n);

    fout<<result<<endl;

    fin.close();
    fout.close();

return 0;
}
