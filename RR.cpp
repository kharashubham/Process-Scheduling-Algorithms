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
    int i, n, RT[20], total = 0, TQ, PCT = 0;
    float avg = 0;
    job job_arr[20];
    cout<<"\n\nEnter the number of Jobs/Processes : ";
    cin>>n;
    cout<<"Enter Time Quantum : ";
    cin>>TQ;
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
        total += job_arr[i].BT;
        job_arr[i].RT = job_arr[i].BT;
    }
    sort(job_arr, job_arr+n, compare);

    if(job_arr[0].RT < TQ || job_arr[0].RT == TQ)
    {
        PCT = job_arr[0].AT + job_arr[0].BT;
        job_arr[0].CT = PCT;
        job_arr[0].RT = 0;
        total -= job_arr[0].BT;
    }
    else
    {
        PCT = job_arr[0].AT + TQ;
        job_arr[0].RT = job_arr[0].BT - TQ;
        total -= TQ;
    }
    while (total)
    {
            for (i = 1; i < n; i++)
            {
                if(job_arr[i].RT)
                {
                if (job_arr[i].AT > PCT)
                {
                    break;
                }
                else
                {
                    if(job_arr[i].RT < TQ || job_arr[i].RT == TQ)
                    {
                        PCT += job_arr[i].RT;
                        job_arr[i].CT = PCT;
                        total -= job_arr[i].RT;
                        job_arr[i].RT = 0;
                    }
                    else
                    {
                        PCT += TQ;
                        job_arr[i].RT -= TQ;
                        total -= TQ;
                    }
                }
                }
            }
        if(job_arr[0].RT)
        {
        if(job_arr[0].RT < TQ || job_arr[0].RT == TQ)
        {
            PCT += job_arr[0].RT;
            job_arr[0].CT = PCT;
            total -= job_arr[0].RT;
            job_arr[0].RT = 0;
        }
        else
        {
            PCT += TQ;
            job_arr[0].RT -= TQ;
            total -= TQ;
        }
        }

    }

    for (i = 0; i < n; i++)
    {
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
