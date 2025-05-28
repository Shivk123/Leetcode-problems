// Last updated: 5/28/2025, 9:48:06 PM
class Solution {
public:
    static bool arrange(const vector<string>& a, const vector<string>& b) {
    int timeA = stoi(a[1]);
    int timeB = stoi(b[1]);

    if (timeA != timeB) {
        return timeA < timeB; 
    }

    if (a[0] == "OFFLINE" && b[0] == "MESSAGE") {
        return true;
    }
    if (a[0] == "MESSAGE" && b[0] == "OFFLINE") {
        return false;
    }

    return false;
}
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers),off(numberOfUsers);
        sort(events.begin(),events.end(),arrange);
        for(auto it: events){
            if(it[0]=="MESSAGE"){
                if(it[2]=="ALL"){
                    for(int i=0;i<numberOfUsers;i++){
                        ans[i]++;
                    }
                }
                else if(it[2]=="HERE"){
                    for(int i=0;i<numberOfUsers;i++){
                        if(stoi(it[1])>=off[i])ans[i]++;
                        cout<<off[i]<<endl;
                    }
                }
                else{
                    stringstream s(it[2]);
                    string w;
                    while (s >> w){
                        cout<<w.substr(2)<<endl;
                        int key = stoi(w.substr(2));
                        ans[key]++;
                    }
                }
            }
            else{
                off[stoi(it[2])]=stoi(it[1])+60;
                cout<<"off "<<it[2]<<off[stoi(it[2])]<<endl;
            }
        }
        return ans;
    }
};