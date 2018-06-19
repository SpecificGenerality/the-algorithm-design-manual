/* 3-7 */
/* Strategy: Cache the max/min. If max and min are Nodes, then 
   initialize both to NULL and change the methods to handle 
   null pointers accordingly. 
   Init:
      max = Integer.MINVALUE;
      min = Integer.MAXVALUE;
   Insert: 
      if (insertNode.getValue() < min)
         min = insertNode.getValue();

      if (insertNode.getValue() > max)
         max = insertNode.getValue();
   Delete:
      if (deleteNode.getValue() == min):
         min = this.successor(deleteNode).getValue();
      if (deleteNode.getValue() == max):
         max = this.predecessor(deleteNode).getValue();
      delete(deleteNode);