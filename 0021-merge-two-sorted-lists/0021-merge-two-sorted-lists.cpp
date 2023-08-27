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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        ListNode* newnode =  new ListNode();
         ListNode*dummy =  newnode;
        while(list1 != NULL && list2 !=NULL){
            if(list1->val > list2->val){
                // newnode->val = list2->val;
                newnode->next = new ListNode(list2->val);
                list2 = list2->next;

            }

             else {
                newnode->next = new ListNode(list1->val);
                list1 = list1->next;
            }

            newnode = newnode->next;
        }

        while(list1!=NULL){
            newnode->next =  new ListNode(list1->val);
            list1 =  list1->next;
             newnode = newnode->next;
        }

        while(list2!=NULL){
            newnode->next = new ListNode(list2->val);
            list2 =  list2->next;
             newnode = newnode->next;
        }

        return dummy->next;
    }
};