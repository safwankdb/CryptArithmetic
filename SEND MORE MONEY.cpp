#include <bits/stdc++.h>

using namespace std;

vector<int> a(8,0);
vector<bool> f(8,false);

void print()
{
    cout<<" " <<a[0]<<a[1]<<a[2]<<a[3]<<endl;
    cout<<" " <<a[7]<<a[5]<<a[6]<<a[1]<<endl;
    cout<<a[7]<<a[5]<<a[2]<<a[1]<<a[4]<<endl;
}
bool check()
{
    int x=a[0]*1000+a[1]*100+a[2]*10+a[3];
    int y=a[7]*1000+a[5]*100+a[6]*10+a[1];
    int z=a[7]*10000+a[5]*1000+a[2]*100+a[1]*10+a[4];
    //cout<<"CHECK"<<endl;
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(x+y==z)
    {
        print();
    }
    return (x+y==z);
}
bool assign(int i, int d)
{
    if(!f[d])
    {
        //f[a[i]]=false;
        f[d]=true;
        a[i]=d;
        return true;
    }
    else
        return false;
}
bool solve(int i)
{
    if(i==7)
    {
        if(check())
        {
            //a[6]++;
            //solve(7);
            return true;
        }
            
        else
        {
            return false;
        }
    }
    for(int j=0;j<10;j++)
    {
        if(i==0)
        {
            if(j<8&&j>0)
                continue;
        }
        if(assign(i,j))
        {
            if(solve(i+1))
                return true;
            else
                f[j]=false;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    a[7]=1;
    f[1]=true;
    bool b=solve(0);
    //cout<<b;
    return 0;
}