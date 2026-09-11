class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        unordered_set<int> visited;
        visited.insert(0);
        auto dfs = [&](auto self, int cur) ->void{
            for (const auto& k : rooms[cur]) {
                keys.insert(k);
            }
            for (auto key : keys) {
                if (visited.contains(key)) continue;
                visited.insert(key);
                self(self, key);
            }
        };
        dfs(dfs, 0);
        return visited.size() == rooms.size();
    }
};