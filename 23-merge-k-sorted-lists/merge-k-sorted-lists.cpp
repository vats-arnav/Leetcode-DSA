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

class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if (temp->next != nullptr) {
                pq.push(temp->next);
            }
        }

        return dummy->next;
    }
};