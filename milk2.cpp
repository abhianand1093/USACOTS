/*
ID: abhiana1
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>



using namespace std;

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    long long int n, i, num1, num2, temp1=0, temp2=0, milkingtime=0, notmilkingtime=0,start, end, j;
    vector <long long int> vec1, vec2;

    fin>>n;

    for(i=0; i<n; i++)
    {
        fin>>num1>>num2;
        vec1.push_back(num1);
        vec2.push_back(num2);
    }

//    for(i=0; i<n; i++)
//    {
//        fout<<vec1[i]<<" "<<vec2[i]<<endl;
//    }



    for(i=1; i<n; i++)
    {
        j = i;
        while( j > 0 and vec1[j-1] > vec1[j])
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

    start = vec1[0];
    end = vec2[0];
    milkingtime = end - start;
    notmilkingtime = 0;

    for(i=1; i<n; i++)
    {
        while(vec1[i] <= end && i<n)
        {
            if(end <= vec2[i])
                end = vec2[i];
            i++;
        }

        temp1 = end - start;

        temp2 = vec1[i] - end;
        start = vec1[i];
        end = vec2[i];
        if(temp1>milkingtime)
            milkingtime = temp1;
        if(temp2>notmilkingtime)
            notmilkingtime = temp2;


    }

    fout<<milkingtime<<" "<<notmilkingtime<<endl;

    fin.close();
    fout.close();

return 0;
}
