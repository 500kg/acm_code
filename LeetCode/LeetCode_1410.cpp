class Solution {
public:
    
    string entityParser(string text) {
        string ans;
        vector<string> t;
        string f;
        t.push_back("&quot;"); f += '\"';
        t.push_back("&apos;"); f += '\'';
        t.push_back("&amp;"); f += '&';
        t.push_back("&gt;"); f += '>';
        t.push_back("&lt;"); f += '<';
        t.push_back("&frasl;"); f += '/';
        for(int i = 0; i < text.length(); i++){
            if(text[i] != '&') ans += text[i];
            else{
                int flag = 0;
                for(int j = 0; j < 6; j++){
                    if(text.find(t[j], i) == i){
                        ans += f[j], i += t[j].length() - 1;
                        flag = 1;
                    }
                }
                if(!flag) ans += '&';
            }
        }
        return ans;
    }
};