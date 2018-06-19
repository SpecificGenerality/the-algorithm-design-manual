/* 3-4 */
public class WholeNumberArray {
   private int[] numbers; 
   // initialization takes n time: single loop 
   public WholeNumberArray(int n) {
      numbers = new Integer[n + 1];
      for (int i = 0; i < n + 1; i++) {
         numbers[i] = -1;
      }
   }
   // constant insert: single array access
   public void insert(int i) {
      numbers[i] = i;
   }
   // constant delete: single array access
   public int delete(int i) {
      numbers[i] = -1;
      return i;
   }
   // constant search: single array access
   public int search(int i) {
      return numbers[i];
   }
}