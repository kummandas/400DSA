/*
    Time Complexity : O(N *maxDeadline)
    Space Complexity :O(maxDeadline)

    Where 'N' is size of the array "jobs" and 
    'maxDeadline' is the maximum among all the deadlines.


#include <algorithm>

// Custom Comparator function to sort the jobs in the decreasing order of their profit.
bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    // Find the maximum deadline among all the jobs.
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    // Create a slots array of size maxDeadline + 1.
    bool slots[maxDeadline + 1];

    // Initialize the array to false initially.
    for (int i = 0; i <= maxDeadline; i++)
    {
        slots[i] = false;
    }

    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {

            if (slots[j] == false)
            {
                maxProfit = maxProfit + jobs[i][1];
                slots[j] = true;
                break;
            }
        }
    }

    return maxProfit;
}
*/






// C program for the above approach

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct Job {
  
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
} Job;

// This function is used for sorting all jobs according to
// profit
int compare(const void* a, const void* b)
{
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return (temp2->profit - temp1->profit);
}

// Find minimum between two numbers.
int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
    // Sort all jobs according to decreasing order of profit
    qsort(arr, n, sizeof(Job), compare);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n]; // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
      
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
          
            // Free slot found
            if (slot[j] == false) {
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%c ", arr[result[i]].id);
}

// Driver's code
int main()
{
    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf(
        "Following is maximum profit sequence of jobs \n");

    // Function call
    printJobScheduling(arr, n);
    return 0;
}









// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
  
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit earned if job is completed before
                // deadline
};

// Custom sorting helper struct which is used for sorting
// all jobs according to profit
struct jobProfit {
    bool operator()(Job const& a, Job const& b)
    {
        return (a.profit < b.profit);
    }
};

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
    vector<Job> result;
    sort(arr, arr + n,
         [](Job a, Job b) { return a.dead < b.dead; });
  
    // set a custom priority queue
    priority_queue<Job, vector<Job>, jobProfit> pq;
  
    for (int i = n - 1; i >= 0; i--) {
        int slot_available;
      
        // we count the slots available between two jobs
        if (i == 0) {
            slot_available = arr[i].dead;
        }
        else {
            slot_available = arr[i].dead - arr[i - 1].dead;
        }
      
        // include the profit of job(as priority),
        // deadline and job_id in maxHeap
        pq.push(arr[i]);
      
        while (slot_available > 0 && pq.size() > 0) {
          
            // get the job with the most profit
            Job job = pq.top();
            pq.pop();
          
            // reduce the slots
            slot_available--;
          
            // add it to the answer
            result.push_back(job);
        }
    }
  
    // sort the result based on the deadline
    sort(result.begin(), result.end(),
         [&](Job a, Job b) { return a.dead < b.dead; });
  
    // print the result
    for (int i = 0; i < result.size(); i++)
        cout << result[i].id << ' ';
    cout << endl;
}

// Driver's code
int main()
{
    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
  
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";

    // Function call
    printJobScheduling(arr, n);
    return 0;
}

// This code is contributed By Reetu Raj Dubey