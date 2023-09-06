/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        ListNode* curr = head;
        int totalNodes = 0;

        while(curr) {
            totalNodes++;
            curr = curr->next;
        }

        int nodesPerBucket = totalNodes / k;
        int extraNodes = totalNodes % k;

        vector<ListNode*> res(k, NULL);
        curr = head;
        ListNode* prev = NULL;

        for(int i = 0; curr  && i < k ; i++) {
            
            res[i] = curr;

            for(int count = 1; count <= nodesPerBucket + (extraNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            extraNodes--;
        }

        return res;
    }
};
