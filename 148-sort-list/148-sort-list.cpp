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
    
    ListNode* merge(ListNode* l,ListNode* r){
        if(l!=nullptr and r!=nullptr){
            if(l->val<=r->val){
                l->next = merge(l->next,r);
                return l;
            }
            else{
                r->next = merge(l,r->next);
                return r;
            }
        }
        
        return (l==nullptr?r:l);
    }
    ListNode* merge_sort(ListNode* head){
        if(head==nullptr or head->next==nullptr){
            return head;
        }
        
        // 2 length list
        if(head->next->next==nullptr){
            if(head->next->val<head->val){
                ListNode* next_node = head->next;
                next_node->next = head;
                head->next = nullptr;
                head = next_node;
            }
            return head;
        }
        
        
        ListNode *slow = head,*fast = head;
        while(fast!=nullptr and fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* node2 = merge_sort(slow->next);
        slow->next = nullptr;
        ListNode* node1 = merge_sort(head);
        
        return merge(node1,node2);
        
    }
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};