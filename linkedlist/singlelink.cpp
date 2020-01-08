#include <string>
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};
class SingleList{
public:
    SingleList();
    // ~SingleList();
    int CreateSingleList(int size);
    int getSingleListData();
    int reverseSingleList();

    Node *head;
    int size;
};

SingleList::SingleList() {
    head = new Node;
    head->value = 0;
    head->next = NULL;
    size = 0;
}
int SingleList::CreateSingleList(int n) {
    if (n < 0) return -1;

    Node *p = NULL;
    Node *newNode = NULL;
    p = this->head;
    this->size = n;
    for (int i=1;i<=n;i++) {
        newNode = new Node;
        newNode->next = NULL;
        newNode->value = i;

        p->next = newNode;
        p = newNode;
    }
    return 0;
}
int SingleList::getSingleListData() {
    cout << "singleList length: " << this->size << endl;
    if (this->head == NULL) {
        cout << "empty link" << endl;
        return -1;
    }
    Node *p = this->head->next;
    while (p) {
        cout << p->value << endl;
        p = p->next;
    }
    return 0;
}


int SingleList::reverseSingleList() {
    if (this->head == NULL) {
        cout << "empty link" << endl;
        return -1;
    }
    Node *curP, *nextP;
    Node *lastP = NULL;
    curP = this->head->next;
    while(curP) {
        // ��¼��һ���ڵ�
        nextP = curP->next;

        // ��ǰ�ڵ�ָ����һ���ڵ�
        curP->next = lastP;

        // ָ�����
        lastP = curP;
        curP = nextP;
    }
    // headָ�����ڵ���ɷ�ת
    this->head->next = lastP;

    cout << "reverse success" << endl;
    return 0;
}

int main()
{
    SingleList list;
    Node *p = list.head;
    list.CreateSingleList(5);
    list.getSingleListData();
    list.reverseSingleList();
    list.getSingleListData();
    return 0;
}
