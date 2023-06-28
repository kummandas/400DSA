class Solution{
  public:
    bool isOk(int a, int b, int c, int d) {
        return a <= 255 and b <= 255 and c <= 255 and d <= 255;
    }
    
    string make(int a, int b, int c, int d) {
        return to_string(a) + "." + to_string(b) + "." + to_string(c) + "." +
               to_string(d);
    }
    
    vector<string> genIp(string &s) {
        vector<string> res;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    for (int l = 1; l <= 3; l++) {
                        if (i + j + k + l == s.length()) {
                            int a = stoi(s.substr(0, i));
                            int b = stoi(s.substr(i, j));
                            int c = stoi(s.substr(i + j, k));
                            int d = stoi(s.substr(i + j + k, l));
    
                            if (isOk(a, b, c, d)) {
                                string str = make(a, b, c, d);
                                /*+3 because of 3 dots*/
                                if (str.length() == s.length() + 3) {
                                    res.push_back(str);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};