class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* pen = &dummy;
        for (int i = 1; i < left; ++i) pen = pen->next;   // nodul dinaintea poziției left

        ListNode* start = pen->next;                      // nodul de la poziția left
        ListNode* cur = start;
        ListNode* prev = nullptr;
        for (int i = left; i <= right; ++i) {             // numeri pașii, nu compari cu un nod
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        start->next = cur;    // coada segmentului inversat -> nodul de după right
        pen->next = prev;     // nodul dinainte -> noul cap al segmentului
        return dummy.next;
    }
};