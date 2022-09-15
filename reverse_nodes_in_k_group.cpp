#include <bits/stdc++.h>
using std::cout;

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

void change(ListNode* l){
    l->next = l->next->next;
}

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

void test(ListNode* prev){
        if (prev == nullptr){
        cout << "nulll\n";
    }
}

// (prev, next)
ListNode* reverseK(ListNode* prev, ListNode* next, int k){
    ListNode* origin = prev->next;
    ListNode* reverse = next;
    ListNode* temp; ListNode* first = prev->next;
    int count = 0;
    while (count < k){
        // cout << count;
        // cout << origin->val << "-o   "; 
        // cout << reverse->val << "-r   "; 
        temp = origin->next;
        
        origin->next = reverse;
        reverse = origin;

        origin = temp;
        // cout << origin->val << "-o after\n"; 
        count++;
    }
    prev->next = reverse;
    // printList(first);
    return first;
};

ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* cur = head;
    ListNode* dummy = new ListNode(0, cur);
    ListNode* prev = dummy;
    while (cur != nullptr){
        int count = 0;
        while (count < k && cur != nullptr){
            count++;
            cur = cur->next;
        }
        if (count == k){
            prev = reverseK(prev, cur, k);
        }
    }
    return dummy->next;
};

int main(){
    int a[]{1,2,3};
    int ak[]{1,2,3,4,5,6,7,8};
    ListNode* l1 = createLinkedList(a, 3);
    ListNode* lk = createLinkedList(ak, 8);
    ListNode* l0 = new ListNode(-1, l1);
    ListNode* l2 = l1->next->next->next;
    // l2->next = nullptr;
    ListNode* l3 = nullptr;
    // ListNode* l7 = reverseK(l0, l2, 3);
    ListNode* l7 = reverseKGroup(lk, 3);

    // test(nullptr);

    // printList(l);
    printList(l7);
}