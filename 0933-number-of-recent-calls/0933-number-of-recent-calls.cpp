class RecentCounter {
    std::queue<int> q{};

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int mini = t - 3000;
        q.push(t);
        while (q.size() && q.front() < mini) {
            q.pop();
        }

        return static_cast<int>(q.size());    
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */