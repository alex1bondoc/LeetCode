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
    int pairSum(ListNode* head) {
        int res{};
        auto slow{head}, fast{head->next};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto next = slow->next;
        slow->next = nullptr;
        ListNode* prev{};
        slow = next;
        while (slow) {
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        auto cur{head};
        while (cur) {
            res = max(res, cur->val + prev->val);
            cur = cur->next;
            prev = prev->next;
        }
        return res;
    }
};