#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;
int main()
{
    vector<int> C[5],R[5];
    vector<float> CANS[5],RANS[5],MANS[5];
    int x,y,M,r=0;
    ifstream fin;
    float distance,mini;
    fin.open("node.txt");
    for(int i=0;i<5;i++)
    {
        fin >> x;
        fin >> y;
        C[i].push_back(x);
        C[i].push_back(y);
    }
    sort(C,C+5);
    M=(C[0][0]+C[4][0])/2;
    for(int i=4;i>=0;i--)
    {
        if(C[i][0]>M)
        {
            R[r].push_back(C[i][0]);
            R[r].push_back(C[i][1]);
            C[i].pop_back();
            C[i].pop_back();
            r++;
        }
    }
    sort(R,R+r);
    int temp;
    if(r!=4)
    {
        for(int k=0,i=0;i<4-r;i++)
        {
            for(int j=i+1;j<5-r;j++)
            {
                distance=pow((C[j][0]-C[i][0]),2)+pow((C[j][1]-C[i][1]),2);
                distance=sqrt(distance);
                CANS[k].push_back(C[i][0]);
                CANS[k].push_back(C[i][1]);
                CANS[k].push_back(C[j][0]);
                CANS[k].push_back(C[j][1]);
                CANS[k].push_back(distance);
                k++;
                temp=k;
            }
        }
        for(int i=temp-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                if(CANS[j][4]>CANS[j+1][4])
                    swap(CANS[j],CANS[j+1]);
    }
    if(r!=1)
    {
        for(int k=0,i=0;i<r;i++)
        {
            for(int j=i+1;j<r;j++)
            {
                distance=pow((R[j][0]-R[i][0]),2)+pow((R[j][1]-R[i][1]),2);
                distance=sqrt(distance);
                RANS[k].push_back(R[i][0]);
                RANS[k].push_back(R[i][1]);
                RANS[k].push_back(R[j][0]);
                RANS[k].push_back(R[j][1]);
                RANS[k].push_back(distance);
                k++;
                temp=k;
            }
        }
        for(int i=temp-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                if(RANS[j][4]>RANS[j+1][4])
                    swap(RANS[j],RANS[j+1]);
    }
    if(r!=1&&r!=4)
        mini=min(CANS[0][4],RANS[0][4]);
    while(1)
    {
        if(r==1)
        {
            cout << CANS[0][0] << "," << CANS[0][1] << endl;
            cout << CANS[0][2] << "," << CANS[0][3] << endl;
            cout << CANS[0][4] << endl;
            break;
        }
        else if(r==4)
        {
            cout << RANS[0][0] << "," << RANS[0][1] << endl;
            cout << RANS[0][2] << "," << RANS[0][3] << endl;
            cout << RANS[0][4] << endl;
            break;
        }
        else
        {
            int l=5-r;
            for(int i=4-r;i>=0;i--)
            {
                if(mini<M-C[i][0])
                {
                    swap(C[i],C[l-1]);
                    C[i].pop_back();
                    C[i].pop_back();
                    l--;
                }
            }
            for(int i=r-1;i>=0;i--)
            {
                if(mini<R[i][0]-M)
                {
                    swap(R[i],R[r-1]);
                    R[i].pop_back();
                    R[i].pop_back();
                    r--;
                }
            }

            int k=0;
            if(l!=0&&r!=0)
            {
                for(int i=0;i<l;i++)
                    for(int j=0;j<r;j++)
                    {
                        distance=pow((R[j][0]-C[i][0]),2)+pow((R[j][1]-C[i][1]),2);
                        distance=sqrt(distance);
                        MANS[k].push_back(C[i][0]);
                        MANS[k].push_back(C[i][1]);
                        MANS[k].push_back(R[j][0]);
                        MANS[k].push_back(R[j][1]);
                        MANS[k].push_back(distance);
                        k++;

                    }
                    if(MANS[0][4]<=mini)
                    {
                        cout << MANS[0][0] << "," << MANS[0][1] << endl;
                        cout << MANS[0][2] << "," << MANS[0][3] << endl;
                        cout << MANS[0][4] << endl;
                        break;
                    }
            }
            else if(l==0)
                r=4;
            else if(r==0)
                r=1;
        }
    }
}
