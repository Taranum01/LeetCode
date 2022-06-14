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
    
   struct cmp{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
    
 ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    for(auto x : lists){  
            if(x)
            q.push(x);
    }
     
    ListNode temp(0);
    ListNode *node = &temp;
     
    while (!q.empty()){
        ListNode *t = q.top();
        q.pop();
        node->next = t;
        node = node->next;
        if(t->next)
            q.push(t->next);

    }
    return temp.next;
  }
};

