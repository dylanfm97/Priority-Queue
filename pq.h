#include <vector>

struct node {
  int key;
  int value;
  int position;
} ;

class PriorityQueue {
 public:
  PriorityQueue(std::vector<node>);  
  void printqueue();
  node* deletemin();
  void decreasekey(node x);
  void changevalue(int i, int value);
  node getnode(int i);
  int size();

 private:
  std::vector<node> makeheap(std::vector<node> S);
  std::vector<node> mHeap;
  int minchild(int i);
  void siftdown(node x, int i);
  void bubbleup(node x, int i);
 
};
