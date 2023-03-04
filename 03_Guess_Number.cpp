//Not applicable if operator is modulo(%)
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long int f,n;
    cin>>f>>n;
    cin.get();
    vector<string>operations;
    string temp;
    while(n--)
    {
        getline(cin,temp);
        operations.push_back(temp);
    }
    // for(string x:operations)
    // {
    //     cout<<x<<" ";
    // }
    long double ans=f;
    for(int i=operations.size()-1;i>=0;i--)
    {
        long long int num=0,r;
        long double x;
        string z;
        for(int j=operations[i].length()-1;j>=0;j--)
        {
            if(operations[i][j]>47 && operations[i][j]<58)
            {
                if(operations[i][j]=='0')
                {
                    z+='0';
                }
                else
                {
                    if(z.length()>0)
                    {
                        string k=operations[i][j]+z;
                        num=(long long int)stoi(k);
                        continue;
                    }
                    r=operations[i][j]-48;
                    num=num*10+r;
                }
            }
            else if(operations[i][j]==' ' && operations[i][j-1]=='^')
            {
                if(num==0)
                {
                    cout<<-2;
                    return 0;
                }
                if(num==1)
                {
                    cout<<ans<<"\n";
                    continue;
                }
                x=1/(long double)num;
                ans=pow(ans,x);
                cout<<ans<<"\n";
                break;
            }
            else if(operations[i][j]==' ' && operations[i][j-1]=='/')
            {
                if(num==0)
                {
                    cout<<-1;
                    return 0;
                }
                ans=ans*num;
                cout<<ans<<"\n";
                break;
            }
            else if(operations[i][j]==' ' && operations[i][j-1]=='*')
            {
                if(num==0)
                {
                    cout<<-2;
                    return 0;
                }
                ans=ans/(long double)num;
                cout<<ans<<"\n";
                break;
            }
            else if(operations[i][j]==' ' && operations[i][j-1]=='-')
            {
                ans=ans+num;
                cout<<ans<<"\n";
                break;
            }
            else if(operations[i][j]==' ' && operations[i][j-1]=='+')
            {
                ans=ans-num;
                cout<<ans<<"\n";
                break;
            }
        }
    }
    cout<<"\n\n";
    cout<<ans<<endl;
    return 0;
}