// Last updated: 5/28/2025, 9:52:45 PM
class ThroneInheritance {
private:
    unordered_map<string, vector<string>> familyTree;
    unordered_set<string> deceased;
    string monarch;
    vector<string> inheritanceOrder;

public:
    ThroneInheritance(string kingName) : monarch(kingName) {}

    void birth(string parentName, string childName) {
        familyTree[parentName].push_back(childName);
    }

    void death(string name) {
        deceased.insert(name);
    }

    vector<string> getInheritanceOrder() {
        inheritanceOrder.clear();
        depthFirstSearch(monarch);
        return inheritanceOrder;
    }

    void depthFirstSearch(const string& name) {
        if (!deceased.count(name)) {
            inheritanceOrder.push_back(name);
        }
        for (const auto& child : familyTree[name]) {
            depthFirstSearch(child);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */