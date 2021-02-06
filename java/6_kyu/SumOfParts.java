/**
Let us consider this example (array written in general format):
    ls = [0, 1, 3, 6, 10]
Its following parts:
    ls = [0, 1, 3, 6, 10]
    ls = [1, 3, 6, 10]
    ls = [3, 6, 10]
    ls = [6, 10]
    ls = [10]
    ls = []
The corresponding sums are (put together in a list): [20, 20, 19, 16, 10, 0]
The function parts_sums (or its variants in other languages) will take as parameter a list ls and return a list of the sums of its parts as defined above.
 */

public class SumOfParts {
    
  public static int[] sumParts(int[] ls) {
    final int range = ls.length; 

    int[] result = new int[range + 1];    
    result[range] = 0;
    for(int i=range; i>0; --i){
        result[i-1] = result[i] + ls[i-1];
    }

    return result;
    }
}
