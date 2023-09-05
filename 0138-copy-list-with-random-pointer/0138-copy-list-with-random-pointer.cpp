/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node* , Node*>mp;
        Node*dummy = new Node(0);
        Node*curr = dummy;
        Node*original = head;

        while(original){
            Node*copy = new Node(original->val);
            curr->next = copy;
            mp[original] = copy;

            curr = curr->next;
            original = original->next;
        }

        original = head;
        curr = dummy->next;

        while(original){
            if(original->random){
                curr->random = mp[original->random];
            }

            original = original->next;
            curr = curr->next;
        }

        return dummy->next;

    }
};