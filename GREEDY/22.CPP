/*
        Time Complexity: O(N ^ 2)
        Space complexity: O(N)

        Where N denotes the number of processes.


#include<climits>

vector<float> sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) 
{
    vector<int>completionTime(n);
    vector<int>turnAroundTime(n);
    vector<int>waitingTime(n);
    vector<int>completed(n);

    int systemTime = 0, totalProcesses = 0;
    float avgwaitingTime = 0, avgturnAroundTime = 0;

    // Initializing all process as undone
    for (int i = 0; i < n; i++) 
    {
        completed[i] = 0;
    }

    // Till all the processes are done
    while (totalProcesses != n) 
    {
        int check = n, min = INT_MAX;

        for (int i = 0; i < n; i++) 
        {
            /*
                If the process arrival time is less than system time and it is not completed
                and burstTime is smallest of this process this process will be executed first
            
            if ((arrivalTime[i] <= systemTime) and (completed[i] == 0) and (burstTime[i] < min)) 
            {
                min = burstTime[i];
                check = i;
            }
        }

        // No process in the queue.
        if (check == n) 
        {
            systemTime++;
        }
        else 
        {
            completionTime[check] = systemTime + burstTime[check];
            systemTime += burstTime[check];
            turnAroundTime[check] = completionTime[check] - arrivalTime[check];
            waitingTime[check] = turnAroundTime[check] - burstTime[check];
            completed[check] = 1;
            totalProcesses++;
        }
    }

    // Sum for calculating averages
    for (int i = 0; i < n; i++) 
    {
        avgwaitingTime += waitingTime[i];
        avgturnAroundTime += turnAroundTime[i];
    }

    vector<float>ans(2);

    ans[0] = (float) (avgwaitingTime / n);
    ans[1] = (float) (avgturnAroundTime / n);

    return ans;
}
*/









#include <iostream>
using namespace std;

int main() {

	// Matrix for storing Process Id, Burst
	// Time, Average Waiting Time & Average
	// Turn Around Time.
	int A[100][4];
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;

	cout << "Enter number of process: ";
	cin >> n;

	cout << "Enter Burst Time:" << endl;

	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		cout << "P" << i + 1 << ": ";
		cin >> A[i][1];
		A[i][0] = i + 1;
	}

	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}

	A[0][2] = 0;
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}

	avg_wt = (float)total / n;
	total = 0;
	cout << "P	 BT	 WT	 TAT" << endl;

	// Calculation of Turn Around Time and printing the
	// data.
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		cout << "P" << A[i][0] << "	 " << A[i][1] << "	 " << A[i][2] << "	 " << A[i][3] << endl;
	}

	avg_tat = (float)total / n;
	cout << "Average Waiting Time= " << avg_wt << endl;
	cout << "Average Turnaround Time= " << avg_tat << endl;
}
