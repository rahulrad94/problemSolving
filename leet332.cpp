/* Reconstruct Itinerary
 * Time : O(n)
 * Simple DFS
 */

class Solution {
public:
    vector<string> res;

    void calc(unordered_map<string, multiset<string>> &hmap, string str){

        while(hmap[str].size()){
                string s = *hmap[str].begin();
                hmap[str].erase(hmap[str].begin());
                calc(hmap, s);
        }
        res.push_back(str);
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        int n = tickets.size();
        if(!n) return res;

        unordered_map<string, multiset<string>> hmap;

        for(int i=0;i<n;i++)
            hmap[tickets[i].first].insert(tickets[i].second);

        calc(hmap, "JFK");
        return vector<string>(res.rbegin(),res.rend());
    }
};
