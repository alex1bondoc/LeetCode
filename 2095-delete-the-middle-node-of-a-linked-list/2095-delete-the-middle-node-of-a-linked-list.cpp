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
    ListNode* deleteMiddle(ListNode* head) {
        auto slow{head}, fast{head};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev{};
        auto cur{head};
        while (cur != slow) {
            prev = cur;
            cur = cur->next;
        }
        if (prev) {
            prev->next = slow->next;
            delete slow;
            return head;
        }
        else {
            
            return nullptr;
        }
        
    }
};