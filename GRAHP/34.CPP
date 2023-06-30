/*
    Time complexity: O(M + N)
    Space complexity: O(M + N) 

    Where 'M' represents the capacity of water the first vessel can store and 
    'N' represents the capacity of water the second vessel can store.


#include <unordered_map>
#include <queue>

class Triplet {
public:
    int x, y, steps;

    Triplet(int x, int y, int steps) {
        this -> x = x;
        this -> y = y;
        this -> steps = steps;
    }
};

int ninjaAndVessels(int m, int n, int w) {
    // Queue to store the vessel states.
    queue<Triplet> vesselStates;
    // Map to have a track of visited states.
    unordered_map<string, bool> visitedStates;
    // Initially start with 0 capacities and 0 steps.
    vesselStates.push(Triplet(0, 0, 0));

    // Iterate till all states of vessel are observed.
    while (!vesselStates.empty()) {
        // Take the first state at the front of the queue.
        Triplet currState = vesselStates.front();
        vesselStates.pop();

        // If the given state is visited, then continue the loop.
        if (visitedStates.find(to_string(currState.x) + "_" + to_string(currState.y)) != visitedStates.end()) {
            continue;
        }

        // Make the current state as visited.
        visitedStates[to_string(currState.x) + "_" + to_string(currState.y)] = true;

        // If capacity is equal to the required capacity, then return the steps.
        if (currState.x == w || currState.y == w) {
            return currState.steps;
        }

        // Now push the possible states in the queue.
        vesselStates.push(Triplet(0, currState.y, currState.steps + 1));
        vesselStates.push(Triplet(currState.x, 0, currState.steps + 1));

        vesselStates.push(Triplet(m, currState.y, currState.steps + 1));
        vesselStates.push(Triplet(currState.x, n, currState.steps + 1));

        vesselStates.push(Triplet(min(currState.x + currState.y, m),
                max(currState.x + currState.y - m, 0), currState.steps + 1));
        vesselStates.push(Triplet(max(0, currState.x + currState.y - n),
                min(currState.x + currState.y, n), currState.steps + 1));

    }

    // If required weight cannot be achieved, return -1.
    return -1;

}
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void printpath(map<pii, pii> mp, pii u)
{
	if (u.first == 0 && u.second == 0) {
		cout << 0 << " " << 0 << endl;
		return;
	}
	printpath(mp, mp[u]);
	cout << u.first << " " << u.second << endl;
}
void BFS(int a, int b, int target)
{
	map<pii, int> m;
	bool isSolvable = false;
	map<pii, pii> mp;

	queue<pii> q;

	q.push(make_pair(0, 0));
	while (!q.empty()) {

		auto u = q.front();
		// cout<<u.first<<" "<<u.second<<endl;
		q.pop();
		if (m[u] == 1)
			continue;

		if ((u.first > a || u.second > b || u.first < 0
			|| u.second < 0))
			continue;
		// cout<<u.first<<" "<<u.second<<endl;

		m[{ u.first, u.second }] = 1;

		if (u.first == target || u.second == target) {
			isSolvable = true;

			printpath(mp, u);
			if (u.first == target) {
				if (u.second != 0)
					cout << u.first << " " << 0 << endl;
			}
			else {
				if (u.first != 0)
					cout << 0 << " " << u.second << endl;
			}
			return;
		}
		// completely fill the jug 2
		if (m[{ u.first, b }] != 1) {
			q.push({ u.first, b });
			mp[{ u.first, b }] = u;
		}

		// completely fill the jug 1
		if (m[{ a, u.second }] != 1) {
			q.push({ a, u.second });
			mp[{ a, u.second }] = u;
		}

		// transfer jug 1 -> jug 2
		int d = b - u.second;
		if (u.first >= d) {
			int c = u.first - d;
			if (m[{ c, b }] != 1) {
				q.push({ c, b });
				mp[{ c, b }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ 0, c }] != 1) {
				q.push({ 0, c });
				mp[{ 0, c }] = u;
			}
		}
		// transfer jug 2 -> jug 1
		d = a - u.first;
		if (u.second >= d) {
			int c = u.second - d;
			if (m[{ a, c }] != 1) {
				q.push({ a, c });
				mp[{ a, c }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ c, 0 }] != 1) {
				q.push({ c, 0 });
				mp[{ c, 0 }] = u;
			}
		}

		// empty the jug 2
		if (m[{ u.first, 0 }] != 1) {
			q.push({ u.first, 0 });
			mp[{ u.first, 0 }] = u;
		}

		// empty the jug 1
		if (m[{ 0, u.second }] != 1) {
			q.push({ 0, u.second });
			mp[{ 0, u.second }] = u;
		}
	}
	if (!isSolvable)
		cout << "No solution";
}

int main()
{
	int Jug1 = 4, Jug2 = 3, target = 2;
	cout << "Path from initial state "
			"to solution state ::\n";
	BFS(Jug1, Jug2, target);
	return 0;
}
