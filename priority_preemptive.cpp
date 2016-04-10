#include <iostream>
#include <algorithm>

using namespace std;

class job
{
public:
    int job_no;
    int AT, BT;   //AT~Arrival Time & BT~Burst Time
    int CT, TAT, WT;  //CT~Completion Time, TAT~Turn Around Time & WT~Waiting Time
    int P;
    int RT;
};

bool compare(class job a, class job b)
{
    if(a.P != b.P)
        return a.P < b.P;
    else
        return a.job_no < b.job_no;
}
bool compare2(class job a, class job b)
{
    return a.job_no < b.job_no;
}

int main()
{
    int i, n, trt=0, chk, time = 0;
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
        job_arr[i].RT = job_arr[i].BT;
        trt += job_arr[i].BT;
    }
    cout<<"\nEnter priorities for jobs 1 to "<<n<<" :\n";
    for (i = 0; i < n; i++)
    {
        cin>>job_arr[i].P;
    }
    chk = 0;
    while (trt)
    {
        sort(job_arr+chk, job_arr+n, compare);
        for (i = chk; i < n; i++)
        {
            if (job_arr[i].AT <= time)
            {
                if (i == chk)
                {
                    chk++;
                    time += job_arr[i].RT;
                    trt -= job_arr[i].RT;
                    job_arr[i].RT = 0;
                    job_arr[i].CT = time;
                }
                else
                {
                    time++;
                    trt--;
                    job_arr[i].RT--;
                    if (job_arr[i].RT == 0)
                        job_arr[i].CT = time;
                }
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        job_arr[i].TAT = job_arr[i].CT - job_arr[i].AT;
        job_arr[i].WT = job_arr[i].TAT - job_arr[i].BT;
        avg += job_arr[i].WT;
    }
    avg = avg/n;


    cout<<"\n\n\tJob\t\tPr.\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n\n";

    sort(job_arr, job_arr+n, compare2);

    for (i = 0; i < n; i++)
    {
        cout<<"\tJ"<<job_arr[i].job_no<<"\t\t"<<job_arr[i].P<<"\t\t"<<job_arr[i].AT<<"\t\t"<<job_arr[i].BT<<"\t\t"
        <<job_arr[i].CT<<"\t\t"<<job_arr[i].TAT<<"\t\t"<<job_arr[i].WT<<"\n\n";
    }
    cout<<"Average Waiting Time :"<<avg<<"\n\n";


    return 0;
}
