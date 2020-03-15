class CustomStack {
public:
    int maxi;
    vector<int> V;
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if(V.size() == maxi) return;
        V.push_back(x);
    }
    
    int pop() {
        if(V.empty()) return -1;
        int t = V.back();
        V.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, (int) V.size()); i++)
            V[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */