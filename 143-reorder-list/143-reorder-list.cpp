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
    ListNode* reverse(ListNode* &head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newhead= reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
            
        
    }
    
    void reorderList(ListNode* head) {
        
        // find the mid of the list
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //reverse the second half
        
        ListNode* second=reverse(slow->next); 
         
        slow->next=NULL;
        ListNode* first=head; 
        
        // merge lists
       
        while(second)
        {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};