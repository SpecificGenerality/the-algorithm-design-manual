/* 3-8 */
/* Approach: BST. Node stores size of subtree rooted at that Node. Modify insert
            such that counters are updated when traversing down tree:
            public void insert(Value value) {
               Node node = new Node(value);
               insert(node, root);
            }
            private void insert(Node newNode, Node curNode) {
               if (curNode == NULL)
                  return newNode;
               else if (newNode.getValue() >= curNode.getValue())
                  curNode.updateSize();
                  curNode.right = insert(newNode, curNode.right);
                  return curNode;
               else 
                  curNode.updateSize();
                  curNode.left = insert(newNode, curNode.left);
                  return curNode;
            }

            Set the rank of new Node on insert as follows:
            if (current.right != NULL)
               Rank = current.right.getSize() + 1; 
            else 
               Rank = 1;

            Assuming balanced binary tree:
               insert: O(log n)
               delete: O(log n) (traversal of tree of height at most log n checking rank)
               member: O(log n) 
            */
