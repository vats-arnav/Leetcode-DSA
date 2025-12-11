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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* ans = new ListNode(0, head);
        ListNode* temp = ans;
        set<int> s1;
        for (int i : nums) {
            s1.insert(i);
        }

        while (temp->next != nullptr) {
            if (s1.count(temp->next->val)) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return ans->next;
    }
};