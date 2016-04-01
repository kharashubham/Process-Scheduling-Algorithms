#include <iostream>
#include <algorithm>

using namespace std;

class job
{
public:
    int job_no;
    int AT, BT;   //AT~Arrival Time & BT~Burst Time
    int CT, TAT, WT;  //CT~Completion Time, TAT~Turn Around Time & WT~Waiting Time
    int RT;
};

bool compare(class job a, class job b)
{
    if(a.BT != b.BT)
        return a.BT < b.BT;
    else
        return a.job_no < b.job_no;
}
bool compare2(class job a, class job b)
{
    return a.job_no < b.job_no;
}
int main()
{
    int i, n, PCT = 0, max_at = 0, str, fg = 0, chk = 0;
    float avg = 0;
    job job_arr[20];
    cout<<"\n\nEnter the number of Jobs/Processes : ";
    cin>>n;
    cout<<"--------All processes arriving together at 0-------";
    cout<<"\nEnter Burst Time for jobs 1 to "<<n<<" :\n";
    for (i = 0; i < n; i++)
    {
        job_arr[i].job_no = i+1;
        cin>>job_arr[i].BT;
    }

    sort(job_arr, job_arr+n, compare);

    PCT = job_arr[0].BT;
    job_arr[0].CT = PCT;

    for (i = 1; i < n; i++)
    {
        job_arr[i].CT = PCT + job_arr[i].BT;
        PCT = job_arr[i].CT;
    }


    for (i = 0; i < n; i++)
    {
        job_arr[i].TAT = job_arr[i].CT ;
        job_arr[i].WT = job_arr[i].TAT - job_arr[i].BT;
        avg += job_arr[i].WT;
    }
    avg = avg/5;


    cout<<"\n\n\tJob\t\tBT\t\tCT\t\tTAT\t\tWT\n\n";

    sort(job_arr, job_arr+n, compare2);

    for (i = 0; i < n; i++)
    {
        cout<<"\tJ"<<job_arr[i].job_no<<"\t\t"<<job_arr[i].BT<<"\t\t"
        <<job_arr[i].CT<<"\t\t"<<job_arr[i].TAT<<"\t\t"<<job_arr[i].WT<<"\n\n";
    }
    cout<<"Average Waiting Time :"<<avg<<"\n\n";

return 0;
}
