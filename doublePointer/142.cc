#include<iostream>
#include<vector>
#include<algorithm>
#include"ListNode.h"
using std::vector;


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        struct ListNode *slow =head, ListNode *fast = head;
        do{
            if (!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }
        while{fast != slow};
        fast = head;
        while (fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
    return fast;
    }
};


int main(int argc, char const *argv[]){


    

}