#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define MAX 500

int max(int a, int b){
    return a > b ? a : b;
}
 
// Driver program
int main()
{
    vector<vector<string> > student = {{"Bob","87"}, {"Mike", "35"},{"Bob", "52"}, {"Jason","35"}, {"Mike", "55"}, {"Jessica", "99"}};
    int high = 0;
    string name;
    map<string, int> sum;
    map<string, int> count;
    for(int i = 0; i < student.size(); i++){
        //cout << student[i][0] << "\n";
        int avg = 0;
        if(count.find(student[i][0]) != count.end()){
            int currCount = count[student[i][0]];
            currCount++;
            count[student[i][0]] = currCount;
            int currSum = sum[student[i][0]];
            currSum = currSum + stoi(student[i][1]);
            sum[student[i][0]] = currSum;
            avg = currSum/currCount;
        }
        else{
            count[student[i][0]] = 1;
            sum[student[i][0]] = stoi(student[i][1]);
            avg = stoi(student[i][1]);
        }
        if(avg > high){
            high = avg;
            name = student[i][0];
        }
    }
    cout << "Student with highest average of " << high << " is: " << name;
    return 0;
}