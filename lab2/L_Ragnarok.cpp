# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }
};
// Kadane's algorithm
int findMaxSum(int n, Node *head) {
    int current_sum = 0;
    int max_sum = head->val;  // Initialize to the first node's value in case all values are negative

    Node *current = head;
    while (current != NULL) {
        current_sum += current->val;
        
        // Update max_sum if current_sum is larger
        max_sum = max(max_sum, current_sum);
        
        // If current_sum drops below 0, reset it
        if (current_sum < 0) {
            current_sum = 0;
        }
        
        current = current->next;
    }

    return max_sum;
}

int main() {
  int n;
  cin >> n;

  Node *head = NULL, *tail = NULL;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
