class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                S.push(s[i]);
            else{
                if(S.empty()) return 0;
                if(s[i] == ')' && S.top() != '(') return 0;
                if(s[i] == ']' && S.top() != '[') return 0;
                if(s[i] == '}' && S.top() != '{') return 0;
                S.pop();
            }
        }
        return S.empty();
    }
};