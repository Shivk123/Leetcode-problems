// Last updated: 5/28/2025, 9:53:31 PM
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(), folders.end());

        vector<string> filteredFolders = {folders[0]};

        for (int i = 1; i < folders.size(); ++i) {
            int parentSize = filteredFolders.back().size();
            int currentSize = folders[i].size();

            if (parentSize >= currentSize ||
                !(filteredFolders.back() == folders[i].substr(0, parentSize) &&
                  folders[i][parentSize] == '/')) {
                filteredFolders.emplace_back(folders[i]);
            }
        }

        return filteredFolders;
    }
};