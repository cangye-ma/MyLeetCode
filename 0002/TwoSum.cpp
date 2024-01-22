
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        int l1Size = getLength(l1);
        int l2Size = getLength(l2);
        ListNode *resultNode{nullptr};
        resultNode = (l1Size < l2Size) ? l2 : l1;
        ListNode *iterNode = resultNode;
        int carryIn{0};
        while (l1 || l2) {
            if (l1 != nullptr && l2 != nullptr) {
                iterNode->val = l1->val + l2->val + carryIn;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != nullptr) {
                iterNode->val = l1->val + carryIn;
                l1 = l1->next;
            } else {
                iterNode->val = l2->val + carryIn;
                l2 = l2->next;
            }
            if (iterNode->val >= 10) {
                iterNode->val = iterNode->val - 10;
                carryIn = 1;
            } else {
                carryIn = 0;
            }
            if (iterNode->next != nullptr) [[likely]] {
                iterNode = iterNode->next;
            }
        }
        if (carryIn == 1) {
            iterNode->next = new ListNode(1, nullptr);
        }
        return resultNode;
    }

private:
    int getLength(ListNode *headNode)
    {
        if (headNode == nullptr) {
            return 0;
        }

        int size{0};
        while (headNode) {
            ++size;
            headNode = headNode->next;
        }

        return size; 
    }
};