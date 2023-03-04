#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int totalMarks;
    cin>>totalMarks;
    int totalStudents;
    cin>>totalStudents;
    vector<string>studentName(totalStudents);
    for(int i=0;i<totalStudents;i++)
    {
        cin>>studentName[i];
    }
    vector<int>obtainedMarks(totalStudents);
    for(int i=0;i<totalStudents;i++)
    {
        cin>>obtainedMarks[i];
    }
    vector<string>passOrFail(totalStudents);
    for(int i=0;i<totalStudents;i++)
    {
        cin>>passOrFail[i];
    }
    int requiredPr;
    cin>>requiredPr;
    vector<string>result;
    for(int i=1;i<=totalStudents;i++)
    {
        int maxMarks=INT_MIN;
        int indOfMax;
        for(int j=0;j<totalStudents;j++)
        {
            if(maxMarks<obtainedMarks[j])
            {
                maxMarks=obtainedMarks[j];
                indOfMax=j;
            }
        }
        float pr=((totalStudents-i)/(float)(totalStudents))*100;
        if(pr>=requiredPr && passOrFail[indOfMax]=="Passed")
        {
            result.push_back(studentName[indOfMax]);
        }
        obtainedMarks[indOfMax]=-1;
    }
    for(int i=0;i<result.size();i++)
    {
        if(i==result.size()-1)
        {
            cout<<result[i];
        }
        else
        {
            cout<<result[i]<<",";
        }
    }
    return 0;
}