#ifndef STRUCT_LISTNODE_H 
#define STRUCT_LISTNODE_H 

using namespace std; 

struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    }; 
#endif // STRUCT_LISTNODE_H 
