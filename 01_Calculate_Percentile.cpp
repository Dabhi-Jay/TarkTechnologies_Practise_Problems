//Calculate Percentile Score
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int totalStudents;
    cin>>totalStudents;
    vector<int>obtainedMarks(totalStudents);
    for(int i=0;i<totalStudents;i++)
    {
        cin>>obtainedMarks[i];
    }
    int myScore;
    cin>>myScore;
    int count=0;      //count indicates number of students that have less marks than mine.
    for(int i=0;i<totalStudents;i++)
    {
        if(obtainedMarks[i]<myScore)
        {
            count++;
        }
    }
    cout<<setprecision(4)<<(count/(float)(totalStudents))*100;
    return 0;
}