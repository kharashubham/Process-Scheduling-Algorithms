#include <iostream>
#include <algorithm>

using namespace std;

class job
{
    public:
    int job_no;
    int AT, BT;   //AT~Arrival Time & BT~Burst Time
    int CT, TAT, WT;  //CT~Completion Time, TAT~Turn Around Time & WT~Waiting Time

};

bool compare(class job a, class job b)
{
    if(a.AT != b.AT)
        return a.AT < b.AT;
    else
        return a.job_no < b.job_no;
}
bool compare2(class job a, class job b)
{
    return a.job_no < b.job_no;
}

int main()
{
    int i, n;
    float avg = 0;
    job job_arr[20];
    cout<<"\nEnter the number of Jobs/Processes : ";
    cin>>n;
    cout<<"\nEnter Arrival Time for jobs 1 to "<<n<<" :\n";
    for (i = 0; i < n; i++)
    {
        job_arr[i].job_no = i+1;
        cin>>job_arr[i].AT;
    }
    cout<<"\nEnter Burst Time for jobs 1 to "<<n<<" :\n";
    for (i = 0; i < n; i++)
    {
        cin>>job_arr[i].BT;
    }
    sort(job_arr, job_arr+n, compare);

        job_arr[0].WT = 0;
        job_arr[0].CT = job_arr[0].AT + job_arr[0].BT;
        job_arr[0].TAT = job_arr[0].BT;

    for (i = 1; i < n; i++)
    {
        if (job_arr[i].AT < job_arr[i-1].CT)
            job_arr[i].CT = job_arr[i-1].CT + job_arr[i].BT;
        else
        {
            job_arr[i].CT = job_arr[i].AT + job_arr[i].BT;
        }
        job_arr[i].TAT = job_arr[i].CT - job_arr[i].AT;
        job_arr[i].WT = job_arr[i].TAT - job_arr[i].BT;
        avg += job_arr[i].WT;
    }
    avg = avg/5;


    cout<<"\n\n\tJob\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n\n";

    sort(job_arr, job_arr+n, compare2);

    for (i = 0; i < n; i++)
    {
        cout<<"\tJ"<<job_arr[i].job_no<<"\t\t"<<job_arr[i].AT<<"\t\t"<<job_arr[i].BT<<"\t\t"
        <<job_arr[i].CT<<"\t\t"<<job_arr[i].TAT<<"\t\t"<<job_arr[i].WT<<"\n\n";
    }
    cout<<"Average Waiting Time :"<<avg<<"\n\n";

return 0;
}
