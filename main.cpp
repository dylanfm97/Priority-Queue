#include <iostream>
#include <stdlib.h>

#include "pq.h"

int main() {
  
  std::vector<node> nodes;
  std::vector<int> weights = {5, 8, 5, 18, 18, 17, 19, 21};

  for(int i = 0; i < weights.size(); i++){
    node n;
    n.key = i;
    n.value = weights[i];
    nodes.push_back(n);
  }
  


  PriorityQueue pq = PriorityQueue(nodes);
  pq.printqueue();

  std::cout << "deleting.." << std::endl;
  pq.deletemin();
  pq.printqueue();

  std::cout << "deleting again" << std::endl;
  pq.deletemin();
  pq.printqueue();

  std::cout << "changing index 4 to weight 0" << std::endl;
  pq.changevalue(4, 0);
  pq.decreasekey(pq.getnode(4));

  pq.printqueue();


  return 0;

}
