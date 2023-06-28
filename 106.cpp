#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,q;
	cin>>n;
	vector<int>v(n),prefix(n);
	for(int i=0;i<n;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++) {
		prefix[i]=(i>0?prefix[i-1]+v[i]:v[i]);
	}
	cin>>q;
	for(int i=0;i<q;i++) {
		int bishu,start=0,end=n-1,index=0;
		cin>>bishu;
		while(start<=end) {
			int mid=(start+(end-start)/2);
			if(v[mid]<=bishu) {
				index=mid;
				start=mid+1;
			}
			else {
				end=mid-1;
			}
		}
		cout<<index+1<<" "<<prefix[index]<<endl;
	}
	return 0;
}