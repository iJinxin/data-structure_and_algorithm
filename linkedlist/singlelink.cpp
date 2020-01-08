#include <iostream>
#include <string>

using namespace std;

struct Node {
  int value;
  Node *next;
};
class SingleList {
 public:
  SingleList();
  // ~SingleList();
  void createSingleList(int size);     // 创建链表
  bool isEmpty();                      // 判断是否为空
  void insertNode(Node *data, int n);  // 插入数据
  void removeNode();                   // 删除数据
  void destroyLink();                  // 摧毁链表
  void getSingleListData();            // 获取链表数据
  void reverseSingleList();            // 链表反转

  Node *head;
  int size;
};

SingleList::SingleList() {
  head = new Node;
  head->value = 0;
  head->next = NULL;
  size = 0;
}
// 创建链表
void SingleList::createSingleList(int n) {
  if (n < 0) return;

  Node *p = NULL;
  Node *newNode = NULL;
  p = this->head;
  this->size = n;
  for (int i = 1; i <= n; i++) {
    newNode = new Node;
    newNode->next = NULL;
    newNode->value = i;

    p->next = newNode;
    p = newNode;
  }
}

bool SingleList::isEmpty() {
  if (this->head == NULL) {
    cout << "empty link" << endl;
    return true;
  }
  return false;
}
// 链表插入
void SingleList::insertNode(Node *data, int n) {
  if (data == NULL) {
    cout << "插入节点为空" << endl;
    return;
  }
  if (n <= 0) {
    cout << "插入位置有误" << endl;
    return;
  }

  // 队尾插入
  if (this->size < n) {
    Node *p = this->head;
    for (int i = 0; i < this->size; i++) {
        p = p->next;
    }
    p->next = data;
    data->next = NULL;
  } else if (n == 1) {
      // 队首插入
      Node *p = this->head->next;
      data->next = p;
      this->head->next = data;
  } else {
      // 队中插入
  }
}
// 获取链表内容
void SingleList::getSingleListData() {
  cout << "singleList length: " << this->size << endl;
  if (isEmpty()) {
    return;
  }
  Node *p = this->head->next;
  while (p) {
    cout << p->value << endl;
    p = p->next;
  }
}

// 链表反转
void SingleList::reverseSingleList() {
  if (isEmpty()) {
    return;
  }
  Node *curP, *nextP;
  Node *lastP = NULL;
  curP = this->head->next;
  while (curP) {
    // 记录下一个节点
    nextP = curP->next;

    // 当前节点指向上一个节点
    curP->next = lastP;

    // 指针后移
    lastP = curP;
    curP = nextP;
  }
  // head指向最后节点完成翻转
  this->head->next = lastP;

  cout << "reverse success" << endl;
}

int main() {
  SingleList list;
  Node *p = list.head;
  list.createSingleList(5);
  list.getSingleListData();
  list.reverseSingleList();
  list.getSingleListData();
  return 0;
}
