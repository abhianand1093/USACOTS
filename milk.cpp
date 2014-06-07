/*
ID: abhiana1
PROG: milk
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>


using namespace std;

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    long long int n, m, i, num1, num2, j, cost = 0, temp1, temp2;
    vector <long long int> vec1, vec2;

    fin>>n>>m;

    for(i=0; i<m; i++)
    {
        fin>>num1>>num2;
        vec1.push_back(num1);
        vec2.push_back(num2);
    }

//    for(i=0; i<n; i++)
//    {
//        fout<<vec1[i]<<" "<<vec2[i]<<endl;
//    }



    for(i=1; i<m; i++)
    {
        j = i;
        while( j > 0 && vec1[j-1] > vec1[j])
        {
            temp1 = vec1[j];
            vec1[j] = vec1[j-1];
            vec1[j-1] = temp1;

            temp1 = vec2[j];
            vec2[j] = vec2[j-1];
            vec2[j-1] = temp1;

            j--;
        }
    }

//    fout<<endl<<endl;
//    for(i=0; i<n; i++)
//    {
//        fout<<vec1[i]<<" "<<vec2[i]<<endl;
//    }

    for(i=0; i<m; i++)
    {
        if(n > vec2[i])
        {
            n = n - vec2[i];
            cost = cost + vec2[i]*vec1[i];
        }
        else
        {
            cost = cost + vec1[i]*n;
            break;
        }
    }

    fout<<cost<<endl;

    fin.close();
    fout.close();

return 0;
}
