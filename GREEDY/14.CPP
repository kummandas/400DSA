/*
    Time Complexity: O(1)
    Space Complexity: O(1)

bool isPossibleToSurvive(int n, int x, int d){

    if(d <= 6){
        if(n >= x){
            return true;
        }else {
            return false;
        }
    }
    else{
        if(n >= x && 6*n >= 7*x){
            return true;
        }else {
            return false;
        }
    }
}*/




// C++ program to find the minimum days on which
// you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// function to find the minimum days
void survival(int S, int N, int M)
{

	// If we can not buy at least a week
	// supply of food during the first week
	// OR We can not buy a day supply of food
	// on the first day then we can't survive.
	if (((N * 6) < (M * 7) && S > 6) || M > N)
		cout << "No\n";
	else {
		// If we can survive then we can
		// buy ceil(A/N) times where A is
		// total units of food required.
		int days = (M * S) / N;
		if (((M * S) % N) != 0)
			days++;
		cout << "Yes " << days << endl;
	}
}

// Driver code
int main()
{
	int S = 10, N = 16, M = 2;
	survival(S, N, M);
	return 0;
}









// C++ program to find the minimum days on which
// you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// function to find the minimum days
int minimumDays(int S, int N, int M)
{

	// Food required to survive S days
	double req = S * M;

	// If buying all possible days except sundays, but can't
	// provide the sufficient food. If total can't provide
	// then each week also can't provide.
	if ((S - S / 7) * N < req) {
		return -1;
	} // If possible get the number of days.
	else {
		return ceil(req / N);
	}

	// Or Simply one line code:
	// return ((S-S/7)*N<S*M) ? -1 : ceil(static_cast<double>(S*M)/N);
}

// Driver code
int main()
{
	int S = 10, N = 16, M = 2;

	int days = minimumDays(S, N, M);
	if (days != -1) {
		cout << "Yes " << days << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
