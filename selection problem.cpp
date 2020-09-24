#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;
int PandS(vector<int> newS,int k,int totalnum)
{
    if(totalnum%5==0)
        totalnum=totalnum/5;
    else
    {
        for(int i=totalnum%5;i<5;i++)
            newS.push_back(9999);
        totalnum=totalnum/5+1;
    }
    vector<int> S1,S2,S3,midS,S[totalnum];
    int temp=totalnum/2,z=0,init=0,p=0,ans=0;
    for(int i=0;i<totalnum;i++)
    {
        init=i*5;
        for(z=init;z<init+5;z++)
            S[i].push_back(newS[z]);
        sort(S[i].begin(),S[i].end());
        if(S[i][2]==9999)
        {
            for(int k=1;k>=0;k--)
                if(S[i][k]!=9999)
                    midS.push_back(S[i][k]);
        }
        else
            midS.push_back(S[i][2]);
    }
    sort(midS.begin(),midS.end());
    if(totalnum%2==0)
        p=(midS[temp]+midS[temp-1])/2;
    else
        p=midS[temp];
    for(int i=0;i<totalnum;i++)
        for(int j=0;j<5;j++)
        {
            if(S[i][j]<p)
                S1.push_back(S[i][j]);
            else if(S[i][j]==p)
                S2.push_back(S[i][j]);
            else
                S3.push_back(S[i][j]);
        }
    if(k<=S1.size())
    {
        temp=S2.size()+S3.size();
        cout << "P : " << p << endl;
        cout << "此回合刪除" << temp << "個數字" << endl;
        PandS(S1,k,S1.size());

    }
    else if(k<=S1.size()+S2.size())
    {
        ans = S2[0];
        cout << ans << endl;
        return ans;
    }
    else
    {
        temp=S2.size()+S1.size();
        cout << "P : " << p << endl;
        cout << "此回合刪除" << temp << "個數字" << endl;
        k=k-S1.size()-S2.size();
        PandS(S3,k,S3.size());

    }
}
int main()
{
    vector < int > S;
    int k,ans=0;
    srand(time(NULL));
    for(int i=0;i<100;i++)
        S.push_back((rand()%1000)+1);
    cout << "請輸入要找尋第幾大的數字 : " ;
    cin >> k;
    PandS(S,k,100);
}
