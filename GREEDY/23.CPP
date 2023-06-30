// C++ program to illustrate
// page faults in LRU

#include <bits/stdc++.h>
using namespace std;

/* Counts no. of page faults */
int pageFaults(int n, int c, int pages[])
{
    // Initialise count to 0
    int count = 0;

    // To store elements in memory of size c
    vector<int> v;
    int i;
    for (i = 0; i <= n - 1; i++) {

        // Find if element is present in memory or not
        auto it = find(v.begin(), v.end(), pages[i]);

        // If element is not present
        if (it == v.end()) {

            // If memory is full
            if (v.size() == c) {
              
                // Remove the first element
                // As it is least recently used
                v.erase(v.begin());
            }

            // Add the recent element into memory
            v.push_back(pages[i]);

            // Increment the count
            count++;
        }
        else {

            // If element is present
            // Remove the element
            // And add it at the end as it is
            // the most recent element
            v.erase(it);
            v.push_back(pages[i]);
        }
    }

    // Return total page faults
    return count;
}

/* Driver program to test pageFaults function*/
int main()
{

    int pages[] = { 1, 2, 1, 4, 2, 3, 5 };
    int n = 7, c = 3;

    cout << "Page Faults = " << pageFaults(n, c, pages);
    return 0;
}

// This code is contributed by rajsanghavi9.




/*/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the length of the array 'Pages'.

int pageFaults(int C, vector<int> Pages)
{
    int n = Pages.size();
    int ans = 0, i = 0, j = 0, tot = 0;
    vector<int> last(n + 1, -1);
    unordered_set<int> s;
    while (j < n)
    {
        // Moving the right pointer and adding the current page to set 'S'.
        while (j < n)
        {
            // Checking if the current page is present in the memory or not.
            if (s.find(Pages[j]) == s.end())
            {
                if (tot == C)
                {
                    // we need to remove some page from memory to make room for this page.
                    break;
                }
                else
                {
                    // We have space to add the current page in the memory.
                    s.insert(Pages[j]);
                    ans++;
                    tot++;
                    // Updating the last occurence  of current page 'Pages[j]'.
                    last[Pages[j]] = j;
                    j++;
                }
            }
            else
            {
                // We already have the required page, so we do not need to add it again.
                last[Pages[j]] = j;
                j++;
            }
        }
        // Removing the Least Recently used page from the memory to create a empty space.
        while (i < j)
        {
            if (last[Pages[i]] == i)
            {
                s.erase(Pages[i]);
                tot--;
                i++;
                break;
            }
            i++;
        }
    }
    return ans;
}*/





// Author: RainX (ABHIJIT ROY, NIT AGARTALA)

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node(int data) {
	this->data = data;
	}
};

unordered_map<int, Node*> mpp;
int size = 0;
Node* head = nullptr;
Node* tail = nullptr;

int pageFaults(int N, int C, int pages[]) {
	int faults = 0;
	for (int i = 0; i < N; i++) {
		if (mpp.find(pages[i]) == mpp.end()) { // O(1)
			faults++;
			if (size == C) {
				mpp.erase(head->data);
				head = head->next;
				size--;
			}
			Node* newNode = new Node(pages[i]);
			if (head == nullptr) {
				head = newNode;
				tail = head;
			}
		
			newNode->prev = tail;
			tail->next = newNode;
			tail = tail->next;
		
			size++;
			mpp[pages[i]] = newNode;
		}
		else {
			Node* ptr = mpp[pages[i]];
			if (ptr == head) { // O(1) linkage time
				head = head->next;
				ptr->prev = tail;
				tail->next = ptr;
				tail = tail->next;
			}
			else if (tail != ptr) { // O(1) linkage time
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				ptr->prev = tail;
				tail->next = ptr;
				tail = tail->next;
			}
		}
	}
	return faults;
}

int main(){

	int pages[] = { 1, 2, 1, 4, 2, 3, 5 };
	int n = 7, c = 3;

	cout << "Page Faults = " << pageFaults(n, c, pages);
	return 0;
}

// Author: RainX (ABHIJIT ROY, NIT AGARTALA)
