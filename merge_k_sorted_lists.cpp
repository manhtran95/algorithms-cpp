#include <bits/stdc++.h>
using std::vector;
using std::cout;
using std::ceil;

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* l){
    while (l != nullptr){
        std::cout << l->val << ", ";
        l = l->next;
    }
    cout << "\n";
}

class Solution {    
    public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* current = new ListNode();
        ListNode* first = new ListNode(0, current);
        int v1, v2;
        while (l1 != nullptr && l2 != nullptr){
            v1 = l1->val; v2 = l2->val;
            if (v1 < v2){
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        current->next = l1 == nullptr? l2 : l1;
        return first->next->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int k = lists.size(); int n = k;
        int d = 2;
        while (k > 1){
            for (int i = 0; i+d/2 < n; i += d){
                lists[i] = merge2Lists(lists[i], lists[i+d/2]);
            }
            d *= 2;
            k = ceil(static_cast<float>(k)/2);
        }
        return lists[0];
    }
};

ListNode* createLinkedList(int arr[], int N){
    ListNode* cur = new ListNode();
    ListNode* first = new ListNode(0, cur);
    for (int i=0; i<N; i++){
        ListNode* nextNode = new ListNode(arr[i]);
        cur->next = nextNode;
        cur = cur->next;
    }
    return first->next->next;
};



int main(){
    Solution sol;
    int a1[] = {1, 4, 5, 10};
    int a2[] = {2, 6, 8, 20};
    int a3[] = {3, 7, 15};
    ListNode* l1 = createLinkedList(a1, 4);
    ListNode* l2 = createLinkedList(a2, 4);
    ListNode* l3 = createLinkedList(a3, 3);
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* l4 = sol.mergeKLists(lists);
    printList(l4);
}