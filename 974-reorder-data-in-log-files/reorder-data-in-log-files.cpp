class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<string> letterLogs;
        vector<string> digitLogs;

        for (string& log : logs) {

            int spacePos = log.find(' ');

            if (isdigit(log[spacePos + 1])) {  
                digitLogs.push_back(log);
            } else {
                letterLogs.push_back(log);
            }

        }

        sort(letterLogs.begin(), letterLogs.end(), [](const string& a, const string& b) {

            int spacePosA = a.find(' ');
            int spacePosB = b.find(' ');

            string contentA = a.substr(spacePosA + 1);
            string contentB = b.substr(spacePosB + 1);

            string idA = a.substr(0, spacePosA);
            string idB = b.substr(0, spacePosB);

        
            if (contentA == contentB) {
                return idA < idB;
            }
            
            return contentA < contentB;

        });

        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());

        return letterLogs;
    }
};
