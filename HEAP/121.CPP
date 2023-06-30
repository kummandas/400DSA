/*class Solution {
public:
  string reorganizeString(string S) {
	vector<int> cnt(26);
	int mostFreq = 0, i = 0;

	for(char c : S)
		if(++cnt[c - 'a'] > cnt[mostFreq])
			mostFreq = (c - 'a');

	if(2 * cnt[mostFreq] - 1 > S.size()) return "";

	while(cnt[mostFreq]) {
		S[i] = ('a' + mostFreq);
		i += 2;
		cnt[mostFreq]--;
	}

	for(int j = 0; j < 26; j++) {
		while(cnt[j]) {
			if(i >= S.size()) i = 1;
			S[i] = ('a' + j);
			cnt[j]--;
			i += 2;
		}
	}

	return S;
}
};*/











class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }
        priority_queue<pair<int,char>> maxh;
        for(auto itr:m){
            maxh.push({itr.second,itr.first});
        }
        string ans="";
        while(maxh.size()>1){
            auto [a,b]=maxh.top();
            maxh.pop();
            auto [c,d]=maxh.top();
            maxh.pop();
            ans.push_back(b);
            ans.push_back(d);
            a--;
            c--;
            if(a>0){
                maxh.push({a,b});
            }
            if(c>0){
                maxh.push({c,d});
            }
        }
        if(maxh.size()==1){
            auto [a,b]=maxh.top();
            maxh.pop();
            if(a>1)return "";
            ans.push_back(b);
        }
        return ans;
    }
};









/*class Solution {
public:
    string reorganizeString(string S) {
        vector<int> mp(26);
        int n = S.size();
        for (char c: S)
            ++mp[c-'a'];
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) pq.push({mp[i], i+'a'});
        }
        queue<pair<int, char>> myq;
        string ans;
        while (!pq.empty() || myq.size() > 1) {
            if (myq.size() > 1) {
                auto cur = myq.front();
                myq.pop();
                if (cur.first != 0) pq.push(cur);
            }
            if (!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                ans += cur.second;
                cur.first--;
                myq.push(cur);
            }
        }
        return ans;
    }
};*/